
NAME = give_me_next

SRC = test.c get_next_line_utils.c get_next_line.c

CC = cc

test: 
	$(CC) $(SRC) -o $(NAME)
	./$(NAME) file.txt
clean:
	rm $(NAME).exe

re:
	test clean

.PHONY:	test clean re