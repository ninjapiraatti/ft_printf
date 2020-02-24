/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 13:36:41 by tlouekar          #+#    #+#             */
/*   Updated: 2020/02/24 12:12:42 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			con_f(t_printf *data, va_list args)
{
	char		*str;

	if (data->star == 1)
	{
		if (data->dot == 1)
			data->prc = va_arg(args, int);
		else
			data->fieldwidth = va_arg(args, int);
	}
	if (data->lf == 1)
		data->flo = va_arg(args, long double);
	else
		data->flo = va_arg(args, double);
	if (data->dot == 0)
		data->prc = 6;
	str = ftoa(data->flo, data);
	data->len = ft_strlen(str);
	if (data->minus == 0)
		helper_print_padding(data);
	helper_plusminus(data);
	helper_zeros_spaces(data);
	helper_prc_zeros(data);
	ft_putstr(str);
}