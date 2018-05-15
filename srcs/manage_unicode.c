#include "unicode.h"
#include "ft_printf.h"

void	octets2_unicode(unsigned int value, t_buffer *buff)
{
	unsigned char o1;
	unsigned char o2;
	unsigned char octet;

	o1 = ((value >> 6) << 27) >> 27; // recuperation des 5 derniers bits 110(xxxxx) 10xxxxxx
	o2 = (value << 26) >> 26; // recuperation des 6 premiers bits 110xxxxx 10(xxxxxx)
        octet = (mask.m1>> 8) | o1; // application des bits du premier octet sur le premier octet mask
        ft_putnchar_buff(buff, octet, 1);
        octet = ((mask.m1<< 24) >> 24) | o2; // application des bits du seond octet sur le second octet du mask
        ft_putnchar_buff(buff, octet, 1);

}

void	octets3_unicode(unsigned int value, t_buffer *buff)
{
	unsigned char o1;
        unsigned char o2;
        unsigned char o3;
	unsigned char octet;
       
	o1 = ((value >> 12) << 28) >> 28;      
	o2 = ((value >> 6) << 26) >> 26;
	o3 = (value << 26) >> 26;
	octet = (mask.m2 >> 16) | o1; 
	ft_putnchar_buff(buff, octet, 1);
	octet = ((mask.m2<< 16) >> 24) | o2; 
	ft_putnchar_buff(buff, octet, 1);
        octet = ((mask.m2<< 24) >> 24) | o3;
	ft_putnchar_buff(buff, octet, 1);
}

void	octets4_unicode(unsigned int value, t_buffer *buff)
{
	unsigned char o1;
	unsigned char o2;
       	unsigned char o3;
	unsigned char o4;	
	unsigned octet;
	
	o1 = ((value >> 18) << 29) >> 29; // recuperation des 3 seconds bits 11110(xxx) 10xxxxxx 10xxxxxx 10xxxxxx
        o2 = ((value >> 12) << 26) >> 26;  // recuperation des 6 seconds bits 11110xxx 10(xxxxxx) 10xxxxxx 10xxxxxx
	o3 = ((value >> 6) << 26) >> 26; // recuperation des 6 seconds bits 11110xxx 10xxxxxx 10(xxxxxx) 10xxxxxx
	o4 = (value << 26) >> 26; // recuperation des 6 premiers bits 11110xxx 10xxxxxx 10xxxxxx 10(xxxxxx)
       	octet = (mask.m3>> 24) | o1; // application des bits du premier octet sur le premier octet mask
    	ft_putnchar_buff(buff, octet, 1);
 	octet = ((mask.m3<< 8) >> 24) | o2; // application des bits du seond octet sur le second octet du mask
       	ft_putnchar_buff(buff, octet, 1);
      	octet = ((mask.m3<< 16) >> 24) | o3; // application des bits du troisieme octet sur le troisieme octet du mask
	ft_putnchar_buff(buff, octet, 1);
        octet = ((mask.m3<< 24) >> 24) | o4; // application des bits du quatrieme octet sur le quatrieme octet du mask
        ft_putnchar_buff(buff, octet, 1);
}
