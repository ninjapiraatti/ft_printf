/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 12:35:17 by tlouekar          #+#    #+#             */
/*   Updated: 2020/01/22 12:55:00 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	//ft_printf("This is displayed as is. Moving on to difficult stuff:\n");
	//ft_printf("Double percentage: %% - and stuff after it.");
	//ft_printf("Character: %c\n\nString: %s\n\nInt: %d", 'X', "Hello world.", 12345);
	ft_printf("Character: %% %#120c and another %*c", 'X', 'B');
	//printf("\n\n");
	//printf("Hello %5d\n", 1);
}