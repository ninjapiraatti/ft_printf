/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 09:43:42 by tlouekar          #+#    #+#             */
/*   Updated: 2020/01/20 12:41:39 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Chop will cut the string into the actual part that we want to handle.
int		chop(char *str)
{
	int		i;

	i = 1;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			break ;
		}
		else if (str[i] == '"')
		{
			break ;
		}
		i++;
	}
	return (i);
}

void		flag_to_data(char *str, t_printf *data)
{
			if(*str == '+')
				data->plus = 1;
			else if(*str == '-')
				data->minus = 1;
			else if(*str == '#')
				data->hash = 1;
			else if(*str == ' ')
				data->space = 1;
			else if(*str == '.')
				data->dot = 1;
			else if(*str == '*')
				data->star = 1;
			else if(*str == '0' && (!(ft_isdigit(*str--))))
				data->zero = 1;
}

char		*parse(char *str, t_printf *data)
{
	int		i;
	int		len;

	i = 0;
	len = chop(str);
	str++;
	while (i < len)
	{
		while (ft_strchr(flags, *str) != NULL)
		{
			flag_to_data(str, data);
			str++;
			i++;
		}
		if (*str == 'c')
		{
			data->c = 1;
			return (str);
		}
		else if (*str == 'd')
		{
			data->d = 1;
			return (str);
		}
		else if (*str == 'o')
		{
			data->o = 1;
			return (str);
		}
		else if (*str == 's')
		{
			data->s = 1;
			return (str);
		}
		else if (*str == 'x')
		{
			data->x = 1;
			return (str);
		}
		i++;
		str++;
	}
	return (str);
}