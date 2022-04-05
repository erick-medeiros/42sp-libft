/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 12:48:40 by eandre-f          #+#    #+#             */
/*   Updated: 2022/04/05 16:17:40 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int		i;
	char	*suc;
	char	cuc;

	suc = (unsigned char *)s;
	cuc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (suc[i] == cuc)
			return (&suc[i]);
		i++;
	}
	return (NULL);
}
