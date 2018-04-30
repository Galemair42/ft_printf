/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:44:04 by galemair          #+#    #+#             */
/*   Updated: 2018/04/30 17:54:15 by galemair         ###   ########.fr       */
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

void	ft_putnbr(long long int n)
{
	//n = (int)n;
//	if (n == -2147483648)
//		ft_putstr("-2147483648");
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
}

void	my_nbr(u_perso val)
{
	printf("my char : %hhd\n", val.i_char);
}

void	manage_test(char *str, ...)
{
	va_list	args;
	long long cool;
	u_perso val;

	cool = 2147483648;
	va_start(args, str);
	//cool = (char)va_arg(args, int);
	ft_putnbr(cool);
	//my_nbr(val);
	va_end(args);
}
int		main(int argc, char **argv)
{
	//char c = 'A';
	//long long int test = 214748367;
	//manage_test(argv[1], argv[2][0], c, test, argv[3]);
	t_cool	cool;
//	cool = hh;
//	if (cool == ll)
//		printf("success\n");
//	if (cool != ll)
//		printf("failure\n");
	printf("cool %p\n", cool);

	return (0);
}
