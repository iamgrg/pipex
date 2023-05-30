# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gansard <gansard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 13:44:04 by ymehlil           #+#    #+#              #
#    Updated: 2023/03/12 14:13:35 by gansard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libft.a

SRCS			=	ft_isalnum.c    ft_isprint.c    ft_memcmp.c  	ft_putchar_fd.c   ft_split.c    \
					ft_strlcat.c    ft_strncmp.c    ft_substr.c   	ft_atoi.c 		  ft_isalpha.c  \
					ft_itoa.c       ft_memcpy.c     ft_putendl_fd.c ft_strchr.c 	  ft_strlcpy.c  \
					ft_strnstr.c    ft_tolower.c    ft_bzero.c   	ft_isascii.c 	  ft_strrchr.c  \
					ft_memmove.c    ft_putnbr_fd.c  ft_strdup.c  	ft_strlen.c 	  ft_memset.c   \
					ft_toupper.c    ft_calloc.c  	ft_isdigit.c 	ft_memchr.c 	  ft_striteri.c \
					ft_putstr_fd.c  ft_strjoin.c 	ft_strmapi.c 	ft_strtrim.c	  ft_strrev.c	\
					ft_abs.c		ft_strcmp.c		ft_long_atoi.c
					

bonus			=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c 		\
					ft_lstdelone.c ft_lstiter.c ft_lstclear.c ft_lstmap.c

PRINTF			=	ft_printf.c ft_print_d.c ft_print_p.c ft_print_u.c ft_print_x.c ft_print_X.c 	\
					ft_atoi_hex.c ft_print_s.c ft_uitoa.c ft_print_majx.c
					
GNL				=	get_next_line.c get_next_line_utils.c

OBJS			= $(SRCS:.c=.o) 
OBJSbonus		= $(bonus:.c=.o)
OBJPRINTF		= $(PRINTF:.c=.o)
OBJSGNL			= $(GNL:.c=.o)

CC				= cc
RM				= rm -f
CFLAGS			= -g -Wall -Wextra -Werror -I.

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS) 

bonus:			$(OBJSbonus) $(OBJS)
				ar rcs $(NAME) $(OBJSbonus) $(OBJS) 
				
so_long:		$(OBJS) $(OBJPRINTF) $(OBJSGNL)
				ar rcs $(NAME) $(OBJS) $(OBJPRINTF) $(OBJSGNL)

push_swap:		$(OBJS) $(OBJPRINTF) $(OBJSbonus)
				ar rcs $(NAME) $(OBJS) $(OBJPRINTF) $(OBJSbonus)
				
pipex:		$(OBJS) $(OBJPRINTF) $(OBJSbonus)
				ar rcs $(NAME) $(OBJS) $(OBJPRINTF) $(OBJSbonus)			

clean:
				$(RM) $(OBJS) $(OBJSbonus) $(OBJPRINTF) $(OBJSGNL)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY: all clean fclean so_long bonus re