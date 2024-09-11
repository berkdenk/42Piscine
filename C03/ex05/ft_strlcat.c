/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstawski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:34:05 by mstawski          #+#    #+#             */
/*   Updated: 2024/09/09 22:19:33 by mstawski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	k = 0;
	j = 0;
	i = 0;
	while (dest[i] != '\0' && i < size)
		i++;
	while (src[j] != '\0')
		j++;
	if (i >= size)
		return (size + j);
	while (src[k] != '\0' && (k + i) < (size - 1))
	{
		dest[k + i] = src[k];
		k++;
	}
	if ((i + k) < size)
		dest[k + i] = '\0';
	return (i + j);
}

int	main(void)
{
	char d[15] = "heja";
	char s[] = " co tam";
	unsigned int r = 14;

	printf("%i\n", ft_strlcat(d, s, r));
	printf("%s\n", d);
}
