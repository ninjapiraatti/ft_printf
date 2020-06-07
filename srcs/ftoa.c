/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 08:33:06 by tlouekar          #+#    #+#             */
/*   Updated: 2020/06/07 19:38:38 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

long double		addfive(long double value, t_printf *data)
{
	int			i;
	long double	five;

	i = 0;
	five = 0.5;
	while (i < data->prc)
	{
		five /= 10;
		i++;
	}
	return (value + five);
}

char			*roundme(long double ds, int start, char *str, t_printf *data)
{
	int			i;

	i = 0;
	while (i < data->prc)
	{
		ds *= 10;
		str[i + start] = (long long)ds + '0';
		ds -= (long long)ds;
		i++;
	}
	str[i + start] = '\0';
	return (str);
}

char			*ftoa(long double value, t_printf *data)
{
	int			i;
	long		is;
	long double	ds;
	int			len;
	char		*str;
	char		*tmp;

	if (value < 0)
		value *= -1;
	value = addfive(value, data);
	is = (long)value;
	tmp = ft_itoa(is);
	ds = value - (long double)is;
	len += ft_strlen(tmp) + data->prc + 2;
	if (!(str = malloc(sizeof(char) * len + 1)))
		return (NULL);
	str = ft_strcpy(str, tmp);
	if (data->prc > 0 || data->hash == 1)
	{
		i = ft_strlen(str);
		str[i] = '.';
		i++;
		return (roundme(ds, i, str, data));
	}
	free(tmp);
	return (str);
}
