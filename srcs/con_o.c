/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_o.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 13:36:41 by tlouekar          #+#    #+#             */
/*   Updated: 2020/03/06 14:49:46 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			con_o(t_printf *data, va_list args)
{
	char					*str;

	/*
	if (data->star == 0)
		pointer = (unsigned long long)va_arg(args, void *);
	else {
		data->fieldwidth = va_arg(args, int);
		pointer = (unsigned long long)va_arg(args, void *);
	}
	*/
	if (data->star == 1)
			data->fieldwidth = va_arg(args, int);
	data->lli = (unsigned int)va_arg(args, int);
	str = helper_itoa_base((unsigned long long)data->lli, 8, data);
	data->len = ft_strlen(str);
	if (data->minus == 0)
		helper_print_padding(data);
	helper_plusminus(data);
	helper_prc_zeros(data);
	ft_putstr(str);
}