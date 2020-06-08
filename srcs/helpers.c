/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 13:37:41 by tlouekar          #+#    #+#             */
/*   Updated: 2020/06/08 13:30:56 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		helper_print_padding(t_printf *data)
{
	int		i;

	i = 0;
	i = data->fieldwidth - data->len;
	if ((data->x != 1 && data->X != 1 && data->u != 1) && 
	((data->plus == 1) || (data->space == 1) ||
	(data->lli < 0) || (data->flo < 0)))
		i--;
	if ((data->prc > data->len) && data->s != 1)
		i -= data->prc - data->len;
	if (data->minus == 0 && data->fieldwidth > 0 && data->zero == 1 
	&& data->dot == 0 && data->loose == 0)
		i = 0;
	if (data->minus == 0 && data->fieldwidth > 0 && data->zero == 1 
	&& (data->f == 1 || data->lo == 1))
		i = 0;
	if ((data->x == 1 || data->X == 1) && data->hash == 1 && data->lli != 0)
		i -= 2;
	if ((data->prc == 0 && data->lli == 0 && data->dot == 1) && (data->i == 1 
	|| data->d == 1 || data->o == 1))
		i++;
	while (i > 0)
	{
		ft_putchar(' ');
		i--;
	}
}

void		helper_spaces(t_printf *data)
{
	if (data->space == 1 && data->plus == 0 && data->lli >= 0 
	&& data->flo >= 0)
		ft_putchar(' ');
}

void		helper_plusminus(t_printf *data)
{
	if (data->plus == 1 && data->lli >= 0 && data->flo >= 0 
	&& data->o != 1) 
		ft_putchar('+');
	if (data->lli < 0 || data->flo < 0)
		ft_putchar('-');
}

void		helper_prc_zeros(t_printf *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (data->hash == 1 && data->o == 1 && data->lli != 0)
			i++;
	if (data->prc > data->len)
		i = data->prc - data->len;
	else if ((data->dot == 0 || data->lo == 1 || data->f == 1) 
	&& data->zero == 1 && data->minus == 0)
	{
		i = data->fieldwidth - data->len;
		if (data->lli < 0 || data->plus == 1 || data->flo < 0 || data->space == 1)
			i--;
	}
	if ((data->x == 1 || data->X == 1) && data->hash == 1 
	&& data->lli != 0 && data->minus == 0 && data->dot == 0)
		i -= 2;
	while (i > 0)
	{
		ft_putchar('0');
		i--;
	}
}

char		*helper_itoa_base(long long value, int base, t_printf *data)
{
	char		*s;
	long long	n;
	int			i;
	int			caps;

	caps = 10;
	if (data->X == 1)
		caps = 42;
	n = (value < 0) ? -value : value;
	i = 1;
	while ((n /= base) >= 1)
		i++;
	s = (char*)malloc(sizeof(char) * (i + 1));
	s[i] = '\0';
	n = (value < 0) ? -value : value;
	while (i--)
	{
		s[i] = (n % base < 10) ? n % base + '0' : n % base + 'a' - caps;
		n /= base;
	}
	return (s);
}