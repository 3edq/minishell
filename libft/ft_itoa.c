/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaegusa <ksaegusa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:26:37 by ksaegusa          #+#    #+#             */
/*   Updated: 2024/10/29 14:29:25 by ksaegusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stdlib.h>

static size_t	get_num_len(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*str;
	size_t			len;
	unsigned int	num;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	len = get_num_len(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
		num = -n;
	else
		num = n;
	while (len > 0)
	{
		len--;
		str[len] = (num % 10) + '0';
		num /= 10;
		if (n < 0 && len == 0)
			str[len] = '-';
	}
	return (str);
}

// #include <limits.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int		test_cases[] = {0, -1, -123, INT_MAX, INT_MIN, 1, 123};
// 	char	*result;
// 	size_t	i;

// 	for (i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++)
// 	{
// 		result = ft_itoa(test_cases[i]);
// 		if (result)
// 		{
// 			printf("ft_itoa(%d) = %s\n", test_cases[i], result);
// 			free(result);
// 		}
// 		else
// 		{
// 			printf("ft_itoa(%d) = NULL\n", test_cases[i]);
// 		}
// 	}
// 	return (0);
// }
