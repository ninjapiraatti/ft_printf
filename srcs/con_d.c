/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 13:36:41 by tlouekar          #+#    #+#             */
/*   Updated: 2020/07/07 15:58:15 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void			con_d(t_printf *data, va_list args)
{
	char		*str;

	if (data->starlen == 1)
		data->fieldwidth = va_arg(args, uintmax_t);
		if (data->fieldwidth < 0)
			data->fieldwidth *= -1;
	if (data->starprc == 1)
	{
		data->prc = va_arg(args, uintmax_t);
		if (data->prc < 0)
			;
		else
			data->len = data->prc;
	}
	handle_length(data, args);
	str = helper_itoa_base(data->val, 10, data);
	data->len = ft_strlen(str);
	if (data->minus == 0)
		helper_print_padding(data);
	helper_plusminus(data);
	helper_spaces(data);
	helper_prc_zeros(data);
	if (!(data->dot == 1 && data->val == 0 && data->prc == 0))
	{
		ft_putstr(str);
		data->cc += ft_strlen(str);
	}
	free(str);
}
