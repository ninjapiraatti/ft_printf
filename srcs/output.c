/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:21:01 by tlouekar          #+#    #+#             */
/*   Updated: 2020/01/23 14:13:17 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_padding(int fw, int zero, int len, int minus)
{
	fw = fw - len;
	while (fw > 0)
	{
		if (zero == 1 && minus == 0)
			ft_putchar('0');
		else
			ft_putchar(' ');
		fw--;
	}
}

int			output(t_printf *data, char *arg, int debug)
{
	if (debug == 1)
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
		ft_putstr("  fieldwidth:");
		ft_putnbr(data->fieldwidth);
		ft_putstr("  len:");
		ft_putnbr(data->len);
		ft_putstr("\n---\n");
	}
	if (data->dot)
		// Do perecision here
	if (data->plus == 1)
	{
		ft_putchar('+');
	}
	if (data->minus == 0)
		print_padding(data->fieldwidth, data->zero, data->len, data->minus);
	if (data->space == 1)
	{
		ft_putchar(' ');
	}
	if (data->c == 1 || data->d == 1)
		ft_putchar(&arg[0]);
	if (data->d == 1)
		ft_putchar('D');
	if (data->s == 1)
		ft_putstr(arg);
	if (data->minus == 1)
		print_padding(data->fieldwidth, data->zero, data->len, data->minus);
	return (0);
}