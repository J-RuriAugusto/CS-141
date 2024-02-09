def tokenize_input(string):
    tokens = []
    current_token = ""
    is_inside_token = False

    for char in string:
        if char in [' ', '\n', '\t']:
            if is_inside_token:
                tokens.append(current_token)
                current_token = ""
                is_inside_token = False
        elif char in [',', ';', '=', '(', ')']:
            if is_inside_token:
                tokens.append(current_token)
                current_token = ""
                is_inside_token = False
            tokens.append(char)
        else:
            current_token += char
            is_inside_token = True

    if is_inside_token:
        tokens.append(current_token)

    return tokens

def isVariableDeclaration(tokens):
    datatypes = ["int", "char", "float", "double", "void"]
    stage = 0

    for token in enumerate(tokens):
        if stage == 0:
            if token not in datatypes:
                return False
            stage = 1
        elif stage == 1:
            if not token.isidentifier():
                return False
            stage = 2
        elif stage == 2:
            if token == ",":
                stage = 1
            if token == "=":
                stage = 3
            else:
                return False
        elif stage == 3:
            if token == "'":
                if (token.isalpha() and (token.next() == "'")):
                    stage = 4
                if token.float() or token.isalnum():
                    stage = 4
            else:
                return False
        elif stage == 4:
            if token != ",":
                return False
            stage = 1
    
    return True

def isFunctionDeclaration(tokens):
    datatypes = ['void', 'int', 'char', 'float', 'double']
    i = 0
    stage = 0

    for i, token in enumerate(tokens):
        if stage == 0:
            if token not in datatypes:
                return False
            stage = 1
        elif stage == 1:
            if not token.isidentifier():
                return False
            stage = 2
        elif stage == 2:
            if token == "(":
                if token[i] not in datatypes:
                    return False
            stage = 3
        elif stage == 3:
            if token != ",":
                return False
            stage = 0
        elif stage == 3:
            if token != ")":
                return False
            stage = 4           
        elif stage == 4:
            if token != ";":
                return False
            stage = 0
    
    return True

# def main():
testcases = int(input())

while testcases > 0:
    statement = input()
    # Since statement will always contain the case in its first character, this gets it
    case = int(statement[0])
    # This splits the statement string by ';' then removes empty elements
    # because sometimes it results in ['int x;', '']
    declarations = [x for x in statement[2:].split(';') if x != '']
        
    for declaration in declarations:
        tokens = tokenize_input(declaration.strip())

        if tokens:
            if case == 1:
                if isVariableDeclaration(tokens):
                    print("VALID VARIABLE DECLARATION")
                else:
                    print("INVALID VARIABLE DECLARATION")
            else:
                if case == 2:
                    if isFunctionDeclaration(tokens):
                        print("VALID FUNCTION DECLARATION")
                    else:
                        print("INVALID FUNCTION DECLARATION")

    testcases -= 1