/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 13:07:24 by aputiev           #+#    #+#             */
/*   Updated: 2023/04/22 16:23:20 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"

void	ft_signal_process(int signumber, siginfo_t *info, void *context)

{	
	static int	symbol;
	static int	bit_counter;
	int			client_pid;

	(void)context;
	(void)info;
	if (signumber == SIGUSR1)
		symbol = symbol | (1 << bit_counter);
	bit_counter++;
	if (bit_counter == 8)
	{
		ft_printf("%c", symbol);
		symbol = 0;
		bit_counter = 0;
		if (symbol == 0)
		{
			client_pid = info->si_pid;
			kill(client_pid, SIGUSR1);
		}
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	action;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	action.sa_sigaction = ft_signal_process;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	while (1)
	{
		sigaction(SIGUSR1, &action, NULL);
		sigaction(SIGUSR2, &action, NULL);
		pause();
	}
	return (0);
}
	//bit shift
	// 00000000
	// 00000001
	// --------
	// 00000001

	// 00000001
	// 00000010
	// --------
	// 00000011	