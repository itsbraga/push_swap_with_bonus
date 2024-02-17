# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/02 11:07:10 by annabrag          #+#    #+#              #
#    Updated: 2024/02/17 02:26:19 by annabrag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################################################################################
#										#
#				      COLORS					#
#										#
#################################################################################

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

# define rainbow
# $(shell echo $(1) | sed -e "s/./\$(shell printf '\033[38;5;%dm' \$$(shell expr \( \$$(od -An -N1 -tu1 /dev/urandom) \% 6 + 196))&) /g")
# endef

# COLORED_TEXT	:= $(call (rainbow))


#################################################################################
#										#
#				    BASICS					#
#										#
#################################################################################

NAME		=	libft.a
LIBC		=	ar -rcs

CC		=	cc

MAKEFLAGS	+=	--no-print-directory
DEPFLAGS	=	-MMD -MP
CFLAGS		=	-Wall -Wextra -Werror -I
INC		=	include/

FSANITIZE	=	-fsanitize=address -g3
DEBUG		=	-g -O0

RM		=	rm -rf


#################################################################################
#										#
#				    SOURCES					#
#										#
#################################################################################

FT_FD_DIR	= 	ft_fd/
FT_FD_FILES	= 	ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_putstr_fd.c ft_putstr_color_fd.c

FT_IS_DIR 	= 	ft_is/
FT_IS_FILES	= 	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
			ft_isprint.c ft_isspace.c

FT_MEM_DIR	=	ft_mem/
FT_MEM_FILES	=	ft_memset.c ft_memcpy.c ft_memmove.c ft_memchr.c \
			ft_memcmp.c ft_bzero.c ft_calloc.c
			
FT_STR_DIR	=	ft_str/
FT_STR_FILES	=	ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c \
			ft_strrchr.c ft_strncmp.c ft_strnstr.c ft_strdup.c \
			ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
			ft_strmapi.c ft_striteri.c \
			ft_strisnum.c ft_strcapitalize.c ft_strcat.c ft_strcmp.c \
			ft_strlowcase.c ft_strupcase.c ft_strncat.c ft_strstr.c

FT_TO_DIR	=	ft_to/
FT_TO_FILES	=	ft_tolower.c ft_toupper.c ft_itoa.c ft_atoi.c ft_atol.c

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

MATHS_DIR	=	maths/
MATHS_FILES	=	ft_fibonacci.c \
			ft_is_prime.c \
			ft_find_next_prime.c \
			ft_sqrt.c \
			ft_iterative_factorial.c \
			ft_recursive_factorial.c \
			ft_iterative_power.c \
			ft_recursive_power.c


#################################################################################
#										#
#				COMBINE FILES					#
#				    and						#
#				DIRECTORIES					#
#									  	#
#################################################################################

SRC_DIR		=	src/

SRCS		=	$(addprefix $(FT_FD_DIR), $(FT_FD_FILES)) \
			$(addprefix $(FT_IS_DIR), $(FT_IS_FILES)) \
			$(addprefix $(FT_MEM_DIR), $(FT_MEM_FILES)) \
			$(addprefix $(FT_STR_DIR), $(FT_STR_FILES)) \
			$(addprefix $(FT_TO_DIR), $(FT_TO_FILES)) \
			$(addprefix $(FT_LST_DIR), $(FT_LST_FILES)) \
			$(addprefix $(GNL_DIR), $(GNL_FILES)) \
			$(addprefix $(FT_PRINTF_DIR), $(FT_PRINTF_FI)) \
			$(addprefix $(FT_FROM_TO_DIR), $(FT_FROM_TO_FI)) \
			$(addprefix $(MATHS_DIR), $(MATHS_FILES))

OBJ_DIR		=	obj/

OBJ_NAMES	=	$(SRCS:.c=.o)

OBJ_FOLDERS	=	$(addprefix $(OBJ_DIR), $(FT_FD_DIR) \
                		$(FT_IS_DIR) \
				$(FT_MEM_DIR) \
				$(FT_STR_DIR) \
                   		$(FT_TO_DIR) \
				$(FT_LST_DIR) \
                		$(GNL_DIR) \
				$(FT_PRINTF_DIR) \
				$(FT_FROM_TO_DIR) \
				$(MATHS_DIR))

OBJS		=	$(addprefix $(OBJ_DIR), $(OBJ_NAMES))


#################################################################################
#										#
#				DEPENDENCIES					#
#										#
#################################################################################

DEP_NAMES	=	$(SRCS:.c=.d)

DEP_FOLDERS	=	$(addprefix $(OBJ_DIR), $(FT_FD_DIR) \
                		$(FT_IS_DIR) \
				$(FT_MEM_DIR) \
				$(FT_STR_DIR) \
                   		$(FT_TO_DIR) \
				$(FT_LST_DIR) \
                		$(GNL_DIR) \
				$(FT_PRINTF_DIR) \
				$(FT_FROM_TO_DIR) \
				$(MATHS_DIR))

DEP		=	$(addprefix $(OBJ_DIR), $(DEP_NAMES))


#################################################################################
#										#
#				     RULES					#
#										#
#################################################################################

all:	$(NAME)

$(info )

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
			@mkdir -p $(dir $@)
			@printf "$(BOLD)$(ITAL)$(PURPLE)Compiling: $(RESET)$(ITAL)$<                                       \r"
			@$(CC) $(DEPFLAGS) $(CFLAGS) $(INC) -c $< -o $@
-include $(DEP)

# link .o files to the library
$(NAME): $(OBJS)
		@$(LIBC) $(NAME) $(OBJS)
		@printf "\n\n$(RESET)$(BOLD)$(PINK)[LIBFT]$(RESET), \
$(BOLD)$(BLUE)[GET_NEXT_LINE]$(RESET), $(BOLD)$(RED)[FT_PRINTF]$(RESET), \
$(BOLD)$(ORANGE)[MATHS FUNC.]$(RESET) $(BOLD)$(YELLOW)successfully compiled!$(RESET)\n\n"
		@printf "\n. ⋅ ˚̣- : ✧ : – ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ ₊° ˗ ˏ ˋ ♡ ˎˊ ˗ °₊ ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ – : ✧ : -˚̣⋅ .\n\n\n\n"

san:	$(FSANITIZE)

clean:
		@$(RM) $(OBJ_DIR)
		@printf "\n$(BOLD)$(PINK)[LIBFT, GNL, FT_PRINTF, MATHS FUNC.]:\t$(RESET)Clean completed!\n"

fclean: clean
		@$(RM) $(NAME)
		@find . -name ".DS_Store" -delete
		@printf "$(BOLD)$(PINK)[LIBFT, GNL, FT_PRINTF, MATHS FUNC.]:\t$(RESET)Full clean completed!\n\n"
		@printf "\n. ⋅ ˚̣- : ✧ : – ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ ₊° ˗ ˏ ˋ ♡ ˎˊ ˗ °₊ ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ – : ✧ : -˚̣⋅ .\n\n"

re:	fclean all
		@printf "✨ $(BOLD)$(YELLOW)Cleaning and rebuilding done! $(RESET)✨\n\n"

diff:
		$(info Repository's status, and the volume of per-file changes:)
		@printf "$(RESET)\n\n"
		@git status
		@git diff --stat

# leak:
# 		@valgrind --leak-check=full --track-origins=yes --leak-resolution=high --show-leak-kinds=all ./program

norm:
		@clear
		@norminette $(SRC_DIR) $(INC) | grep -v Norme -B1 || true

.PHONY:		all clean fclean re diff san norm
