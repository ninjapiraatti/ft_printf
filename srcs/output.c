/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:21:01 by tlouekar          #+#    #+#             */
/*   Updated: 2020/01/20 16:53:22 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		output(t_printf *data, va_list args)
{
	ft_putstr("\n---\nDebug data:\n");
	ft_putstr("c:");
	ft_putnbr(data->c);
	ft_putstr("  d:");
	ft_putnbr(data->d);
	ft_putstr("  o:");
	ft_putnbr(data->o);
	ft_putstr("  s:");
	ft_putnbr(data->s);
	ft_putstr("  x:");
	ft_putnbr(data->x);
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
	ft_putstr("  star:");
	ft_putnbr(data->star);
	ft_putstr("\n---\n");
	if (data->space == 1)
	{
		ft_putchar(' ');
	}
	if (data->plus == 1)
	{
		ft_putchar('+');
	}
	if (data->c == 1 || data->d == 1)
		ft_putchar(va_arg(args, int));
	if (data->d == 1)
		ft_putnbr(va_arg(args, int));
	if (data->s == 1)
		ft_putstr(va_arg(args, char *));
	return (0);
}