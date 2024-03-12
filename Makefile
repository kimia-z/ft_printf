# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kziari <kziari@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 15:14:16 by kziari            #+#    #+#              #
#    Updated: 2023/11/20 15:14:18 by kziari           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs
RM = rm -rf

SRC = ft_printf ft_prints ft_put_hex ft_put_ui ft_print_char

SRCS = $(addsuffix .c, $(SRC))

OBJ_DIR = obj
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

$(OBJ_DIR)/%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJ_DIR) $(OBJS)
	cp $(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(LIBFT) :
	make -C $(LIBFT_PATH) all

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

clean :
	make -C $(LIBFT_PATH) clean
	$(RM) $(OBJ_DIR)

fclean : clean
	make -C $(LIBFT_PATH) fclean
		$(RM) $(NAME)

re : fclean all

.PHONY:all clean fclean re libft