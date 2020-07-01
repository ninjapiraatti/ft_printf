/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 13:36:41 by tlouekar          #+#    #+#             */
/*   Updated: 2020/07/01 12:33:18 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			con_s(t_printf *data, va_list args)
{
	char		*str;
	char		*tmp;

	if (data->spc == 1)
	{
		ft_putchar(' ');
		data->cc++;
	}
	if (!(str = va_arg(args, char *)))
	{
		if (data->dot == 0)
			tmp = ft_strdup("(null)");
		else
			tmp = ft_strsub("(null)", 0, data->len);
	}
	else
	{
		if (data->dot == 0)
			tmp = ft_strdup(str);
		else
			tmp = ft_strsub(str, 0, data->len);
	}
	data->len = ft_strlen(tmp);
	if (data->minus == 0)
		helper_print_padding(data);
	ft_putstr(tmp);
	data->cc += ft_strlen(tmp);
	free(tmp);
}
