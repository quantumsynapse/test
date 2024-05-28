#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"

typedef enum {
    AST_NUMBER,
    AST_OPERATOR
} ASTNodeType;

typedef struct ASTNode {
    ASTNodeType type;
    char *text;
    struct ASTNode *left;
    struct ASTNode *right;
} ASTNode;

ASTNode *create_ast_node(ASTNodeType type, const char *text);
void destroy_ast_node(ASTNode *node);
ASTNode *parse(Token **tokens, int token_count);

#endif // PARSER_H
