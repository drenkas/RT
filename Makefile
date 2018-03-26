#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drenkas <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/17 16:39:27 by drenkas           #+#    #+#              #
#    Updated: 2017/01/17 16:39:29 by drenkas          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

.PHONY: all, $(NAME), clean, fclean, re

NAME = RT

NOC=\033[0m
OKC=\033[32m
ERC=\033[31m
WAC=\033[33m

CC = gcc
CC_FLAGS = -Wall -Wextra -Werror -O3 -g -Ofast
FLAG = -lmlx -framework OpenGL -framework AppKit -lpthread

SRC_PATH = ./
INC_PATH = ./
OBJ_PATH = ./obj/
LFT_PATH = ./libft/

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

OBJ_NAME = $(SRC_NAME:.c=.o)

INC_NAME = rtv1.h

SRC_NAME = main.c rec_objs.c record.c key_hooks.c start_t.c inter.c vect.c \
vect2.c light.c crutch.c menu.c reflect.c antialiasing.c refract.c \
equation_4.c disk.c inter2.c paraboloid.c rec_objs2.c tore.c tringl.c mobius.c \
auxiliary_mob.c coeff.c cube.c piramid.c equation_4_2.c inter3.c tim_c.c \
half_sphere.c limit_cone.c dasha.c menu1.c hooks1.c \
check_parser.c choose_scene.c add_obj.c check_parser1.c \
choose_scene1.c hooks2.c menu1_ad.c check_parser2.c

all: $(NAME)

$(NAME): $(OBJ)
	@echo
	@make -C $(LFT_PATH)
	@$(CC) -o $(NAME) $(OBJ) -lm -L $(LFT_PATH) -lft $(FLAG)
	@echo "$(OKC)RT:\t\tRT ready$(NOC)"


$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CC_FLAGS) $(INC) -o $@ -c $<
	@echo -n =

clean:
	@make -C $(LFT_PATH) clean
	@rm -rf $(OBJ_PATH)
	@echo "$(WAC)RT:\t\tRemoving OBJ path: ./obj/$(NOC)"

fclean: clean
	@make -C $(LFT_PATH) fclean
	@rm -f $(NAME)
	@echo "$(WAC)RT:\t\tRemoving RT executable$(NOC)"

re: fclean all
