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


char	*free__and_clean(char *line, char *buffer)
{
	if(buffer)
		buffer[0] = '\0';
	free(line);
	return (NULL);	
}

int	concatinate(int fd, char **line, char buffer[BUFFER_SIZE + 1])
{
	ssize_t		bytes;
	char		*tmp;

	bytes = 0;
	while (!ft_strchr(*line, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(*line);
			buffer[0] = '\0';
			return (0);
		}
		if (bytes == 0)
		{
			buffer[0] = '\0';
			break ;
		}
		buffer[bytes] = '\0';
		tmp = ft_strjoin(*line, buffer);
		if (!tmp)
		{
			free(*line);
			return (0);
		}
		free(*line);
		*line = tmp;
	}
	return (1);
}

int	line_next(char **line, char buffer[BUFFER_SIZE + 1])
{
	int			i;

	i = 0;
	while ((*line)[i] && (*line)[i] != '\n')
		i++;
	if ((*line)[i] == '\n')
	{
		ft_strcpy(buffer, (*line) + i + 1);
		(*line)[i + 1] = '\0';
	}
	if ((*line)[0] == '\0')
	{
		buffer[0] = '\0';
		free((*line));
		return (0);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	buffer	[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		buffer[0] = '\0';
		return (NULL);
	}
	line = ft_strdup(buffer);
	if (!line)
		return (NULL);
	buffer[0] = '\0';
	if (concatinate(fd, &line, buffer) == 0)
		return (NULL);
	if (line_next(&line, buffer) == 0)
		return (NULL);
	return (line);
}
