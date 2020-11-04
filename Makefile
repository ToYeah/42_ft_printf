NAME=libftprintf.a
SRC_DIR= ./srcs
INC_DIR= ./includes
LIBFT_DIR=./libft
LIBFT=$(LIBFT_DIR)/libft.a
SRCS=\
ft_printf.c\
analyze_format.c\
useful_functions.c\
char_pattern.c\
string_pattern.c\
int_pattern.c\
pointer_pattern.c\
u_int_pattern.c\
lower_hex_pattern.c\
upper_hex_pattern.c\
other_pattern.c
CC=gcc
CFLAGS=-Wall -Wextra -Werror
CFLAGS+=-I $(INC_DIR)
AR=ar
ARFLAGS=crs
OBJNAMES=$(SRCS:.c=.o)
OBJS=$(addprefix $(SRC_DIR)/,$(OBJNAMES))

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	cp $(LIBFT) ./$(NAME)
	$(AR) $(ARFLAGS) $(NAME) $^

clean: 
	$(MAKE) clean -C $(LIBFT_DIR) 
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR) 
	$(RM) $(NAME)

re: fclean all

.PHONEY	: all clean fclean re
