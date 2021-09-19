/*
** EPITECH PROJECT, 2019
** lib
** File description:
** lib
*/

#include "include/my.h"

void	my_putchar(char c)
{
    write(1, &c, 1);
}

void	my_put_nbr(int x)
{
    if (x < 0) {
        my_putchar('-');
        my_put_nbr(-x);
    } else if (x > 9) {
        my_put_nbr(x / 10);
        my_put_nbr(x % 10);
    } else {
        my_putchar(x + '0');
    }
}

int	my_putstr(char const *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
    return (0);
}

int	my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

char	*my_strcat(char *dest, char const *str)
{
    int i = 0;
    int length = my_strlen(dest);

    for (; str[i] != '\0'; i++)
        dest[i + length] = str[i];
    dest[i + length] = '\0';
    return dest;
}
