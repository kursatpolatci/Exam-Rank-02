/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 06:37:02 by kpolatci          #+#    #+#             */
/*   Updated: 2023/08/15 06:57:09 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*ft_rrange(int start, int end)
{
	int	*array;
	int	index;

	index = 0;
	if (start >= end)
		array = (int *)malloc(sizeof(int) * (start - end + 1));
	else if (start < end)
		array = (int *)malloc(sizeof(int) * (end - start + 1));
	if (!array)
		return (0);
	if (start >= end)
	{
		while (start >= end)
			array[index++] = end++;

	}
	else
	{
		while (end >= start)
			array[index++] = end--;

	}
	return (array);
}
