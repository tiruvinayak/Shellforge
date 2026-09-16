#include <stdio.h>
#include <string.h>

#include "token.h"


void token_list_init(token_list_t *list)
{
    if (list == NULL)
        return;

    list->count = 0;

    for (int i = 0; i < MAX_TOKENS; i++)
    {
        list->tokens[i].type = TOKEN_END;

        list->tokens[i].text[0] = '\0';
    }
}


void token_add(token_list_t *list,
               token_type_t type,
               const char *text)
{
    if (list == NULL)
        return;

    if (list->count >= MAX_TOKENS - 1)
        return;

    token_t *t = &list->tokens[list->count];

    t->type = type;

    if (text != NULL)
    {
        strncpy(
            t->text,
            text,
            MAX_TOKEN_LEN - 1
        );

        t->text[MAX_TOKEN_LEN - 1] = '\0';
    }
    else
    {
        t->text[0] = '\0';
    }

    list->count++;
}


void token_print(token_list_t *list)
{
    if (list == NULL)
        return;

    printf("\n========== TOKENS ==========\n");

    for (int i = 0;
         i < list->count;
         i++)
    {
        token_t *t = &list->tokens[i];

        printf("[%d] ", i);

        switch (t->type)
        {
            case TOKEN_WORD:
                printf("WORD");
                break;

            case TOKEN_INPUT:
                printf("INPUT");
                break;

            case TOKEN_OUTPUT:
                printf("OUTPUT");
                break;

            case TOKEN_APPEND:
                printf("APPEND");
                break;

            case TOKEN_BACKGROUND:
                printf("BACKGROUND");
                break;

            case TOKEN_PIPE:
                printf("PIPE");
                break;

            case TOKEN_END:
                printf("END");
                break;

            default:
                printf("UNKNOWN");
                break;
        }

        printf(" -> %s\n", t->text);
    }

    printf("============================\n");
}
