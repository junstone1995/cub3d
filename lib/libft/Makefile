CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
HEADER = libft.h
SRCS = ft_bzero.c \
		ft_calloc.c \
		ft_isdigit.c \
		ft_memcpy.c \
		ft_memset.c \
		ft_split.c \
		ft_free.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_substr.c

OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	ar cr $@ $^

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re fclean clean
