NAME = libgraph.a

FLAGS = -Wall -Werror -Wextra

SRC = src/graph.c

OBJ = graph.o

LIBFTOBJ = ft_strlen.o ft_bzero.o\
			ft_memcpy.o ft_lstadd.o\
			ft_lstcontent.o ft_lstnew.o\
			ft_lstadd_sorted.o ft_memcmp.o

INCL = ./includes

all: $(NAME)

$(NAME): $(SRC) $(INCL)/graph.h
	make -C ./libft
	gcc $(FLAGS) -c $(SRC) -I./libft/includes -I$(INCL) 
	ar -x libft/libft.a $(LIBFTOBJ)
	ar rc $(NAME) $(OBJ) $(LIBFTOBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ) $(LIBFTOBJ) "__.SYMDEF SORTED"
	make clean -C ./libft

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft

re: fclean all

main:
	gcc main.c -L. -lgraph -I./includes -I./libft/includes -I./ft_hash/includes
