# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/02 16:56:10 by ohertzbe          #+#    #+#              #
#    Updated: 2024/01/10 19:59:37 by ohertzbe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc
CFLAGS := -g -Wall -Werror -Wextra
NAME := bin/push_swap
LIBFT := libft/libft.a
SRCS := src/check_arguments.c \
        src/double_sort.c \
        src/is_sorted.c \
        src/push_swap.c \
        src/ra_sa.c \
        src/ra.c \
        src/rra_sa.c \
        src/rra.c \
        src/sa.c \
        src/stack_operations.c \
        src/triple_sort.c \
		src/sb.c \
		src/pa.c \
		src/pb.c \
		src/rb.c \
		src/rrb.c \
		src/inefficient_sort.c \
		src/update_positions.c \
		src/efficient_sort.c \
		src/quick_sort.c \
		src/get_start_end_chunk.c \
		src/stack_len.c \
		src/ra_no_write.c \
		src/rra_no_write.c \
		src/rb_no_write.c \
		src/rrb_no_write.c \
		src/pb_no_write.c \
		src/get_functions_and_cost.c \
		src/rotate_functions.c \
		src/get_top_and_bot_nodes.c \
		src/write_instructions.c \
		src/write_instructions2.c \
		src/insert_functions.c \
		src/free_double_pointer_array.c \
		src/check_for_big_num.c \
		
	
OBJS := $(patsubst src/%.c, obj/%.o, $(SRCS))
INCL := include/push_swap.h

all: $(LIBFT) $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@mkdir -p bin
	$(CC) $(CFLAGS) -o $@ $^

$(LIBFT):
	make -C ./libft

obj/%.o: src/%.c $(INCL)
	@mkdir -p obj
	$(CC) $(CFLAGS) -c -o $@ $< -I include

clean:
	rm -rf obj
	make -C ./libft clean

fclean: clean
	rm -rf bin
	make -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re
