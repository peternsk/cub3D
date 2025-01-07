# #--- BASIC ---#

# NAME        = cube
# CC          = gcc
# CFLAGS      = -Wall -Wextra -Werror -g -fsanitize=address
# RM          = rm -rf

# INC_DIR     = include
# SRCS_DIR    = src
# OBJS_DIR    = obj
# USER        = $(shell whoami)

# LAUNCH      = cub3d main
# PARSE       = color dimentions flood init map parse texture_parsing
# RAYCASTING  = init movements raycaster walls
# UTILS       = draw errors ft_split_set init_draw map_position math mlx

# SRCS        = $(addsuffix .c, $(addprefix $(SRCS_DIR)/launch/, $(LAUNCH))) \
#               $(addsuffix .c, $(addprefix $(SRCS_DIR)/parse/, $(PARSE))) \
#               $(addsuffix .c, $(addprefix $(SRCS_DIR)/raycasting/, $(RAYCASTING))) \
#               $(addsuffix .c, $(addprefix $(SRCS_DIR)/utils/, $(UTILS)))

# OBJS        = $(addprefix $(OBJS_DIR)/, $(subst src/,,$(SRCS:.c=.o)))

# LIBFT_PATH  = libft
# LIBFT_LIB   = $(LIBFT_PATH)/libft.a
# LIBFT_INC   = $(LIBFT_PATH)/include

# MYLIB_PATH  = my_lib
# MYLIB_LIB   = $(MYLIB_PATH)/mylib.a
# MYLIB_INC   = $(MYLIB_PATH)/include

# MLX_PATH    = MLX42/build
# MLX_LIB     = $(MLX_PATH)/libmlx42.a
# MLX_FLAGS   = -framework Cocoa -framework OpenGL -framework IOKit
# # Change this path for your homebrew path
# MLX_INC = -Iinclude -lglfw -L "/Users/$(USER)/homebrew/opt/glfw/lib"
# # MLX_INC = -Iinclude -lglfw -L "/Users/$(USER)/.brew/Cellar/glfw/3.4/lib"
# MLX_FLAGS = -framework Cocoa -framework OpenGL -framework IOKit
# MLX_INC = -Iinclude -lglfw -L "/opt/homebrew/Cellar/glfw/3.3.8/lib"
# # MLX_INC = -Iinclude -lglfw -L "/Users/$(USER)/.brew/Cellar/glfw/3.4/lib"

# # Colors
# GREEN       = \033[32;1m
# CYAN        = \033[36;1m
# RED         = \033[0;31m
# BOLD        = \033[1m
# RESET       = \033[0m
# MAGENTA     = \033[0;95m

# # Targets
# all: $(MLX_LIB) $(LIBFT_LIB) $(MYLIB_LIB) $(NAME)

# $(MLX_LIB):
# 	@cd MLX42 && cmake -B build
# 	@cmake --build $(MLX_PATH) -j4

# $(LIBFT_LIB):
# 	@make -C $(LIBFT_PATH)

# $(MYLIB_LIB):
# 	@make -C $(MYLIB_PATH)

# $(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
# 	@mkdir -p $(@D)
# 	@$(CC) $(CFLAGS) -I $(INC_DIR) -I $(LIBFT_INC) -I $(MYLIB_INC) -c $< -o $@
# 	@echo "$(GREEN)Compiling: $<$(RESET)$(MAGENTA)              [OK]$(RESET)"

# $(NAME): $(OBJS)
# 	@$(CC) $(CFLAGS) $(MLX_FLAGS) $(MLX_INC) $(OBJS) $(LIBFT_LIB) $(MYLIB_LIB) $(MLX_LIB) -o $(NAME)
# 	@echo "$(GREEN)Compilation terminé avec succès !$(RESET)"

# clean:
# 	@make clean -C $(LIBFT_PATH)
# 	@make clean -C $(MYLIB_PATH)
# 	@make clean -C $(MLX_PATH)
# 	@$(RM) $(OBJS_DIR)
# 	@echo "$(RED)$(BOLD)Nettoyage effectué avec succès !$(RESET)"

# fclean: clean
# 	@make fclean -C $(LIBFT_PATH)
# 	@make fclean -C $(MYLIB_PATH)
# 	@make clean -C $(MLX_PATH)
# 	@$(RM) $(NAME)

# re: fclean all
# 	@echo "$(CYAN)Recompilation terminée !$(RESET)"

# leaks:
# 	@valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes --trace-children=yes --suppressions=./$(NAME).sup ./$(NAME)

# .PHONY: all clean fclean re

#--- BASIC ---#

NAME        = cube
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror -g -fsanitize=address
RM          = rm -rf

INC_DIR     = include
SRCS_DIR    = src
OBJS_DIR    = obj
USER        = $(shell whoami)

LAUNCH      = cub3d main
PARSE       = color dimentions flood init map parse texture_parsing
RAYCASTING  = init movements raycaster walls
UTILS       = draw errors ft_split_set init_draw map_position math mlx

SRCS        = $(addsuffix .c, $(addprefix $(SRCS_DIR)/launch/, $(LAUNCH))) \
              $(addsuffix .c, $(addprefix $(SRCS_DIR)/parse/, $(PARSE))) \
              $(addsuffix .c, $(addprefix $(SRCS_DIR)/raycasting/, $(RAYCASTING))) \
              $(addsuffix .c, $(addprefix $(SRCS_DIR)/utils/, $(UTILS)))

OBJS        = $(addprefix $(OBJS_DIR)/, $(subst src/,,$(SRCS:.c=.o)))

MYLIB_PATH  = my_lib
MYLIB_LIB   = $(MYLIB_PATH)/mylib.a
MYLIB_INC   = $(MYLIB_PATH)/include

MLX_PATH    = MLX42/build
MLX_LIB     = $(MLX_PATH)/libmlx42.a
MLX_FLAGS   = -framework Cocoa -framework OpenGL -framework IOKit

MLX_INC = -Iinclude -lglfw -L "/Users/$(USER)/homebrew/opt/glfw/lib"
# MLX_INC = -Iinclude -lglfw -L "/Users/$(USER)/.brew/Cellar/glfw/3.4/lib"
MLX_FLAGS = -framework Cocoa -framework OpenGL -framework IOKit
MLX_INC = -Iinclude -lglfw -L "/opt/homebrew/Cellar/glfw/3.3.8/lib"
# MLX_INC = -Iinclude -lglfw -L "/Users/$(USER)/.brew/Cellar/glfw/3.4/lib"

# Colors
GREEN       = \033[32;1m
CYAN        = \033[36;1m
RED         = \033[0;31m
BOLD        = \033[1m
RESET       = \033[0m
MAGENTA     = \033[0;95m

# Targets
all: $(MLX_LIB) $(MYLIB_LIB) $(NAME)

$(MLX_LIB):
	@cd MLX42 && cmake -B build
	@cmake --build $(MLX_PATH) -j4

$(MYLIB_LIB):
	@make -C $(MYLIB_PATH)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -I $(MYLIB_INC) -c $< -o $@
	@echo "$(GREEN)Compiling: $<$(RESET)$(MAGENTA)              [OK]$(RESET)"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(MLX_FLAGS) $(MLX_INC) $(OBJS) $(MYLIB_LIB) $(MLX_LIB) -o $(NAME)
	@echo "$(GREEN)Compilation terminé avec succès !$(RESET)"

clean:
	@make clean -C $(MYLIB_PATH)
	@make clean -C $(MLX_PATH)
	@$(RM) $(OBJS_DIR)
	@echo "$(RED)$(BOLD)Nettoyage effectué avec succès !$(RESET)"

fclean: clean
	@make fclean -C $(MYLIB_PATH)
	@make clean -C $(MLX_PATH)
	@$(RM) $(NAME)

re: fclean all
	@echo "$(CYAN)Recompilation terminée !$(RESET)"

leaks:
	@valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes --trace-children=yes --suppressions=./$(NAME).sup ./$(NAME)

.PHONY: all clean fclean re
