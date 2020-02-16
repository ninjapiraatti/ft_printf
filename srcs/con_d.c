/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 13:36:41 by tlouekar          #+#    #+#             */
/*   Updated: 2020/02/16 12:27:53 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			con_d(t_printf *data, va_list args)
{
	char		*str;

	data->lli = (long long)va_arg(args, int);
	str = helper_itoa_base(data->lli, 10, data);
	data->len = ft_strlen(str);
	if (data->minus == 0)
		helper_print_padding(data);
	helper_plusminus(data);
	helper_zeros_spaces(data);
	helper_handle_precision(data);
	ft_putstr(str);
}