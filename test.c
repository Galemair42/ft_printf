/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:44:04 by galemair          #+#    #+#             */
/*   Updated: 2018/05/11 19:38:26 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <limits.h>
#include <ctype.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

typedef union		u_perso
{
	char 			i_char;
	int	 			i_int;
	long long int	l_int;
	unsigned int	sa;
}					u_perso;
typedef enum		e_cool
{
	ll, hh, l, h
}					t_cool;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	n = (unsigned int)n;
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
}

int		main(void)
{
	unsigned char c;

	c = 0xe1;
	write(1, &c, 1);
	c = 0x88;
	write(1, &c, 1);
	c = 0xb4;
	write(1, &c, 1);
	c = 0x0a;
	write(1, &c, 1);
	printf("%d\n", sizeof(wchar_t));
	return (0);
}
