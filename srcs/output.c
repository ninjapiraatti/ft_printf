/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:21:01 by tlouekar          #+#    #+#             */
/*   Updated: 2020/02/03 12:03:39 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_con_spec(t_printf *data, va_list args)
{
	if (data->c == 1)
		con_c(data, args);
	if (data->d == 1 || data->i == 1)
		con_d(data, args);
	if (data->s == 1)
		ft_putstr(con_s(data, args));
	if (data->p == 1)
		con_p(data, args);
}

int			output(t_printf *data, va_list args, int debug)
{
	if (debug == 1)
	{
		ft_putstr("\n---\nDebug data:\n");
		ft_putstr("c:");
		ft_putnbr(data->c);
		ft_putstr("  d:");
		ft_putnbr(data->d);
		ft_putstr("  i:");
		ft_putnbr(data->i);
		ft_putstr("  o:");
		ft_putnbr(data->o);
		ft_putstr("  s:");
		ft_putnbr(data->s);
		ft_putstr("  x:");
		ft_putnbr(data->x);
		ft_putstr("  p:");
		ft_putnbr(data->p);
		ft_putstr("\n");
		ft_putstr("zero:");
		ft_putnbr(data->zero);
		ft_putstr("  plus:");
		ft_putnbr(data->plus);
		ft_putstr("  minus:");
		ft_putnbr(data->minus);
		ft_putstr("  space:");
		ft_putnbr(data->space);
		ft_putstr("  hash:");
		ft_putnbr(data->hash);
		ft_putstr("  dot:");
		ft_putnbr(data->dot);
		ft_putstr("  precision:");
		ft_putnbr(data->prc);
		ft_putstr("  star:");
		ft_putnbr(data->star);
		ft_putstr("  fieldwidth:");
		ft_putnbr(data->fieldwidth);
		ft_putstr("  len:");
		ft_putnbr(data->len);
		ft_putstr("\n---\n");
	}
	if (data->dot > 0)
		data->len = data->prc;
	print_con_spec(data, args);
	if (data->minus == 1)
		helper_print_padding(data);
	return (0);
}