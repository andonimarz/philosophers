# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/30 15:52:13 by amarzana          #+#    #+#              #
#    Updated: 2022/09/09 19:06:24 by amarzana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3 #-fsanitize=address
OBJ = $(SRC:.c=.o)
SRC_DIR = src

GREEN 	= "\\033[92m"
RED 	= "\\033[31m"
RESET 	= "\\033[0m"

SRC = 	$(SRC_DIR)/ft_philo.c						\
		$(SRC_DIR)/ft_checks.c						\
		$(SRC_DIR)/ft_sleep.c						\
		$(SRC_DIR)/ft_init.c						\
		$(SRC_DIR)/ft_prints.c						\
		$(SRC_DIR)/libft.c

.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	echo $(GREEN)Compiling philo$(RESET)
	${CC} ${CFLAGS} $(OBJ) -o $(NAME)
	echo $(GREEN)Mandatory: Compilation done!$(RESET)

clean:
	rm -rf philo.dSYM
	rm -f $(OBJ)
	echo $(RED)Object files removed$(RESET)

fclean: clean
	rm -f $(NAME)
	echo $(RED)Executable file removed$(RESET)

re: fclean all

.PHONY: all clean fclean re