#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/26 18:55:16 by tlutsyk           #+#    #+#              #
#    Updated: 2018/01/26 18:55:17 by tlutsyk          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SWITCH =		\033[
ST_NORM =	$(SWITCH)0m
COLOR_GREEN = 	$(SWITCH)32m
COLOR_RED =		$(SWITCH)31m
COLOR_SGREEN = $(SWITCH)33m

NAME = lem-in
CFILES = lemin.c lem_list.c check_error.c check_start_end.c \
		list_links.c list_check.c er_defs_ad.c read_block.c algo.c lst_way.c \
		sort_stack.c algo_doble_check.c ft_print_res.c ft_help.c \
		sort_stack_add.c 

OFILES = $(CFILES:.c=.o)
FOLDER = libft
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
		@gcc -c $(FLAGS) $? $(FILES)

$(NAME): $(OFILES)
		@make -C $(FOLDER)
		@gcc  $(OFILES) -L $(FOLDER) -lft -o $(NAME)
		@echo "$(STYLE_BOLD)$(COLOR_GREEN)\n YO YO YO CHEATERA!!!\n \
ALL NICE: LEM-IN is ready!!!\n \" If there are an exit I will find it... \n Maybe... \"\n"

clean:
	@/bin/rm -f $(OFILES)
	@make clean -C $(FOLDER)
	@echo "$(STYLE_BOLD)$(COLOR_SGREEN) OK!!! ALL O_FILES DELETED!!!"
fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C $(FOLDER)
	@echo "$(STYLE_BOLD)$(COLOR_RED) LEM-IN have been deleted"
re: fclean all

.PHONY: all clean fclean