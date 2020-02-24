/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 13:37:41 by tlouekar          #+#    #+#             */
/*   Updated: 2020/02/24 20:11:48 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		helper_print_padding(t_printf *data)
{
	int		i;

	i = 0;
	i = data->fieldwidth - data->len;
	if ((data->minus == 1 && data->plus == 1) || 
	(data->lli < 0 && data->dot == 1) ||
	(data->minus == 0 && data->plus == 1) ||
	(data->minus == 1 && data->flo < 0))
		i--;
	if (data->prc > data->len)
		i -= data->prc - data->len;
	if (data->minus == 0 && data->fieldwidth > 0 && data->zero == 1 && data->dot == 0)
		i = 0;
	if (data->minus == 0 && data->fieldwidth > 0 && data->zero == 1 && (data->f == 1 || data->lf == 1))
		i = 0;
	while (i > 0)
	{
		ft_putchar(' ');
		i--;
	}
}


void		helper_zeros_spaces(t_printf *data)
{
	if (data->space == 1)
	{
		if (data->plus == 1 && data->minus == 1)
			;
		else if (data->minus == 1 && data->fieldwidth == 0 && data->lli < 0)
			data->len += 1;
		else if (data->minus == 1 && (data->lli >= 0 && data->flo >= 0))
		{
			data->len += 1;
			ft_putchar(' ');
		}
		else if (data->minus == 1)
			data->len += 1;
		else if (data->plus == 1 || data->lli < 0)
			;
		else if (data->fieldwidth == 0 && data->flo >= 0)
			ft_putchar(' ');
	}
}

void		helper_plusminus(t_printf *data)
{
	if (data->plus == 1 && data->lli >= 0 && data->flo >= 0) 
		ft_putchar('+');
	if (data->lli < 0 || data->flo < 0)
		ft_putchar('-');
}

/*
Precision helper works currently for i/d only
*/
void		helper_prc_zeros(t_printf *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (data->prc > data->len)
	{
		i = data->prc - data->len;
		data->len += i;
		if (data->space == 1 && data->minus == 1)
			i++;
	}
	else if ((data->dot == 0 || data->flo > 0) && data->zero == 1 && data->minus == 0)
	{
		i = data->fieldwidth - data->len;
		if (data->lli < 0 || data->plus == 1)
			i--;
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
	return (s);
}