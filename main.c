/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ztan <ztan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/06 17:38:07 by ztan          #+#    #+#                 */
/*   Updated: 2020/12/06 20:33:56 by ztan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	char	*line = "lol idk\nhope it works \nyee";
	int		r;
	
	while ((r = get_next_line(&line)) > 0)
		printf("%s\n", line);
	printf("%s", line);
	return (0);
}