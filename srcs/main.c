/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 12:35:17 by tlouekar          #+#    #+#             */
/*   Updated: 2020/01/20 13:40:36 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	ft_printf("This is displayed as is. Moving on to difficult stuff:\n");
	ft_printf("Character: %c\n\nString: %s\n\nInt: %d", 'X', "Hello world.", 12345);
	//printf("\n\n");
	//printf("Hello %5d\n", 1);
}