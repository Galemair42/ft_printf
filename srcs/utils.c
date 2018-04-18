/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 17:07:51 by galemair          #+#    #+#             */
/*   Updated: 2018/04/18 17:51:10 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_clean_buff(t_buffer *buff)
{
	write(1, buff->buff, (buff->i));
	ft_bzero(buff->buff, BUFF_SIZE);
	buff->i = 0;
	(buff->empty)++;
}
