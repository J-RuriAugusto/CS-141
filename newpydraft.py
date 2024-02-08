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