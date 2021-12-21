

CC := cc
CFLAGS := -Wall -Wextra -Werror
SRCS :=	Binary_operation.c Error_handling.c General_functions.c General_functions2.c Sorting_intermediate.c Sorting_principal.c Stack_initialisation.c Stack_operation_intermediate_functions.c Stack_operation.c main.c
NAME := push_swap
OBJS := ${SRCS:.c=.o}
	
all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(SRCS) libft/libft.a -o $(NAME) 
push_swap.a : $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $@
	ar cr $@ $(OBJS)
clean : 
	$(MAKE) clean -C ./libft
	rm -f ${OBJS} 
fclean : clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)
re : fclean all

.PHONY : all clean fclean re bonus 