/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:44:04 by galemair          #+#    #+#             */
/*   Updated: 2018/05/12 18:08:18 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <limits.h>
#include <ctype.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>

//int		count_bits(unsigned int c)
//{
//	return (0);
//}
//int		main(void)
//{
//	wchar_t c= 945;
//
//	printf("%s\n", setlocale(LC_ALL, ""));
//	printf("ret = %d\n", printf("%C\n", c));
//	return (0);
//}
/**
0xxxxxxx
110xxxxx 10xxxxxx
1110xxxx 10xxxxxx 10xxxxxx
11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
**/
 
//1110 110001
void	ft_putchar(char c)
{
	write (1, &c, 1);
}
void	ft_uputnbr_buff(uintmax_t value, int base)
{
	if (value >= base)
		ft_uputnbr_buff(value / base, base);
	ft_putchar(value % base + '0');
}

int main(int argc, char **argv)
{
        setlocale(LC_ALL, "en_US.UTF-8");
 
        wchar_t value = atoi(argv[1]);
        unsigned int mask0 = 0;
        unsigned int mask1 = 49280;
        unsigned int mask2= 14712960;
        unsigned int mask3= 4034953344;
 
		ft_uputnbr_buff(value, 2);
		ft_putchar('\n');
        unsigned int v = value;
        int size = 10;
        int res = 0;
        //printf("size %d\n", size);
        unsigned char octet;
 
        if (size <= 7)
        {
                octet = value;
                write(1, &octet, 1);
        }
        else  if (size <= 11)
        {
                unsigned char o2 = (v << 26) >> 26; // recuperation des 6 premiers bits 110xxxxx 10(xxxxxx)
                unsigned char o1 = ((v >> 6) << 27) >> 27; // recuperation des 5 derniers bits 110(xxxxx) 10xxxxxx

                octet = (mask1 >> 8) | o1; // application des bits du premier octet sur le premier octet mask
                write(1, &octet, 1);
                octet = ((mask1 << 24) >> 24) | o2; // application des bits du seond octet sur le second octet du mask
                write(1, &octet, 1);
        }
        else  if (size <= 16)
        {
                unsigned char o3 = (v << 26) >> 26; // recuperation des 6 premiers bits 1110xxxx 10xxxxxx 10(xxxxxx)
                unsigned char o2 = ((v >> 6) << 26) >> 26; // recuperation des 6 seconds bits 1110xxxx 10(xxxxxx) 10xxxxxx
                unsigned char o1 = ((v >> 12) << 28) >> 28; // recuperation des 4 derniers bits 1110(xxxx) 10xxxxxx 10xxxxxx
       
                octet = (mask2 >> 16) | o1; // application des bits du premier octet sur le premier octet mask
                write(1, &octet, 1);
                octet = ((mask2 << 16) >> 24) | o2; // application des bits du seond octet sur le second octet du mask
                write(1, &octet, 1);
                octet = ((mask2 << 24) >> 24) | o3; // application des bits du troisieme octet sur le troisieme octet du mask
                write(1, &octet, 1);
        }
        else
        {
                unsigned char o4 = (v << 26) >> 26; // recuperation des 6 premiers bits 11110xxx 10xxxxxx 10xxxxxx 10(xxxxxx)
                unsigned char o3 = ((v >> 6) << 26) >> 26; // recuperation des 6 seconds bits 11110xxx 10xxxxxx 10(xxxxxx) 10xxxxxx
                unsigned char o2 = ((v >> 12) << 26) >> 26;  // recuperation des 6 seconds bits 11110xxx 10(xxxxxx) 10xxxxxx 10xxxxxx
                unsigned char o1 = ((v >> 18) << 29) >> 29; // recuperation des 3 seconds bits 11110(xxx) 10xxxxxx 10xxxxxx 10xxxxxx
       
                octet = (mask3 >> 24) | o1; // application des bits du premier octet sur le premier octet mask
                write(1, &octet, 1);
                octet = ((mask3 << 8) >> 24) | o2; // application des bits du seond octet sur le second octet du mask
                write(1, &octet, 1);
                octet = ((mask3 << 16) >> 24) | o3; // application des bits du troisieme octet sur le troisieme octet du mask
                write(1, &octet, 1);
                octet = ((mask3 << 24) >> 24) | o4; // application des bits du quatrieme octet sur le quatrieme octet du mask
                write(1, &octet, 1);
        }
		write(1, "\n", 1);
        return (0);
}
