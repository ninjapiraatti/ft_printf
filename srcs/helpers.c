/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 13:37:41 by tlouekar          #+#    #+#             */
/*   Updated: 2020/05/02 14:52:46 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Too many trailing:
//First line of code: {return test("% -8.5i", 34);}

// Too few trailing:
//First line of code: {return test("% -8.3d", -8473);}

// Too few in front:
//First line of code: {return test("%-5.i", 0);}
//First line of code: {return test("%+5.0i", 0);}
//First line of code: {return test("%5.0i", 0);}

void		helper_print_padding(t_printf *data)
{
	int		i;

	i = 0;
	i = data->fieldwidth - data->len;
	if ((data->o != 1 && data->x != 1 && data->X != 1 && data->u != 1) && 
	((data->plus == 1) || 
	(data->lli < 0 && data->dot == 1) ||
	(data->lli < 0 && data->fieldwidth > 0) ||
	(data->flo < 0 && data->dot == 1) ||
	(data->minus == 1 && data->flo < 0)))
		i--;
	if ((data->i == 1 || data->d == 1) && (data->prc == 0 && data->dot == 1 && data->lli == 0 && data->len == 1))
		i++;
	if ((data->prc > data->len) && data->s != 1)
		i -= data->prc - data->len;
	if (data->minus == 0 && data->fieldwidth > 0 && data->zero == 1 && data->dot == 0 && data->loose == 0)
		i = 0;
	if (data->minus == 0 && data->fieldwidth > 0 && data->zero == 1 && (data->f == 1 || data->lo == 1))
		i = 0;
	if ((data->x == 1 || data->X == 1) && data->hash == 1 && data->lli != 0)
		i -= 2;
	while (i > 0)
	{
		ft_putchar(' ');
		i--;
	}
}

void		helper_spaces(t_printf *data)
{
	if (data->space == 1)
	{
		if (data->plus == 1 && data->minus == 1)
			;
		else if (data->minus == 1 && data->fieldwidth == 0 && data->lli < 0)
			data->len += 1;
		else if (data->minus == 1 && (data->lli >= 0 && data->flo >= 0))
		{
			data->len += 1;
			ft_putchar(' ');
		}
		else if (data->plus == 1 || data->lli < 0 || data->fieldwidth > data->len || data->flo < 0)
			;
		else if (data->minus == 1)
			data->len += 1;
		else if ((data->fieldwidth == 0 && data->flo >= 0) ||
		(data->fieldwidth > 0 && data->dot == 0) ||
		(data->dot == 1 && (data->lli == 0 || data->prc > 0)))
			ft_putchar(' ');
	}
}

void		helper_plusminus(t_printf *data)
{
	if (data->plus == 1 && data->lli >= 0 && data->flo >= 0 && data->o != 1) 
		ft_putchar('+');
	if (data->lli < 0 || data->flo < 0)
		ft_putchar('-');
}

/*
Precision helper is probably fucked
First line of code: {return test("%#3.3o", 6983);}
*/
void		helper_prc_zeros(t_printf *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (data->hash == 1 && data->o == 1)
	{
		if ((data->prc == 0 && data->lli != 0) ||
		(data->len >= data->prc)) 
			i++;
	}
	if (data->prc > data->len)
	{
		i = data->prc - data->len;
		data->len += i;
		if (data->space == 1 && data->minus == 1 && data->lli > 0)
			i++;
	}
	else if ((data->dot == 0 || data->lo == 1 || data->f == 1) && data->zero == 1 && data->minus == 0)
	{
		i = data->fieldwidth - data->len;
		if (data->lli < 0 || data->plus == 1 || data->flo < 0)
			i--;
	}
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