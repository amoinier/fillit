#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amoinier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/07 12:02:38 by amoinier          #+#    #+#              #
#    Updated: 2016/01/03 15:28:04 by amoinier         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

RED =		\033[31m
GRE =		\033[32m
YEL =		\033[33m
BLU =		\033[34m
CYA =		\033[36m
STD =		\033[39m

NAME =		fillit

IDIR =		./incs/
INCS =		$(shell ls incs/)
INCC =		$(addprefix $(IDIR),$(INCS))

SDIR =		./srcs/
SRCS =		$(shell ls srcs/)
SRCC =		$(addprefix $(SDIR),$(SRCS))

ODIR =		./objs/
OBJS =		$(SRCS:.c=.o)
OBCC =		$(addprefix $(ODIR),$(OBJS))

NORM =		$(SRCC) $(INCC) $(EXEC)

FLAG =		-Wall -Wextra -Werror -I$(IDIR)

all: $(NAME) end

$(NAME): header $(OBCC)
	@echo "  ${BLU}+ Compilation program:${STD} $@"
	@gcc $(FLAG) $(OBCC) -o $(NAME)

$(ODIR)%.o: $(SDIR)%.c
	@mkdir -p $(ODIR)
	@echo "  ${GRE}+ Compilation:${STD} $^"
	@gcc $^ $(FLAG) -c -o $@

header:
	@echo "${YEL}"
	@echo " ______   _   _   _   _   _"
	@echo "|  ____| (_) | | | | (_) | |"
	@echo "| |__     _  | | | |  _  | |_"
	@echo "|  __|   | | | | | | | | | __|"
	@echo "| |      | | | | | | | | | |_"
	@echo "|_|      |_| |_| |_| |_| \__|"
	@echo
	@echo "By: amoinier and fhermoue"
	@echo
	@echo "${STD}"

norme: header
	@echo "${GRE}  Norme${STD}\n"
	@norminette $(NORM)
	@echo "${RED}  \nTotal errors :${STD}" $(shell norminette $(NORM) | grep -v "Norme" | wc -l)

clean: header
	@echo "  ${RED}- Remove objects${STD}"
	@rm -rf $(ODIR)

fclean: clean
	@echo "  ${RED}- Remove $(NAME)${STD}"
	@rm -f $(NAME)

re: fclean all

end:
	@echo
	@echo "    This is the end"
	@echo "    $(CYA)My only friend, the end$(STD)"
	@echo

.PHONY: all $(NAME) header norme clean fclean re end