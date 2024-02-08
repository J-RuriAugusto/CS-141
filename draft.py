# def is_valid_identifier(identifier):
#     if identifier[0] == '_' or identifier[0].isalpha():
#         for char in identifier[1:]:
#             if not (char == '_' or char.isalnum()):
#                 return False
#         return True
#     return False

# def check_variable_declaration(declaration):
#     declaration = declaration.strip(';')
#     tokens = declaration.split(',')
#     for token in tokens:
#         token = token.strip()
#         if '=' in token:
#             identifier, value = token.split('=')
#             if not is_valid_identifier(identifier.strip()):
#                 return False
#         else:
#             if not is_valid_identifier(token):
#                 return False
#     return True

# def check_function_declaration(declaration):
#     declaration = declaration.strip(';')
#     if '(' in declaration and ')' in declaration:
#         function_name, params = declaration.split('(')
#         if not is_valid_identifier(function_name.strip()):
#             return False
#         params = params.strip(')').split(',')
#         for param in params:
#             if param.strip() and not is_valid_identifier(param.strip()):
#                 return False
#         return True
#     return False

# def process_test_case(test_case):
#     declaration_type, declaration = test_case.split(' ', 1)
#     if declaration_type == '1':
#         if check_variable_declaration(declaration):
#             return "VALID VARIABLE DECLARATION"
#         else:
#             return "INVALID VARIABLE DECLARATION"
#     elif declaration_type == '2':
#         if check_function_declaration(declaration):
#             return "VALID FUNCTION DECLARATION"
#         else:
#             return "INVALID FUNCTION DECLARATION"

# # Read the number of test cases
# num_test_cases = int(input())

# # Process each test case
# for _ in range(num_test_cases):
#     test_case = input()
#     result = process_test_case(test_case)
#     print(result)



# def is_valid_identifier(identifier):
#     if identifier[0] == '_' or identifier[0].isalpha():
#         for char in identifier[1:]:
#             if not (char == '_' or char.isalnum()):
#                 return False
#         return True
#     return False

# def check_variable_declaration(declaration):
#     declaration = declaration.strip(';')
#     tokens = declaration.split(',')
#     for token in tokens:
#         token = token.strip()
#         if '=' in token:
#             identifier, value = token.split('=')
#             if not is_valid_identifier(identifier.strip()):
#                 return False
#         else:
#             if not is_valid_identifier(token) or token in ['float', 'int', 'double', 'char']:
#                 return False
#     return True

# def check_function_declaration(declaration):
#     declaration = declaration.strip(';')
#     if '(' in declaration and ')' in declaration:
#         function_name, params = declaration.split('(')
#         if not is_valid_identifier(function_name.strip()):
#             return False
#         params = params.strip(')').split(',')
#         for param in params:
#             if param.strip() and (not is_valid_identifier(param.strip()) or param.strip() in ['float', 'int', 'double', 'char']):
#                 return False
#         return True
#     return False

# def process_test_case(test_case):
#     declaration_type, declaration = test_case.split(' ', 1)
#     if declaration_type == '1':
#         if check_variable_declaration(declaration):
#             return "VALID VARIABLE DECLARATION"
#         else:
#             return "INVALID VARIABLE DECLARATION"
#     elif declaration_type == '2':
#         if check_function_declaration(declaration):
#             return "VALID FUNCTION DECLARATION"
#         else:
#             return "INVALID FUNCTION DECLARATION"

# # Read the number of test cases
# num_test_cases = int(input())

# # Process each test case
# for _ in range(num_test_cases):
#     test_case = input()
#     result = process_test_case(test_case)
#     print(result)


# def is_valid_type(type_str):
#     valid_types = ["int", "char", "float", "double"]
#     return type_str in valid_types

# def is_valid_identifier(identifier):
#     return identifier[0].isalpha() or identifier[0] == "_"

# def is_valid_variable_declaration(declaration):
#     tokens = declaration.split(",")
#     for token in tokens:
#         trimmed_token = token.strip()
#         parts = trimmed_token.split(" ")  # Use space as delimiter
#         if len(parts) < 2 or not is_valid_type(parts[0]):
#             return False
#         for i in range(1, len(parts)):
#             trimmed_part = parts[i].strip()
#             if "=" in trimmed_part:
#                 assignment_parts = trimmed_part.split("=")
#                 if len(assignment_parts) != 2 or not is_valid_identifier(assignment_parts[0].strip()):
#                     return False
#             elif not is_valid_identifier(trimmed_part):
#                 return False
#     return True

# def is_valid_function_declaration(declaration):
#     parts = declaration.split(" ")  # Use space as delimiter
#     if len(parts) < 3 or (parts[0] != "void" and not is_valid_type(parts[0])):
#         return False
#     if not is_valid_identifier(parts[1]):
#         return False
#     if parts[2] != "(" or parts[-1] != ")":
#         return False
#     return True

# num_test_cases = int(input())
# for _ in range(num_test_cases):
#     test_type = int(input())
#     declaration = input().strip()

#     if test_type == 1:
#         if is_valid_variable_declaration(declaration):
#             print("VALID VARIABLE DECLARATION")
#         else:
#             print("INVALID VARIABLE DECLARATION")
#     elif test_type == 2:
#         if is_valid_function_declaration(declaration):
#             print("VALID FUNCTION DECLARATION")
#         else:
#             print("INVALID FUNCTION DECLARATION")
    

def isValidIdentifier(identifier):
    if identifier[0].isalpha() or identifier[0] == "_":
        for char in identifier [1:]:
            if not (char =='_' or char.isalnum()):
                return False
        return True
    return False

def checkVariableDeclaration(declaration):
    declaration = declaration.strip(';')
    tokens = declaration.split(';')
    for token in tokens:
        token = token.strip()
        if '=' in token:
            identifier, value = token.split('=')
            if not isValidIdentifier(identifier.split()):
                return False
        else:
            if not isValidIdentifier(token) or token in ['float', 'int', 'double', 'char']:
                return False
    return True
    
def checkFunctionDeclaration(declaration):
    declaration = declaration.strip(';')
    if '(' in declaration and ')'in declaration:
        functionVariable, params = declaration.split('(')
        if not isValidIdentifier(functionVariable.strip()):
            return False
        params = params.strip(')').split(',')
        for param in params:
            if param.strip() and (not isValidIdentifier(param.strip()) or param.strip() in ['float', 'int', 'double', 'char']):
                return False
        return True
    return False

def inputs(testCase):
    declarationType, declaration = testCase.split(' ', 1)
    if declarationType == '1':
        if checkVariableDeclaration(declaration):
            return "VALID VARIABLE DECLARATION"
        else:
            return "INVALID VARIABLE DECLARATION"
    elif declarationType == '2':
        if checkFunctionDeclaration(declaration):
            return "VALID FUNCTION DECLARATION"
        else:
            return "INVALID FUNCTION DECLARATION"

testCases = int(input())
for _ in range(testCases):
    testCase = input()
    result = inputs(testCase)
    print(result)