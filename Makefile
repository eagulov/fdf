# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/17 17:38:17 by eagulov           #+#    #+#              #
#    Updated: 2019/02/22 09:34:11 by eagulov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC = *.c
LIBFT = libft
OBJ = $(SRC:.c=.o)
DAMN = \033[0;92m

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJ)
		Make -C libft
		Make -C minilibx
		gcc -g -Wall -Werror -Wextra -I includes/fdf.h libft/libft.a -L ./minilibx \
					-lmlx -framework OpenGL -framework AppKit $(SRC) -o $(NAME)

			@echo "$(DAMN)Daaaaamn, it's compiled"

$(OBJ): $(LIBFT)
		gcc -Wall -Werror -Wextra -g -c $(SRC)

clean :
		-rm -f $(OBJ)
		make clean -C libft

			@echo "$(DAMN)Wow, all obj is deleted"
				
fclean : clean
		-rm -f $(NAME)
		make fclean -C libft
		
			@echo "$(DAMN)No way, everything is cleaned"
		
re : fclean all

.PHONY : clean fclean re
