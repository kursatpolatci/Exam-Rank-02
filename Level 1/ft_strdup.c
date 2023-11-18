/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 08:12:35 by kpolatci          #+#    #+#             */
/*   Updated: 2023/08/15 08:15:43 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		size;
	char	*dup;

	size = ft_strlen(src) + 1;
	dup = (char *)malloc(sizeof(char) * size);
	if (!dup)
		return (0);
	dup[size--] = '\0';
	while (size >= 0)
	{
		dup[size] = src[size];
		size--;
	}
	return (dup);
}
