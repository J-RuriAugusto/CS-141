def tokenize_input(self, input_string):
    tokens = []
    current_token = ""
    is_inside_token = False

    for char in input_string:
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

def get_type(self, string):
    if string in ["int", "char", "float", "double", "void"]:
        return 0
    elif self.isidentifier(string):
        return 1
    elif string == ",":
        return 2
    elif string == ";":
        return 3
    elif string == "=":
        return 4
    elif string == "(":
        return 5
    elif string == ")":
        return 6
    else:
        return None

def check_variable_declaration(self, tokens):
    datatypes = ['int', 'char', 'float', 'double']
    i = 0

    while i < len(tokens):
        if tokens[i] not in datatypes:
            return False

        if i >= len(tokens) or not tokens[i].isidentifier():
            return False

        if i < len(tokens) and tokens[i] == '=':

            if i >= len(tokens):
                return False

            if tokens[i] == "'":
                if i + 2 >= len(tokens) or tokens[i + 2] != "'" or (not tokens[i + 1].isalpha() and not tokens[i + 1].isnumeric()):
                    return False
            elif tokens[i] == '-' or tokens[i].isnumeric() or (tokens[i].replace('.', '', 1)).isnumeric():
                while i < len(tokens) and (tokens[i].isnumeric() or tokens[i] == '.'):
                    i += 1
            else:
                return False

        if i >= len(tokens) or tokens[i] != ';':
            return False

        i += 1

    return True

def check_function_declaration(self, tokens):
    datatypes = ['void', 'int', 'char', 'float', 'double']
    i = 0

    while i < len(tokens):
        # Check return datatype
        if tokens[i] not in datatypes:
            return False
        i += 1

        # Check function name
        if i >= len(tokens) or not tokens[i].isidentifier():
            return False
        i += 1

        # Check opening parenthesis
        if i >= len(tokens) or tokens[i] != '(':
            return False
        i += 1

        # Check parameters
        while i < len(tokens):
            if tokens[i] == ')':
                i += 1
                break

            # Check parameter type
            if tokens[i] not in datatypes:
                return False
            i += 1

            # Check parameter name
            if i >= len(tokens) or not tokens[i].isidentifier():
                return False
            i += 1

            # Check comma or closing parenthesis
            if i >= len(tokens) or (tokens[i] != ',' and tokens[i] != ')'):
                return False
            i += 1

        # Check semicolon
        if i >= len(tokens) or tokens[i] != ';':
            return False

        i += 1

    return True

def main():
    testcases = int(input())

    while testcases > 0:
        statement = input()
        declarations = statement.split(';')
        
        for declaration in declarations:
            tokens = tokenize_input(declaration.strip())  # Strip spaces at the beginning and end of the declaration

            if tokens:
                case = tokens[0]
                if case == '1':
                    if check_variable_declaration(tokens[1:]):
                        print("VALID VARIABLE DECLARATION")
                    else:
                        print("INVALID VARIABLE DECLARATION")
                else:
                    if case == '2':
                        if check_function_declaration(tokens[1:]):
                            print("VALID FUNCTION DECLARATION")
                        else:
                            print("INVALID FUNCTION DECLARATION")

        testcases -= 1

if __name__ == "__main__":
    main()