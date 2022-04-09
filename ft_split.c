/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 00:12:23 by eandre-f          #+#    #+#             */
/*   Updated: 2022/04/09 03:40:10 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_split_is_word(char const *s, char c, size_t i)
{
	if (s[i] != c)
		if (i == 0 || (i > 0 && s[i - 1] == c))
			return (1);
	return (0);
}

static size_t	ft_split_count_words(char const *s, char c)
{
	size_t	i;
	size_t	count_words;

	i = 0;
	count_words = 0;
	while (s[i] != '\0')
	{
		if (ft_split_is_word(s, c, i) == 1)
			count_words++;
		i++;
	}
	return (count_words);
}

static size_t	ft_split_count_characters(char const *s, char c, size_t i, size_t slen)
{
	size_t	count_c;

	count_c = 0;
	while (s[i + count_c] != c && (i + count_c) < slen)
		count_c++;
	return (count_c);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	count_c;
	size_t	count_w;
	char	**splited;

	count_w = ft_split_count_words(s, c);
	splited = (char **) malloc(sizeof(char *) * (count_w + 1));
	if (splited == NULL)
		return (NULL);
	count_w = 0;
	i = 0;
	while (s[i] != '\0' && i < ft_strlen(s))
	{
		if (ft_split_is_word(s, c, i) == 1)
		{
			count_c = ft_split_count_characters(s, c, i, ft_strlen(s));
			splited[count_w] = (char *) malloc(sizeof(char) * (count_c + 1));
			if (splited[count_w] == NULL)
				return (NULL);
			ft_strlcpy(splited[count_w], &s[i], count_c + 1);
			count_w++;
			i++;
		}
		else
			i++;
	}
	splited[count_w] = NULL;
	return (splited);
}
