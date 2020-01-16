/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 09:43:42 by tlouekar          #+#    #+#             */
/*   Updated: 2020/01/16 10:38:38 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*preparse(char *str, va_list *args)
{
	char	*ptr;

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
			ft_putstr(structurize(initialize(), ptr));

			// write(1, (char *)ptr, 1);
		}
		write(1, (char *)ptr, 1);
		ptr++;
	}
	write(1, (char *)ptr, 1);
	return (ptr);
}