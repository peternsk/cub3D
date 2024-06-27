#--- BASIC ---#

NAME        =	cube
CC          =	gcc
FLAGS       =	-Wall -Wextra -Werror -g -fsanitize=address
RM          =	rm -rf

INC_DIR 	= 	include
SRCS_DIR    = 	src
OBJS_DIR    = 	obj
USER   = $(shell whoami)

GAME	    =	images ft_player_moves ft_movement background

GARBAGE     =

MAIN	    =	main

MINI_MAP    =

PARSING     =  close_by_one filename getfile getmap look_newline pathtexture removenewline six_char_invalide valide_map wallscolors  ft_isupper free_sstr init_info \
				ft_strcmp atoi_long square_map

UTILS       =	copy_map init_mini_s map_to_arr map_len

SRCS        =   $(addsuffix .c, $(addprefix $(SRCS_DIR)/game/, $(GAME))) \
                $(addsuffix .c, $(addprefix $(SRCS_DIR)/garbage/, $(GARBAGE))) \
                $(addsuffix .c, $(addprefix $(SRCS_DIR)/main/, $(MAIN))) \
                $(addsuffix .c, $(addprefix $(SRCS_DIR)/mini_map/, $(MINI_MAP))) \
                $(addsuffix .c, $(addprefix $(SRCS_DIR)/parsing/, $(PARSING))) \
                $(addsuffix .c, $(addprefix $(SRCS_DIR)/utils/, $(UTILS)))

OBJS        =   $(addprefix ${OBJS_DIR}/, $(subst src/,,$(SRCS:.c=.o)))

LIBFT_PATH = libft
LIBFT_LIB = ${LIBFT_PATH}/libft.a
LIBFT_INC = ${LIBFT_PATH}/include

MLX_PATH = MLX42/build
MLX_LIB = ${MLX_PATH}/libmlx42.a
# Change this path for your homebrew path
# MLX_INC = -Iinclude -lglfw -L "/opt/homebrew/Cellar/glfw/3.3.8/lib"
MLX_INC = -Iinclude -lglfw -L "/Users/$(USER)/.brew/Cellar/glfw/3.4/lib"
MLX_FLAGS = -framework Cocoa -framework OpenGL -framework IOKit

GREEN	= \033[32;1m
CYAN	= \033[36;1m
RED		= \033[0;31m
BOLD	= \033[1m
RESET	= \033[0m
MAGENTA	=\033[0;95m

all: ${MLX_LIB} ${LIBFT_LIB} ${NAME}

${MLX_LIB}:
	@cd MLX42 && cmake -B build
	@cmake --build ${MLX_PATH} -j4

${LIBFT_LIB}:
	@make -C ${LIBFT_PATH}

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c
	@mkdir -p ${@D}
	@${CC} ${CFLAGS} -I ${INC_DIR} -I ${LIBFT_INC} -c $< -o $@
	@echo "$(GREEN)Compiling: $<$(RESET)$(MAGENTA)              [OK]$(RESET)"

${NAME}: ${OBJS}
	@${CC} ${CFLAGS} ${MLX_FLAGS} ${MLX_INC} ${OBJS} ${LIBFT_LIB} ${MLX_LIB} -o ${NAME}
	@echo "$(GREEN)Compilation terminé avec succès !"

clean:
	@make clean -C ${LIBFT_PATH}
	@make clean -C ${MLX_PATH}
	@${RM} ${OBJS_DIR}
	@echo "$(RED)$(BOLD)Nettoyage effectué avec succès !"


fclean:	clean
	@make fclean -C ${LIBFT_PATH}
	@make clean -C ${MLX_PATH}
	@${RM} ${NAME}

re: fclean all
	@echo "$(CYAN)Recompilation Terminé !"

leaks:
	@valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes --trace-children=yes --suppressions=./$(NAME).sup ./$(NAME)

.PHONY: all clean fclean re
