/******************************************************************************
 * @file builtin_env.c
 * @author Paweł Czarny
 * @brief Implementacja polecenia env.
 ******************************************************************************/

#include <stdio.h>

#include "builtins.h"

/**
 * @brief Wyświetla wszystkie zmienne środowiskowe.
 *
 * Funkcja iteruje po liście środowiska
 * przechowywanej przez shell.
 *
 * @param shell Struktura shella.
 *
 * @return Zawsze zwraca 0.
 */
int builtin_env(t_shell *shell)
{
    t_env *env;

    env = shell->env;

    while (env)
    {
        printf("%s=%s\n",
               env->key,
               env->value);

        env = env->next;
    }

    return (0);
}
