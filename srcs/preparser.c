/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 09:43:42 by tlouekar          #+#    #+#             */
/*   Updated: 2020/01/20 13:42:55 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*preparse(char *str, va_list args)
{
	char		*ptr;
	t_printf	*data;

	ptr = (char *)str;

	while (*ptr != 0)
	{
		if (*ptr == '\\') // for escaping
		{
			ptr++;
			write(1, (char *)ptr, 1);
			ptr++;
		}
		if (*ptr == '%')
		{
			data = initialize(ptr);
			ptr = parse(ptr, data);
			//ft_putstr(structurize(initialize(), ptr));
			//ft_putchar((char)*ptr++);
			output(data, args);
		}
		ptr++;
	}
	return (ptr);
}