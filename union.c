/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   union.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ztan <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/06 14:44:38 by ztan          #+#    #+#                 */
/*   Updated: 2020/12/06 17:13:55 by ztan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int argc, char **argv)
{
	int buff[255];
	int i, j;

	if (argc == 3)
	{
		i = 0;
		while (i <= 255)
			buff[i++] = 0;
		i = 1;
		while (i <= 2)
		{
			j = 0;	
			while (argv[i][j])
			{
				if (!buff[(unsigned char)argv[i][j]])
				{
					buff[(unsigned char)argv[i][j]] = 1;
					write(1, &argv[i][j], 1);
				}
				++j;
			}
			++i;
		}
	}
	write(1, "\n", 1);
	return (0);
}