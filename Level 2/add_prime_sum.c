/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 20:00:01 by kpolatci          #+#    #+#             */
/*   Updated: 2023/08/14 20:20:59 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	whitespaces(const char *str, int *index, int *sign)
{
	*index = 0;
	*sign = 1;
	while ((str[*index] >= 9 && str[*index] <= 13) || str[*index] == 32)
		*index += 1;
	if (str[*index] == 43 || str[*index] == 45)
	{
		if (str[*index] == 45)
			*sign = -1;
		*index += 1;
	}
}

int	ft_atoi(const char *str)
{
	int	result;
	int	index;
	int	sign;

	result = 0;
	whitespaces(str, &index, &sign);
	while (str[index] >= '0' && str[index] <= '9' && str[index])
	{
		result = (result * 10) + (str[index] - '0');
		index += 1;
	}
	return (result * sign);
}

int	is_prime(int nbr)
{
	int	i;

	i = 2;
	if (nbr < 2)
		return (0);
	if (nbr == 2)
		return (1);
	while (i <= nbr / 2)
	{
		if (!(nbr % i))
			return (0);
		i++;
	}
	return (1);
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
	int	number;
	int	result;

	if (argc == 2)
	{
		number = ft_atoi(argv[1]);
		if (number < 0)
		{
			write(1, "\n", 1);
			return (0);
		}
		while (number > 1)
		{
			if (is_prime(number))
				result += number;
			number--;
		}
		ft_putnbr(result);
	}
	else
		ft_putnbr(0);
	write(1, "\n", 1);
}
