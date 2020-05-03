/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_o.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 13:36:41 by tlouekar          #+#    #+#             */
/*   Updated: 2020/05/03 13:13:34 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			con_o(t_printf *data, va_list args)
{
	char					*str;

	if (data->star == 1)
		data->fieldwidth = va_arg(args, int);
	data->lli = (long long)va_arg(args, long long);
	str = helper_itoa_base((unsigned long long)data->lli, 8, data);
	data->len = ft_strlen(str);
	if (data->minus == 0)
		helper_print_padding(data);
	helper_plusminus(data);
	helper_prc_zeros(data);
	if (!(data->dot == 1 && data->lli == 0 && data->prc == 0))
		ft_putstr(str);
}