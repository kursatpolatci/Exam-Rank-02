/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 20:01:50 by kpolatci          #+#    #+#             */
/*   Updated: 2023/08/14 00:49:27 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
		i++;
	i--;
	while (str[i] == ' ' || str[i] == '\t')
		i--;
	while (str[i] != ' ' && str[i] != '\t' && i >= 0)
		i--;
	i++;
	while (str[i] != ' ' && str[i] != '\t' && str[i])
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
