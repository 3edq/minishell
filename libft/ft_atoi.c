/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enkwak <enkwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:25:04 by enkwak            #+#    #+#             */
/*   Updated: 2024/10/31 06:58:15 by enkwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_flow(long num, int sign, long next)
{
	if ((num * sign) > (LONG_MAX / 10))
		return ((int)LONG_MAX);
	if ((num * sign) == (LONG_MAX / 10) && next > (LONG_MAX % 10))
		return ((int)LONG_MAX);
	if ((num * sign) < (LONG_MIN / 10))
		return ((int)LONG_MIN);
	if ((num * sign) == (LONG_MIN / 10) && next < (LONG_MIN % 10))
		return ((int)LONG_MIN);
	return (21);
}

static long	make_num(const char *str, long sign)
{
	long	num;

	if (*str >= '0' && *str <= '9')
	{
		num = *str - '0';
		str++;
		while (*str && *str >= '0' && *str <= '9')
		{
			num *= 10;
			if (check_flow(num, sign, *str - '0') != 21)
				return (check_flow(num, sign, *str - '0'));
			num += *str - '0';
			str++;
		}
		return ((int)(num * sign));
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	long	sign;

	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	return (make_num(str, sign));
}

// int main()
// {
// 	char    str91[] = "-a-5";
//     printf("zisaku  : %d\n", ft_atoi(str91));
//     printf("library : %d\n", atoi(str91));
//     char    str92[] = "-100";
//     printf("zisaku  : %d\n", ft_atoi(str92));
//     printf("library : %d\n", atoi(str92));
//     char    str93[] = "1000321";
//     printf("zisaku  : %d\n", ft_atoi(str93));
//     printf("library : %d\n", atoi(str93));
//     char    str94[] = "2147483648";
//     printf("zisaku  : %d\n", ft_atoi(str94));
//     printf("library : %d\n", atoi(str94));
//     char    str95[] = "-2147483649";
//     printf("zisaku  : %d\n", ft_atoi(str95));
//     printf("library : %d\n", atoi(str95));
// 	char    str96[] = "9223372036854775807";
//     printf("zisaku  : %d\n", ft_atoi(str95));
//     printf("library : %d\n", atoi(str95));
// 	return (0);
// }