NAME =	libasm.a

SRC =	ft_read.s \
		ft_write.s \
		ft_strlen.s \
		ft_strcmp.s \
		ft_strcpy.s \
		ft_strdup.s

NASM_FLAGS = -f macho64
FLAGS = -Wall -Werror -Wextra

OBJ =	$(SRC:.s=.o)

all:	$(NAME)

%.o: %.s
		nasm $(NASM_FLAGS) $< -o $@

$(NAME):$(OBJ)
		ar rc $(NAME) $?
		ranlib $(NAME)

test:	$(NAME) main.c
		gcc $(FLAGS) -L. -lasm main.c

clean:
		rm -f $(OBJ)
		rm -f a.out
		rm -f main.o
		rm -f *.txt

fclean: clean
		rm -f $(NAME)
		rm -f a.out

re: fclean all