# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/07/16 09:42:25 by fvivaudo          #+#    #+#              #
#    Updated: 2015/03/13 11:00:00 by fvivaudo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra

SRC = 	phonebook.cpp

NAME = phonebook

all : $(NAME)

$(NAME) :
	clang++ $(FLAGS) $(SRC) -I ./ -o $(NAME)

clean:
	@rm -Rf $(NAME)

fclean: clean
	@rm -Rf $(NAME)

re: fclean all
	
