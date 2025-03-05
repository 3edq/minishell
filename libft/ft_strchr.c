/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaegusa <ksaegusa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:52:26 by ksaegusa          #+#    #+#             */
/*   Updated: 2024/10/30 13:31:38 by ksaegusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			return ((char *)s);
		}
		s++;
	}
	if (c == '\0')
	{
		return ((char *)s);
	}
	return (NULL);
}
// #include <stdio.h>

// int	main(void)
// {
// 	const char	*str = "Hello, world!";
// 	char		c;
// 	char		*result;

// 	c = 'o';
// 	result = ft_strchr(str, c);
// 	if (result)
// 		printf("First occurrence of '%c': %s\n", c, result);
// 	else
// 		printf("Character '%c' not found\n", c);
// 	return (0);
// }
