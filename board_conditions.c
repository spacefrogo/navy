/*
** EPITECH PROJECT, 2019
** Epitech
** File description:
** 2019
*/

#include "include/my.h"

char	*help_board_3(char **map, char **coord, int pos_y, int pos_x)
{
    for (unsigned int i = 0; i < 3; i++, pos_x += 2) {
        if (map[pos_y][pos_x] == '.')
            map[pos_y][pos_x] = coord[1][0];
        else
            return NULL;
    }
}

char	*help_board_3s(char **map, char **coord, int pos_y, int pos_x)
{
    for (unsigned int i = 0; i < 3; i++, pos_y++) {
        if (map[pos_y][pos_x] = '.')
            map[pos_y][pos_x] = coord[1][0];
        else
            return NULL;
    }
}

char	*help_board_4(char **map, char **coord, int pos_y, int pos_x)
{
    for (unsigned int i = 0; i < 4; i++, pos_x += 2) {
        if (map[pos_y][pos_x] == '.')
            map[pos_y][pos_x] = coord[2][0];
        else
            return NULL;
    }
}

char	*help_board_4s(char **map, char **coord, int pos_y, int pos_x)
{
    for (unsigned int i = 0; i < 4; i++, pos_y++) {
        if (map[pos_y][pos_x] == '.')
            map[pos_y][pos_x] = coord[2][0];
        else
            return NULL;
    }
}

char	*help_board_5(char **map, char **coord, int pos_y, int pos_x)
{
    for (unsigned int i = 0; i < 5; pos_x += 2, i++) {
        if (map[pos_y][pos_x] == '.')
            map[pos_y][pos_x] = coord[3][0];
        else
            return NULL;
    }
}
