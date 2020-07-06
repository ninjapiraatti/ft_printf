/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_o.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 13:36:41 by tlouekar          #+#    #+#             */
/*   Updated: 2020/07/06 15:18:38 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			con_o(t_printf *data, va_list args)
{
	char		*str;

	if (data->star == 1)
		data->fieldwidth = va_arg(args, int);
	handle_length_unsigned(data, args);
	str = helper_itoa_base((unsigned long long)data->val, 8, data);
	data->len = ft_strlen(str);
	if (data->hash == 1 && data->val != 0)
		data->len++;
	if (data->minus == 0)
		helper_print_padding(data);
	helper_prc_zeros(data);
	if (!(data->dot == 1 && data->val == 0
	&& data->prc == 0 && data->hash == 0))
	{
		ft_putstr(str);
		data->cc += ft_strlen(str);
	}
	free(str);
}
