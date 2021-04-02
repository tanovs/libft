# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atable <atable@student.school-21.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/19 20:09:43 by atable            #+#    #+#              #
#    Updated: 2020/05/25 19:07:15 by atable           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

HDR = libft.h

SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c\
	  ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c\
	  ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c\
	  ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c\
	  ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c\
	  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

OBJ = $(SRC:.c=.o)

BONUS_SRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstmap.c ft_lstiter.c

BONUS_OBJ = $(BONUS_SRC:.c=.o)

ifdef WITH_BONUS
	OBJ_FILES = $(OBJ) $(BONUS_OBJ)
else
	OBJ_FILES = $(OBJ)
endif

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@ar rc $(NAME) $(OBJ_FILES)
	@ranlib $(NAME)

%.o: %.c $(HDR)
	@gcc $(FLAGS) -c $< -o $@

bonus:
	$(MAKE) WITH_BONUS=1 all

clean:
	@rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
