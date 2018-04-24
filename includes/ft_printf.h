/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 13:49:14 by galemair          #+#    #+#             */
/*   Updated: 2018/04/24 13:36:43 by galemair         ###   ########.fr       */
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


# define ON 				1
# define OFF 				0
# define BUFF_SIZE			100
# define CONVERTERS			"SspdDioOuUxXcC"
# define SIGNED_CONV		"dDicC"	
# define UNSIGNED_CONV		"oOuXxpSs"
# define FLAGS				"#0+- "
/*
 * IMPORTANT ! Mettre modifiers composes de deux lettres avant
 */
# define MODIFIERS			"hh ll h l j z"

typedef	enum				e_types
{
	CHAR, INT, SHORT_INT, LONG_INT, LONG_LONG_INT,
	STR, PTR, UCHAR, UINT, USHORT_INT, ULONG_INT,
	ULONG_LONG_INT, USTR
}							t_types;
typedef	union				u_signed_identifier
{
	char					i_char;
	int						i_int;
	short int				i_short_int;
	long int				i_long_int;
	long long int			i_longlong_int;
	char					*i_str;
	void					*i_ptr;
}							t_signed_identifier;

typedef	union				u_unsigned_identifier
{
	unsigned char			i_char;
	unsigned int			i_int;
	unsigned short int		i_short_int;
	unsigned long int		i_long_int;
	unsigned long long int	i_longlong_int;
	unsigned char			*i_str;
}							t_unsigned_identifier;

typedef	struct				s_value
{
	t_types					type;
	t_unsigned_identifier	unsigned_identifier;	
	t_signed_identifier		signed_identifier;

}							t_value;

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
	t_value					value;
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
void						ft_get_expected_types(char *modifiers, t_parse *parsing_datas);
/*
 * --------------------------ft_utils.c---------------------------------------------------
 */
void						ft_clean_buff(t_buffer *buff);
char						*ft_get_modifiers(char **str, char *converter);
/*
 *---------------------------debug.c-------------------------------------------------------
 */
void						ft_print(t_parse cool);
#endif
