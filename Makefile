##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC =	src/main.c					\
		src/movement.c				\
		src/matrix/mat4x4.c			\
		src/matrix/mat_create.c		\

OBJ = $(SRC:.c=.o)

NAME = workshop

CFLAGS = -Wall -Wextra -I ./include/ -g

LDFLAGS += -L lib/my/ -lmy -g -lm 										\
		-lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window 	\
		-Wparentheses -Wsign-compare -Wpointer-sign -Wuninitialized 	\
		-Wunused-but-set-variable -g

all: $(NAME)

$(NAME):   $(OBJ)
	make -s -C lib/my/
	gcc -o $(NAME) $(FLAGS) $(OBJ) $(LDFLAGS)

clean:
	find . -name "*.o" -delete
	rm -f $(OBJ)

fclean:    clean
	rm -f $(NAME)
	rm -f *.c~
	rm -f *.out
	rm -f vgcore*
	rm -f *.gcda
	rm -f *.gcno
	rm -f unit_tests*

re:        fclean all

run: all
	./$(NAME)

lib_fclean:
		cd lib/my/ && make fclean

push_fclean: fclean
		cd lib/my/ && make fclean

re:	fclean all

valgrind: all
	valgrind --track-origins=yes --leak-check=full \
	--show-leak-kinds=definite,indirect ./$(NAME)

tests_run: exec_lib
	gcc -o unit_tests $(SRC) tests/*.c -Llib/ -lmy --coverage -lcriterion
	./unit_tests
	gcovr --exclude tests
	gcovr -b --exclude tests
