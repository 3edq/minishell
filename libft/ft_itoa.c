/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enkwak <enkwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:38:23 by enkwak            #+#    #+#             */
/*   Updated: 2024/10/26 23:53:08 by enkwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_digit(int n)
{
	int			digit;
	long long	num;

	num = (long long)n;
	if (num < 0)
		num *= -1;
	digit = 1;
	while (num > 9)
	{
		num /= 10;
		digit++;
	}
	return (digit);
}

static char	*make_str(long long n, int digit, char *pst, int i)
{
	int			j;
	int			k;
	long long	num;
	long long	digit_num;

	j = 0;
	while (j < digit)
	{
		num = n;
		k = j;
		while (k < digit - 1)
		{
			num /= 10;
			k++;
		}
		digit_num = num % 10;
		pst[i] = (digit_num) + '0';
		j++;
		i++;
	}
	pst[i] = '\0';
	return (pst);
}

char	*ft_itoa(int n)
{
	int			digit;
	char		*pst;
	int			i;
	long long	num;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	digit = get_digit(n);
	if (n < 0)
		pst = (char *)malloc(sizeof(char) * (digit + 2));
	else
		pst = (char *)malloc(sizeof(char) * (digit + 1));
	if (!pst)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		pst[i] = '-';
		num = n * -1;
		i++;
	}
	else
		num = n;
	pst = make_str(num, digit, pst, i);
	return (pst);
}

// int main()
// {
//     int numbers[] = {42, -42, 0, 12345, -6789};
//     size_t num_tests = sizeof(numbers) / sizeof(numbers[0]);
//     for (size_t i = 0; i < num_tests; i++)
//     {
//         char *str = ft_itoa(numbers[i]);
//         if (str)
//         {
//             printf("ft_itoa(%d) = %s\n", numbers[i], str);
//             free(str);
//         }
//         else
//         {
//             printf("Memory allocation failed for ft_itoa(%d)\n", numbers[i]);
//         }
//     }
//     return 0;
// }