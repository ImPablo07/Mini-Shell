#include "env.h"

t_env *env_init(char **envp)
{
    (void)envp;
    return (NULL);
}

char *env_get(t_env *env, const char *key)
{
    (void)env;
    (void)key;
    return (NULL);
}

void env_destroy(t_env *env)
{
    (void)env;
}
