# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/30 14:49:51 by peternsaka        #+#    #+#              #
#    Updated: 2024/12/30 14:49:52 by peternsaka       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = mylib.a

# Hide calls
export VERBOSE	=	FALSE
ifeq ($(VERBOSE),TRUE)
	HIDE =
else
	HIDE = @
endif

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

# .o files in bin
OBJDIR	=	bin/
OBJS	=	$(patsubst $(SRCDIR)%.c,$(OBJDIR)%.o,$(SRCS))
SRCDIR = src/
SRCS = src/ft_isalpha.c \
		src/ft_isdigit.c \
		src/ft_isalnum.c \
		src/ft_isascii.c \
		src/ft_isprint.c \
		src/ft_strlen.c \
		src/ft_memset.c \
		src/ft_bzero.c \
		src/ft_memcpy.c \
		src/ft_memmove.c \
		src/ft_strlcpy.c \
		src/ft_strlcat.c \
		src/ft_toupper.c \
		src/ft_tolower.c \
		src/ft_strchr.c \
		src/ft_strrchr.c \
		src/ft_strncmp.c \
		src/ft_memchr.c \
		src/ft_memcmp.c \
		src/ft_strnstr.c \
		src/ft_atoi.c \
		src/ft_substr.c \
		src/ft_strjoin.c \
		src/ft_strtrim.c \
		src/ft_split.c \
		src/ft_itoa.c \
		src/ft_strmapi.c \
		src/ft_striteri.c \
		src/ft_putchar_fd.c \
		src/ft_putstr_fd.c \
		src/ft_putendl_fd.c \
		src/ft_putnbr_fd.c \
		src/ft_calloc.c \
		src/ft_strdup.c \
		src/hexa_functions.c \
		src/ft_printf.c \
		src/nbr_functions.c \
		src/char_functions.c \
		src/ft_free_str_array.c \
		src/throw_error.c \
		src/ft_atol.c \
		src/ft_nb_out_bounds.c \
		src/get_next_line.c

$(NAME): $(OBJS)
	$(HIDE) $(AR) $(NAME) $(OBJS)

# Compiles sources into objects
$(OBJS): $(OBJDIR)%.o : $(SRCDIR)%.c| $(OBJDIR)
	$(HIDE) $(CC) $(CFLAGS) -c $< -o $@

# Creates directory for binaries
$(OBJDIR):
	$(HIDE)mkdir -p $@

all: $(NAME)

clean:
	$(HIDE) $(RM) $(OBJS) $(BONUS_OBJ)

fclean: clean
	$(HIDE) $(RM) $(NAME)

re: fclean all

.PHONY : all clean fclean re bonus
