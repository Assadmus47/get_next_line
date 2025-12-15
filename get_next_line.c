/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:02:28 by mkacemi           #+#    #+#             */
/*   Updated: 2025/12/12 14:02:28 by mkacemi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		n;
	char	*ret;
	int		i;
	static char	buffer[BUFFER_SIZE];

	ret = malloc(sizeof(char));
	if (!problem_fd(fd))
		return (NULL);
	i = 0;
	n = 1;
	if (buffer[0] != '\n')
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
	free(ret);
	return (ret);
}

/* int	char_in(char *str)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (str[i] == '\n')
		{
			i++;
			*str = '\0';
			return (i);
		}		
	}
	return (0);
}
 */

/* char *get_next_line(int fd)
{
	char	*ret;
	int		i;
	static char	buffer[BUFFER_SIZE];
	int		n;

	if (!problem_fd(fd))
		return (NULL);
	i = 0;
	n = 1;
	n = read(fd, buffer, BUFFER_SIZE);
	while (!char_in(buffer))
	{
		ret = buffer;
		n = read(fd, buffer, BUFFER_SIZE);
		ft_strjoin(ret ,buffer);
	}

} */

/* int	problem_fd(int fd)
{
	return (fd < 0 || write(fd, "", 0) == -1);
}

int	main(int argc, char **argv)
{
	int		fd;
	int		n;
	char	buffer[1];

	fd = open(argv[1], O_RDONLY);
	if (problem_fd(fd))
		return (1);
	n = 1;
	while (buffer[0] != '\n')
	{
		n = read(fd, buffer, sizeof(buffer));
		if (write(1, buffer, 1) == -1)
		{
			close(fd);
			return (1);
		}
	}
	close(fd);
	return (0);
} */