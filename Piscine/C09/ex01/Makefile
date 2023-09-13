NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

HEADER = includes/ft.h

SOURCES = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

.c.o: $(SOURCES)
	cc -c $(CFLAGS) -I $(HEADER) $(<) -o $(<:.c=.o)

$(NAME): $(OBJECTS)
	ar rcsv $@ $<

clean:
	rm $(OBJECTS)

fclean:
	rm $(OBJECTS) $(NAME)

re: fclean all
