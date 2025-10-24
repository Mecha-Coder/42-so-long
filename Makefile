#==============================================================
# DECLARATION
#==============================================================

NAME = so_long
CC = gcc
CFLAG = -Wall -Wextra -Werror
RM = rm -f
MLX_DIR = ./mlx

GNL_DIR = ./get_next_line
GNL_LIB = $(GNL_DIR)/get_next_line.a

#==============================================================
# CHECK OS
#==============================================================

ifeq ($(shell uname), Linux)
	INCLUDE = -I/usr/include -Imlx
	MLX_FLAG = -Lmlx -lmlx_Linux -L/usr/lib/X11 -lXext -lX11
else
	INCLUDE = -Imlx
	MLX_FLAG = -lmlx -framework OpenGL -framework AppKit
endif

#==============================================================
# FILES
#==============================================================

C_SRC = $(wildcard ./utils/*.c) \
	$(wildcard ./game/*.c) \
	$(wildcard ./check/*.c)

C_BONUS =  $(wildcard ./bonus/*.c)
C_MANDATORY =  $(wildcard ./mandatory/*.c)

OBJ= $(C_MANDATORY:%.c=%.o) \
	$(C_SRC:%.c=%.o)

OBJ_BONUS = $(C_BONUS:%.c=%.o) \
	$(C_SRC:%.c=%.o)

#==============================================================
# BUILD COMMAND
#==============================================================

all: lib $(NAME) clean

bonus: lib mkbonus clean

%.o: %.c
	$(CC) $(CFLAG) -c $< -o $@ $(INCLUDE)

$(NAME): $(OBJ)
	$(CC) $(CFLAG) -o $@ $^ $(MLX_FLAG) $(GNL_LIB)

mkbonus: $(OBJ_BONUS) 
	$(CC) $(CFLAG) -o $(NAME) $^ $(MLX_FLAG) $(GNL_LIB)

lib:
	make -C $(GNL_DIR) all

clean:
	$(RM) $(OBJ) $(OBJ_BONUS)
	
fclean: clean
	$(RM) $(NAME)
	make -C $(GNL_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus mkbonus