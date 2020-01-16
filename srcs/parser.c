/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 09:43:42 by tlouekar          #+#    #+#             */
/*   Updated: 2020/01/16 14:50:33 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*parse(char *str, t_printf *data)
{
	str++;
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