/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 17:07:51 by galemair          #+#    #+#             */
/*   Updated: 2018/04/19 14:29:53 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char 	*ft_get_modifiers(char **str, char *converter)
{
	char	*flags;
	size_t	index;

	index = 0;
	flags = MODIFIERS;
	while (**str != *flags)
		flags++;
	while (*flags != ' ' && **str == *flags) 
	{
		converter[index] = **str;
		flags++;
		index++;
		(*str)++;
	}
	return (converter);
}

void	ft_clean_buff(t_buffer *buff)
{
	write(1, buff->buff, (buff->i));
	ft_bzero(buff->buff, BUFF_SIZE);
	buff->i = 0;
	(buff->empty)++;
}
