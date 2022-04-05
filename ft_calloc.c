/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:55:10 by eandre-f          #+#    #+#             */
/*   Updated: 2022/04/05 21:50:40 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*p;
	int		max;

	max = 2147483647;
	if (nelem == 0 || elsize == 0 || nelem > max / elsize)
		return (NULL);
	p = malloc(nelem * elsize);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, (nelem * elsize));
	return (p);
}
