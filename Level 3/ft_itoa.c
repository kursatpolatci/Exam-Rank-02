/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:08:28 by kpolatci          #+#    #+#             */
/*   Updated: 2023/08/19 22:42:18 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_count_digit(int nbr)
{
	int	count;

	count = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr *= -1;
		count++;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int nbr)
{
	int		count_digit;
	char	*array;

	count_digit = ft_count_digit(nbr);
	array = (char *)malloc(sizeof(char) * (ft_count_digit(nbr) + 1));
	if (!array)
		return (0);
	if (nbr == 0)
	{
		array[count_digit--] = '\0';
		array[count_digit] = '0';
		return (array);
	}
	if (nbr < 0)
	{
		array[0] = '-'; 
		nbr *= -1;
	}
	array[count_digit] = '\0';
	while (nbr > 0)
	{
		if (count_digit == 0)
			break ;
		array[--count_digit] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (array);
}
