NAME = pipex
SRC = main.c parse.c free.c trigger.c
OBJ = $(SRC:.c=.o)
CC	= cc
RM	= rm -rf
FLAGS	= -Wall -Wextra -Werror 
LIBFT_LIB = libft/libft.a


all : $(NAME)

$(LIBFT_LIB) : 
		make -C libft pipex

$(NAME) : $(OBJ) $(LIBFT_LIB)
		$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT_LIB)

clean :
		make -C libft fclean 
		make -C libft fclean 
		$(RM) $(OBJ)

fclean:	clean
		$(RM) $(NAME)

re:	fclean $(NAME)