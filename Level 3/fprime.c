/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 14:53:41 by kpolatci          #+#    #+#             */
/*   Updated: 2023/08/13 14:18:10 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprime(int nbr)
{
	int	i;

	i = 2;
	if (nbr < 2)
		return (0);
	if (nbr == 2)
		return (1);
	while (i <= nbr / 2)
	{
		if (nbr % i == 0)
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

int	ft_nearestdivideprime(int nbr)
{
	int	i;

	i = 0;
	while (i <= nbr)
	{
		if (ft_isprime(i))
		{
			if (nbr % i == 0)
				return (i);
		}
		i++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result * sign);
}

int	main(int argc, char **argv)
{
	int	number;
	int	prove;

	if (argv[1])
		number = ft_atoi(argv[1]);
	if (argc == 2)
	{
		if (ft_isprime(number))
			ft_putnbr (number);
		else if (number == 1)
			write(1, "1", 1);
		else
		{
			prove = ft_nearestdivideprime(number);
			while (prove > 0)
			{
				ft_putnbr(prove);
				number /= prove;
				prove = ft_nearestdivideprime(number);
				if (prove != 0)
					write(1, "*", 1);
			}
		}
	}
	write(1, "\n", 1);
}
