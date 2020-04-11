/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 13:37:41 by tlouekar          #+#    #+#             */
/*   Updated: 2020/04/11 17:34:51 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h> // REMOVE IT YOU DUMBASS

static char			flags[19] = "0123456789#-+hlL.* ";

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
	long double	flo;
	int			c;
	int			d;
	int			i;
	int			o;
	int			u;
	int			s;
	int			x;
	int			X;
	int			p;
	int			f;
	int			lo;
	int			lod;
	char		*ptr;
}				t_printf;

int				output(t_printf *data, va_list args, int debug);
void			con_c(t_printf *data, va_list args);
void			con_d(t_printf *data, va_list args);
void			con_o(t_printf *data, va_list args);
void			con_u(t_printf *data, va_list args);
void			con_s(t_printf *data, va_list args);
void			con_x(t_printf *data, va_list args);
void			con_p(t_printf *data, va_list args);
void			con_f(t_printf *data, va_list args);
int				ft_printf(const char *format, ...);
char			*parse(char *str, t_printf *data);
char			*preparse(char *str, va_list args);
char			*structurize(t_printf *data, char *ptr);
t_printf		*initialize(char *ptr);
char			*helper_itoa_base(long long value, int base, t_printf *data);
char			*ftoa(long double value, t_printf *data);
void			helper_print_padding(t_printf *data);
void			helper_prc_zeros(t_printf *data);
#endif
