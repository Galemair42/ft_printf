/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 11:23:50 by galemair          #+#    #+#             */
/*   Updated: 2018/05/09 19:01:19 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	manage_flags(int size, t_parse *datas, char signe)
{
	printf("signe = %c\n", signe);
	datas->precision -= size;
	datas->precision = datas->precision >= 0 ? datas->precision : 0;
	if ((datas->plus == 1 && signe == '+') || signe == '-' || datas->space == 1)
		size++;
	datas->width -= (datas->precision + size);
}
