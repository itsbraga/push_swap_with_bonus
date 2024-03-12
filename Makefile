#################################################################################
#																				#
#									COLORS										#
#																				#
#################################################################################

RESET		:=	\e[0m
BOLD		:=	\e[1m
DIM			:=	\e[2m
ITAL		:=	\e[3m
UNDERLINE	:=	\e[4m

RED			:=	\e[31m
GREEN		:=	\e[32m
YELLOW		:=	\e[33m
ORANGE		:=	\e[38;5;208m
BLUE		:=	\e[34m
PURPLE		:=	\e[35m
PINK		:=	\033[38;2;255;182;193m
CYAN		:=	\e[36m


#################################################################################
#																				#
#									BASICS										#
#																				#
#################################################################################

PUSH_SWAP	=	push_swap
CHECKER		=	checker

LIBFT_PATH	=	libft

CC			=	cc
MAKEFLAGS	+=	--no-print-directory

# -MMD include only the included files you've explicitly specified in the
# dependencies.
#
# -MP generates dependency rules even for source files without headers. It
# Guarantees robustness, ease of maintenance and compatibility with future
# changes.

DEPFLAGS	=	-MMD -MP
CFLAGS		=	-Wall -Wextra -Werror -I 
INC			=	include/

DEBUG		=	-g -O0
RM			=	rm -rf


#################################################################################
#																				#
#									SOURCES										#
#																				#
#################################################################################

OP_DIR		=	operations/
OP_FILES	=	swap.c rotate.c reverse_rotate.c push.c

UTILS_DIR	=	utils/
UTILS_FILES	=	stack.c set_elem.c utils.c

ALGO_DIR	=	algorithm/
ALGO_FILES	=	sort_mini.c sort.c cost.c move.c

EXEC_DIR	=	exec/
EXEC_FILES	=	check_args.c check_args2.c error_handler.c init.c

MANDAT_DIR	=	mandatory/
MANDAT_FILE	=	main.c

BONUS_DIR	=	bonus/
BONUS_FILES	=	do_op.c main_bonus.c


#################################################################################
#																				#
#								COMBINE FILES									#
#									AND											#
#								DIRECTORIES										#
#																				#
#################################################################################

SRC_DIR		=	src/

BONUS_PATH	=	src/

SRCS		=	$(addprefix $(OP_DIR), $(OP_FILES)) \
				$(addprefix $(UTILS_DIR), $(UTILS_FILES)) \
				$(addprefix $(ALGO_DIR), $(ALGO_FILES)) \
				$(addprefix $(EXEC_DIR), $(EXEC_FILES)) \
				$(addprefix $(MANDAT_DIR), $(MANDAT_FILE))

OBJ_DIR		=	obj/

OBJ_NAMES	=	$(SRCS:.c=.o)

OBJ_FOLDERS	=	$(addprefix $(OBJ_DIR), $(OP_DIR), $(UTILS_DIR), $(ALGO_DIR) \
				$(EXEC_DIR), $(MANDAT_DIR))

OBJ			=	$(addprefix $(OBJ_DIR), $(OBJ_NAMES))


###############################		BONUS PART	#################################

SRCS_B			=	$(addprefix $(OP_DIR), $(OP_FILES)) \
					$(addprefix $(UTILS_DIR), $(UTILS_FILES)) \
					$(addprefix $(ALGO_DIR), $(ALGO_FILES)) \
					$(addprefix $(EXEC_DIR), $(EXEC_FILES)) \
					$(addprefix $(BONUS_DIR), $(BONUS_FILES))

OBJ_B_DIR		=	obj_bonus/

OBJ_B_NAMES		=	$(SRCS_B:.c=.o)

OBJ_B_FOLDERS	=	$(addprefix $(OBJ_B_DIR), $(OP_DIR), $(UTILS_DIR), $(ALGO_DIR) \
					$(BONUS_DIR), $(EXEC_DIR))

OBJ_BONUS		=	$(addprefix $(OBJ_B_DIR), $(OBJ_B_NAMES))


#################################################################################
#																				#
#								DEPENDENCIES									#
#																				#
#################################################################################

DEP_NAMES		=	$(SRCS:.c=.d)

DEP_FOLDERS		=	$(addprefix $(OBJ_DIR), $(OP_DIR), $(UTILS_DIR), $(ALGO_DIR) \
					$(EXEC_DIR))

DEP				=	$(addprefix $(OBJ_DIR), $(DEP_NAMES))


##############################	  BONUS PART	################################

DEP_B_NAMES		=	$(SRCS_B:.c=.d)

DEP_B_FOLDERS	=	$(addprefix $(OBJ_DIR), $(OP_DIR), $(UTILS_DIR), $(ALGO_DIR) \
					$(EXEC_DIR), $(BONUS_DIR))

DEP_BONUS		=	$(addprefix $(OBJ_B_DIR), $(DEP_B_NAMES))


#################################################################################
#																				#
#									RULES										#
#																				#
#################################################################################

build:
		@make -sC $(LIBFT_PATH) $(MAKEFLAGS)
		@mv $(LIBFT_PATH)/libft.a .
		@make all

all:		$(PUSH_SWAP)

bonus:		$(CHECKER)

$(PUSH_SWAP): $(OBJ)
				@printf "\n\n$(RESET)$(BOLD)$(CYAN)[PUSH_SWAP]:  $(RESET)"
				@$(CC) $(CFLAGS) $(INC) $(OBJ) libft.a -o $(PUSH_SWAP)
				@printf "Your program is ready to launch! ˚̩͙⚛ ͙*\n\n"

$(info )

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
					@if [ ! -f .build ]; then \
						printf "\t\t\t%s\n" \
						"──▒▒▒▒▒▒───▄████▄" \
						"─▒─▄▒─▄▒──███▄█▀" \
						"─▒▒▒▒▒▒▒─▐████──█─█" \
						"─▒▒▒▒▒▒▒──█████▄" \
						"─▒─▒─▒─▒───▀████▀"; \
						printf "\n\n"; \
						touch .build; fi
					@mkdir -p $(dir $@)
					@printf "$(BOLD)$(ITAL)$(PURPLE)Compiling: $(RESET)$(ITAL)$<               \r"
					@$(CC) $(DEBUG) $(CFLAGS) $(INC) $(DEPFLAGS) -c $< -o $@
-include $(DEP)

clean:
		@$(RM) $(OBJ_DIR) $(OBJ_B_DIR)
		@make clean -C $(LIBFT_PATH)
		@printf "$(BOLD)$(CYAN)[PUSH_SWAP]:\t\t\t\t$(RESET)Clean completed!\n\n"

fclean: clean
			@$(RM) $(PUSH_SWAP) $(CHECKER)
			@$(RM) $(LIBFT_PATH)/libft.a
			@$(RM) libft.a
			@find . -name ".build" -delete
			@find . -name ".DS_Store" -delete
			@printf "$(BOLD)$(PINK)[LIBFT, GNL, FT_PRINTF, MATHS FUNC.]:\t$(RESET)Full clean completed!\n"
			@printf "$(BOLD)$(CYAN)[PUSH_SWAP]:\t\t\t\t$(RESET)Full clean completed!\n\n"
			@printf "\n. ⋅ ˚̣- : ✧ : – ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ ₊° ˗ ˏ ˋ ♡ ˎˊ ˗ °₊ ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ – : ✧ : -˚̣⋅ .\n\n\n"

re:		fclean build all
			@printf "\n\n✨ $(BOLD)$(YELLOW)Cleaning and rebuilding done! $(RESET)✨\n\n"

diff:
		$(info Repository's status, and the volume of per-file changes:)
		@printf "$(RESET)\n\n"
		@git status
		@git diff --stat

norm:
		@clear
		@norminette $(SRC_DIR) $(INC) $(LIBFT_PATH) | grep -v Norme -B1 || true

# leak:
# 		@valgrind --leak-check=full --track-origins=yes --leak-resolution=high --show-leak-kinds=all ./push_swap


#################################################################################
#																				#
#									BONUS										#
#																				#
#################################################################################


$(CHECKER): $(OBJ_BONUS)
				@make $(MAKEFLAGS) -C $(LIBFT_PATH)
				@mv $(LIBFT_PATH)/libft.a .
				@printf "✨ $(BOLD)$(YELLOW)Bonuses successfully compiled! $(RESET)✨\n"
				@printf "\n$(RESET)$(BOLD)$(CYAN)[BONUS]:  $(RESET)"
				@$(CC) $(CFLAGS) $(INC) $(OBJ_BONUS) libft.a -o $(CHECKER)
				@printf "./checker ready to launch ! (👍 ͡❛ ͜ʖ ͡❛)👍\n\n"
				@printf "\n\n\t\t\t──▒▒▒▒▒▒───▄████▄\n"
				@printf "\t\t\t─▒─▄▒─▄▒──███▄█▀\n"
				@printf "\t\t\t─▒▒▒▒▒▒▒─▐████──█─█\n"
				@printf "\t\t\t─▒▒▒▒▒▒▒──█████▄\n"
				@printf "\t\t\t─▒─▒─▒─▒───▀████▀\n\n\n"

$(OBJ_B_DIR)%.o: $(BONUS_PATH)%.c
						@mkdir -p $(OBJ_B_FOLDERS)
						@printf "$(BOLD)$(ITAL)$(PURPLE)Compiling: $(RESET)$(ITAL)$<                  \r"
						@$(CC) $(DEBUG) $(CFLAGS) $(INC) $(DEPFLAGS) -c $< -o $@

-include $(DEP_BONUS)


.PHONY:		all build clean fclean re diff norm bonus