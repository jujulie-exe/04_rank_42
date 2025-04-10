NAME = megaphone

CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC_DIR = srcs
SRCS = $(SRC_DIR)/megaphone.cpp
OBJ_DIR = obj
# Usa una sostituzione più complessa per mantenere la struttura delle directory
OBJ = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Default target
all: $(NAME)

# Create the object directory before compiling
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Rule to compile .cpp into .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Link the executable
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

# Clean objects
clean:
	rm -rf $(OBJ_DIR)

# Clean everything (objects and executable)
fclean: clean
	rm -f $(NAME)

# Recompile everything
re: fclean all

.PHONY: all clean fclean re $(OBJ_DIR)
