/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:29:37 by mkacemi           #+#    #+#             */
/*   Updated: 2025/12/25 18:06:17 by mkacemi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(char *str)
{
	size_t	i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char  *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	lens;
	char	*sub;

	if (!s)
		return (NULL);
	lens = ft_strlen(s);
	sub = malloc((sizeof(char) * (len + 1)));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len)
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}

void	ft_strcopy(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
}

char	*ft_strcut(char  *s, size_t *i)
{
	size_t	j;
	size_t	lens;
	char	*sub;

	if (!s)
		return (NULL);
	//s[BUFFER_SIZE + 1] = 1;
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
	//printf("i = %zu , j = %zu \n",*i,j);
	ft_strcopy(s , ft_substr(s, *i, BUFFER_SIZE));
	return (sub);
}

int	back_slach_in(char *s, size_t *j)
{
	size_t	i;

	i = *j;
	while (s[i])
	{
		if (s[i] == '\n')
		{
			return (1);
		}
		i++;
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
	printf("strlen %zu \n",ft_strlen(buffer));
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!back_slach_in(buffer, &i))
	//if (buffer[BUFFER_SIZE + 1] != 1)
	{
		//printf("[buffer]\n",buffer);
		if (read(fd, buffer, BUFFER_SIZE) == -1)
			return (NULL);
	}
	if (back_slach_in(buffer, &i))
	{
		return (ft_strcut(buffer, &i));
	}
	else
	{
		str = ft_strdup(buffer);
		while (!back_slach_in(str, &i))
		{
			temp = ft_strdup(buffer);
			if (read(fd, buffer, BUFFER_SIZE) == -1)
			return (NULL);
			//printf("avant str join : str : %s buffer : %s \n", str, buffer);
			str = ft_strjoin(str, buffer);
			//printf("apres str join : str : %s buffer : %s \n", str, buffer);
		}
	}
	return (ft_strcut(str, &i));
}

char *get_next_line1(int fd)
{
	size_t			i;
	char 			*temp;
	char 			*str;
	static char		buffer[BUFFER_SIZE + 1];

	i = 0;
	buffer[BUFFER_SIZE] = 0;
	printf("strlen %zu \n",ft_strlen(buffer));
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!back_slach_in(buffer, &i))
	//if (buffer[BUFFER_SIZE + 1] != 1)
	{
		//printf("[buffer]\n",buffer);
		if (read(fd, buffer, BUFFER_SIZE) == -1)
			return (NULL);
	}
	if (back_slach_in(buffer, &i))
	{
		return (ft_strcut(buffer, &i));
	}
	else
	{
		str = ft_strdup(buffer);
		while (!back_slach_in(str, &i))
		{
			temp = ft_strdup(buffer);
			if (read(fd, buffer, BUFFER_SIZE) == -1)
			return (NULL);
			//printf("avant str join : str : %s buffer : %s \n", str, buffer);
			str = ft_strjoin(str, buffer);
			//printf("apres str join : str : %s buffer : %s \n", str, buffer);
		}
	}
	return (ft_strcut(str, &i));
}


int	main(int argc, char **argv)
{
	int fd;
	//har *temp;
	static char	buffer[BUFFER_SIZE + 1];
	char *str;
	//size_t i = 0;

	//buffer[BUFFER_SIZE] = 0;
	fd = open(argv[1], O_RDONLY);
	//read(fd, buffer, BUFFER_SIZE);
	//printf("%s \n", buffer);
	//str = ft_substr(buffer,5,BUFFER_SIZE);
	//ft_strcopy(buffer , str);
	//read(fd, buffer, BUFFER_SIZE);
	//printf("%s \n", buffer); 
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	//printf("%s", get_next_line(fd));
	//printf("%s", get_next_line(fd));
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