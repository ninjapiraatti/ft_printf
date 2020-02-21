/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 08:33:06 by tlouekar          #+#    #+#             */
/*   Updated: 2020/02/21 13:34:39 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

char		*ftoa(long double value, t_printf *data)
{
	int			i;
	int			j;
	int			is;
	long double	ds;
	int			len;
	char		*str;

	j = 0;
	if (value < 0)
		value *= -1.0;
	is = (int)value;
	ds = value - (long double)is;
	len += ft_strlen(ft_itoa(is)) + data->prc + 2;
	if (!(str = malloc(sizeof(char) * len)))
		return (NULL);
	ft_strcpy(str, ft_itoa(is));
	i = ft_strlen(str);
	str[i] = '.';
	i++;
	while (i < len)
	{
		ds *= 10;
		str[i] = (long long)ds + '0';
		ds -= (long long)ds;
		i++;
	}
	str[i] = '\0';
	return (str);
}
