/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 13:52:13 by galemair          #+#    #+#             */
/*   Updated: 2018/05/11 20:43:16 by galemair         ###   ########.fr       */
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
int	main(int argc, char **argv)
{
	char c = 127;
	int myret;
	int ret;
	myret = ft_printf("Salut a tous %#X comment ccccccc1a va \n%-+12.43O mais bon\n", 21, 1234);
	ret = printf("Salut a tous %#X comment ccccccc1a va \n%-+12.43O mais bon\n", 21, 1234);
	//ret = printf("|%hc|\n", c);
	printf("my ret    = %d\ntheir ret = %d\n", myret, ret);
	//printf("\n TEST PRINTF |%d|", 123);
	return (0);
}
