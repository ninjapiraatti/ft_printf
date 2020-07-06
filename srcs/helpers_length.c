/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_length.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 13:37:41 by tlouekar          #+#    #+#             */
/*   Updated: 2020/07/06 14:54:40 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		handle_length(t_printf *data, va_list args)
{
	if (data->l == 1)
		data->val = (long)va_arg(args, long);
	else if (data->ll == 1)
		data->val = (long long)va_arg(args, long long);
	else if (data->h == 1)
		data->val = (short)va_arg(args, int);
	else if (data->hh == 1)
		data->val = (char)va_arg(args, int);
	else
		data->val = (int)va_arg(args, int);
}

void		handle_length_unsigned(t_printf *data, va_list args)
{
	if (data->l == 1)
		data->val = (unsigned long)va_arg(args, unsigned long);
	else if (data->ll == 1)
		data->val = (unsigned long long)va_arg(args, unsigned long long);
	else if (data->h == 1)
		data->val = (unsigned short)va_arg(args, unsigned int);
	else if (data->hh == 1)
		data->val = (unsigned char)va_arg(args, unsigned int);
	else
		data->val = (unsigned int)va_arg(args, unsigned int);
}

void		helper_length_flags(char *str, t_printf *data)
{
	if (*str == 'L')
		data->lod = 1;
	else if (*str == 'l' && data->ll == 0)
	{
		if (*++str == 'l')
			data->ll = 1;
		else
		{
			str--;
			data->l = 1;
		}
	}
	else if (*str == 'h' && data->hh == 0)
	{
		if (*++str == 'h')
			data->hh = 1;
		else
		{
			str--;
			data->h = 1;
		}
	}
}
