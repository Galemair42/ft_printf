/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 13:49:14 by galemair          #+#    #+#             */
/*   Updated: 2018/04/18 18:01:14 by galemair         ###   ########.fr       */
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
# define CONVERTERS			"SpdDioOuUxXcC"
# define FLAGS				"#0+- "
# define MODIFIERS			"hh h l ll j z"

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

typedef struct				s_parse	
{
	unsigned int			hashtag;
	unsigned int			zero;
	unsigned int			minus;
	unsigned int			plus;
	unsigned int			space;
	unsigned int			sign;
	int						width;
	int						precision;
	t_unsigned_identifier	unsigned_identifier;	
	t_signed_identifier		signed_identifier;	
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
void						ft_percentage_parsing(char *str, t_buffer *buff, va_list args);
void						ft_update_struct(char c, t_parse *parsing_datas);
/*
 * --------------------------ft_utils.c---------------------------------------------------
 */
void						ft_clean_buff(t_buffer *buff);

#endif
