# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npineau <npineau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/08 10:39:32 by npineau           #+#    #+#              #
#    Updated: 2014/05/29 15:30:16 by npineau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	fckoff
PLAY	:=	lemipc
DISPLAY	:=	gfx

### DIRECTORIES ###

DIRSRC	:=	sources
DIRP	:=	$(DIRSRC)/play
DIRDP	:=	$(DIRSRC)/display
DIROBJ	:=	objects
DIRINC	:=	includes
DIRLIB	:=	libft

### FILES ###

SRC

OBJP	:=	$(SRCP:.c=.o)
OBJDP	:=	$(SRDP:.c=.o)

HEADP	:=	$(PLAY).h
HEADDP	:=	$(DISPLAY).h
LIB		:=	libft.a

### PATHS ###

POBJP		:=	$(addprefix $(DIROBJ)/, $(OBJP))
POBJDP		:=	$(addprefix $(DIROBJ)/, $(OBJDP))
PHEADP		:=	$(DIRINC)/$(HEADP)
PHEADDP		:=	$(DIRINC)/$(HEADDP)
PLIB		:=	$(DIRLIB)/$(LIB)

### COMPILATION VARIABLES ###

CC		:=	llvm-gcc
C_FLAG	:=	-Wall -Wextra -Werror
O_FLAG	:=	-O3
L_FLAG	:=	-L $(DIRLIB) -lft
C_INC	:=	-I $(DIRINC) -I $(DIRLIB)/$(DIRINC)

COMPIL	=	$(CC) -o $@ -c $< $(C_INC) $(C_FLAG) $(O_FLAG)
LINK	=	$(CC) -o $@ $^ $(L_FLAG)

### RULES ###

.PHONY: all clean fclean re

all: $(PLIB) $(SERVEUR) $(CLIENT)

### LIBFT ###

$(PLIB):
	make -C $(DIRLIB)

### OBJECTS ###

$(DIROBJ):
	mkdir $(DIROBJ)

$(POBJSRV): |$(DIROBJ)

$(POBJCLI): |$(DIROBJ)

$(DIROBJ)/%.o: $(DIRP)/%.c $(PHEADP)
	$(COMPIL)

$(DIROBJ)/%.o: $(DIRDP)/%.c $(PHEADDP)
	$(COMPIL)

### EXECUTABLE ###

$(NAME):
	echo $(NAME)

$(PLAY): $(POBJP)
	$(LINK)

$(DISPLAY): $(POBJDP)
	$(LINK)

### CLEAN UP ###

clean:
	rm -rf $(DIROBJ)

fclean: clean
	rm -f $(PLAY) $(DISPLAY)

re: fclean all
