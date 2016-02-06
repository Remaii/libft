#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2015/12/11 10:05:45 by rthidet           #+#    #+#             *#
#*   Updated: 2016/02/06 12:12:29 by rthidet          ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME = libft.a
LIBS =-L ./ -lft
RACINE = ../
HPATH = -I ../include/

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
		ft_strtrim.c ft_tolower.c ft_toupper.c ft_lstmap.c ft_lstprint_fd.c\

# STANDARD VARIABLES
CC = gcc -Wall -Wextra -Werror
AR = ar rc
RM = rm -rf
SRCDIR = ./
OBJDIR = object
OBJ = $(addprefix ./$(OBJDIR)/, $(SRC:.c=.o))

# COLORS
RESET=\033[0m
DARK=\033[132m
RED=\033[31m
GREEN=\033[32m
YELLOW=\033[33m
BLUE=\033[34m
MAGENTA=\033[35m
CYAN=\033[36m

# START RULES
all: $(NAME)

$(NAME):
	@echo "$(RESET)$(MAGENTA)Building src to obj...$(RESET)"
	@$(CC) -c $(SRCDIR)$(SRC) $(HPATH)
	@echo "$(RESET)$(MAGENTA)Create Object folder and move all .o in folder"
	@mkdir -p $(OBJDIR) && mv $(SRC:.c=.o) ./$(OBJDIR)/
	@echo "$(RESET)$(MAGENTA)Linking obj files to libft.a...$(RESET)"
	@$(AR) $(NAME) $(OBJ)
	@echo "$(CYAN)Execute ranlib on $(NAME)$(RESET)"
	@ranlib $(NAME)
	@echo "$(CYAN)\tLIBFT.A SUCCESS$(RESET)"
#	@mv $(NAME) $(RACINE)

clean:
	@echo "$(MAGENTA)Removal Object folder...$(RESET)"
	@$(RM) $(OBJDIR)

fclean: clean
	@echo "$(MAGENTA)Removal $(NAME)"
	@$(RM) $(NAME)
#	@$(RM) ../$(NAME)

re: fclean all

.PHONY: all clean fclean re
