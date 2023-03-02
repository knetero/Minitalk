/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:46:30 by abazerou          #+#    #+#             */
/*   Updated: 2023/03/02 02:02:35 by abazerou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
	{
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

static int	pid_p(int pid, int ac, char *av)
{
	if (ac != 3)
	{
		ft_printf("\033\n[0;33m ==> Please enter 3 arguments!\033[0;33m\n\n");
		exit(0);
	}
	pid = ft_atoi(av);
	if (pid <= 0)
	{
		ft_printf("\033[0;31m ==> Please enter a valid PID!\033[0;31m\n\n");
		exit(0);
	}
	return (pid);
}

static void	send_signal(char *msg, int pid)
{
	int		i;
	int		shift;

	i = 0;
	while (msg[i])
	{
		shift = 7;
		while (shift >= 0)
		{
			if ((msg[i] >> shift & 1))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			shift--;
			usleep(500);
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	pid;

	pid = 0;
	pid = pid_p(pid, argc, argv[1]);
	send_signal(argv[2], pid);
	return (0);
}
