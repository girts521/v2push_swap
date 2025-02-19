NAME = push_swap
LIBFT_DIR = libft
CC = cc
CFLAGS = -Wall -Wextra -Werror 
INCLUDES = -I$(LIBFT_DIR)

SRCS = main.c utils.c error.c sort_small.c instructions.c init_nodes.c \
		move_nodes.c push_swap.c instructions_utils.c optimize.c quick_sort.c \
		quick_sort_utils.c index_list.c

OBJS  :=  $(SRCS:.c=.o)

LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT): 
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -rf $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
