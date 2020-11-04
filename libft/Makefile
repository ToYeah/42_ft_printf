NAME=libft.a
SRCS=\
ft_memset.c\
ft_bzero.c\
ft_memcpy.c\
ft_memccpy.c\
ft_memmove.c\
ft_memchr.c\
ft_memcmp.c\
ft_isalpha.c\
ft_isdigit.c\
ft_isalnum.c\
ft_isascii.c\
ft_isprint.c\
ft_toupper.c\
ft_tolower.c\
ft_strlcpy.c\
ft_strlen.c\
ft_strlcat.c\
ft_strchr.c\
ft_strrchr.c\
ft_atoi.c\
ft_strnstr.c\
ft_strncmp.c\
ft_calloc.c\
ft_strdup.c\
ft_strjoin.c\
ft_substr.c\
ft_strtrim.c\
ft_split.c\
ft_itoa.c\
ft_putchar_fd.c\
ft_putstr_fd.c\
ft_putendl_fd.c\
ft_putnbr_fd.c\
ft_strmapi.c\
ft_lstnew.c\
ft_lstadd_front.c\
ft_lstsize.c\
ft_lstlast.c\
ft_lstadd_back.c\
ft_lstdelone.c\
ft_lstclear.c\
ft_lstmap.c\
ft_lstiter.c\
ft_putstr_limit.c\
ft_get_lower.c\
ft_get_upper.c\
ft_putabs_fd.c\
ft_puthex_fd.c\
ft_nbrdig.c\


CC=gcc
CCFLAGS=-Wall -Wextra -Werror
AR=ar
ARFLAGS=crs
OBJS=$(SRCS:.c=.o)

all: $(NAME)

.c.o:
	$(CC) $(CCFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONEY	: all clean fclean re
