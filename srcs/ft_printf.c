/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 12:35:19 by tlouekar          #+#    #+#             */
/*   Updated: 2020/01/16 09:50:36 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	char	*traverse;
	char	c;

	i = 0;
	va_start(args, format);
	//vprintf(format, args);
	traverse = (char *)format;
	while (*traverse != '%')
	{
		ft_putstr(traverse);
		//parse((char *)format);
		c = va_arg(args, int);
		ft_putchar((char)*traverse);
		traverse++;
	}
	va_end(args);
	return (0);
}
