# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: dcoat <marvin@le-101.fr>                   +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/10/21 07:44:43 by dcoat        #+#   ##    ##    #+#        #
#    Updated: 2019/10/21 13:45:37 by dcoat       ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = fractol

SRC = main.c \
	  choose_fract.c \
	  init_fract.c \
	  calc_fract.c \
	  render_fract.c \
	  fract_tools.c \
	  fract_escape_time.c \
	  fract_color.c \

OBJ = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Werror -Wextra

LIBFT = ./libft/

MINILIBX = ./minilibx_macos/

LIBFT.A = ./libft/libft.a

MINILIBX.A = ./minilibx_macos/libmlx.a

FRAMEWORKS = -framework OpenGL -framework AppKit

DEBUG = -fsanitize=address -g3

all : libs $(NAME)

$(NAME): $(SRC) $(LIBFT.A) $(MINILIBX.A)
	@$(CC) -o $(NAME) $(DEBUG) $(SRC) $(LIBFT.A) $(MINILIBX.A) $(FRAMEWORKS)
	@echo "\033[1;32mFRACTOLOK\033[0m"

libs:
	@(cd $(LIBFT) && $(MAKE))
	@(cd $(MINILIBX) && $(MAKE))

%.o: %.c fractol.h
	@$(CC) $(FLAGS) -I. -c $(SRC)

clean:
	@rm -f $(OBJ)
	@rm -f *.gch
	@(cd $(LIBFT) && $(MAKE) $@)
	@(cd $(MINILIBX) && $(MAKE) $@)
	@echo "\033[1;31mCLEAN FRACTOLOK\033[0m"

fclean: clean
	@rm -f $(NAME)
	@(cd $(LIBFT) && $(MAKE) 			$@)
	@echo "\033[1;31mFCLEAN FRACTOLOK\033[0m"

re: fclean all

.PHONY : all clean fclean re
