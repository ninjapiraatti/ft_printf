/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 12:35:19 by tlouekar          #+#    #+#             */
/*   Updated: 2020/01/20 13:41:53 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	char	*traverse;

	i = 0;
	va_start(args, format);
	traverse = (char *)format;
	while (traverse[i] != '\0')
	{
		if (*traverse == '%' || *traverse == '\\') // Move the \\ to preparser?
		{
			if (*traverse + 1 == '%')
			{
				traverse++;
				write(1, (char *)traverse, 1);
				break ;
			}
			traverse = preparse((char *)format, args);
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
