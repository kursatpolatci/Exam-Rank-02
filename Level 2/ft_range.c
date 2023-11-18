/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:14:22 by kpolatci          #+#    #+#             */
/*   Updated: 2023/08/15 06:11:18 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*ft_range(int start, int end)
{
	int	size;
	int	*array;

	size = end - start + 1;
	if (start > end)
		size = start - end + 1;
	array = (int *)malloc(sizeof(int) * (size));
	if (!array)
		return (0);

	if (end > start)
	{
		while (size)
			array[--size] = end--;
	}
	else if (start > end)
	{
		while (size)
			array[--size] = end++;
	}
	else
		array[--size] = 0;
	return (array);
}
