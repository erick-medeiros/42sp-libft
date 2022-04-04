/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:22:14 by eandre-f          #+#    #+#             */
/*   Updated: 2022/04/04 15:42:25 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*temporary_array;
	size_t	i;

	i = 0;
	temporary_array = (char *)src;
	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = ((char *)temporary_array)[i];
		i++;
	}
	return (dest);
}
