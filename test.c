/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 17:32:12 by mkacemi           #+#    #+#             */
/*   Updated: 2025/12/28 17:36:36 by mkacemi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int	fd;
	fd = open(argv[1], O_RDONLY);
	(void)argc;
	char *line = get_next_line(fd);
	printf("[");
	while(line)
	{
		printf("hello");
		printf("%s",line);
		line = get_next_line(fd);
	}
	printf("]");
	close (fd);
}