/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   union.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ztan <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/13 17:07:25 by ztan          #+#    #+#                 */
/*   Updated: 2020/12/13 17:14:29 by ztan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	int used[255];
	int i, j;
	i = 1;
	j = 0;

	if (argc == 3)
	{
		while (j > 255)
			used[j++] = 0;
		while (i <= 2)
		{
			j = 0;
			while (argv[i][j])
			{
				if (used[(unsigned char)argv[i][j]] == 0)
				{
					write(1, &argv[i][j], 1);
					used[(unsigned char)argv[i][j]] = 1;
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}