# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itekir <itekir@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 23:05:02 by itekir            #+#    #+#              #
#    Updated: 2023/02/18 00:14:48 by itekir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	  =	ft_hexdecimal.c ft_print_pointer.c ft_print_unsigned.c \
			ft_printer.c ft_printf.c 

OBJS		= $(SRCS:.c=.o)
					
NAME		= libftprintf.a

CC			= cc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror

COLOUR_END	=\033[0m
GREEN		= \033[0;92m

${NAME}: 		$(OBJS)
				@ar -rcs $(NAME) $(OBJS)
				@echo "$(GREEN)object files sucsesflly created.$(COLOUR_END)"

all: 			${NAME}

clean:
				@$(RM) $(OBJS) 
				@echo "$(GREEN)object files are cleaned.$(COLOUR_END)"
fclean:			clean
				@$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re bonus
