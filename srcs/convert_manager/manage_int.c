/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 16:52:23 by galemair          #+#    #+#             */
/*   Updated: 2018/05/09 18:32:35 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	ft_putnbra(intmax_t n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
		ft_putnbra(n / 10);
	ft_putchar((n % 10) + '0');
}

void	get_value(t_parse *datas, va_list args, intmax_t *value)
{
	if (datas->identifier == hh)
		*value = (char)va_arg(args, int);
	else if (datas->identifier == ll)
		*value = (long long int)va_arg(args, long long int);
	else if (datas->identifier == h)
		*value = (short int)va_arg(args, int);
	else if (datas->identifier == l || datas->converter == 'D')
		*value = (long int)va_arg(args, long int);
	else if (datas->identifier == j)
		*value = va_arg(args, intmax_t);
	else if (datas->identifier == z)
		*value = (size_t)va_arg(args, size_t);
	else
		*value = (int)va_arg(args, int);
}

int			calc_intsize(intmax_t value, int base)
{
	int size;

	value = (intmax_t)value;
	size = 0;
	if (value <= 0)
		value *= -1;
	while (value >= 1)
	{
		size++;
		value /= base;
	}
	return (size);
}
void		manage_int(t_parse *datas, t_buffer *buff, va_list args)
{
	intmax_t 	value; 
	int			size;

	ft_putstr("hello bienvenue dans la gestion de int \n\n");
	get_value(datas, args, &value);
	size = calc_intsize(value, 10);
	ft_print(*datas);
	printf("\n");
	manage_flags(size, datas, value >= 0 ? '+' : '-');
	ft_print(*datas);
}
//int	main(int args, char **argv)
//{
//	intmax_t test;
//	
//	test = (int)test;
//	test = 214748364883;
//	printf("%d\n", calc_intsize(test, atoi(argv[2])));
//	return (0);
//}
