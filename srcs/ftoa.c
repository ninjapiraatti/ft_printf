/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 08:33:06 by tlouekar          #+#    #+#             */
/*   Updated: 2020/02/19 13:09:23 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

char		*ftoa(long double value, t_printf *data)
{
	int			i;
	int			is;
	long double	ds;
	int			len;
	char		*str;

	i = data->prc;
	is = (int)value;
	ds = value - (long double)is;
	while (i > 0)
	{
		ds *= 10;
		i--;
	}
	ds = (long long)ds;
	len += ft_strlen(ft_itoa(is)) + data->prc + 2;
	if (!(str = malloc(sizeof(char) * len)))
		return (NULL);
}
