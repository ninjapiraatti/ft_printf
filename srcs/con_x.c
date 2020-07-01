/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 13:36:41 by tlouekar          #+#    #+#             */
/*   Updated: 2020/07/01 15:04:09 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			con_x(t_printf *data, va_list args)
{
	char		*str;

	if (data->star == 1)
		data->fieldwidth = va_arg(args, int);
	data->lli = (unsigned long)va_arg(args, unsigned long);
	str = helper_itoa_base(data->lli, 16, data);
	data->len = ft_strlen(str);
	if (data->lli == 0 && data->prc == 0 && data->dot == 1)
		data->len = 0;
	if (data->minus == 0)
		helper_print_padding(data);
	if (data->hash == 1 && data->lli != 0)
	{
		if (data->bx == 1)
			ft_putstr("0X");
		else
			ft_putstr("0x");
		data->cc += 2;
	}
	helper_prc_zeros(data);
	if (!(data->lli == 0 && data->prc == 0 && data->dot == 1))
		ft_putstr(str);
	data->cc += ft_strlen(str);
	free(str);
}
