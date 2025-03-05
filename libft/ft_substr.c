/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enkwak <enkwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:45:46 by enkwak            #+#    #+#             */
/*   Updated: 2024/10/28 15:06:21 by enkwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	if (!s || len <= 0 || start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (s[start] && i < len)
	{
		res[i] = s[start];
		start++;
		i++;
	}
	res[i] = '\0';
	return (res);
}

// int main()
// {
//     char *test_string = "Hello, World!";
//     char *substr1 = ft_substr(test_string, 0, 5);
//     char *substr2 = ft_substr(test_string, 7, 5);
//     char *substr3 = ft_substr(test_string, 7, 10);
//     char *substr4 = ft_substr(test_string, 20, 5);
//     printf("Substring 1: %s\n", substr1);
//     printf("Substring 2: %s\n", substr2);
//     printf("Substring 3: %s\n", substr3);
//     printf("Substring 4: %s\n", substr4 ? substr4 : "(NULL)\n");
//     free(substr1);
//     free(substr2);
//     free(substr3);
//     free(substr4);
//     return 0;
// }