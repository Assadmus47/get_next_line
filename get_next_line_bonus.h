/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 17:57:31 by mkacemi           #+#    #+#             */
/*   Updated: 2025/12/29 17:58:01 by mkacemi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h> 
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

char	*get_next_line(int fd);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *src);
char	*ft_strchr(const char *s, int c);

#endif