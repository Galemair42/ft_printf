# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: galemair <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/05 14:48:14 by galemair          #+#    #+#              #
#    Updated: 2018/05/11 17:04:03 by galemair         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


RM			=	rm -rf

NAME		=	libftprintf.a

LIBFT		=	libft/

SRCS		=	srcs/ft_percentage_parsing.c				\
				srcs/manage_converter.c						\
				srcs/ft_printf.c							\
				srcs/utils.c								\
				srcs/manage_buffer.c						\
				srcs/manage_unicode.c				\
				srcs/debug.c								\
				srcs/manage_flag.c							\
				srcs/convert_manager/manage_char.c			\
				srcs/convert_manager/manage_int.c			\
				srcs/convert_manager/manage_pct.c			\
				srcs/convert_manager/manage_ptr.c			\
				srcs/convert_manager/manage_string.c		\
				srcs/convert_manager/manage_unsignedint.c	\

LIB_OBJS	=	Libft/ft_bzero.o		\
			Libft/ft_char_in_str.o		\
			Libft/ft_memset.o		\
			Libft/ft_isdigit.o		\
			Libft/ft_strlen.o

OBJS		=	$(SRCS:.c=.o) 

INCLUDES	=	includes/

#COLORS

ROUGE		= \033[31m
VERT		= \033[32m
JAUNE		= \033[33m
BLEU		= \033[34m

$(NAME): lib $(OBJS)
	@ar rc 	$(NAME) $(OBJS) $(LIB_OBJS)
	@echo "\nFT_PRINTF COMPILED"

all:		$(NAME)

x:			$(NAME)
	@./$(NAME)
lib:
	@make -C libft/

%.o : %.c
	@printf "✅ "
	@gcc -o $@ -c $< -I $(INCLUDES)

clean:
	@make clean -C libft/
	@$(RM) $(OBJS)
	@echo "♻️ "

fclean: clean
	@make fclean -C libft/
	@$(RM) $(NAME)
re:	fclean all


.PHONY: clean fclean re
