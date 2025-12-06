/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 11:26:47 by marvin            #+#    #+#             */
/*   Updated: 2025/12/06 11:26:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>


int	problem_fd(int fd)
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
}