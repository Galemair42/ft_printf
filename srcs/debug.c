/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 14:12:00 by galemair          #+#    #+#             */
/*   Updated: 2018/05/04 17:49:41 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print(t_parse cool)
{
	printf("hashtag :%u\n", cool.hashtag);
	printf("zero :%u\n", cool.zero);
	printf("minus :%u\n", cool.minus);
	printf("plus :%u\n", cool.plus);
	printf("space :%u\n", cool.space);
	printf("sign :%u\n", cool.sign);
	printf("converter :%c\n", cool.converter);
	printf("precision :%d\n", cool.precision);
	if (cool.identifier == ll)
			printf("identifier :ll\n");	
	if (cool.identifier == hh)
			printf("identifier :hh\n");
	if (cool.identifier == l)
			printf("identifier :l\n");
	if (cool.identifier == h)
			printf("identifier :h\n");
	if (cool.identifier == j)
			printf("identifier :j\n");
	if (cool.identifier == z)
			printf("identifier :z\n");
	printf("width :%d\n", cool.width);
}
