/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:28:41 by amarzana          #+#    #+#             */
/*   Updated: 2022/08/30 15:01:50 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_philo_atoi(const char *str)
{
	int		sign;
	int		i;
	long	num;

	sign = 1;
	i = 0;
	num = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}	
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			break ;
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * sign);
}
