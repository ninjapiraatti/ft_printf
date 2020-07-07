/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 13:36:41 by tlouekar          #+#    #+#             */
/*   Updated: 2020/07/07 14:26:54 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			con_p(t_printf *data, va_list args)
{
	unsigned long long		pointer;
	char					*str;

	if (data->starlen == 1)
		data->fieldwidth = va_arg(args, int);
	else if (data->starprc == 1)
		data->prc = va_arg(args, int);
	pointer = va_arg(args, unsigned long long);
	str = helper_itoa_base((unsigned long long)pointer, 16, data);
	data->len = ft_strlen(str) + 2;
	if (data->minus == 0)
		helper_print_padding(data);
	ft_putstr("0x");
	ft_putstr(str);
	data->cc += ft_strlen(str) + 2;
	free(str);
}
