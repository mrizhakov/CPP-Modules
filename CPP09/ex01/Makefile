# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrizakov <mrizakov@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 17:37:29 by mrizhakov         #+#    #+#              #
#    Updated: 2025/05/08 17:19:11 by mrizakov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = c++
FLAGS = -Wall -Werror -Wextra -std=c++98 -g
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include
EXECUTABLE = rpn
VPATH = $(SRC_DIR)
SRC = RPN.cpp main.cpp
OBJ = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRC))


all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ) | $(OBJ_DIR)
	$(CC) $(FLAGS) $^ -o $@

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CC) $(FLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(EXECUTABLE) $(TEST_EXECUTABLE)

re: fclean all

.PHONY: clean test
