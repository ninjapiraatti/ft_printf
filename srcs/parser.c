/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 09:43:42 by tlouekar          #+#    #+#             */
/*   Updated: 2020/01/13 11:12:11 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse(char *str)
{
	char	*ptr;

	ptr = (char *)str;

	while (*ptr != 0)
	{
		if (*ptr == 92)
		{
			ptr++;
			write(1, (char *)ptr, 1);
			ptr++;
		}
		if (*ptr == 37)
		{
			ft_putstr(structurize(initialize(), ptr));
			// write(1, (char *)ptr, 1);
		}
		write(1, (char *)ptr, 1);
		ptr++;
	}
	write(1, (char *)ptr, 1);
	return (0);
}