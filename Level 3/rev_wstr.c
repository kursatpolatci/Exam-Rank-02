/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 03:19:07 by kpolatci          #+#    #+#             */
/*   Updated: 2023/08/15 13:08:48 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	whitespaces(char *str, int *index)
{
	while ((str[*index] == ' ' || str[*index] == '\t') && *index != 0)
		*index -= 1;
}

void	print_str(char *str, int *index)
{
	while (str[*index] != ' ' && str[*index] != '\t' && *index >= 0)
		*index -= 1;
	*index += 1;
	while (str[*index] != ' ' && str[*index] != '\t' && str[*index])
	{
		write(1, &str[*index], 1);
		*index += 1;
	}
	*index -= 1;
	while (str[*index] != ' ' && str[*index] != '\t' && *index >= 0)
		*index -= 1;
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	int	index;

	if (argc == 2)
	{
		index = ft_strlen(argv[1]) - 1;
		whitespaces(argv[1], &index);
		while (index >= 0)
		{
			print_str(argv[1], &index);
			if ((argv[1][index]) != '\0')
				write(1, " ", 1);
			else
			{
				write(1, "\n", 1);
				return (0);
			}
			whitespaces(argv[1], &index);
		}
	}
	write(1, "\n", 1);
}
