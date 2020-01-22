/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 09:43:42 by tlouekar          #+#    #+#             */
/*   Updated: 2020/01/22 13:02:11 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		enterpadding(char *str, t_printf *data)
{
	int		i;

	i = 0;
	data->fieldwidth = ft_atoi((char *)str);
	while(ft_isdigit(*(str)) == 1)
	{
		str++;
		i++;
	}
	return (i);
}

int			flag_to_data(char *str, t_printf *data)
{
	int 	i;

	i = 0;
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
	else if(*str == '0')
	{
		str--;
		if(ft_isdigit(*(str)) == 0)
			data->zero = 1;
		str++;
	}
	if(ft_isdigit(*(str)) == 1)
		return (enterpadding(str, data));
	return (1);
}

char		*parse(char *str, t_printf *data)
{
	int		i;

	i = 0;
	str++;
	while (ft_strchr(flags, *str) != NULL)
	{
		str += flag_to_data(str, data);
	}
	if (*str == 'c')
		data->c = 1;
	else if (*str == 'd')
		data->d = 1;
	else if (*str == 'o')
		data->o = 1;
	else if (*str == 's')
		data->s = 1;
	else if (*str == 'x')
		data->x = 1;
	return (str);
}