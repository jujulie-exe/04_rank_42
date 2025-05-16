NAME = ex01

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC_DIR = src
SRCS =	$(SRC_DIR)/main.cpp   \
 	$(SRC_DIR)/Animal.cpp \
 	$(SRC_DIR)/Cat.cpp    \
	$(SRC_DIR)/Dog.cpp \
	$(SRC_DIR)/WrongAnimal.cpp \
	$(SRC_DIR)/WrongCat.cpp \
	$(SRC_DIR)/Brain.cpp \


OBJ_DIR = obj
OBJ = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

