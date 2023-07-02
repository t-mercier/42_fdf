# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tmercier <tmercier@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/12/02 17:13:26 by tmercier      #+#    #+#                  #
#    Updated: 2023/05/01 14:18:07 by tmercier      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #



LIB			=		_libs
INC			=		-I_libs/inc -Iinc -I_libs/graphic/MLX42/include/MLX42
SRCS		=		_fdf_main.c colors_1.c colors_2.c input.c lines.c \
					key_hooks.c loop_hooks.c rotation.c usage.c utils.c
OBJS		=		$(addprefix out/, $(SRCS:.c=.o))
BIN			=		fdf
CC			=		cc
EXTRAS		=		-lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
ifdef HOME
EXTRAS		=		-lglfw -framework Cocoa -framework OpenGL -framework IOKit
endif
LFLAGS		=		-lm -lpthread -Wl
CFLAGS 		+= 		-Ofast $(INC) -Wall -Wextra
ifdef DEBUG
CFLAGS		+=		-g3 -fsanitize=address
endif
ifndef DEV
CFLAGS		+=		-Werror
endif

$(shell mkdir -p out)

all: $(BIN)

$(BIN): $(OBJS) _libs/lib42mlx.a
	@$(CC) $(CFLAGS) $(EXTRAS) -o $@ $^ $(LFLAGS)
	@make signature

out/%.o: _src/%.c 
	@printf "$(GREEN)Compiling: $(RESET)$(notdir $<)\n"
	$(CC) $(CFLAGS)  $(INC) -c -o $@ $<

_libs/lib42mlx.a:
	MLX=1 $(MAKE) -C _libs

clean:
	$(MAKE) -C _libs clean
	rm -rf $(OBJS)

fclean: clean
	$(MAKE) -C _libs fclean
	rm -rf $(BIN)

re: fclean all

cleanlib:
	@make fclean -C _libs

signature:
			@printf \
	"\n$(LIGHT_CYAN)+---------------------+ © tmercier@student.codam.nl +\n\n$(RESET)"

.PHONY: fclean re test clean apple_valgrind


GREEN			:=	\033[1;32m
LIGHT_RED		:=	\033[1;31m
LIGHT_CYAN		:=	\033[1;36m
RESET			:= \033[0m
