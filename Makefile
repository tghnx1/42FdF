# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/24 10:09:10 by mkokorev          #+#    #+#              #
#    Updated: 2024/04/24 11:23:19 by mkokorev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
PRINTFNAME = libftprintf.a
MINILIBXNAME = libmlx.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
MINILIBFLAGS = -Lminilibx-linux -lmlx_Linux -lX11 -lXext -lm
PRINTFDIR = ./printf
MINILIBXDIR = ./minilibx-linux
PRINTF_LIB_PATH = $(PRINTFDIR)/libftprintf.a

SRCS = 	dots_connection.c \
		draw.c \
		FdF.c \
		get_next_line_utils.c \
		get_next_line.c \
		math.c \
		utils.c \
		utils2.c \
		utils3.c \
		window_manage.c


OBJS = $(SRCS:.c=.o)

all: $(NAME)

makeminilibx:
	@make -C $(MINILIBXDIR) || exit 1
	@cp $(MINILIBXDIR)/*.a .
	@mv $(MINILIBXNAME) $(NAME)

makeprintf:
	@make -C $(PRINTFDIR) || exit 1
	@cp $(PRINTFDIR)/$(PRINTFNAME) .
	@mv $(PRINTFNAME) $(NAME)

$(NAME): makeprintf makeminilibx $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(PRINTF_LIB_PATH) $(MINILIBFLAGS) -o $@


clean:
	@rm -f $(OBJS)
	@rm -f $(MINILIBXNAME)
	@cd $(PRINTFDIR) && make clean

fclean: clean
	@rm -f *.a
	@cd $(PRINTFDIR) && make fclean
	@cd $(MINILIBXDIR) && rm -f *.a

re: fclean all
