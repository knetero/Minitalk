/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:41:54 by abazerou          #+#    #+#             */
/*   Updated: 2023/02/27 23:29:31 by abazerou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	print_char(char *str)
{
	int i;
	int a;
	int result;

	i = 0;
	a = 128;
	result = 0;
	while(str[i])
	{
		result = result + (str[i] - 48) * a;
		a = a / 2;
		i++;
	}
	ft_printf("%c", result);
}

static int ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

static void	ft_myhandler(int sig, siginfo_t *info, void *content)
{
	(void)content;
	static char str[9];
	static int pid;
	static int i;

	if (pid != info->si_pid)
	{
		pid = info->si_pid;
		while (i >= 0)
		{
			str[i] = '\0';
			i--;
		}
		i = 0;
	}
	i = ft_strlen(str);
	if (i < 8)
	{
		if (sig == SIGUSR1)
			str[i] = '1';
		else if (sig == SIGUSR2)
			str[i] = '0';
	}
	if (i == 7)
	{
		print_char(str);
		str[8] = '\0';
		while (i >= 0)
		{
			str[i] = '\0';
			i--;
		}
	}
}

int main(void)
{
	struct sigaction sa;
	
	ft_printf("Server PID : %d\n", getpid());
	ft_printf("\033[92m==> Waiting for a message from client...\033[0m\n\n");
	sa.sa_sigaction = &ft_myhandler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while(1)
	{
		pause();
	}
	return 0;
}