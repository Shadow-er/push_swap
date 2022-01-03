

CC := cc
CFLAGS := -Wall -Wextra -Werror
SRCS :=	Binary_operation.c Error_handling.c General_functions.c General_functions2.c Sorting_intermediate.c Sorting_principal.c Stack_initialisation.c Stack_operation_intermediate_functions.c Stack_operation.c go.c \
		Other_functions.c Stack_opeartion2.c

NAME := push_swap
SRCS2 :=	Binary_operation.c Error_handling.c General_functions.c General_functions2.c Sorting_intermediate.c Sorting_principal.c Stack_initialisation.c Stack_operation_intermediate_functions.c Stack_operation.c \
			checker.c Get_next_line/get_next_line.c Get_next_line/get_next_line_utils.c other_functions2.c other_functions3.c Stack_opeartion2.c
OBJS := ${SRCS:.c=.o}
OBJS2 := ${SRCS2:.c=.o}
	
all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(SRCS) libft/libft.a -o $(NAME) 
push_swap.a : $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $@
	ar cr $@ $(OBJS)
checker : $(OBJS2) $(OBJS)
	$(CC) $(CFLAGS) $(SRCS2) libft/libft.a -o $@ 
clean : 
	$(MAKE) clean -C ./libft
	rm -f ${OBJS} ${OBJS2} 
fclean : clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME) checker
re : fclean all

.PHONY : all clean fclean re bonus 