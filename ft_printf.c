/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 13:52:13 by galemair          #+#    #+#             */
/*   Updated: 2018/04/25 12:21:14 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int		ft_printf(char *str, ...)
{
	va_list		args;
	int			ret;
	char 		*test;

	ret = 0;
	va_start(args, str);
	//printf("%d\n",va_arg(args, int));
	test = va_arg(args, char*);
	printf("%s\n",test);
	va_end(args);
	return (ret);
}
int	main(int argc, char **argv)
{
	char c = 127;
	//printf("ret = %d\n",ft_printf("Bah ouais Maggle\n"));
	ft_printf(argv[1], argv[2]);
	//setlocale(128, "br");
	//printf("%d", atoi);
//	printf("%ld", atoi(argv[1]));
	//printf("nombre normal : %d barh : %d et brah %hhd", INT_MAX, INT_MAX + 1, 2147483650);
	return (0);
}
