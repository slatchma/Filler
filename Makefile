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

EXEC = slatchma.filler
CC = gcc -Wall -Wextra -Werror

all :
	make -C libft/
	make -C filler/
	$(CC) filler/filler.a libft/libft.a -o $(EXEC)

clean :
	make -C libft/ clean
	make -C filler/ clean

fclean : clean
	make -C libft/ fclean
	make -C filler/ fclean
	rm -f $(EXEC)

re : fclean all
