/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:44:04 by galemair          #+#    #+#             */
/*   Updated: 2018/04/24 12:28:41 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

typedef union		u_perso
{
	char 			i_char;
	int	 			i_int;
	long long int	l_int;
}					u_perso;

int	main(int argc, char **argv)
{
	u_perso val;
	int c;
	char d = 'A';

	val.i_char = d;
	c = val.i_int; 
	printf("int = %d\n", c);
	return (0);
}
