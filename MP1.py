# def check(line):
#     def tokenize(args, token_type):
#         tokens = []
#         current_token = ''
#         identifiers = (',', '=', ' ', ';') if token_type == 1 else (',', '=', ' ', ';', '(', ')')

#         for char in args:
#             if char in identifiers:
#                 if current_token:
#                     tokens.append(current_token)
#                     current_token = ''
#                 if char in ('=', ';', ',', ')', '('):
#                     tokens.append(char)
#             elif char != ' ':
#                 current_token += char

#         if current_token:
#             tokens.append(current_token)

#         return tokens

#     def isValidFunctionDeclaration(tokens):
#         comma_count = 0
#         current_index = 1
#         data_types = ['int', 'char', 'double', 'float', 'void']
#         check = 0

#         while current_index < len(tokens):
#             if check == 0:
#                 data_type = 'nothing'
#                 for dt in data_types:
#                     if dt == tokens[current_index]:
#                         data_type = dt
#                 if data_type == 'nothing':
#                     return False
#                 check = 1
#             elif check == 1:
#                 if '-' in tokens[current_index] or tokens[current_index][0].isdigit():
#                     return False
#                 for dt in data_types:
#                     if dt == tokens[current_index]:
#                         return False
#                 check = 2
#             elif check == 2:
#                 if tokens[current_index] != '(':
#                     return False
#                 check = 3
#             elif check == 3:
#                 if tokens[current_index] == ')':
#                     check = 4
#                 elif tokens[current_index] == ',':
#                     comma_count += 1
#                 else:
#                     return False
#             elif check == 4:
#                 if tokens[current_index] == ',':
#                     comma_count += 1
#                     check = 1
#                 elif tokens[current_index] == ';':
#                     check = 0
#                 else:
#                     return False
#             else:
#                 return False
#             current_index += 1

#         if check != 0:
#             return False

#         return True

#     def isValidVariableDeclaration(tokens):
#         data_types = ['int', 'char', 'double', 'float']
#         values = []
#         current = None

#         if len(tokens) < 3 or tokens[0] not in data_types:
#             return False

#         for token in tokens[1:]:
#             if token == ';':
#                 if current is not None and not values:
#                     return False
#                 break
#             elif token == ',':
#                 if current is None or not values:
#                     return False
#                 values.clear()
#                 current = None
#             elif current is None:
#                 current = token
#             elif token == '=':
#                 continue
#             else:
#                 if '-' in token or token[0].isdigit():
#                     return False
#                 values.append(token)

#         return True

#     tokens = tokenize(line, 1)

#     if tokens:
#         if isValidVariableDeclaration(tokens):
#             return True
#     else:
#         tokens = tokenize(line, 2)
#         if tokens:
#             if isValidFunctionDeclaration(tokens):
#                 return True

#     return False

# testcase = int(input(""))

# while testcase > 0:
#     line = input("")
#     tokens = line.split()
#     if tokens:
#         cases = tokens[0]
#     if cases == '1':
#         if check(line):
#             print("VALID VARIABLE DECLARATION")
#         else:
#             print("INVALID VARIABLE DECLARATION")
#     else:
#         if check(line):
#             print("VALID FUNCTION DECLARATION")
#         else:
#             print("INVALID FUNCTION DECLARATION")
#     testcase -= 1

# def tokenize(args, token_type):
#     tokens = []
#     current_token = ''
#     identifiers = (',', '=', ' ', ';') if token_type == 1 else (',', '=', ' ', ';', '(', ')')

#     for char in args:
#         if char in identifiers:
#             if current_token:
#                 tokens.append(current_token)
#                 current_token = ''
#             if char in ('=', ';', ',', ')', '('):
#                 tokens.append(char)
#         elif char != ' ':
#             current_token += char

#     if current_token:
#         tokens.append(current_token)

#     return tokens

# def isValidFunctionDeclaration(tokens):
#     comma_count = 0
#     current_index = 1
#     data_types = ['int', 'char', 'double', 'float', 'void']
#     check = 0

#     while current_index < len(tokens):
#         if check == 0:
#             data_type = 'nothing'
#             for dt in data_types:
#                 if dt == tokens[current_index]:
#                     data_type = dt
#             if data_type == 'nothing':
#                 return False
#             check = 1
#         elif check == 1:
#             if '-' in tokens[current_index] or tokens[current_index][0].isdigit():
#                 return False
#             for dt in data_types:
#                 if dt == tokens[current_index]:
#                     return False
#             check = 2
#         elif check == 2:
#             if tokens[current_index] != '(':
#                 return False
#             check = 3
#         elif check == 3:
#             if tokens[current_index] == ')':
#                 check = 4
#             elif tokens[current_index] == ',':
#                 comma_count += 1
#             else:
#                 return False
#         elif check == 4:
#             if tokens[current_index] == ',':
#                 comma_count += 1
#                 check = 1
#             elif tokens[current_index] == ';':
#                 check = 0
#             else:
#                 return False
#         else:
#             return False
#         current_index += 1

#     if check != 0:
#         return False
    
#     return True

# def isValidVariableDeclaration(tokens):
#     data_types = ['int', 'char', 'double', 'float']
#     values = []
#     current = None

#     if len(tokens) < 3 or tokens[0] not in data_types:
#         return False

#     for token in tokens[1:]:
#         if token == ';':
#             if current is not None and not values:
#                 return False
#             break
#         elif token == ',':
#             if current is None or not values:
#                 return False
#             values.clear()
#             current = None
#         elif current is None:
#             current = token
#         elif token == '=':
#             continue
#         else:
#             if '-' in token or token[0].isdigit():
#                 return False
#             values.append(token)

#     return True

# def check_1(line):
#     tokens = tokenize(line)
#     if tokens:  
#         listt = []
#         return isValidVariableDeclaration(tokens, listt)
#     else:
#         return False

# def check_2(line):
#     tokens = tokenize(line)
#     if tokens:  
#         return isValidFunctionDeclaration(tokens)
#     else:
#         return False


def check_value(value):
    # Check if the value contains a hyphen or starts with a number
    if '-' in value or value[0].isdigit():
        return False
    return True

def tokenize(line):
    tokens = []
    current_token = ''
    for char in line:
        if char in (',', '=', ' ', ';', '(', ')'):
            if current_token:
                tokens.append(current_token)
                current_token = ''
            if char in (',', '=', ';', '(', ')'):
                tokens.append(char)
        elif char != ' ':
            current_token += char
    if current_token:
        tokens.append(current_token)
    return tokens

def validate_variable_declaration(tokens):
    if not tokens or tokens[0] != '1':
        return False
    current_list = []
    current = None
    semicolon_count = 0
    for token in tokens[1:]:
        if token == '=':
            current = 'assigning'
        elif token == ';':
            semicolon_count += 1
            if semicolon_count > 1 or not current_list:
                return False
            if current == 'value':
                if not check_value(current_list[-1]):
                    return False
            current_list = []
            current = None
        elif token == ',':
            if current == 'value':
                if not check_value(current_list[-1]):
                    return False
            current_list = []
            current = None
        elif current == 'assigning':
            current = 'value'
            current_list.append(token)
        elif current != 'value':
            current_list.append(token)
    return semicolon_count == 1

def validate_function_declaration(tokens):
    if not tokens or tokens[0] != '2':
        return False
    datatypes = ['int', 'char', 'double', 'float', 'void']
    if len(tokens) < 5 or tokens[1] not in datatypes or tokens[2].isalpha() or tokens[3] != '(':
        return False
    param_count = 0
    for token in tokens[4:]:
        if token == '(':
            return False
        elif token == ')':
            return param_count <= 3
        elif token == ',':
            param_count += 1
        elif token not in datatypes and not token.isalpha():
            return False
    return False

testcases = int(input(""))

while testcases > 0:
    line = input("")
    tokens = tokenize(line)
    if tokens:
        num = tokens[0]
        if num == '1':
            if validate_variable_declaration(tokens):
                print("VALID VARIABLE DECLARATION")
            else:
                print("INVALID VARIABLE DECLARATION")
        elif num == '2':
            if validate_function_declaration(tokens):
                print("VALID FUNCTION DECLARATION")
            else:
                print("INVALID FUNCTION DECLARATION")
    testcases -= 1
