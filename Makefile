# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/03 15:56:35 by vnakonec          #+#    #+#              #
#    Updated: 2017/10/26 23:36:11 by vnakonec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

CFLAGS = -Wall -Wextra -Werror

INCLUDES = .

SRCS = main.c\
	  prm.c\
	  sort.c\
	  make_ls.c\
	  ft_ls.c\

OBJ = $(SRCS:.c=.o)

LIBFTDIR = libft/

all: $(NAME)

$(NAME) : $(LIBFTDIR)libftprintf.a $(OBJ)
	gcc $(CFLAGS) $(OBJ) -o $(NAME) -L./$(LIBFTDIR) -lftprintf

%.o: %.c
	gcc $(CFLAGS) -c -o $@ $< -I $(INCLUDES) -I $(LIBFTDIR)

$(LIBFTDIR)libftprintf.a: libft/Makefile
	make -C libft/

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFTDIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFTDIR)libftprintf.a

re: fclean all
