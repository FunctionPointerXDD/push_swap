NAME = push_swap
BNS_NAME = checker

SRCS = push_swap.c mystack.c main.c quick_select.c operator.c main_utils.c simple_sort.c push_swap_utils.c dispose_3_items.c dispose_a_dummy.c dispose_b_dummy.c
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

BNS_SRCS = main_bonus.c main_utils_bonus.c mystack_bonus.c operator_bonus.c bonus_utils.c
BNS_OBJS = $(BNS_SRCS:.c=.o)
BNS_DEPS = $(BNS_SRCS:.c=.d)

CC = cc
CFLAGS = -Wall -Werror -Wextra -MD
LIBFT = libft/libft.a
RM = rm -rf
MAKE = make

all: $(NAME)

bonus : $(BNS_NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $@

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)

$(BNS_NAME): $(LIBFT) $(BNS_OBJS)
	$(CC) $(CFLAGS) $(BNS_OBJS) $(LIBFT) -o $@

$(BNS_OBJS): $(BNS_SRCS)
	$(CC) $(CFLAGS) -c $(BNS_SRCS)

$(LIBFT):
	$(MAKE) -sC libft all

%.a: lib
	$(MAKE) $(@F) -C $(@D)

clean:
	$(RM) $(OBJS) $(DEPS) $(BNS_OBJS) $(BNS_DEPS)
	$(MAKE) -sC libft clean

fclean: clean
	$(RM) $(NAME) $(BNS_NAME)
	$(MAKE) -sC libft fclean

re: fclean all

.PHONY: all clean fclean re bonus
