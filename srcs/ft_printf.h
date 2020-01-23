/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 13:37:41 by tlouekar          #+#    #+#             */
/*   Updated: 2020/01/23 13:47:55 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h> // REMOVE IT YOU DUMBASS

static char			flags[19] = "0123456789#-+hl.* ";

typedef	struct	s_printf
{
	int			zero;
	int			plus;
	int			minus;
	int			space;
	int			hash;
	int			dot;
	int			star;
	int			fieldwidth;
	int			len;
	int			c;
	int			d;
	int			o;
	int			s;
	int			x;
	char		*ptr;
}				t_printf;

int				output(t_printf *data, char *arg, int debug);
void			display_c(const char c);
void			display_str(const char *str);
int				ft_printf(const char *format, ...);
char			*parse(char *str, t_printf *data, char *arg);
char			*preparse(char *str, va_list args);
char			*structurize(t_printf *data, char *ptr);
t_printf		*initialize(char *ptr);
#endif
