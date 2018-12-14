# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/03/16 15:32:25 by slatchma     #+#   ##    ##    #+#        #
#    Updated: 2018/04/23 16:56:06 by slatchma    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = filler.a
CC = gcc -Wall -Wextra -Werror
FILES = main algo map other pattern
FILESC = $(addsuffix .c, $(FILES))
FILESO = $(addsuffix .o, $(FILES))

all : $(NAME)

$(NAME) : $(FILESO)
	ar rc $(NAME) $(FILESO)
	ranlib $(NAME)

%.o: %.c
	$(CC) -o $@ -c $?

clean :
	/bin/rm -f $(FILESO)

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all
