/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achavez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 15:02:06 by achavez           #+#    #+#             */
/*   Updated: 2019/03/13 19:16:42 by achavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"

int main()
{
	char 	*str = "Hello";
	char 	*col = "Blakkk";
	char	c = 'F';
	unsigned int	u = 42949672;
	int		num = 042;
	float flo = 1233;


	ft_printf("My .11x[%hx]\nMy s[%s]\n\n", num, str);

	printf("printf #xll[%hx]\nprintf .3s[%.3s]\n", num, str);
	return 0;
}
