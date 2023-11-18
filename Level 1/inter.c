/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 12:31:59 by kpolatci          #+#    #+#             */
/*   Updated: 2023/08/13 14:16:27 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_doubles(char *str1, char *str2, int index, char c)
{
	int	i;

	i = 0;
	while (str1[i])
	{
		if (str1[i] == c)
		{
			if (index > i)
				return (0);
		}
		i++;
	}
	i = 0;
	while (str2[i])
	{
		if (str2[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 3)
	{
		while (argv[1][i])
		{
			if (check_doubles(argv[1], argv[2], i, argv[1][i]))
				write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}
