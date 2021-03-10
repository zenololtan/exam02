/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   inter.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ztan <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/13 16:54:59 by ztan          #+#    #+#                 */
/*   Updated: 2020/12/13 17:06:35 by ztan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int argc, char **argv){
	int used[255];
	int i = 0; // -1?

	if (argc == 3)
	{
		while (i < 255)
			used[i++] = 0;
		i = 0;
		while (argv[2][i])
		{
			used[(unsigned char)argv[2][i]] = 1;
			i++;
		}
		i = 0;
		while (argv[1][i])
		{
			if (used[(unsigned char)argv[1][i]] == 1)
			{
				write(1, &argv[1][i], 1);
				used[(unsigned char)argv[1][i]] = 0;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}