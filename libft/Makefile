# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddo-carm <ddo-carm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/25 12:13:34 by ddo-carm          #+#    #+#              #
#    Updated: 2024/11/05 16:05:51 by ddo-carm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#		   ________________________________________________        
#  _______|                                               |_______
# \       |                 NAMES & PATHS                 |      /
#  \      |                                               |     /
#  /      |_______________________________________________|     \ 
# /__________)                                        (__________\ 


NAME = libft.a
SRCS_D = .
HEADER = $(SRCS_D)/libft.h

#source files
SRC = $(SRCS_D)/ft_isalpha.c \
	$(SRCS_D)/ft_isdigit.c \
	$(SRCS_D)/ft_isalnum.c \
	$(SRCS_D)/ft_isascii.c \
	$(SRCS_D)/ft_isprint.c \
	$(SRCS_D)/ft_strlen.c \
	$(SRCS_D)/ft_memset.c \
	$(SRCS_D)/ft_bzero.c \
	$(SRCS_D)/ft_memcpy.c \
	$(SRCS_D)/ft_memmove.c \
	$(SRCS_D)/ft_strlcpy.c \
	$(SRCS_D)/ft_strlcat.c \
	$(SRCS_D)/ft_toupper.c \
	$(SRCS_D)/ft_tolower.c \
	$(SRCS_D)/ft_strchr.c \
	$(SRCS_D)/ft_strrchr.c \
	$(SRCS_D)/ft_strncmp.c \
	$(SRCS_D)/ft_memchr.c \
	$(SRCS_D)/ft_memcmp.c \
	$(SRCS_D)/ft_strnstr.c \
	$(SRCS_D)/ft_atoi.c \
	$(SRCS_D)/ft_calloc.c \
	$(SRCS_D)/ft_strdup.c \
	$(SRCS_D)/ft_substr.c \
	$(SRCS_D)/ft_strjoin.c \
	$(SRCS_D)/ft_itoa.c \
	$(SRCS_D)/ft_strmapi.c \
	$(SRCS_D)/ft_striteri.c \
	$(SRCS_D)/ft_putchar_fd.c \
	$(SRCS_D)/ft_putstr_fd.c \
	$(SRCS_D)/ft_putendl_fd.c \
	$(SRCS_D)/ft_putnbr_fd.c \
	$(SRCS_D)/ft_strtrim.c \
	$(SRCS_D)/ft_split.c \
	$(SRCS_D)/free_arrays.c \
	$(SRCS_D)/free_matrix.c \

BONUS_SRC = $(SRCS_D)/ft_lstnew_bonus.c \
			$(SRCS_D)/ft_lstadd_front_bonus.c \
			$(SRCS_D)/ft_lstsize_bonus.c \
			$(SRCS_D)/ft_lstlast_bonus.c \
			$(SRCS_D)/ft_lstadd_back_bonus.c \
			$(SRCS_D)/ft_lstdelone_bonus.c \
			$(SRCS_D)/ft_lstclear_bonus.c \
			$(SRCS_D)/ft_lstiter_bonus.c \
			$(SRCS_D)/ft_lstmap_bonus.c 

FTPRINTF_SRC = $(SRCS_D)/ft_printf.c \
			$(SRCS_D)/ft_printf_utils.c \
			$(SRCS_D)/ft_hex_utils.c

GNL_SRC = $(SRCS_D)/get_next_line.c \
		$(SRCS_D)/get_next_line_utils.c \
		$(SRCS_D)/get_next_line_bonus.c \
		$(SRCS_D)/get_next_line_utils_bonus.c

#object files
OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)
FTPRINTF_OBJ = $(FTPRINTF_SRC:.c=.o)
GNL_OBJ = $(GNL_SRC:.c=.o)

#		   ________________________________________________
#  _______|                                               |_______
# \       |                FLAGS & COMMANDS               |      /
#  \      |                                               |     /
#  /      |_______________________________________________|     \ 
# /__________)                                        (__________\ 

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs

#          ________________________________________________
# ________|                                               |_______
# \       |                    LIB RULES                  |      /
#  \      |                                               |     /
#  /      |_______________________________________________|     \ 
# /__________)                                        (__________\ 


all: $(NAME)

#compile the lib
$(NAME): $(OBJ) $(BONUS_OBJ) $(FTPRINTF_OBJ) $(GNL_OBJ)
	$(AR) $(NAME) $(OBJ) $(BONUS_OBJ) $(FTPRINTF_OBJ) $(GNL_OBJ)
	@echo "$(BGRN)✨Compilation completed✨"

#compile .o files
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(BMAG)Compiling..."

#          ________________________________________________
# ________|                                               |_______
# \       |                  CLEAN RULES                  |      /
#  \      |                                               |     /
#  /      |_______________________________________________|     \ 
# /__________)                                        (__________\ 

#remove .o
clean:
	$(RM) $(OBJ) $(BONUS_OBJ) $(FTPRINTF_OBJ) $(GNL_OBJ)
	@echo "$(BMAG)✨Objects removed $(BGRN)successfully✨"


#clean and remove
fclean: clean
	$(RM) $(NAME)
	@echo "$(BMAG)✨Program removed $(BGRN)successfully✨"
	
#remake
re: fclean all
	@echo "$(BMAG)✨Re-compile was $(BGRN)successfull✨"

#          ________________________________________________
# ________|                                               |_______
# \       |                  HELP RULES                   |      /
#  \      |                                               |     /
#  /      |_______________________________________________|     \ 
# /__________)                                        (__________\ 

#help
help:
	@echo "✳$(BMAG) make  $(BWHI)    -> $(BMAG)compiles the lib"

	@echo "$(BWHI)✳$(BMAG) clean    $(BWHI) -> $(BMAG)removes all objects"
	@echo "$(BWHI)✳$(BMAG) fclean    $(BWHI)-> $(BMAG)removes all objects plus the program"
	@echo "$(BWHI)✳$(BMAG) re        $(BWHI)-> $(BMAG)removes all objects plus the program and recompiles the lib"

#Phony targets to avoid clashes
.PHONY: all clean fclean re

#          ________________________________________________
# ________|                                               |_______
# \       |                    COLORS                     |      /
#  \      |                                               |     /
#  /      |_______________________________________________|     \ 
# /__________)                                        (__________\ 

#color list for foreground
#bash -c 'for c in {0..255}; do tput setaf $c; tput setaf $c | cat -v; echo =$c; done'

BLA		:= $(echo "u001b[30m")
RED		:= $(echo "\u001b[31m")
GRN		:= $(echo "\u001b[32m")
YEL		:= $(echo "\u001b[33m")
BLU		:= $(echo "\u001b[34m")
MAG		:= $(echo "\u001b[35m")
CYA		:= $(echo "\u001b[36m")
WHI		:= $(echo "\u001b[37m")
GRE		:= $(echo "\u001b[0m")
BBLA	:= $(echo "\u001b[30;1m")
BRED 	:= $(echo "\u001b[31;1m")
BGRN	:= $(echo "\u001b[32;1m")
BYEL	:= $(echo "\u001b[33;1m")
BBLU	:= $(echo "\u001b[34;1m")
BMAG	:= $(echo "\u001b[35;1m")
BCYA	:= $(echo "\u001b[36;1m")
BWHI	:= $(echo "\u001b[37;1m")
Reset	:= $(echo "\u001b[0m")
