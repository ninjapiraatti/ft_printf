/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_u.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 13:36:41 by tlouekar          #+#    #+#             */
/*   Updated: 2020/04/10 11:41:50 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			con_u(t_printf *data, va_list args)
{
	char		*str;

	if (data->star == 1)
		data->fieldwidth = va_arg(args, int);
	data->lli = (long long)va_arg(args, int);
	str = helper_itoa_base(data->lli, 10, data);
	data->len = ft_strlen(str);
	if (data->minus == 0)
		helper_print_padding(data);
	helper_zeros_spaces(data);
	helper_prc_zeros(data);
	ft_putstr(str);
}