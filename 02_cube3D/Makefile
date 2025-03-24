NAME = cube3D

define HEADER
	\033[38;5;213m

	\033[0m
endef

# Compiler and flags
CC = cc
CFLAGS = -g3 -Wall -Wextra -Werror -Iminilibx -Isrc

# Source files and objects
SRCS = 

OBJ_DIR = obj
OBJ = $(SRCS:src/%.c=$(OBJ_DIR)/%.o)

# MiniLibX paths
MINILIBX_DIR = minilibx
MINILIBX_LIB = -L$(MINILIBX_DIR) -lmlx_Linux
MINILIBX_INCLUDE = -I$(MINILIBX_DIR)

# Libraries to link
LIB = $(MINILIBX_LIB) -L/usr/lib -lXext -lX11 -lm -lz

#Libft path
LIBFT_DIR = libft_fprintf/libft
LIBFT = $(LIBFT_DIR)/libft.a

#Fprintf
FPRINTF_DIR = libft_fprintf/ftprintf
FPRINTF = $(FPRINTF_DIR)/libftfprintf.a

# Default target
all: $(NAME)
	@echo "$$HEADER"
	@echo "\033[38;5;213m(っ◔◡◔)っ ♥ Ecole 19 | Fractol | Julie ♥\033[0m"

# Create the object directory before compiling
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Compile MiniLibX only if needed

minilibx:
	@echo "\033[38;5;208mCompiling MiniLibX...\033[0m"
	@if [ ! -f $(MINILIBX_DIR)/libmlx_Linux.a ] || [ $(MINILIBX_DIR)/mlx.h -nt $(MINILIBX_DIR)/libmlx_Linux.a ]; then \
		$(MAKE) -C $(MINILIBX_DIR) --silent; \
	else \
		echo "MiniLibX already compiled"; \
	fi
libft:
	@echo "\033[38;5;208mCompiling libft...\033[0m"
	$(MAKE) -C  $(LIBFT_DIR) --silent

fprintf:
	@echo "\033[38;5;208mCompiling fprintf...\033[0m"
	$(MAKE) -C $(FPRINTF_DIR) --silent

# Compile the program
$(NAME): $(OBJ_DIR) $(OBJ) minilibx libft fprintf
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)

# Rule to compile .c into .o
$(OBJ_DIR)/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean objects and MiniLibX
clean:
	rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(MINILIBX_DIR) clean
	@$(MAKE) -C $(FPRINTF_DIR) clean
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "File oggetto rimossi."

# Clean everything (objects and executable)
fclean: clean
	rm -f $(NAME)
	@echo "Eseguibile rimosso."

# Recompile everything
re: fclean all

# Run the program
run: re
	./$(NAME)

#debug: #con un main apposta che i return delle funzioni in un dubug.file.txt

.PHONY: all clean fclean re run minilibx

