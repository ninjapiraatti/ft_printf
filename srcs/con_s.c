/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 13:36:41 by tlouekar          #+#    #+#             */
/*   Updated: 2020/01/27 15:48:27 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*con_s(t_printf *data, va_list args)
{
	char		*str;

	if(!(str = va_arg(args, char *)))
		str = ft_strdup("(null)");
	if (data->dot > 0)
		str = ft_strsub(str, 0, data->len);
	else
		data->len = ft_strlen(str);
	return (str);
}