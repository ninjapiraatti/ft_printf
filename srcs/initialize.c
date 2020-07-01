/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 11:07:43 by tlouekar          #+#    #+#             */
/*   Updated: 2020/07/01 13:38:10 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

t_printf		*initialize_more(char *ptr, t_printf *data)
{
	data->lo = 0;
	data->lod = 0;
	data->zero = 0;
	data->pl = 0;
	data->minus = 0;
	data->spc = 0;
	data->hash = 0;
	data->dot = 0;
	data->prc = 0;
	data->star = 0;
	data->fieldwidth = 0;
	data->len = 0;
	data->lli = 0;
	data->flo = 0;
	data->ptr = ptr;
	data->loose = 0;
	data->cc = 0;
	return (data);
}

t_printf		*initialize(char *ptr)
{
	t_printf	*data;

	if (!(data = (t_printf *)malloc(sizeof(t_printf))))
	{
		ft_printf("Failed to allocate Data.");
		return (NULL);
	}
	data->c = 0;
	data->d = 0;
	data->i = 0;
	data->o = 0;
	data->u = 0;
	data->s = 0;
	data->x = 0;
	data->bx = 0;
	data->p = 0;
	data->f = 0;
	return (initialize_more(ptr, data));
}
