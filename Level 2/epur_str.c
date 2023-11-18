/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 22:22:22 by kpolatci          #+#    #+#             */
/*   Updated: 2023/08/13 22:57:01 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	first_character(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] > 32 && str[i] < 127)
			return (i);
		i++;
	}
	return (i);
}

int	last_character(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	i--;
	while (str[i] == ' ' || str[i] == '\t')
		i--;
	return (i);
}

void	whitespaces(char *str, int *index)
{
	while (str[*index] == ' ' || str[*index] == '\t')
		*index += 1;
	if (*index == first_character(str))
		return ;
	write(1, " ", 1);
}

int	main(int argc, char **argv)
{
	int	index;
	int	last_index;

	if (argc == 2)
	{
		index = 0;
		last_index = last_character(argv[1]);
		while (argv[1][index])
		{
			if (argv[1][index] == ' ' || argv[1][index] == '\t')
				whitespaces(argv[1], &index);
			if (argv[1][index] == '\0')
				break ;
			if (!(index == last_index))
				write(1, &argv[1][index], 1);
			if (index == last_index)
			{
				write(1, &argv[1][index], 1);
				break ;
			}
			index++;
		}
	}
	write(1, "\n", 1);
}
