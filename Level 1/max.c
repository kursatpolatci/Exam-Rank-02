/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 06:22:21 by kpolatci          #+#    #+#             */
/*   Updated: 2023/08/15 06:36:13 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	max(int *tab, unsigned int len)
{
	int	max;
	int	index;

	index = 0;
	if (len == 0)
		return (0);
	max = tab[0];
	while (index < len)
	{
		if (tab[index] >= max)
			max = tab[index];
		index++;
	}
	return (max);
}
