/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 18:05:53 by kpolatci          #+#    #+#             */
/*   Updated: 2023/08/11 19:35:36 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	first_check(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	second_check(char *str1, char *str2, int c)
{
	int	i;

	i = 0;
	if (first_check(str1, c))
		return (1);
	if (first_check(str2, c))
		return (1);
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
			if (!first_check (argv[1], argv[1][i]))
				write(1, &argv[1][i], 1);
			i++;
		}
		i = 0;
		while (argv[2][i])
		{
			if (!second_check(argv[1], argv[2], argv[2][i]))
				write(1, &argv[2][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}
