/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 13:07:43 by aputiev           #+#    #+#             */
/*   Updated: 2023/04/22 17:16:09 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"

int	g_bytes_counter;

void	ft_message_received(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)info;
	(void)context;
	g_bytes_counter++;
}

void	ft_process_symbol(int pid, char symbol)
{	
	static int	bit_counter;

	bit_counter = 0;
	while (bit_counter < 8)
	{
		if ((symbol & (1 << bit_counter)) != 0)
		{
			kill (pid, SIGUSR1);
		}
		else
		{
			kill (pid, SIGUSR2);
		}
		usleep(100);
		bit_counter++;
	}
}

int	process_function(char	**argv)
{
	int	i;
	int	pid;

	i = 0;
	if (ft_isnumber(argv[1]))
	{
		ft_printf("Check PID. PID is non-numeric\n");
		return (1);
	}
pid = ft_atoi(argv[1]);
	while (argv[2][i] != '\0')
	{
		ft_process_symbol(pid, argv[2][i]);
		i++;
	}
	ft_process_symbol(pid, '\0');
	if (g_bytes_counter > 0)
		ft_printf("Message has been received by a server, %d bytes",
			g_bytes_counter - 1);
	return (0);
}

int	main(int argc, char	**argv)
{
	struct sigaction	action;

	g_bytes_counter = 0;
	action.sa_sigaction = ft_message_received;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	sigaction(SIGUSR1, &action, NULL);
	if (argc == 3)
	{
		process_function(argv);
	}
	else
	{
		ft_printf("Error. Number of arguments should be 3\n");
		return (1);
	}
	return (0);
}
