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

char *get_next_line1(int fd)
{
	ssize_t			bytes;
	size_t			bs_indx;
	static char		buffer[BUFFER_SIZE + 1];
	char			*str;
	char			*temp;
	
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
		return (NULL);
	str = malloc(sizeof(char) * (BUFFER_SIZE + 1));	
	str[BUFFER_SIZE] = '\0';
	if (buffer[0] != '\0')
		strcopy(str, buffer);
	bs_indx = back_slach_in(str);
	while (bs_indx == 0)
	{
		
		ft_strcopy(buffer, ft_substr(str, bs_indx + 1, BUFFER_SIZE));
		bs_indx = back_slach_in(str);		
	}
	return (ft_substr(str, 0, bs_indx));

}


