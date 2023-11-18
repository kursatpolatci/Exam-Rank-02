/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 00:16:15 by kpolatci          #+#    #+#             */
/*   Updated: 2023/08/20 02:03:02 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	whitespaces(char *str, int *index)
{
	while ((str[*index] >= 9 && str[*index] <= 13) || str[*index] == 32)
		*index += 1;
}

void	pass_words(char *str, int *index)
{
	while (str[*index] > 32 && str[*index] < 127 && str[*index])
		*index += 1;
}

int	word_counter(char *str)
{
	int	count;
	int	index;

	index = 0;
	count = 0;
	whitespaces(str, &index);
	while (str[index])
	{
		if (str[index] > 32 && str[index] < 128)
		{
			count++;
			pass_words(str, &index);
		}
		else
			whitespaces(str, &index);
	}
	return (count);
}

char	*sub_string(char *str, int index)
{
	char	*sub;
	int		len;

	len = 0;
	whitespaces(str, &index);
	while (str[index] > 32 && str[index] < 127)
	{
		len++;
		index++;
	}
	if (len == 0)
		return (0);
	sub = (char *)malloc(sizeof(char) * (len + 1));
	sub[len--] = '\0';
	index--;
	while (len >= 0)
		sub[len--] = str[index--];
	return (sub);
}

char	**ft_split(char *str)
{
	int		index;
	int		split_index;
	char	**split;

	index = 0;
	split_index = 0;
	split = (char **)malloc(sizeof(char *) * (word_counter(str) + 1));
	whitespaces(str, &index);
	while (str[index])
	{
		split[split_index++] = sub_string(str, index);
		pass_words(str, &index);
		whitespaces(str, &index);
	}
	split[split_index] = '\0';
	return (split);
}
