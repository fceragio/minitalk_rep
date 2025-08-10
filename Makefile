#Makefile#

NAME = server client

NAME_S = server

NAME_C = client

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS_S = main_server.c \
	f_strings.c

SRCS_C = main_client.c \
	f_strings.c

OBJS_S = $(SRCS_S:.c=.o)

OBJS_C = $(SRCS_C:.c=.o)

COLOR_GREEN=\033[0;32m
COLOR_END=\033[0m

all: $(NAME_S) $(NAME_C)

$(NAME_S): $(OBJS_S)
	$(CC) $(OBJS_S) -o $(NAME_S)
	@echo "$(COLOR_GREEN)$(NAME_S) created.✅$(COLOR_END)"

$(NAME_C): $(OBJS_C)
	$(CC) $(OBJS_C) -o $(NAME_C)
	@echo "$(COLOR_GREEN)$(NAME_C) created.✅$(COLOR_END)"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS_S) & $(RM) $(OBJS_C)

fclean: clean
	$(RM) $(NAME_S) & $(RM) $(NAME_C)
	@echo "$(COLOR_GREEN)$(NAME_S) & $(NAME_C) cleaned.✅$(COLOR_END)"

re: fclean all

.PHONY: all clean fclean re bonus