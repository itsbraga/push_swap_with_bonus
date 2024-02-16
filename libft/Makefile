# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/02 11:07:10 by annabrag          #+#    #+#              #
#    Updated: 2024/02/16 16:01:03 by annabrag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################### COLORS #####################################

RESET		:=	\e[0m
BOLD		:=	\e[1m
DIM		:=	\e[2m
ITAL		:=	\e[3m
UNDERLINE	:=	\e[4m

BLACK		:=	\e[30m
GRAY		:=	\e[90m
RED		:=	\e[31m
GREEN		:=	\e[32m
YELLOW		:=	\e[33m
ORANGE		:=	\e[38;5;208m
BLUE		:=	\e[34m
PURPLE		:=	\e[35m
PINK		:=	\033[38;2;255;182;193m
CYAN		:=	\e[36m

BRIGHT_BLACK	:=	\e[90m
BRIGHT_GREEN	:=	\e[92m
BRIGHT_YELLOW	:=	\e[93m
BRIGHT_BLUE	:=	\e[94m
BRIGHT_PURPLE	:=	\e[95m
BRIGHT_CYAN	:=	\e[96m


################################### BASICS ###################################

NAME		=	libft.a
CC		=	cc
CFLAGS		=	-Wall -Wextra -Werror -I
INC		=	include/
FSANITIZE	=	-fsanitize=address -g3
LIBC		=	ar -rcs
RM		=	rm -rf


################################### SOURCES ###################################

FT_FD_DIR	= 	ft_fd/
FT_FD_FILES	= 	ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_putstr_color_fd.c

FT_IS_DIR 	= 	ft_is/
FT_IS_FILES	= 	ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c

FT_MEM_DIR	=	ft_mem/
FT_MEM_FILES	=	ft_memset.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_bzero.c \
			ft_calloc.c
			
FT_STR_DIR	=	ft_str/
FT_STR_FILES	=	ft_strlen.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_strisnum.c \
			ft_strcapitalize.c \
			ft_strcat.c \
			ft_strcmp.c \
			ft_strlowcase.c \
			ft_strupcase.c \
			ft_strncat.c \
			ft_strstr.c

FT_TO_DIR	=	ft_to/
FT_TO_FILES	=	ft_tolower.c \
			ft_toupper.c \
			ft_itoa.c \
			ft_atoi.c \
			ft_atol.c

FT_LST_DIR	=	ft_lst/
FT_LST_FILES	=	ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_lstdisplay.c

GNL_DIR		=	get_next_line/
GNL_FILES	=	get_next_line.c \
			get_next_line_utils.c

FT_PRINTF_DIR	=	ft_printf/
FT_PRINTF_FI	=	ft_printf.c \
			ft_print_unsigned_int.c \
			ft_printchar.c \
			ft_printhex.c \
			ft_printnbr.c \
			ft_printptr.c \
			ft_printstr.c

FT_FROM_TO_DIR	=	ft_from_to/
FT_FROM_TO_FI	=	ft_convert_base.c \
			ft_convert_base2.c \
			ft_putnbr_base.c

INT_DIR		=	int/
INT_FILES	=	ft_print_comb.c \
			ft_print_comb2.c \
			ft_range.c \
			ft_rev_int_tab.c \
			ft_sort_int_tab.c \
			ft_ultimate_range.c

MATHS_DIR	=	maths/
MATHS_FILES	=	ft_fibonacci.c \
			ft_is_prime.c \
			ft_find_next_prime.c \
			ft_sqrt.c \
			ft_iterative_factorial.c \
			ft_recursive_factorial.c \
			ft_iterative_power.c \
			ft_recursive_power.c


######################## COMBINE DIRECTORIES AND FILES ########################

SRC_DIR		=	src/

SRC_NAMES	=	$(addprefix $(FT_FD_DIR), $(FT_FD_FILES)) \
			$(addprefix $(FT_IS_DIR), $(FT_IS_FILES)) \
			$(addprefix $(FT_MEM_DIR), $(FT_MEM_FILES)) \
			$(addprefix $(FT_STR_DIR), $(FT_STR_FILES)) \
			$(addprefix $(FT_TO_DIR), $(FT_TO_FILES)) \
			$(addprefix $(FT_LST_DIR), $(FT_LST_FILES)) \
			$(addprefix $(GNL_DIR), $(GNL_FILES)) \
			$(addprefix $(FT_PRINTF_DIR), $(FT_PRINTF_FI)) \
			$(addprefix $(FT_FROM_TO_DIR), $(FT_FROM_TO_FI)) \
			$(addprefix $(INT_DIR), $(INT_FILES)) \
			$(addprefix $(MATHS_DIR), $(MATHS_FILES))

OBJ_DIR		=	obj/

OBJ_NAMES	=	$(SRC_NAMES:.c=.o)

OBJ_FOLDERS	=	$(addprefix $(OBJ_DIR), $(FT_FD_DIR) \
                		$(FT_IS_DIR) \
				$(FT_MEM_DIR) \
				$(FT_STR_DIR) \
                		$(FT_TO_DIR) \
				$(FT_LST_DIR) \
                		$(GNL_DIR) \
				$(FT_PRINTF_DIR) \
				$(FT_FROM_TO_DIR) \
				$(INT_DIR) \
				$(MATHS_DIR))

OBJ		=	$(addprefix $(OBJ_DIR), $(OBJ_NAMES))


#################################### RULES ####################################

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
			@mkdir -p $(dir $@)
			@printf "$(ITAL)$(PURPLE)Compiling: $(RESET)$(ITAL)$<                                       \r"
			@$(CC) $(CFLAGS) $(INC) -c $< -o $@

# link .o files to the library
$(NAME): $(OBJ)
		@$(LIBC) $(NAME) $(OBJ)
		@printf "\n\n$(RESET)$(BOLD)$(PINK)[LIBFT]$(RESET), $(BOLD)$(BLUE)[GET_NEXT_LINE]$(RESET), $(BOLD)$(RED)[FT_PRINTF]$(RESET), $(BOLD)$(YELLOW)[POOL_FUNC]$(RESET) successfully compiled! ฅ^•ﻌ•^ฅ\n\n"
		@printf "\n. ⋅ ˚̣- : ✧ : – ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ ₊° ˗ ˏ ˋ ♡ ˎˊ ˗ °₊ ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ – : ✧ : -˚̣⋅ .\n\n\n"

all:		$(NAME)

san:		$(FSANITIZE)

clean:
			@$(RM) $(OBJ_DIR)
			@printf "\n$(BOLD)$(PINK)[LIBFT & Co.]:\t$(RESET)$(PINK)object files $(RESET)\t=> CLEANED!\n"

fclean: 	clean
			@$(RM) $(NAME)
			@find . -name ".DS_Store" -delete
			@printf "$(BOLD)$(PINK)[LIBFT & Co.]: $(RESET)$(PINK)exec. files $(RESET)\t=> CLEANED!\n"

re:		fclean all
			@printf "\n\n✨ $(BOLD)$(YELLOW)Cleaning and rebuilding done! $(RESET)✨\n"

norm:
			@clear
			@norminette $(SRC_DIR) $(INC) | grep -v Norme -B1 || true

.PHONY:		all clean fclean re norm
