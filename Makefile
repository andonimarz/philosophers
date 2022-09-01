# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/30 15:52:13 by amarzana          #+#    #+#              #
#    Updated: 2022/09/01 14:23:42 by amarzana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3 #-fsanitize=address
OBJ = $(SRC:.c=.o)
SRC_DIR = src

GREEN 	= "\\x1b[32m"
RED 	= "\\x1b[31m"
RESET 	= "\\x1b[37m"

SRC = 	$(SRC_DIR)/ft_philo.c						\
		$(SRC_DIR)/ft_checks.c						\
		$(SRC_DIR)/ft_sleep.c						\
		$(SRC_DIR)/libft.c

.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	echo $(GREEN)Compiling philo$(RESET)
	${CC} ${CFLAGS} $(OBJ) -o $(NAME)
	echo $(GREEN)Mandatory: Compilation done!$(RESET)

clean:
	rm -f $(OBJ)
	echo $(RED)Object files removed$(RESET)

fclean: clean
	rm -f $(NAME)
	echo $(RED)Executable file removed$(RESET)

re: fclean all

.PHONY: all clean fclean re