/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 09:43:42 by tlouekar          #+#    #+#             */
/*   Updated: 2020/06/08 12:22:52 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*preparse(char *str, va_list args)
{
	t_printf	*data;

	if (*str == '\\') // for escaping
	{
		str++;
		write(1, (char *)str, 1);
		str++;
	}
	if (*(str + 1) == '%')
	{
		ft_putchar('%');
		str += 2;
		return (str);
	}
	data = initialize(str);
	str = parse(str + 1, data);
	if (str != NULL)
	{
		output(data, args, 0);
		str++;
	}
	free(data);
	return (str);
}