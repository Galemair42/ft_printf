/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 13:49:14 by galemair          #+#    #+#             */
/*   Updated: 2018/05/09 19:06:06 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>


# define BUFF_SIZE			100
# define CONVERTERS			"SspdDioOuUxXcC%"
# define SIGNED_CONV		"dDicC"	
# define UNSIGNED_CONV		"oOuXxpSs"
# define FLAGS				"#0+- "
/*
 * IMPORTANT ! Put 2 letters modifiers first 
 */
# define MODIFIERS			"hh ll h l j z"

typedef	enum				e_types
{
	none, ll, hh, h, l, j, z
}							t_types;

typedef struct				s_parse	
{
	unsigned int			hashtag;
	unsigned int			zero;
	unsigned int			minus;
	unsigned int			plus;
	unsigned int			space;
	unsigned int			sign;
	char					converter;
	int						width;
	int						precision;
	t_types					identifier;
}							t_parse;

typedef	struct				s_buffer
{
	char					buff[BUFF_SIZE];
	int						i;
	int						empty;
}							t_buffer;

/*
 * -------------------------ft_printf.c--------------------------------------------------
 */
int							ft_printf(char *str, ...);
int							ft_control_center(char *str, va_list args);
/*
 * -------------------------ft_percentage_parsing.c---------------------------------------
 */
char						*ft_percentage_parsing(char *str, t_buffer *buff, va_list args);
void						ft_update_struct(char c, t_parse *parsing_datas);
void						ft_get_modifiers(char **str, t_parse *parsing_datas);
void						ft_get_modifiers2(char *modifiers, t_parse *parsing_datas);
/*
 * --------------------------ft_utils.c---------------------------------------------------
 */
void						ft_clean_buff(t_buffer *buff);
int							ft_atoi_custom(char **str);
/*
 *---------------------------debug.c-------------------------------------------------------
 */
void						ft_print(t_parse cool);
/*
 *---------------------------ft_manage_conv.c----------------------------------------------
 */
void						ft_manage_conv(t_parse datas, t_buffer *buff, va_list args);
/*
 *---------------------------manage_flag.c-------------------------------------------------
 */
void						manage_flags(int size, t_parse *datas, char signe);
#endif
