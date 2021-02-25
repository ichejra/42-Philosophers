# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/19 10:25:37 by ichejra           #+#    #+#              #
#    Updated: 2021/02/20 17:55:27 by ichejra          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_utils.c exit.c set_msg.c init.c status.c check_args.c ft_itoa.c

# OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

LIBS = -lpthread

NAME = philo_two

MAIN = philo_two.c

all: $(NAME)

$(NAME):	$(MAIN) $(SRCS)
			@gcc $(MAIN) $(CFLAGS) $(SRCS) $(LIBS) -o $(NAME)
			@echo "SUCCESS!"

# %.o: %.c
# 	@gcc -c -Wall -Wextra -Werror $< -o $@

clean:
		@rm -rf *.o

fclean:	clean
		@rm -rf $(NAME)

re:	fclean all
