/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:21:01 by tlouekar          #+#    #+#             */
/*   Updated: 2020/01/27 13:23:08 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_padding(t_printf *data)
{
	int		i;

	i = 0;
	if (data->dot > 0)
		i = data->fieldwidth - data->dot;
	else
		i = data->fieldwidth - data->len;
	while (i > 0)
	{
		if (data->zero == 1 && data->minus == 0)
			ft_putchar('0');
		else
			ft_putchar(' ');
		i--;
	}
}

void		print_con_spec(t_printf *data, va_list args)
{
	char	*str;
	if (data->c == 1 || data->d == 1)
		con_c(data, args);
	if (data->d == 1)
		con_d(data, args);
	if (data->s == 1)
		ft_putstr(con_s(data, args));
	if (data->p == 1)
	{
		con_p(data, args);
		//ft_putstr(ft_itoa_base((unsigned long long)arg, 16));
	}
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
	if (data->plus == 1)
	{
		ft_putchar('+');
	}
	if (data->minus == 0)
		print_padding(data);
	if (data->space == 1)
	{
		ft_putchar(' ');
	}
	print_con_spec(data, args);
	if (data->minus == 1)
		print_padding(data);
	return (0);
}