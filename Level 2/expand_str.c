/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 02:30:04 by kpolatci          #+#    #+#             */
/*   Updated: 2023/08/20 02:41:07 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	whitespaces(char *str, int *index)
{
	while ((str[*index] >= 9 && str[*index] <= 13) || str[*index] == 32)
		*index += 1;
}

void	print_word(char *str, int *index)
{
	while (str[*index] > 32 && str[*index] < 127 && str[*index])
	{
		write(1, &str[*index], 1);
		*index += 1;
	}
}

int	main(int argc, char **argv)
{
	int	index;

	if (argc == 2)
	{
		index = 0;
		whitespaces(argv[1], &index);
		while (argv[1][index])
		{
			print_word(argv[1], &index);
			whitespaces(argv[1], &index);
			if (argv[1][index] != '\0')
				write(1, "   ", 3);
		}
	}
	write(1, "\n", 1);
}
