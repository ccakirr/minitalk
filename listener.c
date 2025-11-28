/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listener.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccakir <ccakir@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 10:44:27 by ccakir            #+#    #+#             */
/*   Updated: 2025/11/28 18:15:07 by ccakir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "ft_printf/ft_printf.h"

static void handler(int signum, siginfo_t *info, void *context)
{
	static unsigned char	c;
	static int				bit_count;

	(void)context;
	if (signum == SIGUSR1)
	{
		c = (c << 1);
		bit_count++;
	}
	else if (signum == SIGUSR2)
	{
		c = (c << 1) | 1;
		bit_count++;
	}
	if (bit_count == 8)
	{
		if(!c)
			write(1, "\n", 1);
		else 
			write(1, &c, 1);
		c = 0;
		bit_count = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int main(void)
{
	struct sigaction	action;

	ft_printf("Server PID: %d\n", getpid());
	action.sa_sigaction = handler;
	action.sa_flags = SA_SIGINFO;
	sigemptyset(&action.sa_mask);
	sigaddset(&action.sa_mask, SIGUSR1);  // Handler çalışırken SIGUSR1'i blokla
	sigaddset(&action.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
	return (0);
}

