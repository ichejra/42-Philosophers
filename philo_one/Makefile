# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/06 16:05:28 by ichejra           #+#    #+#              #
#    Updated: 2021/02/20 10:52:27 by ichejra          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_utils.c exit.c set_msg.c init.c status.c check_args.c

CFLAGS = -Wall -Wextra -Werror

LIBS = -lpthread

NAME = philo_one

MAIN = philo_one.c

all: $(NAME)

$(NAME):	$(MAIN) $(SRCS)
			@gcc $(MAIN) $(CFLAGS) $(SRCS) $(LIBS) -o $(NAME)
			@echo "SUCCESS!"

clean:
		@rm -rf *.o

fclean:	clean
		@rm -rf $(NAME)

re:	fclean all
