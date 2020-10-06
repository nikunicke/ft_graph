NAME = libgraph.a

FLAGS = -Wall -Werror -Wextra

SRC = src/graph.c

OBJ = graph.o

LIBFTOBJ = ft_strlen.o ft_bzero.o\
			ft_memcpy.o ft_lstadd.o\
			ft_lstcontent.o ft_lstnew.o\
			ft_lstadd_sorted.o ft_memcmp.o

HASHOBJ = ft_hash.o

INCL = ./includes

all: $(NAME)

$(NAME): $(SRC) $(INCL)/graph.h
	make -C ./libft
	make -C ./ft_hash
	gcc $(FLAGS) -c $(SRC) -I./libft/includes -I./ft_hash/includes -I$(INCL) 
	ar -x libft/libft.a $(LIBFTOBJ)
	ar -x ft_hash/libhashft.a $(HASHOBJ)
	ar rc $(NAME) $(OBJ) $(LIBFTOBJ) $(HASHOBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ) $(LIBFTOBJ) $(HASHOBJ) "__.SYMDEF SORTED"
	make clean -C ./libft
	make clean -C ./ft_hash

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft
	make fclean -C ./ft_hash

re: fclean all

main:
	gcc main.c -L. -lgraph -I./includes -I./libft/includes -I./ft_hash/includes
