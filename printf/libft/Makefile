# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/24 12:40:58 by mkokorev          #+#    #+#              #
#    Updated: 2023/12/20 15:26:01 by mkokorev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
SRC		= ft_atoi.c      ft_isprint.c   ft_strchr.c    ft_strnstr.c\
 ft_bzero.c      ft_memchr.c    ft_strdup.c     ft_strrchr.c\
 ft_calloc.c     ft_memcmp.c    ft_strjoin.c    ft_strtrim.c\
 ft_isalnum.c    ft_memcpy.c    ft_strlcat.c    ft_substr.c\
 ft_isalpha.c    ft_memmove.c   ft_strlcpy.c    ft_tolower.c\
 ft_isascii.c    ft_memset.c    ft_strlen.c     ft_toupper.c\
 ft_isdigit.c    ft_split.c     ft_strncmp.c    ft_itoa.c\
 ft_strmapi.c    ft_striteri.c  ft_putchar_fd.c ft_putstr_fd.c\
 ft_putendl_fd.c ft_putnbr_fd.c\

OBJ		= $(SRC:.c=.o)
CFLAGS	= -Wall -Wextra -Werror -std=c11 -g3 -O0 \

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: %.c
	@$(CC) -o $@ -c $? $(CFLAGS)

.PHONY: clean fclean re

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

suicide: fclean
	@rm -f $(SRC)
