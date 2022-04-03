NAME				=	fractol

HEAD				=	fractol.h

SRC_MAN				=	main.c\
						actions.c\
						ft_printing.c\
						hook_keys.c\
						utils.c

OBJ					=	$(patsubst %.c,%.o,$(SRC_MAN))

FLAGS				=	-Wall -Werror -Wextra

FRAMEWORK			=	-I MLX/ -L mlx/ -lmlx -framework OpenGL -framework AppKit

.c.o:
		gcc {FLAGS} -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME): $(HEAD)
		make -C MLX/
		gcc $(SRC_MAN) -o $(NAME) $(FLAGS) $(FRAMEWORK)

clean:
	@make -C MLX/ clean
	@rm -f $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re