#include <stdio.h>

#include "builtins.h"

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
