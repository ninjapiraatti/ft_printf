/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 13:36:41 by tlouekar          #+#    #+#             */
/*   Updated: 2020/02/03 12:35:49 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			con_d(t_printf *data, va_list args)
{
	long long	number;
	char		*str;

	number = (long long)va_arg(args, int);
	str = helper_itoa_base(number, 10);
	data->len = ft_strlen(str);
	if (data->plus == 1)
		ft_putchar('+');
	if (data->space == 1)
	{
		if (data->plus == 1 && data->minus == 1)
			;
		else if (data->minus == 1 && data->fieldwidth == 0)
			data->len += 1;
		else if (data->minus == 1 && number >= 0)
			ft_putchar(' ');
		else if (data->minus == 1)
		{
			data->len += 1;
			ft_putchar(' ');
		}
		else
			ft_putchar(' ');
	}
	if (data->minus == 0)
		helper_print_padding(data);
	ft_putnbr(number);
}