
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	
	fd = open(argv[1], O_RDONLY);
	get_next_line(fd);
	//printf("salam");
	get_next_line(fd);
	get_next_line(fd);
	//get_next_line(fd);
	//get_next_line(fd);
	//get_next_line(fd);
	//printf("salam");
	close(fd);
	return (0);
}