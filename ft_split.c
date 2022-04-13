/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 00:12:23 by eandre-f          #+#    #+#             */
/*   Updated: 2022/04/13 15:03:53 by eandre-f         ###   ########.fr       */
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

static size_t	ft_split_next_word(char const *s, char c, size_t idword)
{
	size_t	i;

	i = idword;
	while (ft_split_is_word(s, c, i) == 0 && s[i] != '\0')
		i++;
	return (i);
}

static size_t	ft_split_count_characters(char const *sc, char c, size_t i)
{
	size_t	count_c;

	count_c = 0;
	while (sc[i + count_c] != c && sc[i + count_c] != '\0')
		count_c++;
	return (count_c);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	count_c;
	size_t	count_w;
	size_t	idword;
	char	**splited;

	if (s == NULL)
		return (NULL);
	count_w = ft_split_count_words(s, c);
	splited = (char **) malloc(sizeof(char *) * (count_w + 1));
	if (splited == NULL)
		return (NULL);
	idword = -1;
	i = -1;
	while (++i < count_w)
	{
		idword = ft_split_next_word(s, c, ++idword);
		count_c = ft_split_count_characters(s, c, idword);
		splited[i] = (char *) malloc(sizeof(char) * (count_c + 1));
		if (splited[i] == NULL)
			return (NULL);
		ft_strlcpy(splited[i], &s[idword], count_c + 1);
	}
	splited[count_w] = NULL;
	return (splited);
}
