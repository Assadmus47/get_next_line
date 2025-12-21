/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:29:37 by mkacemi           #+#    #+#             */
/*   Updated: 2025/12/21 22:06:04 by mkacemi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"




char	*ft_substr(char  *s, size_t *i)
{
	size_t	j;
	size_t	lens;
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
	sub = malloc((sizeof(char) * (lens + 2)));
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
	sub[j++] = '\n';
	sub[j] = '\0';
	return (sub);
}

static size_t	ft_strlen(char *str)
{
	size_t	i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}


int	back_slach_in(char *s, size_t *j)
{
	size_t	i;

	i = *j;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		s++;
	}
	return (0);
}



char	*ft_strdup(char *src)
{
	size_t	i;
	size_t	src_taille;
	char	*dest;

	i = 0;
	src_taille = ft_strlen(src);
	dest = malloc(src_taille + 1);
	if (!dest)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char  *s2)
{
	char	*new_str;
	size_t	len;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	new_str = malloc((sizeof(char) * (len + 1)));
	if (!new_str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		new_str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		new_str[j++] = s2[i++];
	new_str[j] = '\0';
	return (new_str);
}

char *get_next_line(int fd)
{
	size_t			i;
	char 			*temp;
	char 			*str;
	static char		buffer[BUFFER_SIZE + 1];

	i = 0;
	buffer[BUFFER_SIZE] = 0;
	if (fd < 0)
		return (NULL);
	if (read(fd, buffer, BUFFER_SIZE) == -1)
		return (NULL);
	if (back_slach_in(buffer, &i))
		return (ft_substr(buffer, &i));
	else
	{
		str = ft_strdup(buffer);
		while (!back_slach_in(str, &i))
		{
			temp = ft_strdup(buffer);
			if (read(fd, buffer, BUFFER_SIZE) == -1)
				return (NULL);
			str = ft_strjoin(str, buffer);
			j++;
		}
	}
	return (ft_substr(str, &i));
}


int	main(int argc, char **argv)
{
	int fd;
	//har *temp;
	//static char	buffer[BUFFER_SIZE + 1];
	//size_t i = 0;

	//buffer[BUFFER_SIZE] = 0;
	fd = open(argv[1], O_RDONLY);
	//read(fd, buffer, BUFFER_SIZE);
	//printf("%s \n", buffer);
	printf("p %s\n", get_next_line(fd));
	//printf("p %s\n", get_next_line(fd));
/* 	buffer[BUFFER_SIZE] = 0;
	read(fd, buffer, BUFFER_SIZE);
	printf("%s \n", buffer);
	printf("phrase 1 %s\n",ft_substr(buffer, &i));
	printf("back slach in : ");
	printf(back_slach_in(buffer, &i) ? "yes\n" : "no\n");
	temp = ft_strdup(buffer);
	read(fd, buffer,  BUFFER_SIZE);
	printf("temp : %s \n", temp);
	printf("buffer : %s\n", buffer);
	temp = ft_strjoin(temp, buffer);
	printf("temp : %s \n", temp);
	//read(fd, buffer, BUFFER_SIZE);
	i = 0;
	printf("phrase 2 %s\n",ft_substr(temp, &i)); */
	//printf("phrase 3 %s\n",ft_substr(buffer, &i));
	//printf("phrase 4 %s\n",ft_substr(buffer, &i));
	//printf("phrase 5 %s\n",ft_substr(buffer, &i)); 

	return (0);
}