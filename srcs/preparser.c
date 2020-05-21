/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 09:43:42 by tlouekar          #+#    #+#             */
/*   Updated: 2020/05/21 13:57:56 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*preparse(char *str, va_list args)
{
	char		*ptr;
	t_printf	*data;
	char		*arg;

	ptr = (char *)str;
	if (*ptr == '\\') // for escaping
	{
		ptr++;
		write(1, (char *)ptr, 1);
		ptr++;
	}
	if (*(ptr + 1) == '%')
	{
		ft_putchar('%');
		ptr += 2;
		return (ptr);
	}
	data = initialize(ptr);
	ptr = parse(ptr, data);
	if (ptr != NULL)
	{
		output(data, args, 0);
		ptr++;
	}
	return (ptr);
}