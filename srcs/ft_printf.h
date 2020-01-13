/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 13:37:41 by tlouekar          #+#    #+#             */
/*   Updated: 2020/01/13 11:12:54 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h> // REMOVE IT YOU DUMBASS

typedef	struct	s_printf
{
	int			i;
	char		*ptr;
}				t_printf;

void			display_c(const char c);
void			display_str(const char *str);
int				ft_printf(const char *format, ...);
int				parse(char *str);
char			*structurize(t_printf *data, char *ptr);
t_printf		*initialize(void);
#endif
