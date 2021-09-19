/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include <string.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <assert.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

void handler(int sig)
{
    if (sig == SIGUSR1 || sig == SIGUSR2) {
    }
}

int	p1(int pid)
{
    signal(SIGUSR2, handler);
    printf("My pid is: %d\n", pid);
    printf("waitinggggg\n");
    pause();
    return (pid);
}

int	p2(int pid, int pid2)
{
    signal(SIGUSR1, handler);
    printf("My pid is %d\n", pid2);
    kill(pid2, SIGUSR1);
    printf("connected");
    return pid2;
}

int	main(int ac, char **av)
{
    pid_t pid = getpid();

    pid = p1(pid);
    pid = p2(pid, atoi(av[1]));
}
