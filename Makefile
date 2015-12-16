#******************************************************************************#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2015/12/06 13:02:35 by rthidet           #+#    #+#             *#
#*   Updated: 2015/12/15 20:26:38 by rthidet          ###   ########.fr       *#
#*                                                                            *#
#******************************************************************************#

NAME = libft.a
EXE = test_libft
LIBS =-L./ -lft
TEST = mainqperez42.c

HPATH = -I ./include/

SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c\
		ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c\
		ft_lstiter.c ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c\
		ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memdup.c ft_memmove.c\
		ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c\
		ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c\
		ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c\
		ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c\
		ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c\
		ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c\
		ft_strrchr.c ft_strrev.c ft_strsplit.c ft_strstr.c ft_strsub.c\
		ft_strtrim.c ft_tolower.c ft_toupper.c\

#STANDARD VARIABLES
CC = gcc -Wall -Wextra -Werror
AR = ar -cvq libft.a
RM = rm -rf
SRCDIR = $(addprefix ./src/, $(SRC))
OBJDIR = ./object
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

# COLORS
RESET=\033[0m
DARK=\033[132m
RED=\033[31m
GREEN=\033[32m
YELLOW=\033[33m
BLUE=\033[34m
MAGENTA=\033[35m
CYAN=\033[36m
WHITE=\033[37m
BOLDBLACK=\033[1m\033[30m
BOLDRED=\033[1m\033[31m
BOLDWHITE=\033[1m\033[37m

# START RULES

all:
	@echo "$(RESET)$(GREEN)Building src to obj...$(WHITE)$(RESET)\n"
	@$(CC) -c $(SRCDIR) $(HPATH)
	@echo "$(RESET)$(YELLOW)\nMoving obj files to obj folder...$(RESET)\n"
	@mkdir -p object && mv *.o ./object/
	@echo "$(RED)\nLinking obj files to libft.A ...$(DARK)\n"
	@ar rc $(NAME) $(OBJ)
	@echo "$(CYAN)\nExecute ranlib on libft.a\n$(RESET)"
	@ranlib $(NAME)
	@echo "$(BLUE)\nLIBFT.A SUCESS, OBJ files are $(OBJDIR)/\n\tReady to Make run!...\n$(DARK)"

clean:
	@echo "$(YELLOW)\nRemoval object files at $(OBJDIR)/...\n$(RESET)"
	@$(RM) $(OBJDIR)

fclean: clean
	@echo "$(YELLOW)\nRemoval binary $(EXE) and $(NAME)...\n$(RESET)"
	@$(RM) $(NAME) $(EXE)

re: fclean
	@make all

# Personnal rules
go: run
	@make fclean

run:
	@echo "$(RED)Compiling TEST\n$(RESET)"
	$(CC) -o $(EXE) $(LIBS) $(TEST) $(HPATH)
	@echo "$(YELLOW)\nSTART TEST = $(EXE)\n$(RESET)"
	@./$(EXE)
	@echo "$(GREEN)END TEST\n$(RESET)"

.PHONY: all clean fclean re go
