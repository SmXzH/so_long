NAME			=	so_long

SRCS			=	checks.c so_long.c

OBJS			=	${SRCS:.c=.o}

LD_FLAGS		=	-Llibft -lft

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
					${CC} ${CFLAGS} ${OBJS} ${LD_FLAGS} ${MLX_FLAGS} -o ${NAME}
# chmod 744 so_long

all				:	${NAME}

clean			:
					make clean -C libft
					make clean -C mlx
					@rm -rf ${OBJS}

fclean			:	clean
					make fclean -C libft
					@rm -rf ${NAME}
					@rm -f libmlx.dylib

re				:	fclean all

.PHONY			:	all clean fclean re
