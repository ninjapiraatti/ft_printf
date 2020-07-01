/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:21:01 by tlouekar          #+#    #+#             */
/*   Updated: 2020/07/01 10:43:21 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		con_loose(t_printf *data, va_list args)
{
	data->fieldwidth--;
	if (data->minus == 0 && data->zero == 0)
		helper_print_padding(data);
	helper_plusminus(data);
	helper_spaces(data);
	helper_prc_zeros(data);
	ft_putchar('%');
}

void		print_con_spec(t_printf *data, va_list args)
{
	if (data->c == 1)
		con_c(data, args);
	else if (data->d == 1 || data->i == 1)
		con_d(data, args);
	else if (data->s == 1)
		con_s(data, args);
	else if (data->p == 1)
		con_p(data, args);
	else if (data->o == 1)
		con_o(data, args);
	else if (data->u == 1)
		con_u(data, args);
	else if (data->x == 1 || data->bx == 1)
		con_x(data, args);
	else if (data->f == 1)
		con_f(data, args);
	else if (data->loose == 1)
		con_loose(data, args);
}

int			output(t_printf *data, va_list args, int debug)
{
	if (data->dot > 0)
		data->len = data->prc;
	print_con_spec(data, args);
	if (data->minus == 1)
		helper_print_padding(data);
	if (debug == 1)
	{
		ft_putstr("\n---\nDebug data:\n");
		ft_putstr("  prc:");
		ft_putnbr(data->prc);
		ft_putstr("\n---\n");
	}
	return (0);
}
