/*
** EPITECH PROJECT, 2019
** itoa
** File description:
** itoa
*/

#include "include/my.h"

char	*my_itoa(int nb)
{
    short sign = (nb < 0);
    char *str = malloc(my_count_digits(nb) + sign + 1);
    short left = 0;
    unsigned int i = 0;

    nb = (nb < 0) ? -nb : nb;
    do {
        left = nb % 10;
        nb /= 10;
        str[i++] = left + '0';
    } while (nb > 0);
    if (sign)
        str[i++] = '-';
    str[i] = '\0';
    return my_revstr(str);
}

char	*my_revstr(char *str)
{
    int a = 0;
    int b = my_strlen(str) - 1;
    int c;

    while (a < b) {
        c = str[a];
        str[a++] = str[b];
        str[b--] = c;
    }
    return str;
}

static	int	my_count_digits_rec(int n, int i)
{
    if (n < INT_MIN || n > INT_MAX) {
        write(2, "count_digits: number out of bounds\n", 35);
        return 84;
    }
    if (n / 10 != 0)
        return i + my_count_digits_rec(n / 10, i);
    else if (n >= 0)
        return 1;
    else
        return 0;
}

int my_count_digits(int n)
{
    return my_count_digits_rec((n >= 0) ? n : -n, 0);
}
