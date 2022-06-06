NAME			=	so_long

SRCS			=	checks.c so_long.c loadmap.c get_next_line.c get_next_line_utils.c player_move.c utilits.c movement.c move_utils.c

OBJS			=	${SRCS:.c=.o}

LD_FLAGS		=	-Llibft -lft ft_printf/ft_printf

MLX_FLAGS		=	-Lmlx -lmlx

# HEAD			=	-I includes -I libft -I mlx

CC				=	gcc

CFLAGS			=	-Wall -Werror -Wextra #-fsanitize=address

# MLXA			=	./mlx/libmlx.dylib

.c.o			:
					${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME)			:	${OBJS}
					make -C libft
					make -C mlx
					make -C ft_printf
					${CC} ${CFLAGS} ${OBJS} ${LD_FLAGS} -framework OpenGL -framework AppKit ${MLX_FLAGS} -o ${NAME}
# chmod 744 so_long

all				:	${NAME}

clean			:
					make clean -C libft
					make clean -C mlx
					make clean -C ft_printf
					@rm -rf ${OBJS}

fclean			:	clean
					make fclean -C ft_printf
					make fclean -C libft
					@rm -rf ${NAME}
					@rm -f libmlx.dylib

re				:	fclean all

.PHONY			:	all clean fclean re
