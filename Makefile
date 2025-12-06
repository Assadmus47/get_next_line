
NAME = give_me_next

SRC = test.c

CC = cc

test:
	$(CC) $(SRC) -o $(NAME)
	./$(NAME).exe a.txt

clean:
	rm $(NAME).exe

re:
	test clean

.PHONY:	test clean re