# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfezzuog <gfezzuog@student.42rome.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/16 17:31:12 by gfezzuog          #+#    #+#              #
#    Updated: 2022/07/16 17:31:12 by gfezzuog         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT	=	client

NAME_SERVER	=	server


SRC_CLIENT	=	client.c

SRC_SERVER	=	server.c


OBJ_CLIENT	=	$(SRC_CLIENT:.c=.o)

OBJ_SERVER	=	$(SRC_SERVER:.c=.o)


CC			=	gcc

RM			=	rm -f

CFLAGS		=	-g -Wall -Wextra -Werror

LIBFOLDER = ft_utils/libftutils.a

all:			$(NAME_CLIENT) $(NAME_SERVER)


$(NAME_CLIENT):	$(OBJ_CLIENT)
				@make all -C ft_utils/
				$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJ_CLIENT) $(LIBFOLDER)
$(NAME_SERVER):	$(OBJ_SERVER)
				@make all -C ft_utils/
				$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJ_SERVER) $(LIBFOLDER)


clean:
				$(RM) $(OBJ_CLIENT) $(OBJ_SERVER)
				@make clean -C ft_utils/
fclean:			clean
				$(RM) $(NAME_CLIENT) $(NAME_SERVER) $(OBJ_CLIENT) $(OBJ_SERVER)
				$(MAKE) fclean -C ft_utils/
re:				fclean all

.PHONY:		all clean fclean re