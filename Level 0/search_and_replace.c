/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 02:31:43 by kpolatci          #+#    #+#             */
/*   Updated: 2023/08/13 02:50:01 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int	i;

	i = 0;
	if (argc == 4)
	{
		if (ft_strlen(argv[2]) != 1 || ft_strlen(argv[3]) != 1 || 
			ft_strlen(argv[1]) == 0)
		{
			write(1, "\n", 1);
			return (0);
		}
		while (argv[1][i])
		{
			if (argv[1][i] == *argv[2])
				write(1, &(*argv[3]), 1);
			else
				write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}
