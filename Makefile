
NAME = give_me_next

SRC = test.c get_next_line_utils.c get_next_line.c

CC = cc -g -O0

test: 
	$(CC) $(SRC) -o $(NAME)
	./$(NAME) a
clean:
	rm $(NAME)

re:
	test clean

git:
	git add .
	git commit -m "$(msg)"
	git push

.PHONY:	test clean re