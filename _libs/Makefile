# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tmercier <tmercier@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/11/27 21:50:52 by tmercier      #+#    #+#                  #
#    Updated: 2022/12/01 22:22:40 by tmercier      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# ----------------- FILES #
SRCS 		=		get_next_line/get_next_line.c libft/ft_printf/char_conversion.c \
					libft/ft_printf/ft_printf.c libft/ft_printf/num_conversion.c \
					libft/check_bool.c libft/check_case.c libft/check_char.c libft/compare.c \
					libft/convert_char.c libft/convert_num.c libft/convert_str.c \
					libft/copy.c libft/errors.c libft/free.c libft/join.c libft/length.c \
					libft/memory.c libft/put_.c libft/search.c libft/split.c \
					libft/strings_iter.c libft/ternaries.c \
					vectors/v0.c vectors/v1.c vectors/v2.c vectors/v3.c\
					linkedlist/llc_add.c linkedlist/llc_create.c linkedlist/llc_remove.c \
					linkedlist/llc_utils.c linkedlist/lls_add.c linkedlist/lls_create.c \
					linkedlist/lls_remove.c linkedlist/lls_utils.c
ifdef MLX
SRCS		+=		graphic/arbitrary_rotation.c graphic/bresenham.c graphic/colors.c \
                    graphic/matrices.c graphic/perspectives.c graphic/utils.c
endif

LIB42		=		lib42.a
LIB42MLX	=		lib42mlx.a
HDRS 		= 		inc/lib42.h inc/libft.h inc/vectors.h inc/linkedlist.h inc/storage_classes.h
ifdef MLX
HDRS		+=		inc/graphic.h
endif

# ----------------- DIRECTORIES #
OBJ_DIR		=		obj
BIN_DIR		=		bin
MLX_DIR		=		graphic/MLX42

# ----------------- CC #
CC			= 		gcc

# ----------------- COMPILER FLAGS #
CFLAGS 		=		-Iinc -I graphic/MLX42/include -Wall -Wextra
ifdef DEBUG
CFLAGS		+=		-g3 -fsanitize=address
endif
ifndef DEV
CFLAGS 		+=		-Werror
endif

# ----------------- EXTERNAL LIBS #
MLX42		=		graphic/MLX42/libmlx42.a

# ----------------- OBJECTS #
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# ----------------- TARGETS #

NAME = $(LIB42)
ifdef MLX
NAME += $(LIB42MLX)
endif

all: $(NAME)

$(OBJ_DIR)/%.o: %.c $(HDRS)
	@mkdir -p $(@D)
	@printf "$(CYAN)Compiling: $(RESET)$(notdir $<)\n"
	@$(CC) -o $@ -c $< $(CFLAGS)

$(LIB42): $(OBJS)
	@ar rc $@ $^
	@printf "\n$(CYAN)-> $(LIB42) archive created ✔️\n\n$(RESET)"

$(LIB42MLX): $(OBJS)
	@make -C $(MLX_DIR)
	@mv $(MLX42) $(LIB42MLX)
	@ar rcs $(LIB42MLX) $(OBJS)
	@printf "$(CYAN)-> $(LIB42) & mlx42.a archives merged successfully ✔️\n$(RESET)"

# ----------------- MISC #
norm:
	norminette ./**/**/{*.c,*.h}
	norminette inc/*.h

# ----------------- CLEANING #
clean:
	@if [ -d $(OBJ_DIR) ]; then rm -rf $(OBJ_DIR) && \
		printf "$(GREEN)\n-> lib42/obj cleaned\n$(RESET)"; \
		else printf "$(GREEN)\n-> lib42/obj already cleaned\n$(RESET)"; fi

fclean: clean
	@rm -rf $(LIB42) $(LIB42MLX)

cleanmlx:
	@$(MAKE) clean -C $(MLX_DIR)
	@printf "$(RED)-> mlx42 objects files\n $(RESET)"
	@$(MAKE) fclean -C $(MLX_DIR)
	@printf "$(RED)-> mlx42 archive\n $(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all

signature:
	@printf \
	"+---------------------+ © tmercier@student.codam.nl +\n\n$(RESET)"

.PHONY: clean fclean re graphic

# ----------------------------------- colors --------------------------------- #

BOLD	:= \033[1m
BLACK	:= \033[30;1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
BLUE	:= \033[34;1m
MAGENTA	:= \033[35;1m
CYAN	:= \033[36;1m
WHITE	:= \033[37;1m
RESET	:= \033[0m


################### BUILDING LIBRARIES PROCESS

# 'ar rc' creates a static library named 'libft.a' and puts copies
# of the object files in it. If the library file already exists, it has
# the object files added to it, or replaced, if they are newer than
# those inside the library.
# The 'c' flag tells ar to create the library if it doesn't already exist.
# The 'r' flag tells it to replace older object files in the library,
# with the new object files.

# After an archive is created, or modified, there is a need to index it.
# This index is later used by the compiler to speed up symbol-lookup
# inside the library, and to make sure that the order of the symbols
# in the library won't matter during compilation.
# The command used to create or update the index is called 'ranlib'.