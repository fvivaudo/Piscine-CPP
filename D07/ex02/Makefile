#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/07/16 09:42:25 by fvivaudo          #+#    #+#              #
#    Updated: 2015/06/25 22:15:40 by fvivaudo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra

SRC = main.cpp

NAME = ok

all : $(NAME)

$(NAME) :
	clang++ $(FLAGS) $(SRC) -o $(NAME)

clean:
	@rm -Rf $(NAME)

fclean: clean
	@rm -Rf $(NAME)

re: fclean all
	
