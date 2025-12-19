/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:29:37 by mkacemi           #+#    #+#             */
/*   Updated: 2025/12/19 23:36:21 by mkacemi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, int *i)
{
	int	j;
	int	lens;
	char	*sub;

	if (!s)
		return (NULL);
	j = *i;
	lens = 0;
	while (s[j] != '\n')
	{		
		lens++;
		j++;
	}	
	sub = malloc((sizeof(char) * (lens + 1)));
	if (!sub)
		return (NULL);
	j = 0;
	
	while (j < lens)
	{
		sub[j] = s[(*i)];
		(*i)++;
		j++;
	}
	(*i)++;
	//sub[j] = '\0';
	return (sub);
}

int	main(int argc, char **argv)
{
	int fd;
	int	i=0;
	static char	buffer[BUFFER_SIZE];

	fd = open(argv[1], O_RDONLY);
	read(fd, buffer, sizeof(buffer));
	//printf("%s \n", buffer);
	printf("phrase 1 %s\n",ft_substr(buffer, &i));
	//printf("%d\n",i);
	//printf("%c",buffer[i]);
	//read(fd, buffer, sizeof(buffer));
	printf("phrase 2 %s\n",ft_substr(buffer, &i));
	printf("phrase 3 %s\n",ft_substr(buffer, &i));
	printf("phrase 4 %s\n",ft_substr(buffer, &i));
	printf("phrase 5 %s\n",ft_substr(buffer, &i));
	return (0);
}