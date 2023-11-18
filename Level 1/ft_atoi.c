/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 04:10:38 by kpolatci          #+#    #+#             */
/*   Updated: 2023/08/13 04:17:59 by kpolatci         ###   ########.fr       */
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
