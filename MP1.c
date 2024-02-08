#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int isValidType(char*);
int isValidIdentifier(char*);
int isValidVariableDeclaration(char*);
int isValidFunctionDeclaration(char*);

int main() {
    int numTestCases;
    scanf("%d\n", &numTestCases);

    for (int i = 0; i < numTestCases; i++) {
        int testType;
        scanf("%d ", &testType);

        char declaration[1000];
        fgets(declaration, sizeof(declaration), stdin);
        declaration[strcspn(declaration, "\n")] = '\0';

        if (testType == 1) {
            if (isValidVariableDeclaration(declaration)) {
                printf("VALID VARIABLE DECLARATION\n");
            } else {
                printf("INVALID VARIABLE DECLARATION\n");
            }
        } else if (testType == 2) {
            if (isValidFunctionDeclaration(declaration)) {
                printf("VALID FUNCTION DECLARATION\n");
            } else {
                printf("INVALID FUNCTION DECLARATION\n");
            }
        }
    }

    return 0;
}

int isValidType(char* type) {
    return strcmp(type, "int") == 0 || strcmp(type, "char") == 0 ||
           strcmp(type, "float") == 0 || strcmp(type, "double") == 0;
}

int isValidIdentifier(char* identifier) {
    int length = strlen(identifier);
    if (length == 0 || (!isalpha(identifier[0]) && identifier[0] != '_')) {
        return 0;
    }
    for (int i = 1; i < length; i++) {
        if (!isalnum(identifier[i]) && identifier[i] != '_') {
            return 0;
        }
    }
    return 1;
}

int isValidVariableDeclaration(char* declaration) {
    char* token = strtok(declaration, ",");
    while (token != NULL) {
        char* trimmedToken = strtok(token, " ");
        if (trimmedToken == NULL || !isValidType(trimmedToken)) {
            return 0;
        }
        trimmedToken = strtok(NULL, " ");
        if (trimmedToken == NULL || !isValidIdentifier(trimmedToken)) {
            return 0;
        }
        trimmedToken = strtok(NULL, " ");
        if (trimmedToken != NULL && strcmp(trimmedToken, "=") == 0) {
            trimmedToken = strtok(NULL, " ");
            if (trimmedToken == NULL || strchr(trimmedToken, ';') != NULL) {
                return 0;
            }
        }
        token = strtok(NULL, ",");
    }
    return 1;
}

int isValidFunctionDeclaration(char* declaration) {
    char* token = strtok(declaration, " ");
    if (token == NULL || (!strcmp(token, "void") && token[strlen(token) - 1] == ';')) {
        return 1;
    }
    if (!isValidType(token)) {
        return 0;
    }
    token = strtok(NULL, " ");
    if (token == NULL || !isValidIdentifier(token)) {
        return 0;
    }
    token = strtok(NULL, "(");
    if (token == NULL || strchr(token, ')') == NULL) {
        return 0;
    }
    return 1;
}