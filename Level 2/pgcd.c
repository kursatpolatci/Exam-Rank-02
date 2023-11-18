/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 03:26:05 by kpolatci          #+#    #+#             */
/*   Updated: 2023/08/13 03:57:50 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	whitespaces(char *str, int *index, int *sign)
{
	while ((str[*index] >= 9 && str[*index] <= 13) || str[*index] == 32)
		*index += 1;
	if (str[*index] == 43 || str[*index] == 45)
	{
		if (str[*index] == 45)
			*sign = -1;
		*index += 1;
	}
}

int	ft_atoi(char *str)
{
	int	result;
	int	index;
	int	sign;

	index = 0;
	sign = 1;
	result = 0;
	whitespaces(str, &index, &sign);
	while (str[index] >= '0' && str[index] <= '9' && str[index])
	{
		result = (result * 10) + (str[index] - '0');
		index++;
	}
	return (result * sign);
}

void	ft_putnbr(unsigned int nbr)
{
	char	*base;

	base = "0123456789";
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		write(1, &base[nbr % 10], 1);
	}
	else if (nbr >= 0 && nbr <= 9)
		write(1, &base[nbr % 10], 1);
}

int	main(int argc, char **argv)
{
	int	number1;
	int	number2;
	int	i;
	int	max;

	if (argc == 3)
	{
		number1 = ft_atoi(argv[1]);
		number2 = ft_atoi(argv[2]);
		i = 2;
		max = 1;
		while (i <= number1 && i <= number2)
		{
			if (!(number1 % i))
			{
				if (!(number2 % i))
					max = i;
			}
			i++;
		}
		ft_putnbr(max);
	}
	write(1, "\n", 1);
}
