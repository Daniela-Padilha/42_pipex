# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/27 17:07:50 by ddo-carm          #+#    #+#              #
#    Updated: 2024/12/27 17:07:50 by ddo-carm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#		   ________________________________________________        
#  _______|                                               |_______
# \       |                 NAMES & PATHS                 |      /
#  \      |                                               |     /
#  /      |_______________________________________________|     \ 
# /__________)                                        (__________\ 



NAME = pipex.a
TEST_NAME = pipex_test.a
LIBFT_D = libft
LIBFT = $(LIBFT_D)/libft.a
SRCS_D = .
HEADERS = .

#source files
SRC = $(SRCS_D)/ft_printf.c \
		$(SRCS_D)/ft_printf_utils.c \
		$(SRCS_D)/ft_hex_utils.c

MAIN = $(SRCS_D)/main.c

#object files
# OBJ = $(SRC:.c=.o)

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


all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_D)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@echo "$(BGRN)✨Compilation completed✨"

%.o: %.c $(HEADERS) $(LIBFT)
	@$(CC) $(CFLAGS) -c $< -o $@ -L$(LIBFT_D) -lft
	@echo "$(BMAG)Compiling..."

#          ________________________________________________
# ________|                                               |_______
# \       |                   TEST RULES                  |      /
#  \      |                                               |     /
#  /      |_______________________________________________|     \ 
# /__________)                                        (__________\ 

#TESTING
test: all
	@$(CC) $(CFLAGS) $(MAIN) $(SRC) -o $(TEST_NAME)
	@echo "$(BGRN)$(TEST_NAME) created successfully"
	@./$(TEST_NAME)
	@echo "$(BGRN)✨Test completed✨"

cleantest:
	@$(RM) $(OBJ_MAIN) $(TEST_NAME)
	@echo "$(BMAG)✨$(TEST_NAME) was removed✨"

retest: cleantest test
	@echo "$(BMAG)✨Retest was $(BGRN)successfull✨"


#          ________________________________________________
# ________|                                               |_______
# \       |                  CLEAN RULES                  |      /
#  \      |                                               |     /
#  /      |_______________________________________________|     \ 
# /__________)                                        (__________\ 

#remove .o
clean:
	@$(RM) $(OBJ)
	@make clean -C $(LIBFT_D)
	@echo "$(BMAG)✨Objects removed $(BGRN)successfully✨"

#clean and remove
fclean: clean cleantest
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT_D)
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
	@echo "$(BWHI)✳$(BMAG) test      $(BWHI)-> $(BMAG)compiles the lib with the main"
	@echo "$(BWHI)✳$(BMAG) clean    $(BWHI) -> $(BMAG)removes all objects"
	@echo "$(BWHI)✳$(BMAG) fclean    $(BWHI)-> $(BMAG)removes all objects plus the program"
	@echo "$(BWHI)✳$(BMAG) re        $(BWHI)-> $(BMAG)removes all objects plus the program and recompiles the lib"
	@echo "$(BWHI)✳$(BMAG) cleantest $(BWHI)-> $(BMAG)removes all test files"
	@echo "$(BWHI)✳$(BMAG) retest    $(BWHI)-> $(BMAG)removes test files and recompiles"

#Phony targets to avoid clashes
.PHONY: all clean fclean re help test cleantest retest

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
