/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   inter.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ztan <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/06 17:14:27 by ztan          #+#    #+#                 */
/*   Updated: 2020/12/06 17:30:56 by ztan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int usable[255];
	int i;

	if (argc == 3)
	{
		i = 0;
		while (i <= 255)
			usable[i++] = 0;
		i = 0;
		while (argv[2][i])
		{
			usable[(unsigned int)argv[2][i]] = 1;
			++i;
		}
		i = 0;
		while (argv[1][i])
		{
			if (usable[(unsigned int)argv[1][i]])
			{
				write(1, &argv[1][i], 1);
				usable[(unsigned int)argv[1][i]] = 0;
			}
			++i;
		}
	}
	write(1, "\n", 1);
	return (0);
}