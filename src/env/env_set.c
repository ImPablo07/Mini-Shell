/******************************************************************************
 * @file env_set.c
 * @author Paweł Czarny
 * @brief Operacje modyfikujące środowisko MiniShell.
 ******************************************************************************/

#include <stdlib.h>
#include <string.h>

#include "env.h"
#include "utils.h"

/**
 * @brief Wyszukuje zmienną środowiskową.
 *
 * @param env Lista środowiska.
 * @param key Nazwa zmiennej.
 *
 * @return Wskaźnik do znalezionej zmiennej lub NULL.
 */
t_env *env_find(t_env *env, const char *key)
{
    while (env)
    {
        if (strcmp(env->key, key) == 0)
            return (env);

        env = env->next;
    }

    return (NULL);
}

/**
 * @brief Tworzy nowy element listy środowiska.
 *
 * @param key Nazwa zmiennej.
 * @param value Wartość zmiennej.
 *
 * @return Nowy element lub NULL.
 */
static t_env *create_env_node(
    const char *key,
    const char *value)
{
    t_env *node;

    node = malloc(sizeof(t_env));
    if (!node)
        return (NULL);

    node->key = ft_strdup(key);
    node->value = ft_strdup(value);

    if (!node->key || !node->value)
    {
        free(node->key);
        free(node->value);
        free(node);
        return (NULL);
    }

    node->next = NULL;

    return (node);
}

/**
 * @brief Dodaje lub aktualizuje zmienną środowiskową.
 *
 * Jeśli zmienna istnieje, aktualizowana jest jej wartość.
 * Jeśli nie istnieje, tworzony jest nowy element listy.
 *
 * @param env Lista środowiska.
 * @param key Nazwa zmiennej.
 * @param value Wartość zmiennej.
 *
 * @return
 * - 0 przy sukcesie
 * - 1 przy błędzie
 */
int env_set(
    t_env **env,
    const char *key,
    const char *value)
{
    t_env *existing;
    t_env *current;
    t_env *new_node;

    existing = env_find(*env, key);

    if (existing)
    {
        free(existing->value);

        existing->value = ft_strdup(value);

        if (!existing->value)
            return (1);

        return (0);
    }

    new_node = create_env_node(key, value);
    if (!new_node)
        return (1);

    if (!*env)
    {
        *env = new_node;
        return (0);
    }

    current = *env;

    while (current->next)
        current = current->next;

    current->next = new_node;

    return (0);
}

/**
 * @brief Usuwa zmienną środowiskową.
 *
 * @param env Lista środowiska.
 * @param key Nazwa zmiennej.
 *
 * @return
 * - 0 przy sukcesie
 * - 1 jeśli zmienna nie istnieje
 */
int env_unset(
    t_env **env,
    const char *key)
{
    t_env *current;
    t_env *previous;

    if (!env || !*env)
        return (1);

    current = *env;
    previous = NULL;

    while (current)
    {
        if (strcmp(current->key, key) == 0)
        {
            if (previous)
                previous->next = current->next;
            else
                *env = current->next;

            free(current->key);
            free(current->value);
            free(current);

            return (0);
        }

        previous = current;
        current = current->next;
    }

    return (1);
}
