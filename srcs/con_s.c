/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 13:36:41 by tlouekar          #+#    #+#             */
/*   Updated: 2020/01/27 13:12:56 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*con_s(t_printf *data, va_list args)
{
	char		*str;

	str = va_arg(args, char *);
	if (data->dot > 0)
		str = ft_strsub(str, 0, data->len);
	return (str);
}