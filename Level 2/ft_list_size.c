/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 22:36:36 by kpolatci          #+#    #+#             */
/*   Updated: 2023/08/19 22:40:17 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}	t_list;

int	ft_list_size(t_list *begin_list)
{
	int	len;

	len = 0;
	if (!begin_list)
		return (0);
	while (begin_list != 0)
	{
		begin_list = begin_list -> next;
		len++;
	}
	return (len);
}
