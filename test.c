/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:29:37 by mkacemi           #+#    #+#             */
/*   Updated: 2025/12/21 00:27:10 by mkacemi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char  *s, int *i)
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

static size_t	ft_strlen(const char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}


int	back_slach_in(char *s, int *j)
{
	int	i;

	i = *j;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		s++;
	}
	return (0);
}



char	*ft_strdup(const char *src)
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

char	*ft_strjoin(char const *s1, char const *s2)
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


int	main(int argc, char **argv)
{
	int fd;
	int	i=0;
	char *temp;
	static char	buffer[3];

	fd = open(argv[1], O_RDONLY);
	read(fd, buffer, sizeof(buffer));
	printf("before stjoin : %s|\n",buffer);
	printf("%d \n",back_slach_in(buffer, &i));
	temp = ft_strdup(buffer);
	read(fd, buffer, sizeof(buffer));
	temp = ft_strjoin(temp, buffer);
	printf("fqter strjoin : %s|\n",temp);
	printf("%d",back_slach_in(temp, &i));
	/* //printf("%s \n", buffer);
	printf("phrase 1 %s\n",ft_substr(buffer, &i));
	//printf("%d\n",i);
	//printf("%c",buffer[i]);
	//read(fd, buffer, sizeof(buffer));
	printf("phrase 2 %s\n",ft_substr(buffer, &i));
	printf("phrase 3 %s\n",ft_substr(buffer, &i));
	printf("phrase 4 %s\n",ft_substr(buffer, &i));
	printf("phrase 5 %s\n",ft_substr(buffer, &i)); */
	return (0);
}