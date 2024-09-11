/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenk <bdenk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:43:48 by bdenk             #+#    #+#             */
/*   Updated: 2024/09/08 19:05:34 by bdenk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_valid_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_len;
	long	num;
	char	buffer[32];
	int		i;

	num = nbr;
	if (!is_valid_base(base))
		return ;
	base_len = ft_strlen(base);
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
	}
	i = 0;
	while (num >= base_len)
	{
		buffer[i++] = base[num % base_len];
		num /= base_len;
	}
	buffer[i++] = base[num];
	while (i--)
		write(1, &buffer[i], 1);
}
