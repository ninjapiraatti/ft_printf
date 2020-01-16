/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 12:35:19 by tlouekar          #+#    #+#             */
/*   Updated: 2020/01/16 10:34:36 by tlouekar         ###   ########.fr       */
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
	traverse = (char *)format;
	while (traverse[i] != '\0')
	{
		if (*traverse == '%' || *traverse == 92)
		{
			traverse = parse((char *)format, args);
		}
		else
		{
			ft_putchar((char)*traverse);
			traverse++;
		}
	}
	va_end(args);
	return (0);
}
