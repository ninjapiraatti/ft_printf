/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 13:36:41 by tlouekar          #+#    #+#             */
/*   Updated: 2020/06/08 12:35:28 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			con_x(t_printf *data, va_list args)
{
	char		*str;
	int			prefix;

	if (data->star == 1)
		data->fieldwidth = va_arg(args, int);
	data->lli = (unsigned long)va_arg(args, unsigned long);
	str = helper_itoa_base(data->lli, 16, data);
	data->len = ft_strlen(str);
	/*
	ft_putstr("\n---\nDebug data:\n");
	ft_putstr("  minus:\n");
	ft_putnbr(data->minus);
	ft_putstr("  len:\n");
	ft_putnbr(data->len);
	ft_putstr("\n---\n");
	*/
	if (data->lli == 0 && data->prc == 0 && data->dot == 1)
		data->len = 0;
	if (data->minus == 0)
		helper_print_padding(data);
	if (data->hash == 1 && data->lli != 0) {
		if (data->X == 1)
			ft_putstr("0X");
		else
			ft_putstr("0x");
	}
	helper_prc_zeros(data);
	if (!(data->lli == 0 && data->prc == 0 && data->dot == 1))
		ft_putstr(str);
	free(str);
}