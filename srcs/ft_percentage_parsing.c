/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percentage_parsing.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 17:14:21 by galemair          #+#    #+#             */
/*   Updated: 2018/05/05 17:08:07 by galemair         ###   ########.fr       */
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

void	ft_get_modifiers2(char *modifiers, t_parse *parsing_datas)
{
	if (modifiers[0] == 'h' && modifiers[1] == 'h')
		parsing_datas->identifier = hh;
	else if (modifiers[0] == 'l' && modifiers[1] == 'l')
		parsing_datas->identifier = ll;
	else if (modifiers[0] == 'h')
		parsing_datas->identifier = h;
	else if (modifiers[0] == 'l')
		parsing_datas->identifier = l;
	else if (modifiers[0] == 'j')
		parsing_datas->identifier = j;
	else if (modifiers[0] == 'z')
		parsing_datas->identifier = z;
}

void	ft_get_modifiers(char **str, t_parse *parsing_datas)
{
	char	modifiers[3];
	char	*flags;
	size_t	index;

	index = 0;
	flags = MODIFIERS;
	while (**str != *flags)
		flags++;
	while (*flags != ' ' && **str == *flags)
	{
		modifiers[index] = **str;
		flags++;
		index++;
		(*str)++;
	}
	modifiers[index] = '\0';
	ft_get_modifiers2(modifiers, parsing_datas);
}

char	*ft_percentage_parsing(char *str, t_buffer *buff, va_list args)
{
	t_parse		parsing_datas;
	short int	flag_modifier;

	flag_modifier = 0;
	ft_bzero(&parsing_datas, sizeof(t_parse));
	while (*str)
	{
		if (ft_isdigit(*str))
			parsing_datas.precision = ft_atoi_custom(&str);
		else if (*str == '.')
		{
			str++;
			parsing_datas.width = ft_atoi_custom(&str);
		}
		else if (ft_char_in_str(FLAGS, *str))
			ft_update_struct(*str, &parsing_datas);
		else if (ft_char_in_str(MODIFIERS, *str) && flag_modifier == 0)
		{
			ft_get_modifiers(&str, &parsing_datas);
			flag_modifier = 1;
		}
		else if (ft_char_in_str(CONVERTERS, *str))
		{
			parsing_datas.converter = *str;
			break;
		}
		str++;
	}
//	ft_print(parsing_datas);
	ft_manage_conv(parsing_datas, buff, args);
	return (str);
}
