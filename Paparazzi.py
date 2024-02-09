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
    i = 0
    stage = 0

    for i, token in enumerate(tokens):
        if stage == 0:
            if token[i] not in datatypes:
                return False
            stage = 1
        elif stage == 1:
            if not token[i].isidentifier() and token == "-":
                return False
            stage = 2
        elif stage == 2:
            if token[i] != ",":
                return False
            stage == 1
            if token[i] != "=":
                return False
            stage == 3
        elif stage == 3:
            if token[i].isalpha():
                return False
            if token[i] == "'":
                if not token[i].isalpha():
                    return False
                stage = 4
            # stage = 4
            if not token[i].float() or token[i].isalnum():
                return False
            stage = 4
        elif stage == 4:
            if token[i] != ";":
                return False
            stage = 0
        else:
            return False
    
    return True

def isFunctionDeclaration(tokens):
    datatypes = ['void', 'int', 'char', 'float', 'double']
    i = 0
    stage = 0

    for i, token in enumerate(tokens):
        if stage == 0:
            if token[i] not in datatypes:
                return False
            stage = 1
        elif stage == 1:
            if not token[i].isidentifier() and token == "-":
                return False
            stage = 2
        elif stage == 2:
            if token[i] == "(":
                if token[i] not in datatypes:
                    return False
            stage = 3
        elif stage == 3:
            if token[i] != ",":
                return False
            stage = 0
        elif stage == 3:
            if token[i] != ")":
                return False
            stage = 4           
        elif stage == 4:
            if token[i] != ";":
                return False
            stage = 0
        else:
            return False
    
    return True

# def main():
testcases = int(input())

while testcases > 0:
    statement = input()
    declarations = statement.split()
        
    for declaration in declarations:
        tokens = tokenize_input(declaration.strip())

        if tokens:
            case = tokens[0]
            if case == '1':
                if isVariableDeclaration(tokens[1:]):
                    print("VALID VARIABLE DECLARATION")
                else:
                    print("INVALID VARIABLE DECLARATION")
            else:
                if case == '2':
                    if isFunctionDeclaration(tokens[1:]):
                        print("VALID FUNCTION DECLARATION")
                    else:
                        print("INVALID FUNCTION DECLARATION")

    testcases -= 1

# if __name__ == "__main__":
#     main()

# def get_type(string):
#     if string in ["int", "char", "float", "double", "void"]:
#         return 0
#     elif string.isidentifier():
#         return 1
#     elif string == ",":
#         return 2
#     elif string == "=":
#         return 3
#     elif string == "(":
#         return 4
#     elif string == ")":
#         return 5
#     elif string == ";":
#         return 6
#     else:
#         return None