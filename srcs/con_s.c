/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 13:36:41 by tlouekar          #+#    #+#             */
/*   Updated: 2020/04/11 15:50:38 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			con_s(t_printf *data, va_list args)
{
	char		*str;

	if (data->space == 1)
		ft_putchar(' ');
	if(!(str = va_arg(args, char *)))
		str = ft_strdup("(null)");
	if (data->dot > 0)
		str = ft_strsub(str, 0, data->len);
	data->len = ft_strlen(str);
	if (data->minus == 0)
		helper_print_padding(data);
	ft_putstr(str);
}