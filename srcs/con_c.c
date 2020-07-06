/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 13:36:41 by tlouekar          #+#    #+#             */
/*   Updated: 2020/07/06 09:15:37 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			con_c(t_printf *data, va_list args)
{
	char		c;

	data->len = 1;
	if (data->spc == 1)
	{
		ft_putchar(' ');
		data->cc++;
	}
	if (data->minus == 0)
		helper_print_padding(data);
	if (!(c = va_arg(args, int)))
	{
		if (c == 0)
		{
			ft_putchar('\0');
			data->cc++;
		}
	}
	else
	{
		data->len = 1;
		ft_putchar(c);
		data->cc++;
	}
}
