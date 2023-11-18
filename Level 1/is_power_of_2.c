/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 13:47:30 by kpolatci          #+#    #+#             */
/*   Updated: 2023/08/11 15:11:45 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_power_of_2(unsigned int n)
{
	unsigned int	number;

	number = n;
	if (number == 1 || number == 2)
		return (1);
	if (number <= 0)
		return (0);
	while (number > 0)
	{
		if (number == 2)
			return (1);
		if (number % 2 == 0)
			number /= 2;
		else
			return (0);
	}
	return (1);
}
