/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 13:36:41 by tlouekar          #+#    #+#             */
/*   Updated: 2020/07/07 10:44:11 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			con_x(t_printf *data, va_list args)
{
	char		*str;

	if (data->star == 1)
		data->fieldwidth = va_arg(args, int);
	handle_length_unsigned(data, args);
	str = helper_itoa_base(data->val, 16, data);
	data->len = ft_strlen(str);
	if (data->val == 0 && data->prc == 0 && data->dot == 1)
		data->len = 0;
	if (data->minus == 0)
		helper_print_padding(data);
	if (data->hash == 1 && data->val != 0)
	{
		data->bx == 1 ? ft_putstr("0X") : ft_putstr("0x");
		data->cc += 2;
	}
	helper_prc_zeros(data);
	if (!(data->val == 0 && data->prc == 0 && data->dot == 1))
	{
		ft_putstr(str);
		data->cc += ft_strlen(str);
	}
	free(str);
}
