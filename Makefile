NAME_S = listener
NAME_C = speaker
CC = cc
CFLAGS = -Wall -Wextra -Werror

PRINTF_DIR = ft_printf
PRINTF = $(PRINTF_DIR)/ft_printf.a

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS_S = listener.c
SRCS_C = speaker.c

all: $(LIBFT) $(PRINTF) $(NAME_S) $(NAME_C)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(PRINTF):
	@make -C $(PRINTF_DIR)

$(NAME_S): $(SRCS_S) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(SRCS_S) $(LIBFT) $(PRINTF) -o $(NAME_S)

$(NAME_C): $(SRCS_C) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(SRCS_C) $(LIBFT) $(PRINTF) -o $(NAME_C)

clean:
	@make -C $(LIBFT_DIR) clean
	@make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME_S) $(NAME_C)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re