/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 13:37:41 by tlouekar          #+#    #+#             */
/*   Updated: 2020/02/05 12:38:43 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		helper_print_padding(t_printf *data)
{
	int		i;

	i = 0;
	if (data->dot > 0)
		i = data->fieldwidth - data->prc; // This will not work in the end
	else
		i = data->fieldwidth - data->len;
	while (i > 0)
	{
		if (data->zero == 1 && data->minus == 0)
			ft_putchar('0');
		else
			ft_putchar(' ');
		i--;
	}
}

void		helper_handle_precision(t_printf *data)
{
	int		i;

	i = 0;
	if (data->prc > data->len)
		i = data->prc - data->len;
	while (i >= 0)
	{
		ft_putchar('0');
		i--;
	}
}

char		*helper_itoa_base(long value, int base)
{
	char	*s;
	long	n;
	int		i;

	n = (value < 0) ? -value : value;
	i = 1;
	while ((n /= base) >= 1)
		i++;
	s = (char*)malloc(sizeof(char) * (i + 1));
	s[i] = '\0';
	n = (value < 0) ? -value : value;
	while (i--)
	{
		s[i] = (n % base < 10) ? n % base + '0' : n % base + 'a' - 10;
		n /= base;
	}
	(i == 0) ? s[i] = '-' : 0;
	return (s);
}