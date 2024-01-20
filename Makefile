CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -lX11 -lXext
SRCS = drawing_utils.c string_utils.c fractol.c ft_atof.c math_utils.c mlx_utils.c
BSRCS = BONUS/drawing_utils_bonus.c string_utils.c BONUS/fractol_bonus.c ft_atof.c \
		BONUS/math_utils_bonus.c BONUS/mlx_utils_bonus.c
HFILE = fractol.h
BHFILE = fractol_bonus.h
OBJS = ${SRCS:.c=.o}
BOBJS = ${BSRCS:.c=.o}
NAME = fractol
BONUS = fractol_bonus


all: $(NAME)

$(NAME): $(OBJS) $(HFILE)
	$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) -lm -o $@

bonus: $(BONUS)
	@rm -rf $(NAME)
	@cp -rf $< $(NAME)

$(BONUS): $(BOBJS)
	$(CC) $(CFLAGS) $(BOBJS) $(MLXFLAGS) -lm -o $@

%.o: %.c $(HFILE)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(BOBJS)

fclean: clean
	rm -rf $(NAME) $(BONUS)

re: fclean all

.PHONY: re clean fclean all

.SECONDARY: $(OBJS) $(BOBJS)