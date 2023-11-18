/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 22:44:36 by kpolatci          #+#    #+#             */
/*   Updated: 2023/08/13 02:29:45 by kpolatci         ###   ########.fr       */
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

int	process(int number1, int number2, int operator)
{
	if (operator == '+')
		return (number1 + number2);
	else if (operator == '-')
		return (number1 - number2);
	else if (operator == '/')
		return (number1 / number2);
	else if (operator == '*')
		return (number1 * number2);
	else
		return (0);
}

void	ft_putnbr(int nbr)
{
	char	*base;

	base = "0123456789";
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
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

	if (argc == 4)
	{
		number1 = ft_atoi (argv[1]);
		number2 = ft_atoi (argv[3]);
		ft_putnbr(process(number1, number2, argv[2][0]));
	}
	write(1, "\n", 1);
}
