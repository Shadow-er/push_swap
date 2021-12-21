

CC := cc
CFLAGS := -Wall -Wextra -Werror
SRCS :=	Binary_operation.c Error_handling.c General_functions.c General_functions2.c Sorting_intermediate.c Sorting_principal.c Stack_initialisation.c Stack_operation_intermediate_functions.c Stack_operation.c go.c
NAME := push_swap
SRCS2 :=	Binary_operation.c Error_handling.c General_functions.c General_functions2.c Sorting_intermediate.c Sorting_principal.c Stack_initialisation.c Stack_operation_intermediate_functions.c Stack_operation.c \
			checker.c Get_next_line/get_next_line.c Get_next_line/get_next_line_utils.c 
OBJS := ${SRCS:.c=.o}
OBJS := ${SRCS2:.c=.o}
	
all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(SRCS) libft/libft.a -o $(NAME) 
push_swap.a : $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $@
	ar cr $@ $(OBJS)
checker : $(OBJS)
	$(CC) $(CFLAGS) $(SRCS2) libft/libft.a -o $@ 
clean : 
	$(MAKE) clean -C ./libft
	rm -f ${OBJS} 
fclean : clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)
re : fclean all

.PHONY : all clean fclean re bonus 