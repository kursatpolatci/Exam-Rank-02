/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 04:21:49 by kpolatci          #+#    #+#             */
/*   Updated: 2023/08/13 04:28:49 by kpolatci         ###   ########.fr       */
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

void	print_multip(int *number)
{
	int	i;

	i = 1;
	while (i <= 9)
	{
		ft_putnbr(i);
		write(1, " x ", 3);
		ft_putnbr(*number);
		write(1, " = ", 3);
		ft_putnbr(i * (*number));
		if (i != 9)
			write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	number;

	if (argc == 2)
	{
		number = ft_atoi(argv[1]);
		print_multip(&number);
	}
	write(1, "\n", 1);
}
