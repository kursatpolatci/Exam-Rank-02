/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 07:04:21 by kpolatci          #+#    #+#             */
/*   Updated: 2023/08/15 08:07:32 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	find_character(char *str, int c, int index)
{
	while (str[index])
	{
		if (str[index] == c)
			return (index);
		index++;
	}
	return (-1);
}

int	main(int argc, char **argv)
{
	int	index;
	int	finded_i;
	int	tmp;

	index = 0;
	finded_i = 0;
	tmp = -1;
	if (argc == 3)
	{
		while (argv[1][index])
		{
			finded_i = find_character(argv[2], argv[1][index], finded_i);
			if (finded_i == -1 || finded_i < tmp)
			{
				write(1, "0\n", 2);
				return (0);
			}
			index++;
			tmp = finded_i;
		}
		write(1, "1", 1);
	}
	write(1, "\n", 1);
}
