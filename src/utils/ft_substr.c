/******************************************************************************
 * @file ft_substr.c
 * @brief Implementacja funkcji ft_substr.
 ******************************************************************************/

#include <stdlib.h>

#include "utils.h"

/**
 * @brief Tworzy podciąg znaków.
 *
 * @param s Źródłowy tekst.
 * @param start Pozycja początkowa.
 * @param len Maksymalna długość podciągu.
 *
 * @return Nowo zaalokowany podciąg lub NULL.
 */
char *ft_substr(const char *s, unsigned int start, size_t len)
{
    char    *substr;
    size_t  s_len;
    size_t  i;

    if (!s)
        return (NULL);

    s_len = ft_strlen(s);

    if (start >= s_len)
        return (ft_strdup(""));

    if (len > s_len - start)
        len = s_len - start;

    substr = malloc(sizeof(char) * (len + 1));
    if (!substr)
        return (NULL);

    i = 0;

    while (i < len)
    {
        substr[i] = s[start + i];
        i++;
    }

    substr[i] = '\0';

    return (substr);
}
