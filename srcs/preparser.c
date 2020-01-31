/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 09:43:42 by tlouekar          #+#    #+#             */
/*   Updated: 2020/01/31 12:34:34 by tlouekar         ###   ########.fr       */
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
	if (*ptr == '%')
	{
		data = initialize(ptr);
		/* Put this elsewhere
		if (arg == NULL)
		{
			ft_putstr("(null)");
			ptr++;
		}
		*/
		ptr = parse(ptr, data);
		output(data, args, 0);
		//ft_putstr(structurize(initialize(), ptr));
		//ft_putchar((char)*ptr++);
	}
	ptr++;
	return (ptr);
}