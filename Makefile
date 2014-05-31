# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npineau <npineau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/08 10:39:32 by npineau           #+#    #+#              #
#    Updated: 2014/05/31 17:19:26 by npineau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	lemipc

### DIRECTORIES ###

DIRSRC	:=	sources
DIRP	:=	$(DIRSRC)/play
DIRU	:=	$(DIRSRC)/utility
DIRDP	:=	$(DIRSRC)/display
DIROBJ	:=	objects
DIRINC	:=	includes
DIRLIB	:=	libft

### FILES ###

SRCU	:=	x.c \
			shared_memory.c \
			semaphore.c \
			message_queue.c \
			clean_up.c \
			get_options.c

SRCP	:=	main.c \
			play.c

SRCDP	:=	mlx.c

OBJU	:=	$(SRCU:.c=.o)
OBJP	:=	$(SRCP:.c=.o)
OBJDP	:=	$(SRCDP:.c=.o)

HEADP	:=	$(NAME).h
LIB		:=	libft.a

### PATHS ###

POBJU		:=	$(addprefix $(DIROBJ)/, $(OBJU))
POBJP		:=	$(addprefix $(DIROBJ)/, $(OBJP))
POBJDP		:=	$(addprefix $(DIROBJ)/, $(OBJDP))
PHEADP		:=	$(DIRINC)/$(HEADP)
PLIB		:=	$(DIRLIB)/$(LIB)

### COMPILATION VARIABLES ###

CC		:=	llvm-gcc
C_FLAG	:=	-Wall -Wextra -Werror
O_FLAG	:=	-O3
L_FLAG	:=	-L $(DIRLIB) -lft -L /usr/X11/lib -lmlx -lX11 -lXext
C_INC	:=	-I $(DIRINC) -I $(DIRLIB)/$(DIRINC)

COMPIL	=	$(CC) -o $@ -c $< $(C_INC) $(C_FLAG) $(O_FLAG)
LINK	=	$(CC) -o $@ $^ $(L_FLAG)

### RULES ###

.PHONY: all clean fclean re

all: $(PLIB) $(NAME)

### LIBFT ###

$(PLIB):
	make -C $(DIRLIB)

### OBJECTS ###

$(DIROBJ):
	mkdir $(DIROBJ)

$(POBJU): |$(DIROBJ)

$(POBJP): |$(DIROBJ)

$(POBJDP): |$(DIROBJ)

$(DIROBJ)/%.o: $(DIRU)/%.c $(PHEADP)
	$(COMPIL)

$(DIROBJ)/%.o: $(DIRP)/%.c $(PHEADP)
	$(COMPIL)

$(DIROBJ)/%.o: $(DIRDP)/%.c $(PHEADP)
	$(COMPIL)

### EXECUTABLE ###

$(NAME): $(POBJDP) $(POBJP) $(POBJU)
	$(LINK)

### CLEAN UP ###

clean:
	rm -rf $(DIROBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
