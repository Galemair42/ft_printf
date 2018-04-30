/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 20:33:53 by exam              #+#    #+#             */
/*   Updated: 2018/04/25 14:47:59 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			get_size(long value, int base, int flag)
{
	int i;

	i = 0;
	if (value == 0)
		return (1);
	if (base == 10 && flag == 1)
		i = 1;
	while (value > 0)
	{
		value = value / base;
		i++;
	}
	return (i);
}

char		get_char(long value)
{
	if (value >= 0 && value <= 9)
		return (value + 48);
	if (value >= 10 && value <= 15)
		return (value + 55);
	return ('G');
}

char		*fill_tab(long a, char *nbr, int size, int base)
{
	nbr[size] = '\0';
	size--;
	if (a == 0)
		nbr[size] = '0';
	while (a > 0)
	{
		nbr[size] = get_char(a % base);
		a /= base;
		size--;
	}
	return (nbr);
}

char		*ft_itoa_base(int value, int base)
{
	char	*nbr;
	int		size;
	int		flag;
	long	a;

	a = value;
	flag = 0;
	if (a < 0)
	{
		flag++;
		a *= -1;
	}
	size = get_size(a, base, flag);
	nbr = malloc(sizeof(char) * size);
	nbr = fill_tab(a, nbr, size, base);
	if (flag == 1 && base == 10)
		nbr[0] = '-';
	return (nbr);
}
