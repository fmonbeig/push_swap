# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/02 17:43:56 by fmonbeig          #+#    #+#              #
#    Updated: 2021/09/23 16:45:52 by fmonbeig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =				push_swap
NAME_BONUS =		checker

CC =		clang
CFLAG =		-Wall -Wextra -Werror

LIBFT_PATH=	libft/
LIBFT_LIB=	libft.a

SRC =		push_swap.c\
			utils/utils.c\
			utils/find.c\
			utils/find_chunk.c\
			utils/print.c\
			utils/check.c\
			utils/ft_list_chunks.c\
			check_and_take/check_error.c\
			check_and_take/take.c\
			check_and_take/take_checker.c\
			move/move.c\
			move/mandatory_move.c\
			move/mandatory_move2.c\
			move/mandatory_move3.c\
			move/mandatory_move_no_print.c\
			move/mandatory_move_no_print2.c\
			move/mandatory_move_no_print3.c\
			utils/get_next_line_bonus.c\
			utils/get_next_line_utils_bonus.c\
			move/move_algo_simple.c\
			move/move_algo_insertion.c\
			algo.c\
			clean/free.c\
			clean/error.c\
			clean/error2.c\

SRC_CHECKER = checker_bonus/checker.c\
			utils/utils.c\
			utils/find.c\
			utils/find_chunk.c\
			utils/print.c\
			utils/check.c\
			utils/ft_list_chunks.c\
			check_and_take/check_error.c\
			check_and_take/take.c\
			check_and_take/take_checker.c\
			move/move.c\
			move/mandatory_move.c\
			move/mandatory_move2.c\
			move/mandatory_move3.c\
			move/mandatory_move_no_print.c\
			move/mandatory_move_no_print2.c\
			move/mandatory_move_no_print3.c\
			utils/get_next_line_bonus.c\
			utils/get_next_line_utils_bonus.c\
			move/move_algo_simple.c\
			move/move_algo_insertion.c\
			algo.c\
			clean/free.c\
			clean/error.c\
			clean/error2.c\

SRC_OBJ =			$(SRC:.c=.o)	
SRC_CHECKER_OBJ =	$(SRC_CHECKER:.c=.o)
LIBFT_OBJ=			${LIBFT_PATH}*.o

LIBFT = $(addprefix $(LIBFT_PATH),libft.a)


all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(SRC_OBJ)
		@echo "\\n\033[32;1m ***     MAKE_LIB     ***\033[0m \\n"
		make -C ${LIBFT_PATH}
		@echo "\\n\033[34;1m ***PUSH_SWAP COMPILATION*** \033[0m \\n"
		$(CC) $(CFLAG) -o $(NAME) $(SRC_OBJ) ${LIBFT_OBJ}
		@echo "\\n\033[31;1m --- COMPILATION FINISH --- \033[0m \\n"

$(NAME_BONUS):$(NAME) $(SRC_CHECKER_OBJ)
		@echo "\\n\033[32;1m ***     MAKE_LIB     ***\033[0m \\n"
		make -C ${LIBFT_PATH}
		@echo "\\n\033[35;1m ***CHECKER COMPILATION *** \033[0m \\n"
		$(CC) $(CFLAG) -o $(NAME_BONUS) $(SRC_CHECKER_OBJ) ${LIBFT_OBJ}
		@echo "\\n\033[31;1m --- COMPILATION FINISH --- \033[0m \\n"
			
clean:
				make -C ${LIBFT_PATH} clean
				rm -f ${SRC_OBJ} ${SRC_CHECKER_OBJ}

fclean: 		clean
				rm -f ${NAME} checker ${LIBFT_PATH}${LIBFT_LIB}

re:         	fclean all

.PHONY:        all clean fclean re bonus