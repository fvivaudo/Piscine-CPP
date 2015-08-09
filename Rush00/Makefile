# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbarbisa <cbarbisa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 17:49:54 by cbarbisa          #+#    #+#              #
#    Updated: 2015/06/21 13:06:48 by cbarbisa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_retro

SRC = main.cpp \
	  Boss.cpp \
	  Foreground.cpp \
	  Background.cpp \
	  Ship.cpp \
	  Enemy.cpp \
	  Shoot.cpp \
	  Bonus.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	g++ -o $@ $^ -L$(HOME)/.brew/Cellar/ncurses/5.9/lib -lncurses

%.o: %.cpp
	g++ -o $@ -c $^  -Wall -Werror -Wextra -I$(HOME)/.brew/Cellar/ncurses/5.9/include

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
