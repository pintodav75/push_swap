# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpinto <dpinto@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/26 16:26:07 by dpinto            #+#    #+#              #
#    Updated: 2024/07/08 02:18:58 by dpinto           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

LIBFT_DIR	= libft
INCLUDE_DIR	= includes

SRCS_DIR	= srcs
SRCS		= $(addprefix $(SRCS_DIR)/, main.c parse.c lst.c instruction.c \
	instruction2.c instruction3.c ft_swap.c helpers.c compute.c free.c quick_sort.c \
	strat.c big_sort.c helpers_big_sort.c abs.c)
OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT_DIR)/libft.a:
	@make -s -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT_DIR)/libft.a 
	$(CC) $(CFLAGS) $(OBJS) -Llibft -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -I$(INCLUDE_DIR) -I$(LIBFT_DIR) -o $@

clean:
	@make -s -C $(LIBFT_DIR) clean
	@rm -f $(OBJS)

fclean: clean
	@make -s -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re MLX LIBFT