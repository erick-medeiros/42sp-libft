/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:22:14 by eandre-f          #+#    #+#             */
/*   Updated: 2022/04/10 21:09:08 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest_uc;
	unsigned char	*src_uc;

	dest_uc = (unsigned char *)dest;
	src_uc = (unsigned char *)src;
	if (src_uc < dest_uc)
	{
		i = 1;
		while (i <= n)
		{
			dest_uc[n - i] = src_uc[n - i];
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			dest_uc[i] = src_uc[i];
			i++;
		}
	}
	return (dest);
}
