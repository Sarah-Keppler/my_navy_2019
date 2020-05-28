/*
** EPITECH PROJECT, 2019
** my_str_to_word_array.c
** File description:
** Put each work in an array, then return it.
*/

#include <stddef.h>
#include <stdlib.h>
#include "../../include/my.h"
#include "../../include/proto.h"

void get_each_word(char **array, char *src, char c)
{
    int y = 0;
    int z = 0;

    for (int i = 0; src[i]; ++i) {
        if (c != src[i] && '\n' != src[i]) {
            array[y][z] = src[i];
            array[y][z + 1] = '\0';
            ++z;
        } else {
            z = 0;
            ++y;
        }
    }
}

int my_count_words(char *src, char c)
{
    int nb = 0;

    for (int i = 0; src[i]; ++i) {
        if (c == src[i])
            ++nb;
    }
    ++nb;
    return (nb);
}

char **my_str_to_word_array(char *src, char c)
{
    int words = my_count_words(src, c);
    char **array = malloc(sizeof(char *) * (words + 1));

    if (NULL == array)
        return (NULL);
    for (int i = 0; words > i; ++i) {
        array[i] = malloc(sizeof(char) * (my_strlen(src) + 1));
        if (NULL == array[i])
            return (NULL);
    }
    get_each_word(array, src, c);
    array[words] = NULL;
    return (array);
}
