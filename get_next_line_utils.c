/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 11:01:00 by marvin            #+#    #+#             */
/*   Updated: 2025/12/06 11:01:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void test_static(void)
{
	static int a = 0 ;
	printf("%d \n",a);
	a++;
}

int	main(void)
{
	test_static();
	test_static();
	test_static();
	test_static();
}