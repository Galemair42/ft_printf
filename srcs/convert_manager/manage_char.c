/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 16:53:33 by galemair          #+#    #+#             */
/*   Updated: 2018/05/11 20:41:50 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_cvalue(t_parse *datas, va_list args, wchar_t *value)
{
	if (datas->identifier == l || datas->converter == 'C')
		*value = (wchar_t)va_arg(args, long int);	
	else
		*value = (char)va_arg(args, int);
}
void	manage_char(t_parse *datas, t_buffer *buff, va_list args)
{
	wchar_t value;	

	get_cvalue(datas, args, &value);
}
