/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_specifiers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achavez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:49:35 by achavez           #+#    #+#             */
/*   Updated: 2020/02/23 17:55:54 by achavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_s(t_data *p)
{
	char	*s;

	s = va_arg(p->arg, char *);
	if (s == NULL)
		print_str("(null)", p);
	else
		print_str(s, p);
}

void	print_o(t_data *p)
{
	uintmax_t	num;

	num = oux_length(p);
	num = ft_u_num_to_base((intmax_t)num, 8);
	if (p->flags[3] == '-')
	{
		print_symbols(p, 3, (int)num);
		handle_u_precision_intV2(num, ft_getdigits(num), p);
		if (p->precision != 0 && p->precision != -2)
			ft_putnbr_u(num);
		if (p->width > ft_getdigits(num))
			handle_u_width_intV2(num, ft_getdigits(num), p);
	}
	else
	{
		if (p->width > ft_getdigits(num))
		{
			if (p->flags[0] == '0' && p->precision == -1)
				print_symbols(p, 3, (int)num);
			handle_u_width_intV2(num, ft_getdigits(num), p);
			if (p->flags[0] != '0' || (p->flags[0] == '0' && (p->width > p->precision) && p->precision != -1))
				print_symbols(p, 3, (int)num);
		}
		else
			print_symbols(p, 3, (int)num);
		handle_u_precision_intV2(num, ft_getdigits(num), p);
		if (p->precision != 0 && p->precision != -2)
			ft_putnbr_u(num);
	}
}

void	print_x(t_data *p)
{
	uintmax_t		num;
	char			*str;

	num = oux_length(p);
	str = ft_itoa_base_u(num, 16);
	if (*p->traverse == 'x')
		ft_strlower(str);
	num = ft_u_num_to_base((intmax_t)num, 16);
	if (p->flags[3] == '-')
	{
		print_symbols(p, 3, (int)num);
		handle_u_precision_intV2(num, ft_strlen(str), p);
		if (p->precision != 0 && p->precision != -2)
			ft_putstr(str);
		if (p->width > (int)ft_strlen(str))
			handle_u_width_intV2(num, ft_strlen(str), p);
	}
	else
	{
		if (p->width > (int)ft_strlen(str))
		{
			if (p->flags[0] == '0' && p->precision == -1)
				print_symbols(p, 3, (int)num);
			handle_u_width_intV2(num, ft_strlen(str), p);
			if (p->flags[0] != '0' || (p->flags[0] == '0' && (p->width > p->precision) && p->precision != -1))
				print_symbols(p, 3, (int)num);
		}
		else
			print_symbols(p, 3, (int)num);
		handle_u_precision_intV2(num, ft_strlen(str), p);
		if (p->precision != 0 && p->precision != -2)
			ft_putstr(str);
	}
}

void	print_di(t_data *p)
{
	intmax_t	num;
	int			neg;

	num = di_length(p);
	neg = 0;
	if (num < 0)
	{
		num *= -1;
		neg = 1;
	}
	if (p->flags[3] == '-')
	{
		print_symbols(p, neg, num);
		handle_precision_intV2(num, p);
		if (p->precision != 0 && p->precision != -2)
			ft_putnbr(num);
		if (p->width > ft_getdigits(num))
			handle_width_intV2(neg, num, p);
	}
	else
	{
		if (p->width > ft_getdigits(num))
		{
			if (p->flags[0] == '0' && p->precision == -1)
				print_symbols(p, neg, num);
			handle_width_intV2(neg, num, p);
			if (p->flags[0] != '0' || (p->flags[0] == '0' && (p->width > p->precision) && p->precision != -1))
				print_symbols(p, neg, num);
		}
		else
			print_symbols(p, neg, num);
		handle_precision_intV2(num, p);
		if (p->precision != 0 && p->precision != -2)
			ft_putnbr(num);
	}
}

void	print_f(t_data *p)
{
	long double		f;
	char			*tmp;

	f = f_length(p);
	tmp = ft_putfloat(f, p->precision);
	if (p->width > (int)ft_strlen(tmp))
		tmp = handle_width_int(tmp, p);
	ft_putstr(tmp);
}
