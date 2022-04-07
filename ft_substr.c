/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 22:00:24 by eandre-f          #+#    #+#             */
/*   Updated: 2022/04/07 23:24:04 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	slen;

	slen = ft_strlen(s);
	if (start > slen)
		return (ft_strdup(""));
	if (slen - start > len)
		sub = (char *) malloc(sizeof(char) * (len + 1));
	else
		sub = (char *) malloc(sizeof(char) * (slen - start + 1));
	if (sub == NULL)
		return (NULL);
	ft_strlcpy(sub, (s + start), (len + 1));
	return (sub);
}
