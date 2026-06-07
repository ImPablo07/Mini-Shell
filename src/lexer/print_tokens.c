#include <stdio.h>

#include "lexer.h"

/**
 * @brief Wyświetla wszystkie tokeny.
 *
 * Funkcja pomocnicza do debugowania lexer'a.
 *
 * @param tokens Lista tokenów.
 */
void print_tokens(t_token *tokens)
{
    while (tokens)
    {
        printf("TYPE=%d VALUE=[%s]\n",
               tokens->type,
               tokens->value);

        tokens = tokens->next;
    }
}
