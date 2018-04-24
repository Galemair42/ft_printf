/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percentage_parsing.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 17:14:21 by galemair          #+#    #+#             */
/*   Updated: 2018/04/23 15:43:42 by galemair         ###   ########.fr       */
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

void	get_signed_expected_types(char *modifiers, t_parse *parsing_datas, va_list args)
{
	//(parsing_datas->value).sign = 1;
	
}
void	get_unsigned_expected_types(char *modifiers, t_parse *parsing_datas, va_list args)
{
	if (modifiers[0] == 'h' && modifiers[1] == 'h')
	{
		if (ft_char_in_str("sS", parsing_datas->converter))
		{
				((parsing_datas->value).unsigned_identifier).i_str = va_arg(args, unsigned char*)
				(parsing_datas->value).type = USTR;
		}
		else
		{
				((parsing_datas->value).unsigned_identifier).i_str = va_arg(args, char)
				(parsing_datas->value).type = UCHAR;
		}
	}
}
char	*ft_percentage_parsing(char *str, t_buffer *buff, va_list args)
{
	t_parse		parsing_datas;
	char		modifiers[3];

	ft_bzero(modifiers, (sizeof(char) * 4));
	ft_bzero(&parsing_datas, sizeof(t_parse));
	while (*str)
	{
		if (ft_char_in_str(FLAGS, *str))
			ft_update_struct(*str, &parsing_datas);
		else if (ft_char_in_str(MODIFIERS, *str) && !(modifiers[0]))
			ft_get_modifiers(&str, modifiers);
		else if (ft_char_in_str(CONVERTERS, *str))
		{
			parsing_datas.converter = *str;
			if (ft_char_in_str(UNSIGNED_CONV, *str))
				get_unsigned_expected_types(modifiers, &parsing_datas, args);
			else
				get_signed_expected_types(modifiers, &parsing_datas, args);
			break;
		}
		str++;
	}
	ft_print(parsing_datas);
	return (str + 1);
}
