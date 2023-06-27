CC = cc

CFLAG = -Wall -Werror -Wextra

NAME = get_next_line.a

SRCS = get_next_line.c get_next_line_utils.c


OBJS = $(SRCS:.c=.o)


all : $(NAME)

bonus : all

$(NAME) : $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o : %.c
	 $(CC) $(CFLAG) $^ -o $@ -c -I ./get_next_line.h

clean : 
		rm -rf $(OBJS)

fclean : clean 
	     rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re