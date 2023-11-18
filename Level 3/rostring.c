/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 22:59:42 by kpolatci          #+#    #+#             */
/*   Updated: 2023/08/14 00:27:01 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	whitespaces(char *str, int *index)
{
	while (str[*index] == '\t' || str[*index] == ' ')
		*index += 1;
}

int	first_word(char *str)
{
	int	index;

	index = 0;
	whitespaces(str, &index);
	while (str[index] > 32 && str[index] < 127)
		index++;
	return (index);
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

int	main(int argc, char **argv)
{
	int	index;
	int	last_c_index;

	last_c_index = last_character(argv[1]);
	index = first_word(argv[1]);
	whitespaces(argv[1], &index);
	while (argv[1][index])
	{
		if (index == last_c_index)
		{
			write(1, &argv[1][index], 1);
			write(1, " ", 1);
			break ;
		}
		if (argv[1][index] == ' ' || argv[1][index] == '\t')
		{
			whitespaces(argv[1], &index);
			write(1, " ", 1);
		}
		write(1, &argv[1][index], 1);
		index++;
	}
	index = first_word(argv[1]);
	index--;
	while (index >= 0 && argv[1][index] > 32 && argv[1][index] < 127)
		index--;
	index++;
	while (index >= 0 && argv[1][index] > 32 && argv[1][index] < 127)
	{
		write(1, &argv[1][index], 1);
		index++;
	}
	write(1, "\n", 1);
}
