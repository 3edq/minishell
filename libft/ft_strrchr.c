/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaegusa <ksaegusa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:51:12 by ksaegusa          #+#    #+#             */
/*   Updated: 2024/10/30 15:14:36 by ksaegusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	const char	*last = NULL;

	if (!s)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			last = s;
		}
		s++;
	}
	if (c == '\0')
	{
		return ((char *)s);
	}
	return ((char *)last);
}
// #include <stdio.h>

// char	*ft_strrchr(const char *s, int c);

// int	main(void)
// {
// 	const char	*str = "Hello, world!";
// 	char		c;
// 	char		*result;

// 	c = 'o';
// 	result = ft_strrchr(str, c);
// 	if (result)
// 		printf("Last occurrence of '%c': %s\n", c, result);
// 	else
// 		printf("Character '%c' not found\n", c);
// 	return (0);
// }
