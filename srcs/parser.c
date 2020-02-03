/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 09:43:42 by tlouekar          #+#    #+#             */
/*   Updated: 2020/02/03 11:45:20 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		inject_int(char *str, t_printf *data, int *flag)
{
	int		i;

	i = 0;
	*flag = ft_atoi((char *)str);
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
	{
		data->dot = 1;
		str++;
		return (inject_int(str, data, &(data->prc)) + 1);
	}
	else if(*str == '*')
		data->star = 1;
	else if(*str == '0')
	{
		str--;
		if(ft_isdigit(*(str)) == 0)
			data->zero = 1;
		str++;
	}
	else if(ft_isdigit(*(str)) == 1)
		return (inject_int(str, data, &(data->fieldwidth)));
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
	{
		data->c = 1;
		data->len = 1;
	}
	else if (*str == 'd')
		data->d = 1;
	else if (*str == 'i')
		data->i = 1;
	else if (*str == 'o')
		data->o = 1;
	else if (*str == 's')
		data->s = 1;
	else if (*str == 'x')
		data->x = 1;
	else if (*str == 'p')
		data->p = 1;
	return (str);
}