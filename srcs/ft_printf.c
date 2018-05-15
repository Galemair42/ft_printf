/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 13:52:13 by galemair          #+#    #+#             */
/*   Updated: 2018/05/12 14:32:29 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>

int		ft_control_center(char *str, va_list args)
{
	t_buffer buff;

	ft_bzero(&buff, sizeof(t_buffer));
	while(*str)
	{
		if (buff.i >= BUFF_SIZE)
			ft_clean_buff(&buff);
		if (*str == '%')
			str = ft_percentage_parsing(str + 1, &buff, args);
		else
		{
			(buff.buff)[buff.i] = *str;
			buff.i++;
		}
		str++;
	}
	write(1, buff.buff, (buff.i));
	return ((buff.empty * BUFF_SIZE) + buff.i);
}

int		ft_printf(char *str, ...)
{
	va_list		args;
	int			ret;

	ret = 0;
	va_start(args, str);
	if (str)
		ret = ft_control_center(str, args);
	va_end(args);
	return (ret);
}
//int	main(int argc, char **argv)
//{
//	setlocale(LC_ALL, "");
//	char c = 127;
//	int myret;
//	int ret;
//	myret = ft_printf("|%.p|\n", 0);
//	ret = printf("|%.p|\n", 0);
////	myret = ft_printf("|%5.d|%5.0d|\n", 0, 0);
////	ret = printf("|%5.d|%5.0d|\n", 0, 0);
//	printf("my ret    = %d\ntheir ret = %d\n", myret, ret);
//	return (0);
//}
