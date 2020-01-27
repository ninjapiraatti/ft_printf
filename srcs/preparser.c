/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 09:43:42 by tlouekar          #+#    #+#             */
/*   Updated: 2020/01/27 09:56:32 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*preparse(char *str, va_list args)
{
	char		*ptr;
	t_printf	*data;
	char		*arg;

	ptr = (char *)str;

	arg = va_arg(args, char *);
	if (*ptr == '\\') // for escaping
	{
		ptr++;
		write(1, (char *)ptr, 1);
		ptr++;
	}
	if (*ptr == '%')
	{
		data = initialize(ptr);
		if (arg == NULL)
		{
			ft_putstr("(null)");
			ptr++;
		}
		else
		{
			ptr = parse(ptr, data, arg);
			output(data, arg, 0);
		}
		//ft_putstr(structurize(initialize(), ptr));
		//ft_putchar((char)*ptr++);
	}
	ptr++;
	return (ptr);
}