/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 19:21:19 by kpolatci          #+#    #+#             */
/*   Updated: 2023/08/14 19:43:37 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	convert(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		if (c <= 'M')
		{
			c = 'Z' - (c - 'A');
			write(1, &c, 1);
		}
		else if (c >= 'N')
		{
			c = 'A' + ('Z' - c);
			write(1, &c, 1);
		}
	}
	else if (c >= 'a' && c <= 'z')
	{
		if (c <= 'm')
		{
			c = 'z' - (c - 'a');
			write(1, &c, 1);
		}
		else if (c >= 'n')
		{
			c = 'a' + ('z' - c);
			write(1, &c, 1);
		}
	}
	else
		write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i])
		{
			convert(argv[1][i]);
			i++;
		}
	}
	write(1, "\n", 1);
}
