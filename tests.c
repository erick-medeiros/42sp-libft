/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 21:16:09 by eandre-f          #+#    #+#             */
/*   Updated: 2022/04/14 18:12:23 by eandre-f         ###   ########.fr       */
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

char	*clearlist(char *list)
{
	memset(list, STATUS_SUCESS, MAX_TESTS);
	return (list);
}

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
		printf("\t\t\t%s KO\n\t\t\tError Test %d\n", name_test, i);
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
	list[1] = FUNC_TEST(ft_memcpy(((void*)0), ((void*)0), 3) == NULL);
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

	int size_test2 = 128 * 1024;
	char *dst_test2 = (char *)malloc(sizeof(char) * size_test2);
	char *data_test2 = (char *)malloc(sizeof(char) * size_test2);

	char *dst2_test2 = (char *)malloc(sizeof(char) * size_test2);
	char *data2_test2 = (char *)malloc(sizeof(char) * size_test2);

	memset(data_test2, 'A', size_test2);
	ft_memmove(dst_test2, data_test2, size_test2);
	memset(data2_test2, 'A', size_test2);
	memmove(dst2_test2, data2_test2, size_test2);

	list[2] = FUNC_TEST(strncmp(dst_test2, data_test2, size_test2)  == 0);
	list[3] = FUNC_TEST(strncmp(dst_test2, dst2_test2, size_test2)  == 0);
	char *test3 = ft_memmove(((void*)0), ((void*)0), 5);
	list[4] = FUNC_TEST(test3 == NULL);
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
	char s3[] = "testando";
	list[0] = FUNC_TEST(strcmp(ft_strchr(s, ' '), strchr(s, ' ')) == 0);
	list[1] = FUNC_TEST(ft_strchr(s3, 't' + 256) == s3);
	list[2] = FUNC_TEST(ft_strchr(s, '\0') == strchr(s, '\0'));
	ft_test("ft_strchr", list);
}

void	test_ft_strrchr(char *list)
{
	char *s = "test um novo testo";
	char *s2 = "1";
	char s3[] = "testando";
	list[0] = FUNC_TEST(strncmp(ft_strrchr(s, ' '), strrchr(s, ' '), strlen(s)) == 0);
	list[1] = FUNC_TEST(ft_strrchr(s3, 't' + 256) == strrchr(s3, 't' + 256));
	ft_test("ft_strrchr", list);
}

void	test_ft_strncmp(char *list)
{
	char *s1 = "testi";
	char *s2 = "teste";
	char *s3 = "test\200";
	char *s4 = "test\0";
	list[0] = FUNC_TEST(ft_strncmp(s1, s2, 5) == strncmp(s1, s2, 5));
	list[1] = FUNC_TEST(ft_strncmp(s3, s4, 6) == strncmp(s3, s4, 6));
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

	char s3[] = { 't', 'e', 's', 't', '\0', 'a' };
	char s4[] = { 't', 'e', 's', 't', '\0', 'e' };
	int r1 = ft_memcmp(s1, s2, 6);
	int r2 = memcmp(s3, s4, 6);

	list[0] = FUNC_TEST(r1 < 0 && r2 < 0);
	list[1] = FUNC_TEST(ft_memcmp(s1, s2, 5) == 0);
	list[2] = FUNC_TEST(ft_memcmp(s1, s2, 7) == -4);
	list[3] = FUNC_TEST(ft_memcmp(s1, s2, 0) == 0);

	list[4] = FUNC_TEST(ft_memcmp(s1, s2, 5) == memcmp(s1, s2, 5));
	list[5] = FUNC_TEST(ft_memcmp(s1, s2, 7) < 0 && memcmp(s1, s2, 7) < 0);
	list[6] = FUNC_TEST(ft_memcmp(s1, s2, 0) == memcmp(s1, s2, 0));
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
	char s4[40] = "-99999999999999999999999999";
	char s5[40] = "99999999999999999999999999";

	list[0] = FUNC_TEST(ft_atoi(s1) == atoi(s1));
	list[1] = FUNC_TEST(ft_atoi(s2) == atoi(s2));
	list[2] = FUNC_TEST(ft_atoi(s3) == atoi(s3));
	list[3] = FUNC_TEST(ft_atoi(s4) == atoi(s4));
	list[4] = FUNC_TEST(ft_atoi(s5) == atoi(s5));
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

void	test_ft_substr(char *list)
{
	char *str = "0123456789";
	list[0] = FUNC_TEST(strcmp(ft_substr(str, 6, 10), "6789") == 0);
	ft_test("ft_substr", list);
}

void	test_ft_strjoin(char *list)
{
	list[0] = FUNC_TEST(strcmp(ft_strjoin("4", "2"), "42") == 0);
	ft_test("ft_strjoin", list);
}


void	test_ft_strtrim(char *list)
{
	list[0] = FUNC_TEST(strcmp(ft_strtrim("   xxx   xxx", " x"), "") == 0);
	ft_test("ft_strtrim", list);
}

void	test_ft_split(char *list)
{
	char **tab = ft_split("4 2", ' ');
	list[0] = FUNC_TEST(strcmp(tab[0], "4") == 0);
	list[1] = FUNC_TEST(strcmp(tab[1], "2") == 0);
	ft_test("ft_split", list);
}

void	test_ft_itoa(char *list)
{
	list[0] = FUNC_TEST(strcmp(ft_itoa(2147483647), "2147483647") == 0);
	list[1] = FUNC_TEST(strcmp(ft_itoa(-2147483648), "-2147483648") == 0);
	ft_test("ft_itoa", list);
}

char strmapiTestF(unsigned int i, char c) {return (i + c);}

void	test_ft_strmapi(char *list)
{
	list[0] = FUNC_TEST(strcmp(ft_strmapi("1111", strmapiTestF), "1234") == 0);
	ft_test("ft_strmapi", list);
}

void striteriTestF(unsigned int i, char * s) {*s += i;}

void	test_ft_striteri(char *list)
{
	char s[] = "0000000000";
	ft_striteri(s, striteriTestF);
	list[0] = FUNC_TEST(strcmp(s, "0123456789") == 0);
	ft_test("ft_striteri", list);
}

void	test_ft_putchar_fd(char *list)
{
	char s[] = "ft_putchar_fd OK";
	int i = -1;
	while (s[++i])
		ft_putchar_fd(s[i], 1);
	ft_putchar_fd('\n', 1);
}

void	test_ft_putstr_fd(char *list)
{
	char s[] = "ft_putstr_fd OK";
	ft_putstr_fd(s, 1);
	ft_putstr_fd("\n", 1);
}

void	test_ft_putendl_fd(char *list)
{
	char s[] = "ft_putendl_fd OK";
	ft_putendl_fd(s, 1);
}

void	test_ft_putnbr_fd(char *list)
{
	ft_putendl_fd("ft_putnbr_fd OK", 1);
	ft_putnbr_fd(2147483647, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(-2147483648, 1);
	ft_putchar_fd('\n', 1);
}

void	test_ft_lstnew(char *list)
{
	t_list *lst =  ft_lstnew((void*)42);

	list[0] = FUNC_TEST(lst->content == (void*)42);
	list[1] = FUNC_TEST(lst->next == 0);
	ft_test("ft_lstnew", list);
}

void	test_ft_lstadd_front(char *list)
{
	t_list * l =  NULL;
	ft_lstadd_front(&l, ft_lstnew((void*)2));
	list[0] = FUNC_TEST(l->content == (void*)2);
	list[1] = FUNC_TEST(l->next == 0);

	ft_lstadd_front(&l, ft_lstnew((void*)4));
	list[2] = FUNC_TEST(l->content == (void*)4);
	list[3] = FUNC_TEST(l->next->content == (void*)2);
	list[4] = FUNC_TEST(l->next->next == 0);

	ft_test("ft_lstadd_front", list);
}

void	test_ft_lstsize(char *list)
{
	t_list * l =  NULL;
	ft_lstadd_front(&l, ft_lstnew((void*)2));
	ft_lstadd_front(&l, ft_lstnew((void*)4));
	list[0] = FUNC_TEST(ft_lstsize(l) == 2);
	ft_test("ft_lstsize", list);
}

void	test_ft_lstlast(char *list)
{
	t_list * l =  NULL;
	ft_lstadd_back(&l, ft_lstnew((void*)4));
	list[0] = FUNC_TEST(ft_lstlast(l)->content == (void*)4);
	ft_test("ft_lstlast", list);
}

void	test_ft_lstadd_back(char *list)
{
	t_list * l =  NULL;

	ft_lstadd_back(&l, ft_lstnew((void*)4));
	list[0] = FUNC_TEST(l->content == (void*)4);
	list[1] = FUNC_TEST(l->next == 0);
	ft_lstadd_back(&l, ft_lstnew((void*)2));
	list[2] = FUNC_TEST(l->content == (void*)4);
	list[3] = FUNC_TEST(l->next->content == (void*)2);
	list[4] = FUNC_TEST(l->next->next == 0);
	ft_test("ft_lstadd_back", list);
}

void	lstdeloneTestF(void *content){}

void	test_ft_lstdelone(char *list)
{
	t_list * node0 = ft_lstnew((void *)"0");
	t_list * node1 = ft_lstnew((void *)"1");
	t_list * node2 = ft_lstnew((void *)"2");
	ft_lstadd_back(&node0, node1);
	ft_lstadd_back(&node0, node2);
	ft_lstdelone(node1, &lstdeloneTestF);
	ft_test("ft_lstdelone", list);
}

void	test_ft_lstclear(char *list)
{
	t_list * l =  ft_lstnew((void*)"42");
	ft_lstadd_back(&l, ft_lstnew((void*)"42"));
	ft_lstclear(&l, lstdeloneTestF);
	list[0] = FUNC_TEST(l == 0);
	ft_test("ft_lstclear", list);
}

void lstiterTestF(void * content) {
	char	list[MAX_TESTS];
	clearlist(list);
	list[0] = FUNC_TEST(strcmp((char *)content, "42") == 0);
	ft_test("ft_lstiter", list);
}

void	test_ft_lstiter(char *list)
{
	t_list * l =  ft_lstnew((void *)"42");
	ft_lstiter(l, lstiterTestF);
}

void *lstmapTestF(void * p) {
	char *r = strdup((char *) p);
	r[0] += 1;
	return ((void *)r);
}

void	test_ft_lstmap(char *list)
{
	t_list * l =  ft_lstnew((void *)"4");
	ft_lstadd_back(&l, ft_lstnew((void *)"2"));
	t_list * m = ft_lstmap(l, lstmapTestF, free);
	list[0] = FUNC_TEST(strcmp((char *)m->content, "5") == 0);
	list[1] = FUNC_TEST(strcmp((char *)m->next->content, "3") == 0);
	ft_test("ft_lstmap", list);
}

int	main(void)
{	
	char	list[MAX_TESTS];

	//Part 1
	test_ft_isalpha(clearlist(list));
	test_ft_isdigit(clearlist(list));
	test_ft_isalnum(clearlist(list));
	test_ft_isascii(clearlist(list));
	test_ft_isprint(clearlist(list));
	test_ft_strlen(clearlist(list));
	test_ft_memset(clearlist(list));
	test_ft_bzero(clearlist(list));
	test_ft_memcpy(clearlist(list));
	test_ft_memmove(clearlist(list));
	test_ft_strlcpy(clearlist(list));
	test_ft_strlcat(clearlist(list));
	test_ft_toupper(clearlist(list));
	test_ft_tolower(clearlist(list));
	test_ft_strchr(clearlist(list));
	test_ft_strrchr(clearlist(list));
	test_ft_strncmp(clearlist(list));
	test_ft_memchr(clearlist(list));
	test_ft_memcmp(clearlist(list));
	test_ft_strnstr(clearlist(list));
	test_ft_atoi(clearlist(list));
	test_ft_calloc(clearlist(list));
	test_ft_strdup(clearlist(list));
	//Part 2
	test_ft_substr(clearlist(list));
	test_ft_strjoin(clearlist(list));
	test_ft_strtrim(clearlist(list));
	test_ft_split(clearlist(list));
	test_ft_itoa(clearlist(list));
	test_ft_strmapi(clearlist(list));
	test_ft_striteri(clearlist(list));
	test_ft_putchar_fd(clearlist(list));
	test_ft_putstr_fd(clearlist(list));
	test_ft_putendl_fd(clearlist(list));
	test_ft_putnbr_fd(clearlist(list));
	//Bonus
	test_ft_lstnew(clearlist(list));
	test_ft_lstadd_front(clearlist(list));
	test_ft_lstsize(clearlist(list));
	test_ft_lstlast(clearlist(list));
	test_ft_lstadd_back(clearlist(list));
	test_ft_lstdelone(clearlist(list));
	test_ft_lstclear(clearlist(list));
	test_ft_lstiter(clearlist(list));
	test_ft_lstmap(clearlist(list));
	return (0);
}
