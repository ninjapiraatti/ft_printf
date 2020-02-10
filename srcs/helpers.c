/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 13:37:41 by tlouekar          #+#    #+#             */
/*   Updated: 2020/02/10 15:58:01 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		helper_print_padding(t_printf *data)
{
	int		i;

	i = 0;
	/*if (data->dot > 0 && (data->i > 0 || data->d > 0))
		i = data->fieldwidth - data->prc;
	else*/
	i = data->fieldwidth - data->len;
	if ((data->minus == 1 && data->plus == 1) || 
	(data->lli < 0 && data->dot == 1))
		i--;
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
	{
		i = data->prc - data->len;
		if (data->space == 1)
			i++;
	}
	while (i > 0)
	{
		ft_putchar('0');
		i--;
	}
}

char		*helper_itoa_base(long long value, int base, t_printf *data)
{
	char		*s;
	long long	n;
	int			i;
	int			j;

	n = (value < 0) ? -value : value;
	i = 1;
	while ((n /= base) >= 1)
		i++;
	s = (char*)malloc(sizeof(char) * (i + 1));
	s[i] = '\0';
	n = (value < 0) ? -value : value;
	if ((j = data->prc - i) < 0)
		j = 0;
	while (i--)
	{
		s[i + j] = (n % base < 10) ? n % base + '0' : n % base + 'a' - 10;
		n /= base;
	}
	while (j > 0)
	{
		s[j - 1] = '0';
		j--;
	}
	(i == 0) ? s[i] = '-' : 0;
	return (s);
}