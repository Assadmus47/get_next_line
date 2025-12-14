/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:02:09 by mkacemi           #+#    #+#             */
/*   Updated: 2025/12/12 14:02:09 by mkacemi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	problem_fd(int fd)
{
	return (fd < 0 || write(fd, "", 0) == -1);
}

static size_t	ft_strlen(char *str)
{
	int	i;
	
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *first, char *second)
{
	int		i;
	int		j;
	char	*str;

	str = malloc(ft_strlen(first) + ft_strlen(second));
	i = 0;
	j = 0;
	while (first[i])
		str[j++] = first[i++];
	i = 0;	
	while (second[i])
		str[j++] = second[i++];
	return (str);
}

