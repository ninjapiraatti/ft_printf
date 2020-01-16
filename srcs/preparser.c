/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 09:43:42 by tlouekar          #+#    #+#             */
/*   Updated: 2020/01/16 14:49:28 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*preparse(char *str, va_list *args)
{
	char		*ptr;
	t_printf	*data;

	ptr = (char *)str;

	while (*ptr != 0)
	{
		if (*ptr == 92) // for escaping
		{
			ptr++;
			write(1, (char *)ptr, 1);
			ptr++;
		}
		if (*ptr == '%')
		{
			data = initialize(ptr);
			parse(ptr, data);
			//ft_putstr(structurize(initialize(), ptr));
			//ft_putchar((char)*ptr++);
			ft_putnbr(data->c);
			ft_putnbr(data->d);
			ft_putnbr(data->o);
			ft_putnbr(data->s);
			ft_putnbr(data->x);
			ft_putchar(va_arg(*args, int));
		}
		ptr++;
	}
	return (ptr);
}