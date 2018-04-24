/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 14:12:00 by galemair          #+#    #+#             */
/*   Updated: 2018/04/24 12:19:50 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print(t_parse cool)
{
	printf("hashtag :%ud", cool.hashtag);
	printf("zero :%ud", cool.zero);
	printf("minus :%ud", cool.minus);
	printf("plus :%ud", cool.plus);
	printf("space :%ud", cool.space);
	printf("sign :%ud", cool.sign);
	printf("converter :%us", cool.converter);
	printf("precision :%d", cool.precision);
	printf("width :%d", cool.width);
}
