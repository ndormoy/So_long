CC =				clang
NAME	=			so_long
SRCS_NAME =			mandatory/parsing.c \
					mandatory/tab2d_utils.c \
					mandatory/check.c \
					mandatory/check2.c \
					mandatory/main.c \
					mandatory/ft_init_map.c \
					mandatory/moves.c \
					mandatory/ft_error.c \
					mandatory/ft_display_map.c \
					mandatory/my_key.c
SRCS =				$(addprefix $(SRCS_PATH)/, $(SRCS_NAME))

SRCS_PATH =			srcs
INC_NAME =			so_long.h
INC =				$(addprefix $(INC_PATH)/, $(INC_NAME))
INC_PATH =			includes
INC_PATH_LIBFT = 	includes/libft/includes
RM =				rm -rf
OBJ =				$(SRCS:.c=.o)
CFLAG =				-Wall -Wextra -Werror
INCFLAGS =			-I$(INC_PATH_LIBFT) -I$(INC_PATH) -Imlx
LIBFT =				includes/libft/libft.a
LIBFT_PATH =		includes/libft

bonus	=			so_long_bonus
SRCS_BONUS_NAME =	mandatory/parsing.c \
					mandatory/tab2d_utils.c \
					mandatory/check.c \
					mandatory/check2.c \
					mandatory/ft_error.c \
					bonus/moves_bonus.c \
					bonus/main_bonus.c \
					bonus/my_key_bonus.c \
					bonus/ft_display_map_bonus.c \
					bonus/ft_init_map_bonus.c \
					bonus/ft_enemy.c
SRCS_BONUS =		$(addprefix $(SRCS_PATH)/, $(SRCS_BONUS_NAME))
SRCS_BONUS_PATH =	srcs
OBJ_BONUS =			$(SRCS_BONUS:.c=.o)

all :				 $(NAME) $(bonus)

%.o : %.c
					@$(CC) $(CFLAG) $(INCFLAGS) -c $< -o $@

$(NAME) : 			$(OBJ) $(INC)
					@make -C $(LIBFT_PATH) >/dev/null
					@$(CC) -I /usr/local/include -o $@ $(OBJ) $(LIBFT) -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

$(bonus) :			$(OBJ_BONUS) $(INC)
					@make -C $(LIBFT_PATH) >/dev/null
					@$(CC) -I /usr/local/include -o $@ $(OBJ_BONUS) $(LIBFT) -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

clean :
					make clean -C $(LIBFT_PATH)
					$(RM) $(OBJ) $(OBJ_BONUS)

fclean :			clean
					make fclean -C $(LIBFT_PATH)
					$(RM) $(NAME) $(bonus)

re : 				fclean all

.PHONY : 			all clean fclean re
