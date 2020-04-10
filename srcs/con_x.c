/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 13:36:41 by tlouekar          #+#    #+#             */
/*   Updated: 2020/04/10 15:32:29 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			con_x(t_printf *data, va_list args)
{
	char		*str;
	int			prefix;

	prefix = 0;
	if (data->hash == 1)
		prefix = 0;
	if (data->star == 1)
		data->fieldwidth = va_arg(args, int);
	data->lli = (unsigned long)va_arg(args, unsigned long);
	str = helper_itoa_base(data->lli, 16, data);
	data->len = ft_strlen(str) + prefix;
	if (data->minus == 0)
		helper_print_padding(data);
	if (data->hash == 1) {
		if (data->X == 1)
			ft_putstr("0X");
		else
			ft_putstr("0x");
	}
	//helper_zeros_spaces(data);
	helper_prc_zeros(data);
	ft_putstr(str);
}