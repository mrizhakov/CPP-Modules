# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 17:37:29 by mrizhakov         #+#    #+#              #
#    Updated: 2024/02/03 16:40:04 by mrizakov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
FLAGS = -Wall -Werror -Wextra -std=c++98
SRC = Phonebook.class.cpp
OBJ = $(SRC:.cpp=.o)
EXECUTABLE = Phonebook

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
