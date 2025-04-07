# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 17:37:29 by mrizhakov         #+#    #+#              #
#    Updated: 2025/04/07 22:28:07 by mrizakov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = c++
FLAGS = -Wall -Werror -Wextra -std=c++98
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include
EXECUTABLE = ScalarConverter
VPATH = $(SRC_DIR)
SRC = ScalarConverter.cpp main.cpp
OBJ = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRC))
TEST_SRCS = tests/test_main.cpp
TEST_OBJS = $(filter-out $(OBJ_DIR)/main.o, $(OBJ))
TEST_NAME = test_converter


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
	rm -f $(EXECUTABLE)

re: fclean all

test: $(OBJ) | $(OBJ_DIR)
	$(CC) $(FLAGS) -o $(TEST_NAME) $(TEST_OBJS) $(TEST_SRCS)
	./$(TEST_NAME)

.PHONY: clean test
