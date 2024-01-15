#------------MakeFile------------#
NAME = pipex

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS_DIR = ./src/
SRCS =	pipex.c\
		pipex_main.c\
		pipex_utils.c

OBJS_DIR = ./obj/
OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

all: obj lib $(NAME)

obj:
	mkdir obj

$(OBJS_DIR)%.o:$(SRCS_DIR)%.c
	$(CC) $(CFLAGS) -I ./includes/ -I ./42-libft/ -o $@ -c $< -g

lib: 
	make -C 42-libft/

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L ./42-libft/ -l ft -o $(NAME) -g

clean:
	make clean -C 42-libft/
	rm -rf obj pipex

fclean: clean
	rm -rf $(NAME)
	make fclean -C 42-libft/

re: fclean all

test:
	./pipex src "ls -la" "wc -m" delte
	
.PHONY: all clean fclean re
