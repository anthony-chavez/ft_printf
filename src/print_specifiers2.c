/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_specifiers2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achavez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 19:11:56 by achavez           #+#    #+#             */
/*   Updated: 2019/04/22 20:49:24 by achavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_p(t_data *p)
{
	int		x;
	char	*str;

	x = va_arg(p->arg, int);
	str = ft_itoa_base(x, 16);
	p->str = ft_strjoin("0x10", str);
	ft_strlower(p->str);
	if (p->width > 11 && p->flags[3] == '-')
	{
		ft_putstr(p->str);
		while (p->width-- > 11)
			ft_putchar(' ');
	}
	else
	{
		while (p->width-- > 11)
			p->flags[0] != '0' ? ft_putchar(' ') : ft_putchar('0');
		ft_putstr(p->str);
	}
}

void	print_c(t_data *p)
{
	int		c;

	c = va_arg(p->arg, int);
	if (p->width > 1 && p->flags[3] == '-')
	{
		ft_putchar(c);
		while (p->width-- > 1)
			ft_putchar(' ');
	}
	else
	{
		while (p->width-- > 1)
			p->flags[0] != '0' ? ft_putchar(' ') : ft_putchar('0');
		ft_putchar(c);
	}
}

void	print_u(t_data *p)
{
	unsigned int 	u;
//	int 			digits;

	u = va_arg(p->arg, unsigned int);
//	digits = ft_getdigits((int)u);
//	while(--p->width > digits)
//		ft_putchar(' ');
	ft_putnbr_u(u);
}