# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lspiess <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/19 07:01:26 by lspiess           #+#    #+#              #
#    Updated: 2019/06/07 16:52:52 by lspiess          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
LIB = libft.a
FLAGS = -Wall -Werror -Wextra
LIBSRC = ft_atoi.c ft_lstmap.c       ft_putstr.c       ft_strncat.c \
ft_bzero.c        ft_lstnew.c       ft_putstr_fd.c    ft_strncmp.c\
ft_elem_len.c     ft_lstpop.c       ft_strcat.c       ft_strncpy.c\
ft_is_escapable.c ft_memalloc.c     ft_strchr.c       ft_strnequ.c\
ft_isalnum.c      ft_memccpy.c      ft_strclr.c       ft_strnew.c\
ft_isalpha.c      ft_memchr.c       ft_strcmp.c       ft_strnstr.c\
ft_isascii.c      ft_memcmp.c       ft_strcpy.c       ft_strrchr.c\
ft_isdigit.c      ft_memcpy.c       ft_strdel.c       ft_strsplit.c\
ft_isprint.c      ft_memdel.c       ft_strdup.c       ft_strstr.c\
ft_isqrt.c        ft_memmove.c      ft_strequ.c       ft_strsub.c\
ft_itoa.c         ft_memset.c       ft_striter.c      ft_strtrim.c\
ft_lstadd.c       ft_putchar.c      ft_striteri.c     ft_tolower.c\
ft_lstdel.c       ft_putchar_fd.c   ft_strjoin.c      ft_toupper.c\
ft_lstdelnode.c   ft_putendl.c      ft_strlcat.c      get_next_line.c\
ft_lstdelone.c    ft_putendl_fd.c   ft_strlen.c\
ft_lstinsert.c    ft_putnbr.c       ft_strmap.c\
ft_lstiter.c      ft_putnbr_fd.c    ft_strmapi.c
LIBOBJ = $(LIBSRC:.c=.o)
SRC = ft_check_elems.c ft_lstutils.c ft_solve.c ft_err_msg.c \
ft_measure_elems.c ft_get_coords.c ft_output.c main.c ft_align_elems.c \
ft_get_elems.c ft_rec_utils.c
SRCOBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) :
	gcc $(FLAGS) -c $(addprefix ./libft/, $(LIBSRC))
	ar rc $(LIB) $(LIBOBJ)
	ranlib $(LIB)
	gcc $(FLAGS) $(SRC) $(LIB) -o $(NAME)

clean :
	rm *.o

fclean :
	rm -f $(LIB)
	rm -f $(NAME)
	rm -f *.o

re : fclean all
