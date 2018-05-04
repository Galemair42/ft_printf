/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 13:52:13 by galemair          #+#    #+#             */
/*   Updated: 2018/05/04 18:08:10 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
#include <locale.h>
int	main(int argc, char **argv)
{
	char c = 127;
	ft_printf("%d", 123);
	//setlocale(128, "br");
	//printf("%d", atoi);
//	printf("%ld", atoi(argv[1]));
	//printf("nombre normal : %d barh : %d et brah %hhd", INT_MAX, INT_MAX + 1, 2147483650);
	return (0);
}
