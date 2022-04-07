/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:22:14 by eandre-f          #+#    #+#             */
/*   Updated: 2022/04/07 02:54:51 by eandre-f         ###   ########.fr       */
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
	i = 1;
	while (i <= n)
	{
		dest_uc[n - i] = src_uc[n - i];
		i++;
	}
	return (dest);
}
