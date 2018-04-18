/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percentage_parsing.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 17:14:21 by galemair          #+#    #+#             */
/*   Updated: 2018/04/18 17:52:29 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_update_struct(char c, t_parse *parsing_datas)
{
	if (c == '#')
		parsing_datas->hashtag = 1;
	else if (c == '0')
		parsing_datas->zero = 1;
	else if (c == '+')
		parsing_datas->plus = 1;
	else if (c == '-')
		parsing_datas->minus = 1;
	else if (c == ' ')
		parsing_datas->space = 1;
}
void	ft_percentage_parsing(char *str, t_buffer *buff, va_list args)
{
	t_parse parsing_datas;

	ft_bzero(&parsing_datas, sizeof(t_parse));
	while (*str)
	{
		if (ft_char_in_str(FLAGS, *str))
			ft_update_struct(*str, &parsing_datas);
	//	if (ft_char_in_str(CONVERTERS, *str))
	}
}
