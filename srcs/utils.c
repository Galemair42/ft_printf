/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 17:07:51 by galemair          #+#    #+#             */
/*   Updated: 2018/05/15 20:51:59 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi_custom(char **str, int precision_flag)
{
	int		sign;
	int		nb;

	if (precision_flag == 1)
		(*str)++;
	nb = 0;
	sign = 1;
	while (**str == '\t' || **str == '\n' || **str == '\r' ||
			**str == '\v' || **str == '\f' || **str == ' ')
		(*str)++;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	while (**str >= '0' && **str <= '9')
	{
		nb = 10 * nb + (**str - 48);
		(*str)++;
	}
	(*str)--;
	return (nb * sign);
}

char	get_rank(int n, int maj)
{
	char *minu;
	char *maju;

	minu = MINUSCULES;
	maju = MAJUSCULES;
	if (maj == 1)
		return (maju[n]);
	return (minu[n]);
}

int		ft_strlenbytes(wchar_t *str)
{
	int size;

	size = 0;
	while (*str)
	{
		size += get_char_size(*str);
		str++;
	}
	return (size);
}

int		get_char_size(wchar_t c)
{
	if (c <= 127)
		return (1);
	else if (c <= 2047)
		return (2);
	else if (c <= 65535)
		return (3);
	else
		return (4);
}
