# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thoraffr <thoraffr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/08/26 14:19:42 by thoraffr          #+#    #+#              #
#    Updated: 2015/06/27 16:19:38 by ksicart          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	clang++

CFLAGS		=	-g -Wall -Wextra -Werror -I./includes

SFMLINC		=	-I ~/.brew/Cellar/sfml/2.3/include

SFMLFLAGS	=	-L ~/.brew/Cellar/sfml/2.3/lib -lsfml-graphics -lsfml-window -lsfml-system

NAME		=	ft_gkrellm

SRCD		=	srcs

OBJD		=	objs

SRCS		=	main.cpp \
				CPUModule.cpp \
				InfoModule.cpp \
				RAMModule.cpp \
				NetworkModule.cpp

SRC			:=	$(addprefix $(SRCD)/, $(SRCS))

OBJS		=	$(SRCS:.cpp=.o)

OBJ			:=	$(addprefix $(OBJD)/, $(OBJS))

CLR0		=	\033[0m
CLR1		=	\033[32m
CLR2		=	\033[1;34m
CLR3		=	\033[31m
CLR4		=	\033[1;34m
CLR5		=	\033[1;30m
CLR6		=	\033[33m

all:		$(NAME)

$(NAME):	$(OBJ)
			@echo "$(CLR5)$(NAME) »$(CLR1) Création du binaire..."
			@$(CC) $(CFLAGS) $(SFMLFLAGS) -lcurses -lncurses -o $@ $(OBJ)

$(OBJ):		$(SRC)
			@echo "$(CLR5)$(NAME) »$(CLR6) Création des fichiers objets..."
			@$(CC) $(CFLAGS) $(SFMLINC) -c $(SRC)
			@mkdir -p $(OBJD)
			@mv $(OBJS) $(OBJD)

clean:
			@rm -rf $(OBJD)
			@echo "$(CLR5)$(NAME) »$(CLR6) Suppression des fichiers objets..."

fclean:		clean
			@rm -f $(NAME)
			@echo "$(CLR5)$(NAME) »$(CLR3) Suppression du binaire ($(NAME))..."

re:			fclean all

.PHONY: all clean fclean re
