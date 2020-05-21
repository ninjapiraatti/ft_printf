/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 12:35:19 by tlouekar          #+#    #+#             */
/*   Updated: 2020/05/21 13:54:21 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	va_list	args;
	char	*traverse;

	va_start(args, format);
	traverse = (char *)format;
	while (*traverse != '\0')
	{
		if (*traverse == '%')
		{
			if (*(traverse + 1) == '%')
			{
				ft_putchar('%');
				traverse += 2;
			}
			else
				traverse = preparse(traverse, args);
		}
		else
		{
			ft_putchar((char)*traverse);
			traverse++;
		}
		if (traverse == NULL)
			return (0);
	}
	va_end(args);
	return (0);
}
