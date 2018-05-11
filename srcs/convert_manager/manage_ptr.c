/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 16:56:38 by galemair          #+#    #+#             */
/*   Updated: 2018/05/11 20:21:06 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	manage_ptr(t_parse *datas, t_buffer *buff, va_list args)
{
	uintmax_t value;

	value = (uintmax_t)va_arg(args, void*);
	ft_putstr_buff(buff, "0x");
	ft_uputnbr_buff(value, buff, 16, 0);
}
