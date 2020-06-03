/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 13:36:41 by tlouekar          #+#    #+#             */
/*   Updated: 2020/06/03 20:53:29 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			con_c(t_printf *data, va_list args)
{
	char		c;
	data->len = 1;
	if (data->space == 1)
		ft_putchar(' ');
	if(!(c = va_arg(args, char)))
	{
		if (c == 0)
			ft_putchar('\0');
		data->len = 0;
	}
	else
	{
		data->len = 1;
		if (data->minus == 0)
			helper_print_padding(data);
		ft_putchar(c);
	}
}