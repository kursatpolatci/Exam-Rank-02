/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 20:38:59 by kpolatci          #+#    #+#             */
/*   Updated: 2023/08/11 21:19:00 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putnbr(unsigned int nbr)
{
	char	*base;

	base = "0123456789";
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
	if (argc == 1)
		write(1, "0", 1);
	else
	{
		argc -= 1;
		ft_putnbr(argc);
	}
	write(1, "\n", 1);
}
