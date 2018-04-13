/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 13:52:13 by galemair          #+#    #+#             */
/*   Updated: 2018/04/09 13:46:53 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *str, ...)
{
	va_list		args;

	va_start(args, str);
	printf("%s\n", va_arg(args, char *));
	printf("%d\n", va_arg(args, int));
	return (0);
}

int	main(int argc, char **argv)
{
//	ft_printf(argv[1], argv[2], atoi(argv[3]));
	printf("%+.6d", atoi(argv[1]));
	return (0);
}
