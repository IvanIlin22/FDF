# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: whumfrey <marvin@42.fr>		              +#+  +:+       +#+       #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/12 20:29:33 by whumfrey          #+#    #+#              #
#    Updated: 2019/04/20 17:21:48 by whumfrey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c read.c rotate.c tool.c hook.c draw.c defination.c color.c
OBJ = $(SRC:.c=.o)
MLX = -L $(MLXDIR) -lmlx -framework OpenGL -framework Appkit

SRCDIR = srcs
OBJDIR = objs
LIBDIR = libs/libft
MLXDIR = libs/minilibx_macos

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(OBJ))
LIBS = $(LIBDIR)/libft.a $(MLX)
HEADER = -I includes -I $(LIBDIR)/includes -I $(MLXDIR)

CC = gcc
CFLAGS = -c

NAME = fdf

.PHONY: all clean fclean re
.SUFFIXES: .c .o

all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -I includes -I $(LIBDIR) -I $(MLXDIR) $< -o $@

$(NAME): $(OBJS)
	@make -C $(MLXDIR)
	@make -C $(LIBDIR)
	@$(CC) $(OBJS) $(LIBS) -o $@

clean:
	@/bin/rm -rf $(OBJDIR)
	@make -C $(MLXDIR) clean
	@make -C $(LIBDIR) clean

fclean: clean
	@/bin/rm -f $(NAME)
	@rm -f $(LIBDIR)/libft.a

re: fclean all
