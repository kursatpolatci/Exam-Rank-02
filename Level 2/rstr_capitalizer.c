/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 02:34:26 by kpolatci          #+#    #+#             */
/*   Updated: 2023/08/14 03:15:23 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_last_character_of_word(char *str, int i)
{
	if (str[i + 1] <= 32 || str[i + 1] == 127 || str[i + 1] == '\0')
		return (1);
	return (0);
}

void	print_upper(char *str, int i)
{
	char	c;

	if (str[i] >= 'a' && str[i] <= 'z')
	{
		c = str[i] - 32;
		write(1, &c, 1);
	}
	else
		write(1, &str[i], 1);
}

void	print_lower(char *str, int i)
{
	char	c;

	if (str[i] >= 'A' && str[i] <= 'Z')
	{
		c = str[i] + 32;
		write(1, &c, 1);
	}
}

void	capitalizer(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_last_character_of_word(str, i))
			print_upper(str, i);
		else if (str[i] >= 'A' && str[i] <= 'Z')
			print_lower(str, i);
		else
			write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	index;

	index = 1;
	while (index <= argc - 1)
	{
		capitalizer(argv[index]);
		write(1, "\n", 1);
		index++;
	}
	if (argc == 1)
		write(1, "\n", 1);
}
