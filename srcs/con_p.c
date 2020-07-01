/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 13:36:41 by tlouekar          #+#    #+#             */
/*   Updated: 2020/07/01 09:46:20 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			con_p(t_printf *data, va_list args)
{
	unsigned long long		*pointer;
	char					*str;

	if (data->star == 0)
		pointer = (unsigned long long)va_arg(args, void *);
	else
	{
		data->fieldwidth = va_arg(args, int);
		pointer = (unsigned long long)va_arg(args, void *);
	}
	str = helper_itoa_base((unsigned long long)pointer, 16, data);
	data->len = ft_strlen(str) + 2;
	if (data->minus == 0)
		helper_print_padding(data);
	ft_putstr("0x");
	ft_putstr(str);
	free(str);
}
