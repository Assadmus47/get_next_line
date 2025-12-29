/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 17:55:24 by mkacemi           #+#    #+#             */
/*   Updated: 2025/12/29 18:18:34 by mkacemi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	free_and_clean(char **line, char *buffer)
{
	if (buffer)
		buffer[0] = '\0';
	free(*line);
	*line = NULL;
	return (0);
}

int	concatinate(int fd, char **line, char buffer[OPEN_MAX][BUFFER_SIZE + 1])
{
	ssize_t		bytes;
	char		*tmp;

	bytes = 0;
	while (!ft_strchr(*line, '\n'))
	{
		bytes = read(fd, buffer[fd], BUFFER_SIZE);
		if (bytes < 0)
			return (free_and_clean(line, buffer[fd]), 0);
		if (bytes == 0)
		{
			buffer[fd][0] = '\0';
			break ;
		}
		buffer[fd][bytes] = '\0';
		tmp = ft_strjoin(*line, buffer[fd]);
		if (!tmp)
			return (free_and_clean(line, NULL), 0);
		free(*line);
		*line = tmp;
	}
	return (1);
}

int	line_next(char **line, char buffer[OPEN_MAX][BUFFER_SIZE + 1], int fd)
{
	int			i;

	i = 0;
	while ((*line)[i] && (*line)[i] != '\n')
		i++;
	if ((*line)[i] == '\n')
	{
		ft_strcpy(buffer[fd], (*line) + i + 1);
		(*line)[i + 1] = '\0';
	}
	if ((*line)[0] == '\0')
	{
		buffer[fd][0] = '\0';
		free((*line));
		return (0);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	buffer [OPEN_MAX][BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0
		|| read(fd, 0, 0) < 0 || fd > OPEN_MAX || OPEN_MAX > 1024)
		return (NULL);
	line = ft_strdup(buffer[fd]);
	if (!line)
		return (NULL);
	buffer[fd][0] = '\0';
	if (concatinate(fd, &line, buffer) == 0)
		return (NULL);
	if (line_next(&line, buffer, fd) == 0)
		return (NULL);
	return (line);
}
