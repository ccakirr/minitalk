/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   speaker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccakir <ccakir@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 11:57:08 by ccakir            #+#    #+#             */
/*   Updated: 2025/11/28 17:57:25 by ccakir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

volatile sig_atomic_t g_ack = 0;

void	wake_up_pause(int	sig)
{
	(void)sig;
	g_ack = 1;
}

void	send_null(int	pid)
{
	int	i;

	i = 0;
	while(i < 8)
	{
		g_ack = 0;
		kill(pid, SIGUSR1);
		while (g_ack == 0)
			pause();
		i++;
	}
}

void	talk(int	pid, char	*message)
{
	int	char_num;
	int	i;

	char_num = 0;
	while (message[char_num])
	{
		i = 0;
		while (i < 8)
		{
			g_ack = 0;
			if(((message[char_num] >> (7 - i)) & 1) == 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			while (g_ack == 0)
				pause();
			i++;
		}
		char_num++;
	}
	send_null(pid);
}

int	main(int ac, char **av)
{
	char		*message;
	int			pid;

	if (ac == 3)
	{
		signal(SIGUSR1, wake_up_pause);
		signal(SIGUSR2, wake_up_pause);
		message = av[2];
		pid = ft_atoi(av[1]);
		if (!pid)
		{
			ft_printf("Error.");
			return (0);
		}
		if (!message[0])
		{
			send_null(pid);
		}
		talk(pid, message);
	}
	else
		ft_printf("Error.");
	return (0);
}
