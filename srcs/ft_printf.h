/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 13:37:41 by tlouekar          #+#    #+#             */
/*   Updated: 2020/02/10 13:09:03 by tlouekar         ###   ########.fr       */
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
	int			prc;
	int			star;
	int			fieldwidth;
	int			len;
	long long	lli;
	int			c;
	int			d;
	int			i;
	int			o;
	int			s;
	int			x;
	int			p;
	char		*ptr;
}				t_printf;

int				output(t_printf *data, va_list args, int debug);
void			con_c(t_printf *data, va_list args);
void			con_d(t_printf *data, va_list args);
void			con_o(t_printf *data, va_list args);
char			*con_s(t_printf *data, va_list args);
void			con_x(t_printf *data, va_list args);
void			con_p(t_printf *data, va_list args);
int				ft_printf(const char *format, ...);
char			*parse(char *str, t_printf *data);
char			*preparse(char *str, va_list args);
char			*structurize(t_printf *data, char *ptr);
t_printf		*initialize(char *ptr);
char			*helper_itoa_base(long value, int base, t_printf *data);
void			helper_print_padding(t_printf *data);
void			helper_handle_precision(t_printf *data);
#endif
