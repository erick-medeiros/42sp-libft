/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 21:16:09 by eandre-f          #+#    #+#             */
/*   Updated: 2022/04/10 21:18:01 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>
#include <bsd/string.h>
#include <stdlib.h>

#define STATUS_SUCESS 0
#define STATUS_ERROR 1
#define MAX_TESTS 20
#define FUNC_TEST(condition) (condition ? STATUS_SUCESS : STATUS_ERROR)

void	ft_test(char *name_test, char *list_test)
{
	int		i;
	int		status;

	status = STATUS_SUCESS;
	i = 0;
	while (i < MAX_TESTS && status == STATUS_SUCESS)
	{
		if (list_test[i] == STATUS_ERROR)
		{
			status = STATUS_ERROR;
			break ;
		}
		i++;
	}
	if (status == STATUS_ERROR)
		printf("%s --------- KO\nError Test %d\n", name_test, i);
	else
		printf("%s OK\n", name_test);
}

void freeTab(char * * tab)
{
	for (int i = 0; tab[i] != NULL; ++i)
		free(tab[i]);
	free(tab);
}

void	test_ft_isalpha(char *list)
{
	list[0] = FUNC_TEST(ft_isalpha('a') != 0 && isalpha('a') != 0);
	list[1] = FUNC_TEST(ft_isalpha('A') != 0 && isalpha('A') != 0);
	list[2] = FUNC_TEST(ft_isalpha('z') != 0 && isalpha('z') != 0);
	list[3] = FUNC_TEST(ft_isalpha('Z') != 0 && isalpha('Z') != 0);
	list[4] = FUNC_TEST(ft_isalpha(1) == isalpha(1));
	list[5] = FUNC_TEST(ft_isalpha('\n') == isalpha('\n'));
	ft_test("ft_isalpha", list);
}

void	test_ft_isdigit(char *list)
{
	list[0] = FUNC_TEST(ft_isdigit('\n') == isdigit('\n'));
	list[1] = FUNC_TEST(ft_isdigit(1) == isdigit(1));
	list[2] = FUNC_TEST(ft_isdigit('a') == isdigit('a'));
	list[3] = FUNC_TEST(ft_isdigit('1') != 0 && isdigit('1') != 0);
	ft_test("ft_isdigit", list);
}

void	test_ft_isalnum(char *list)
{
	list[0] = FUNC_TEST(ft_isalnum('\n') == isalnum('\n'));
	list[1] = FUNC_TEST(ft_isalnum(1) == isalnum(1));
	list[2] = FUNC_TEST(ft_isalnum('a') != 0 && isalnum('a') != 0);
	list[3] = FUNC_TEST(ft_isalnum('1') != 0 && isalnum('1') != 0);
	ft_test("ft_isalnum", list);
}

void	test_ft_isascii(char *list)
{
	list[0] = FUNC_TEST(ft_isascii('\n') != 0 && isascii('\n') != 0);
	list[1] = FUNC_TEST(ft_isascii(0) != 0 && isascii(1) != 0);
	list[2] = FUNC_TEST(ft_isascii(127) != 0 && isascii(127) != 0);
	list[3] = FUNC_TEST(ft_isascii(128) == 0 && isascii(128) == 0);
	list[4] = FUNC_TEST(ft_isascii(178) == 0 && isascii(178) == 0);
	ft_test("ft_isascii", list);
}

void	test_ft_isprint(char *list)
{
	list[0] = FUNC_TEST(ft_isprint('\n') == 0 && isprint('\n') == 0);
	list[1] = FUNC_TEST(ft_isprint(0) == 0 && isprint(1) == 0);
	list[2] = FUNC_TEST(ft_isprint(127) == 0 && isprint(127) == 0);
	list[3] = FUNC_TEST(ft_isprint(' ') != 0 && isprint(' ') != 0);
	list[4] = FUNC_TEST(ft_isprint('~') != 0 && isprint('~') != 0);
	ft_test("ft_isprint", list);
}

void	test_ft_strlen(char *list)
{
	list[0] = FUNC_TEST(ft_strlen("123") == strlen("123"));
	list[1] = FUNC_TEST(ft_strlen("") == strlen(""));
	ft_test("ft_strlen", list);
}

void	test_ft_memset(char *list)
{
	char memset_s1[10];
	char memset_s2[10];
	list[0] = FUNC_TEST(strncmp(ft_memset(memset_s1, 'f', 4), memset(memset_s2, 'f', 4), 4) == 0);
	ft_test("ft_memset", list);
}

void	test_ft_bzero(char *list)
{
	char bzero_buffer1[10];
	char bzero_buffer2[10];
	memset(bzero_buffer1, 'a', 10);
	memset(bzero_buffer2, 'a', 10);
	ft_bzero(bzero_buffer1, 4);
	bzero(bzero_buffer2, 4);
	list[0] = FUNC_TEST(strncmp(bzero_buffer1, bzero_buffer1, 10)  == 0);
	list[1] = FUNC_TEST(bzero_buffer1[1] == '\0' && bzero_buffer2[1] == '\0');
	list[2] = FUNC_TEST(bzero_buffer1[5] == 'a' && bzero_buffer2[5] == 'a');
	ft_test("ft_bzero", list);
}

void	test_ft_memcpy(char *list)
{
	char	memcpy_s1[10];
	char	memcpy_s2[10];
	ft_memcpy(memcpy_s1, "1234567890", 5);
	memcpy(memcpy_s2, "1234567890", 5);
	list[0] = FUNC_TEST(strncmp(memcpy_s1, memcpy_s2, 5)  == 0);
	ft_test("ft_memcpy", list);
}

void	test_ft_memmove(char *list)
{
	char	memmove_s1[10];
	char	memmove_s2[10];
	ft_memmove(memmove_s1, "1234567890", 5);
	memmove(memmove_s2, "1234567890", 5);
	list[0] = FUNC_TEST(strncmp(memmove_s1, memmove_s2, 5)  == 0);

	char	src[] = "lorem ipsum dolor sit amet";
	char	*dest;
	dest = src + 1;
	memmove(dest, "consectetur", 5);
	memmove(dest, "con\0sec\0\0te\0tur", 10);
	memmove(dest, src, 8);
	memmove(src, dest, 8);
	memmove(src, dest, 0);
	char	src2[] = "lorem ipsum dolor sit amet";
	char	*dest2;
	dest2 = src2 + 1;
	ft_memmove(dest2, "consectetur", 5);
	ft_memmove(dest2, "con\0sec\0\0te\0tur", 10);
	ft_memmove(dest2, src2, 8);
	ft_memmove(src2, dest2, 8);
	ft_memmove(src2, dest2, 0);
	list[1] = FUNC_TEST(strncmp(src, src2, strlen(src))  == 0);
	ft_test("ft_memmove", list);
}

void	test_ft_strlcpy(char *list)
{
	char	s1[10];
	char	s2[10];
	ft_strlcpy(s1, "1234567890", 5);
	strlcpy(s2, "1234567890", 5);
	list[0] = FUNC_TEST(strncmp(s1, s2, 5)  == 0);
	ft_test("ft_strlcpy", list);
}

void	test_ft_strlcat(char *list)
{
	char	dst1[10] = { 'a', 'b', 'c', 'd', 'e', 'f', '\0', '\0', '\0', '\0' };
	char	src1[5] = { '1', '2', '3', '4', '\0' };
	char	dst2[10] = { 'a', 'b', 'c', 'd', 'e', 'f', '\0', '\0', '\0', '\0' };
	char	src2[5] = { '1', '2', '3', '4', '\0' };
	size_t	t1;
	size_t	t2;

	t1 = ft_strlcat(dst1, src1, 10);
	t2 = strlcat(dst2, src2, 10);
	list[0] = FUNC_TEST(strncmp(dst1, dst2, 10) == 0);
	list[1] = FUNC_TEST(t1 == t2);
	ft_test("ft_strlcat", list);
}

void	test_ft_toupper(char *list)
{
	list[0] = FUNC_TEST(ft_toupper('a') == 'A');
	list[1] = FUNC_TEST(ft_toupper('z') == 'Z');
	list[2] = FUNC_TEST(ft_toupper('2') == '2');
	ft_test("ft_toupper", list);
}

void	test_ft_tolower(char *list)
{
	list[0] = FUNC_TEST(ft_tolower('A') == 'a');
	list[1] = FUNC_TEST(ft_tolower('Z') == 'z');
	list[2] = FUNC_TEST(ft_tolower('2') == '2');
	ft_test("ft_tolower", list);
}

void	test_ft_strchr(char *list)
{
	char *s = "test um novo testo";
	char *s2 = "1";
	char s3[] = "tripouille";
	list[0] = FUNC_TEST(strncmp(ft_strchr(s, ' '), strchr(s, ' '), strlen(s)) == 0);
	list[1] = FUNC_TEST(ft_strrchr(s3, 't' + 256) == s3); // working (convert int to unsigned int)?
	//list[1] = FUNC_TEST((&ft_strchr(s, '\0')) == (&strchr(s, '\0')));
	ft_test("ft_strchr", list);
}

void	test_ft_strrchr(char *list)
{
	char *s = "test um novo testo";
	char *s2 = "1";
	char s3[] = "tripouille";
	list[0] = FUNC_TEST(strncmp(ft_strrchr(s, ' '), strrchr(s, ' '), strlen(s)) == 0);
	list[1] = FUNC_TEST(ft_strrchr(s3, 't' + 256) == s3); // working (convert int to unsigned int)?
	ft_test("ft_strrchr", list);
}

void	test_ft_strncmp(char *list)
{
	char *s1 = "testi";
	char *s2 = "teste";
	list[0] = FUNC_TEST(ft_strncmp(s1, s2, 5) == strncmp(s1, s2, 5));
	ft_test("ft_strncmp", list);
}

void	test_ft_memchr(char *list)
{
	char s1[] = { 't', 'e', 's', 't', '\0', 'a' };
	list[0] = FUNC_TEST(strncmp(ft_memchr(s1, 'a', 6), memchr(s1, 'a', 6), 6) == 0);
	ft_test("ft_memchr", list);
}

void	test_ft_memcmp(char *list)
{
	char s1[] = { 't', 'e', 's', 't', '\0', 'a' };
	char s2[] = { 't', 'e', 's', 't', '\0', 'e' };
	int r1 = ft_memcmp(s1, s2, 6);
	// not working | output = (-1, 0, 1)
	//int r2 = memcmp(s1, s2, 6);
	//printf("%d %d \n", r1, r2);
	list[0] = FUNC_TEST(r1 == -4);
	list[1] = FUNC_TEST(ft_memcmp(s1, s2, 5) == 0);
	list[2] = FUNC_TEST(ft_memcmp(s1, s2, 7) == -4);
	list[3] = FUNC_TEST(ft_memcmp(s1, s2, 0) == 0);
	ft_test("ft_memcmp", list);
}

void	test_ft_strnstr(char *list)
{
	char s[] = { 't', 'e', 's', 't', 'e', ' ', 'a', 'q', 'u', 'i', ' ', '1', '2', '3', '\0' };
	char c[] = {'a', 'q', 'u', 'i', ' ', '1', '2', '3', '\0'};
	char haystack[30] = "aaabcabcd";
	char *r;
	r = ft_strnstr(s, "aqui", 11);
	list[0] = FUNC_TEST(strncmp(r, c, strlen(c)) == 0);
	list[1] = FUNC_TEST(ft_strnstr(haystack, "cd", 8) == NULL);
	ft_test("ft_strnstr", list);
}

void	test_ft_atoi(char *list)
{
	char *s1 = " 	123";
	char *s2 = " 	-123";
	char *s3 = " 	--123";
	list[0] = FUNC_TEST(ft_atoi(s1) == atoi(s1));
	list[1] = FUNC_TEST(ft_atoi(s2) == atoi(s2));
	list[2] = FUNC_TEST(ft_atoi(s3) == atoi(s3));
	ft_test("ft_atoi", list);
}

void	test_ft_calloc(char *list)
{
	char *p;
	char c[5] = { '\0', '\0', '\0', '\0', '\0' };

	p = (char *) ft_calloc(5, sizeof(char));
	list[0] = FUNC_TEST(strncmp(p, c, 5) == 0);
	ft_test("ft_calloc", list);
}

void	test_ft_strdup(char *list)
{
	char *s1 = "testando";
	char *s2;
	char *s3;

	s2 = ft_strdup(s1);
	s3 = strdup(s1);
	list[0] = FUNC_TEST(strncmp(s2, s3, strlen(s1)) == 0);

	char * s = ft_strdup((char*)"coucou");
	list[1] = FUNC_TEST(strcmp(s, "coucou") == 0);

	s = ft_strdup((char*)"");
	list[2] = FUNC_TEST(strcmp(s, "") == 0);

	ft_test("ft_strdup", list);
}


void	test_ft_split(char *list)
{
	//list[0] = FUNC_TEST();

	char **tab = ft_split("  tripouille  42  ", ' ');
	freeTab(tab);
	tab = ft_split("tripouille", 0);
	freeTab(tab);
	char * splitme = strdup("Tripouille");
	tab = ft_split(splitme, ' ');
	free(splitme);
	freeTab(tab);

	ft_test("ft_split", list);
}

// void	test_(char *list)
// {
// 	list[0] = FUNC_TEST();
// 	ft_test("", list);
// }

int	main(void)
{	
	char	list[MAX_TESTS];
	int		i;

	i = 0;
	while (i < MAX_TESTS)
	{
		list[i] = STATUS_SUCESS;
		i++;
	}
	test_ft_isalpha(list);
	test_ft_isdigit(list);
	test_ft_isalnum(list);
	test_ft_isascii(list);
	test_ft_isprint(list);
	test_ft_strlen(list);
	test_ft_memset(list);
	test_ft_bzero(list);
	test_ft_memcpy(list);
	test_ft_memmove(list);
	test_ft_strlcpy(list);
	test_ft_strlcat(list);
	test_ft_toupper(list);
	test_ft_tolower(list);
	test_ft_strchr(list);
	test_ft_strrchr(list);
	test_ft_strncmp(list);
	test_ft_memchr(list);
	test_ft_memcmp(list);
	test_ft_strnstr(list);
	test_ft_atoi(list);
	test_ft_calloc(list);
	test_ft_strdup(list);
	test_ft_split(list);
	return (0);
}
