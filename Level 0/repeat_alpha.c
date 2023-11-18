/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 21:14:38 by kpolatci          #+#    #+#             */
/*   Updated: 2023/08/12 22:39:52 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_repeat(char c, int count)
{
	while (count >= 0)
	{
		write(1, &c, 1);
		count--;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	index;

	index = 0;
	i = 0;
	if (argc == 2)
	{
		while (argv[1][index])
		{
			i = 0;
			if (argv[1][index] >= 'a' && argv[1][index] <= 'z')
			{
				i = argv[1][index] - 'a';
				print_repeat(argv[1][index], i);
			}
			else if (argv[1][index] >= 'A' && argv[1][index] <= 'Z')
			{
				i = argv[1][index] - 'A';
				print_repeat(argv[1][index], i);
			}
			else
				write(1, &argv[1][index], 1);
			index++;
		}
	}
	write(1, "\n", 1);
}
