# Nome dell'eseguibile
NAME = cube3D

# Header
define HEADER
\033[38;5;213m\033[0m
endef

# Compiler e flag
CC = cc
CFLAGS = -g3 -Wall -Wextra -Werror -Iminilibx -Isrc

# Directory sorgenti e oggetti
SRCDIR = src
OBJ_DIR = obj

# File sorgente
SRCS =  $(SRCDIR)/GNL/get_next_line.c \
        $(SRCDIR)/parsing/proccess_parsing.c \
        $(SRCDIR)/parsing/parsing_utilis.c \
        $(SRCDIR)/clean_up_and_error/clean_err.c \
        $(SRCDIR)/main.c

# Creazione degli oggetti (o) a partire dai sorgenti
OBJ = $(SRCS:$(SRCDIR)/%.c=$(OBJ_DIR)/%.o)

# MiniLibX paths
MINILIBX_DIR = ./minilibx
MINILIBX_LIB = -L$(MINILIBX_DIR) -lmlx 
MINILIBX_INCLUDE = -I$(MINILIBX_DIR)


# Libft path
LIBFT_DIR = libft_fprintf/libft
LIBFT = $(LIBFT_DIR)/libft.a

# Fprintf
FPRINTF_DIR = libft_fprintf/ftprintf
FPRINTF = $(FPRINTF_DIR)/libftfprintf.a
# Librerie da linkare
LIB = $(MINILIBX_LIB) -lmlx_Linux $(LIBFT) $(FPRINTF) -L/usr/lib -lXext -lX11 -lm -lz

# Target predefiniti
all: $(NAME)

# Creazione della directory obj/GNL/ e compilazione degli oggetti
$(OBJ_DIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)  # Crea tutte le sottodirectory necessarie
	@$(CC) $(CFLAGS) -c $< -o $@

# Regola per compilare minilibx
minilibx:
	@echo "\033[38;5;208mCompiling MiniLibX...\033[0m"
	@if [ ! -f $(MINILIBX_DIR)/libmlx_Linux.a ] || [ $(MINILIBX_DIR)/mlx.h -nt $(MINILIBX_DIR)/libmlx_Linux.a ]; then \
		$(MAKE) -C $(MINILIBX_DIR) --silent; \
	else \
		echo "MiniLibX already compiled"; \
	fi

# Regola per compilare libft
$(LIBFT_RULES):
	@echo "\033[38;5;208mCompiling libft...\033[0m"
	$(MAKE) -C  $(LIBFT_DIR) --silent

# Regola per compilare fprintf
$(FPRINTF_RULES):
	@echo "\033[38;5;208mCompiling fprintf...\033[0m"
	$(MAKE) -C $(FPRINTF_DIR) --silent

# Regola per compilare il programma
$(NAME): $(OBJ) $(FPRINTF_RULES) $(LIBFT_RULES) minilibx
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)

# Pulizia oggetti e MiniLibX
clean:
	rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(MINILIBX_DIR) clean
	@$(MAKE) -C $(FPRINTF_DIR) clean
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "File oggetto rimossi."

# Pulizia totale (oggetti e eseguibile)
fclean: clean
	rm -f $(NAME)
	@echo "Eseguibile rimosso."

# Ricompilazione completa
re: fclean all

# Esecuzione del programma
run: re
	./$(NAME)

.PHONY: all clean fclean re run minilibx

