
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>


int	problem_fd(int fd)
{
	return (fd < 0 || write(fd, "", 0) == -1);
}

char *get_next_line(int fd)
{
	int		n;
	char	*ret;
	int		i;
	static char	buffer[1];

	ret = malloc(sizeof(char));
	if (problem_fd(fd))
		return (NULL);
	i = 0;
	n = 1;
	if (buffer[0])
		write(1, buffer, n);
	while (n != 0)
	{
		n = read(fd, buffer, sizeof(buffer));
		if (buffer[0] == '\n')
		{
			n = read(fd, buffer, sizeof(buffer));
			break ;
		}
		if (write(1, buffer, n) == -1)
		{
			close(fd);
			return (NULL);
		}
		i++;
	}
	write(1, "\n", 1);
	return (ret);
}

int	main(int argc, char **argv)
{
	int		fd;
	
	fd = open(argv[1], O_RDONLY);
	get_next_line(fd);
	//printf("salam");
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	printf("salam");
	close(fd);
	return (0);
}