/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ztan <ztan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/13 17:18:21 by ztan          #+#    #+#                 */
/*   Updated: 2020/12/13 19:12:05 by ztan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
	int		r;
	char	*line;

	line = NULL;
	while ((r = get_next_line(&line)) > 0)
	{
		printf("[%s]\n", line);
		free(line);
		line = NULL;
	}
	printf("[%s]", line);
	free(line);
	line = NULL;
}