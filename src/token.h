#ifndef TOKEN_H
#define TOKEN_H

#define MAX_TOKEN_LEN 256
#define MAX_TOKEN_LENGTH 256
#define MAX_TOKENS 128

typedef enum
{
    TOKEN_WORD,

    TOKEN_INPUT,

    TOKEN_OUTPUT,

    TOKEN_APPEND,

    TOKEN_BACKGROUND,

    TOKEN_PIPE,

    TOKEN_END

} token_type_t;


typedef struct
{
    token_type_t type;

    char text[MAX_TOKEN_LEN];

} token_t;


typedef struct
{
    token_t tokens[MAX_TOKENS];

    int count;

} token_list_t;


/* Initialize token list */
void token_list_init(token_list_t *list);


/* Add a token */
void token_add(token_list_t *list,
               token_type_t type,
               const char *text);


/* Print tokens */
void token_print(token_list_t *list);

#endif
