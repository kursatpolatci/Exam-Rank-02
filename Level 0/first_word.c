/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 19:46:46 by kpolatci          #+#    #+#             */
/*   Updated: 2023/08/11 19:58:37 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	while (str[i] != ' ' && str[i] && str[i] != '\t')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		print_str(argv[1]);
	write(1, "\n", 1);
}
