/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 13:36:41 by tlouekar          #+#    #+#             */
/*   Updated: 2020/02/14 13:38:08 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			con_d(t_printf *data, va_list args)
{
	char		*str;

	data->lli = (long long)va_arg(args, int);
	str = helper_itoa_base(data->lli, 10, data);
	data->len = ft_strlen(str);
	helper_handle_precision(data);
	if (data->minus == 0)
		helper_print_padding(data);
	if (data->plus == 1 && data->lli >= 0) 
		ft_putchar('+');
	if (data->lli < 0)
		ft_putchar('-');
	if (data->space == 1)
	{
		if (data->plus == 1 && data->minus == 1)
			;
		else if (data->minus == 1 && data->fieldwidth == 0 && data->lli < 0)
			data->len += 1;
		else if (data->minus == 1 && data->lli >= 0)
		{
			data->len += 1;
			ft_putchar(' ');
		}
		else if (data->minus == 1)
			data->len += 1;
		else if (data->plus == 1 || data->lli < 0)
			;
		else if (data->fieldwidth == 0)
			ft_putchar(' ');
	}
	ft_putstr(str);
}