/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 11:29:48 by galemair          #+#    #+#             */
/*   Updated: 2018/04/09 12:16:55 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int raturn;

	raturn = 0;
	raturn = printf("salut et %.5d\n", atoi(argv[1]));
	printf("%d\n", raturn);
	return (0);
}
