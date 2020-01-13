/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 11:07:43 by tlouekar          #+#    #+#             */
/*   Updated: 2020/01/13 11:15:34 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf		*initialize(void)
{
	t_printf	*data;

	if (!(data = (t_printf *)malloc(sizeof(t_printf))))
		return (NULL);
	data->i = 42;
	data->ptr = NULL;
	
	return(data);
}