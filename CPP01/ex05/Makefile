# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 17:37:29 by mrizhakov         #+#    #+#              #
#    Updated: 2024/02/10 18:58:48 by mrizakov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
FLAGS = -Wall -Werror -Wextra -std=c++98
SRC = Harl.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
EXECUTABLE = harl

all: ${EXECUTABLE}

${EXECUTABLE}: ${OBJ}
	${CC} ${FLAGS} $^ -o $@

${OBJ}: ${SRC}
	${CC} ${FLAGS} -c $^

clean:
	rm -f ${OBJ} 

fclean: clean
	rm -f ${EXECUTABLE}

re: fclean all

.PHONY: clean fclean
