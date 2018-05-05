# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: galemair <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/05 14:48:14 by galemair          #+#    #+#              #
#    Updated: 2018/05/05 17:38:33 by galemair         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


RM			=	rm -rf

NAME		=	ft_printf

SRCS		=	srcs/ft_percentage_parsing.c			\
				srcs/manage_converter.c					\
				srcs/ft_printf.c						\
				srcs/utils.c							\
				srcs/convert_manager/manage_char.c		\
				srcs/convert_manager/manage_int.c		\
				srcs/convert_manager/manage_pct.c		\
				srcs/convert_manager/manage_ptr.c		\
				srcs/convert_manager/manage_string.c	\
				libft/libft.a

OBJS		=	$(SRCS:.c=.o) 

INCLUDES	=	includes/

#COLORS

ROUGE		= \033[31m
VERT		= \033[32m
JAUNE		= \033[33m
BLEU		= \033[34m

$(NAME): $(OBJS)	
	@gcc -o	$(NAME) $(OBJS) -I $(INCLUDES) 
	@echo "$(JAUNE)♨"

all:		$(NAME)

print:
	@echo "$(JAUNE)♨"

clean:
	@(RM) $(NAME)
	@echo "$(ROUGE)♲"

fclean: clean
	@$(RM) $(NAME)

.PHONY: all clean fclean re
