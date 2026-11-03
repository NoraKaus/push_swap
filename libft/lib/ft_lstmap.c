/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezaimaki <ezaimaki@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 11:49:15 by ezaimaki          #+#    #+#             */
/*   Updated: 2026/10/19 21:16:55 by ezaimaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*current;
	void	*content_new;

	start = 0;
	while (lst != 0)
	{
		content_new = f(lst->content);
		current = ft_lstnew(content_new);
		if (current == 0)
		{
			del(content_new);
			ft_lstclear(&start, del);
			return (0);
		}
		ft_lstadd_back(&start, current);
		lst = lst->next;
	}
	return (start);
}

/*#include "libft.h"
#include <stdio.h>
#include <bsd/string.h>
#include <assert.h>
#include <ctype.h>

// for strmapi
static char ft_modify(unsigned int i, char c)
{
	c = 'b';
	i = 7;
	return (c);
}

// for striteri
static void ft_mod(unsigned int i, char *c)
{
	*c = 'b';
}

// for lstdelone + lstclear + lstmap
static void	del(void *content)
{
	printf("Pretend-delete of %s\n", (char *)content);
}

// for lstiter
static void	f1(void *content)
{
	printf("Pretend-modification of %s\n", (char *)content);
}

// for lstmap
static void	*f2(void *content)
{
	return ("HI");
}

int main(void)
{
	//atoi
	assert(atoi("  -2147483648aa") == ft_atoi("  -2147483648aa"));
	assert(atoi("") == ft_atoi(""));
	assert(atoi("ab") == ft_atoi("ab"));
	assert(atoi("+123") == ft_atoi("+123"));
	assert(atoi("\n  -34") == ft_atoi("\n  -34"));

	//bzero
	char s1[] = "hello";
	char s2[] = "hello";
	bzero(s1, 5);
	ft_bzero(s2, 5);
	assert(strcmp(s1, s2) == 0);

	//isalnum
	assert(ft_isalnum('c') == 1);
	assert(ft_isalnum('Z') == 1);
	assert(ft_isalnum('1') == 1);
	assert(ft_isalnum('0') == 1);
	assert(ft_isalnum('!') == 0);
	assert(ft_isalnum('\n') == 0);

	//isalpha
	assert(ft_isalpha('c') == 1);
	assert(ft_isalpha('Z') == 1);
	assert(ft_isalpha(' ') == 0);
	assert(ft_isalpha('\n') == 0);
	assert(ft_isalpha('4') == 0);

	//isascii
	assert(ft_isascii('}') == 1);
	assert(ft_isascii('\0') == 1);
	assert(ft_isascii('!') == 1);
	assert(ft_isascii('A') == 1);
	assert(ft_isascii('7') == 1);
	assert(ft_isascii(156) == 0);

	//isdigit
	assert(ft_isdigit('9') == 1);
	assert(ft_isdigit('0') == 1);
	assert(ft_isdigit(' ') == 0);
	assert(ft_isdigit('\n') == 0);
	assert(ft_isdigit('a') == 0);

	//isprint
	assert(ft_isprint('9') == 1);
	assert(ft_isprint('a') == 1);
	assert(ft_isprint('&') == 1);
	assert(ft_isprint('\n') == 0);
	assert(ft_isprint('\0') == 0);

	//memchr
	char s[] = "hello world";
	assert(strcmp(ft_memchr(s, 'o', 8), memchr(s, 'o', 8)) == 0);
	assert(strcmp(ft_memchr(s, 'o', 10), memchr(s, 'o', 10)) == 0);
	assert(ft_memchr(s, 'o', 3) == memchr(s, 'o', 3));
	assert(ft_memchr(s, 'o', 0) == memchr(s, 'o', 0));
	assert(ft_memchr(s, 287, 0) == memchr(s, 287, 0));
	assert(ft_memchr(s, 367, 0) == memchr(s, 367, 0));
	assert(ft_memchr(s, 0, 0) == memchr(s, 0, 0));

	//memcmp
	assert(ft_memcmp("ABBA", "ABBC", 4) < 0);
	assert(ft_memcmp("ABBC", "ABBA", 4) > 0);
	assert(ft_memcmp("ABBA", "ABBC", 3) == 0);
	assert(ft_memcmp("ABB", "ABB", 4) == 0);
	assert(ft_memcmp("ABBA", "ABBC", 0) == 0);

	//memcpy
	char src1[] = "abcdefghijk";
	char dest1[] = "!!!!!!!!!!!";
	char src2[] = "abcdefghijk";
	char dest2[] = "!!!!!!!!!!!";
	assert(strcmp(memcpy(dest1, src1, 4), ft_memcpy(dest2, src2, 4)) == 0);
	assert(strcmp(memcpy(dest1, src1, 0), ft_memcpy(dest2, src2, 0)) == 0);

	//memmove
	char src3[] = "abcdefghijk";
	char src4[] = "abcdefghijk";
	assert(strcmp(ft_memmove(&src3[3], src3, 5), 
	memmove(&src4[3], src4, 5)) == 0);
	assert(strcmp(ft_memmove(&src3[8], src3, 0), 
	memmove(&src4[8], src4, 0)) == 0);

	//memset
	char s3[] = "!!!!!!!!";
	char s4[] = "!!!!!!!!";
	assert(strcmp(ft_memset(s3, 'a', 5), memset(s4, 'a', 5)) == 0);
	assert(strcmp(ft_memset(s3, 'b', (0)), memset(s4, 'b', (0))) == 0);

	//strchr
	char *s5= "abcfdchijkc";
	assert(ft_strchr(s5, 'c') == strchr(s5, 'c'));
	assert(ft_strchr(s5, 'A') == strchr(s5, 'A'));
	assert(ft_strchr(s5, '\0') == strchr(s5, '\0'));

	//strdup
	char *s6 = "ABC";
	assert(strcmp(ft_strdup(s6), strdup(s6)) == 0);

	//strlcat
	char dest5[20] = "hello";
	char *src5 = "World";
	char dest6[20] = "hello";
	char *src6 = "World";
	assert(ft_strlcat(dest5, src5, 4) == strlcat(dest6, src6, 4));
	printf("STRLCAT:\n%s\n%s\n", dest5, dest6);
	assert(ft_strlcat(dest5, src5, 8) == strlcat(dest6, src6, 8));
	printf("STRLCAT:\n%s\n%s\n", dest5, dest6);
	assert(ft_strlcat(dest5, src5, 14) == strlcat(dest6, src6, 14));
	printf("STRLCAT:\n%s\n%s\n", dest5, dest6);

	//strlcpy
	char src7[] = "abcdefghijk";
	char dest7[] = "!!!!!!!!!!!";
	char src8[] = "abcdefghijk";
	char dest8[] = "!!!!!!!!!!!";
	assert(ft_strlcpy(dest7, src7, 4) == strlcpy(dest8, src8, 4));
	printf("STRLCPY:\n%s\n%s\n", dest7, dest8);
	assert(ft_strlcpy(dest7, src7, 0) == strlcpy(dest8, src8, 0));
	printf("STRLCPY:\n%s\n%s\n", dest7, dest8);
	char src9[] = "abcdefghijk";
	char dest9[] = "!!!!!!!!!!!";
	char src10[] = "abcdefghijk";
	char dest10[] = "!!!!!!!!!!!";
	assert(ft_strlcpy(dest9, src9, 20) == strlcpy(dest10, src10, 20));
	printf("STRLCPY:\n%s\n%s\n", dest9, dest10);

	//strlen
	assert(ft_strlen("a") == strlen("a"));
	assert(ft_strlen("") == strlen(""));
	assert(ft_strlen("123") == strlen("123"));
	assert(ft_strlen("abcd") == strlen("abcd"));
	assert(ft_strlen("\nk") == strlen("\nk"));

	//strncmp
	assert(ft_strncmp("ABCD", "ABCD", 4) == strncmp("ABCD", "ABCD", 4)); // == 0
	assert(ft_strncmp("ABCD", "ABCD", 5) == 
	strncmp("ABCD", "ABCD", 5)); // == 0
	assert(ft_strncmp("ABCD", "ABCD", 7) == strncmp("ABCD", "ABCD", 7)); // == 0
	assert(ft_strncmp("ABCDFFF", "ABCDEEE", 3) == 
	strncmp("ABCDFFF", "ABCDEEE", 3)); // == 0
	assert(ft_strncmp("ABCD", "ABCD", 0) == strncmp("ABCD", "ABCD", 0)); // == 0
	assert(ft_strncmp("ABCDFFF", "ABCDEEE", 5) > 0);
	assert(ft_strncmp("ABCDE", "ABCDF", 5) < 0);

	//strnstr
	char *big = "AAAcAAccAAccc";
	char *little = "cc";
	assert(ft_strnstr(big, little, 9) == strnstr(big, little, 9));
	assert(ft_strnstr(big, little, 0) == strnstr(big, little, 0));
	assert(ft_strnstr(big, "", 13) == strnstr(big, "", 13));
	assert(ft_strnstr(big, little, 4) == strnstr(big, little, 4));
	assert(ft_strnstr(big, "b", 13) == strnstr(big, "b", 13));
	assert(ft_strnstr(big, "ccc", 13) == strnstr(big, "ccc", 13));

	//strrchr
	char *s7 = "ABcDEEccFGcHIJ";
	assert(ft_strrchr(s7, 'c') == strrchr(s7, 'c'));
	assert(ft_strrchr(s7, 'G') == strrchr(s7, 'G'));
	assert(ft_strrchr(s7, 'E') == strrchr(s7, 'E'));
	assert(ft_strrchr(s7, '\0') == strrchr(s7, '\0'));

	//tolower
	assert(ft_tolower('G') == tolower('G'));
	assert(ft_tolower('g') == tolower('g'));
	assert(ft_tolower('!') == tolower('!'));
	assert(ft_tolower('4') == tolower('4'));

	//toupper
	assert(ft_toupper('g') == toupper('g'));
	assert(ft_toupper('G') == toupper('G'));
	assert(ft_toupper('7') == toupper('7'));

	//calloc
	char *s8 = ft_calloc(6, 4);
	char *s9 = calloc(6, 4);
	for (int i = 0; i < 24; i++)
	{
		assert(s8[i] == s9[i]);
		s8[i] = 'a';
		assert(s8[i] == 'a');
	}
	free(s8);
	free(s9);

	char *s10 = ft_calloc(9999999999, 999999999999);
	char *s11 = calloc(9999999999, 999999999999);
	assert(s10 == s11 && s10 == 0);

	char *s12 = ft_calloc(0, 6);
	assert(s12 != 0);

	//substr
	// printf("%s\n", ft_substr("abcdefg", 2, 15));
	assert(strcmp(ft_substr("abcdefg", 2, 3), "cde") == 0);
	assert(strcmp(ft_substr("abcdefg", 2, 15), "cdefg") == 0);

	//strjoin
	// printf("%s\n", ft_strjoin("Hello", "World"));
	assert(strcmp(ft_strjoin("Hello", "World"), "HelloWorld") == 0);
	assert(strcmp(ft_strjoin("Hello", ""), "Hello") == 0);

	//strtrim
	assert(strcmp(ft_strtrim("aaaBBaaBccc", "ac"), "BBaaB") == 0);
	assert(strcmp(ft_strtrim("acaBBacBcac", "ac"), "BBacB") == 0);
	assert(strcmp(ft_strtrim("BBaaBccc", "ac"), "BBaaB") == 0);
	assert(strcmp(ft_strtrim("aaaBBaaB", "ac"), "BBaaB") == 0);
	assert(strcmp(ft_strtrim("BBaaB", "ac"), "BBaaB") == 0);
	assert(strcmp(ft_strtrim("aBBaaBd", "acd"), "BBaaB") == 0);
	assert(strcmp(ft_strtrim("", "a"), "") == 0);
	assert(strcmp(ft_strtrim("aaa", "a"), "") == 0);
	assert(strcmp(ft_strtrim("aaa", ""), "aaa") == 0);

	//split
	char **array = ft_split("ccAAcAAAcccAAAAcAAAAA", 'c');
	assert(strcmp(array[0], "AA") == 0);
	assert(strcmp(array[1], "AAA") == 0);
	assert(strcmp(array[2], "AAAA") == 0);
	assert(strcmp(array[3], "AAAAA") == 0);
	assert(array[4] == 0);
	int i = 4;
	while (i >= 0)
	{
		free(array[i]);
		i--;
	}
	free(array);

	//itoa
	assert(strcmp(ft_itoa(-2147), "-2147") == 0);
	assert(strcmp(ft_itoa(-2147483648), "-2147483648") == 0);
	assert(strcmp(ft_itoa(0), "0") == 0);
	assert(strcmp(ft_itoa(21), "21") == 0);
	assert(strcmp(ft_itoa(3), "3") == 0);
	assert(strcmp(ft_itoa(2147483647), "2147483647") == 0);

	//strmapi
	assert(strcmp(ft_strmapi("aaaa", ft_modify), "bbbb") == 0);
	assert(strcmp(ft_strmapi("", ft_modify), "") == 0);

	//striteri
	char s13[] = "aaa";
	ft_striteri(s13, ft_mod);
	assert(strcmp(s13, "bbb") == 0);
	char s14[] = "";
	ft_striteri(s14, ft_mod);
	assert(strcmp(s14, "") == 0);

	//putchar_fd
	printf("\nPutchar_fd:\n");
	ft_putchar_fd('g', 1);
	ft_putchar_fd('4', 1);
	ft_putchar_fd('!', 1);

	//putstr_fd
	printf("\nPutstr_fd:\n");
	ft_putstr_fd("Zero bugs given\n", 1);
	ft_putstr_fd("12345!\n", 1);
	ft_putstr_fd("I miss the sea\n", 1);
	ft_putstr_fd("i\n", 1);

	//putendl_fd
	printf("Putendl_fd:\n");
	ft_putendl_fd("Hello friend", 1);
	ft_putendl_fd("I am tired", 1);
	ft_putendl_fd("And you?", 1);

	//putnbr_fd
	printf("\nPutnbr_fd:\n");
	printf("Input: 0 Output: ");
	fflush(stdout);
	ft_putnbr_fd(0, 1);
	printf("\nInput: -123 Output: ");
	fflush(stdout);
	ft_putnbr_fd(-123, 1);
	printf("\nInput: 987 Output: ");
	fflush(stdout);
	ft_putnbr_fd(987, 1);
	printf("\nInput: -2147483648 Output: ");
	fflush(stdout);
	ft_putnbr_fd(-2147483648, 1);
	printf("\nInput: 2147483647 Output: ");
	fflush(stdout);
	ft_putnbr_fd(2147483647, 1);

	// PART 3 LINKED LIST

	//ft_lstnew + ft_lstadd_front + ft_lstsize + ft_lstadd_back
	t_list *new1 = ft_lstnew("A");
	t_list *new2 = ft_lstnew("B");
	t_list *new3 = ft_lstnew("C");
	t_list *new4 = ft_lstnew("D");
	t_list *new5 = ft_lstnew("E");
	t_list **start = &new1;

	ft_lstadd_front(start, new2);
	ft_lstadd_front(start, new3);
	ft_lstadd_front(start, new4);

	ft_lstadd_back(start, new5);

	printf("\n\nLIST Size: %i\n", ft_lstsize(*start));
	t_list *current = *start;
	while(current->next != 0)
	{
		printf("%p\n", current);
		printf("%s\n", (char *)current->content);
		printf("%p\n\n", current->next);
		current = current->next;
	}
	printf("%p\n", current);
	printf("%s\n", (char *)current->content);
	printf("%p\n\n", current->next);

	//ft_lstlast
	t_list *last = ft_lstlast(*start);
	printf("LAST NODE: \n");
	printf("%p\n", last);
	printf("%s\n", (char *)last->content);
	printf("%p\n\n", last->next);


	//ft_lstdelone + ft_lstclear
	ft_lstclear(&new2, del);
	new3->next = 0;
	current = *start;
	printf("CLEARED UP LIST: \n");
	while(current->next != 0)
	{
		printf("%p\n", current);
		printf("%s\n", (char *)current->content);
		printf("%p\n\n", current->next);
		current = current->next;
	}
	printf("%p\n", current);
	printf("%s\n", (char *)current->content);
	printf("%p\n\n", current->next);

	//ft_lstiter
	printf("LSTITER: \n");
	ft_lstiter(*start, f1);

	// //ft_lstmap (COMMENT OUT lstdelone + lstclear)
	// t_list *new_list = ft_lstmap(*start, f2, del);
	// current = new_list;
	// printf("\nNEW LIST WITH LSTMAP: \n");
	// while(current->next != 0)
	// {
	// 	printf("%p\n", current);
	// 	printf("%s\n", (char *)current->content);
	// 	printf("%p\n\n", current->next);
	// 	current = current->next;
	// }
	// printf("%p\n", current);
	// printf("%s\n", (char *)current->content);
	// printf("%p\n\n", current->next);
}*/
