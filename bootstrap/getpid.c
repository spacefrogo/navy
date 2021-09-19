/*
** EPITECH PROJECT, 2019
** projec
** File description:
** test
*/

#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int	main(int ac, char **av)
{
    pid_t	x = getpid();
    pid_t	y = getppid();
    pid_t	z = getpgid(x);

    
    printf("PID  is: %d\n", x);
    printf("PPID is: %d\n", y);
    printf("PGID is: %d\n", z);
    return (0);
}
