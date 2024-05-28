#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Adicione esta linha

ASTNode *create_ast_node(ASTNodeType type, const char *text) {
    ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
    node->type = type;
    node->text = strdup(text);
    node->left = NULL;
    node->right = NULL;
    return node;
}

void destroy_ast_node(ASTNode *node) {
    if (node) {
        free(node->text);
        free(node);
    }
}

ASTNode *parse(Token **tokens, int token_count) {
    ASTNode *root = NULL;
    ASTNode **stack = (ASTNode **)malloc(token_count * sizeof(ASTNode *));
    int stack_size = 0;

    for (int i = 0; i < token_count; i++) {
        Token *token = tokens[i];
        if (token->type == TOKEN_NUMBER) {
            stack[stack_size++] = create_ast_node(AST_NUMBER, token->text);
        } else if (token->type == TOKEN_OPERATOR) {
            ASTNode *node = create_ast_node(AST_OPERATOR, token->text);
            node->right = stack[--stack_size];
            node->left = stack[--stack_size];
            stack[stack_size++] = node;
        }
    }

    root = stack[0];
    free(stack);
    return root;
}
