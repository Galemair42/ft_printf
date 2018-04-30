/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 17:07:51 by galemair          #+#    #+#             */
/*   Updated: 2018/04/30 17:59:08 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi_custom(char **str)
{
	int		sign;
	int		nb;

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
	return (nb * sign);
}

void	ft_clean_buff(t_buffer *buff)
{
	write(1, buff->buff, (buff->i));
	ft_bzero(buff->buff, BUFF_SIZE);
	buff->i = 0;
	(buff->empty)++;
}
