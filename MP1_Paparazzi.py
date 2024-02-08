# import re

# class SyntaxChecker:
#     def __init__(self, input_str):
#         self.status = False
#         self.input = input_str
#         self.delims = " ,;"
#         self.tokens = []
#         self.check()

#     def check(self):
#         st = self.input.split(self.delims)
#         self.tokens = [token.strip() for token in st if token.strip()]
#         stage = 0
#         i = 0
#         s = len(self.tokens)

#         while i < s:
#             token = self.tokens[i]
#             input_type = self.get_type(token)

#             if stage == 0 and input_type == 0:
#                 stage = 1
#             elif stage == 0 and input_type == 1:
#                 stage = 0
#             elif stage == 0 and input_type != 0:
#                 self.status = False
#                 break
#         i += 1
    
    # def get_type(self, string):
    #     if string in ["int", "char", "float", "double"]:
    #         return 0
    #     elif string == " ":
    #         return 1
    #     elif self.is_identifier(string):
    #         return 2
    #     elif string == ",":
    #         return 3
    #     elif string == ";":
    #         return 4
    #     else:
    #         return 5
        
#     def is_identifier(self, string):
#         if string[0] == '_' or string[0].isalpha():
#             for char in string[1:]:
#                 if not (char == '_' or char.isalnum()):
#                     return False
#             return True
#         else:
#             return False
        
#     def get_status(self):
#         return self.status
    
#     def get_string(self):
#         return self.input


# def is_valid_type(type_str):
#     valid_types = ["int", "char", "float", "double"]
#     return type_str in valid_types

# def is_valid_identifier(identifier):
#     if not identifier[0].isalpha() and identifier[0] != '_':
#         return False
#     for char in identifier[1:]:
#         if not char.isalnum() and char != '_':
#             return False
#     return True

# def is_variable_declaration(input_str):
#     tokens = input_str.split()
#     if len(tokens) >= 2 and is_valid_type(tokens[0]):
#         for token in tokens[1:]:
#             if not is_valid_identifier(token):
#                 return False
#         return True
#     return False

# def is_function_declaration(input_str):
#     tokens = input_str.split()
#     if len(tokens) >= 3 and is_valid_type(tokens[0]) and is_valid_identifier(tokens[1]):
#         if tokens[2] == "(" and tokens[-1] == ")":
#             return True
#     return False

# def main():
#     input_str = input()

#     if is_variable_declaration(input_str):
#         print("Valid Variable Declaration")
#     else:
#         print("Invalid Variable Declaration")

#     if is_function_declaration(input_str):
#         print("Valid Function Declaration")
#     else:
#         print("Invalid Function Declaration")

# if __name__ == "__main__":
#     main()



# def is_valid_type(type_str):
#     valid_types = ["int", "char", "float", "double"]
#     return type_str in valid_types

# def is_valid_identifier(identifier):
#     return identifier[0].isalpha() or identifier[0] == "_"

# def is_valid_variable_declaration(declaration):
#     tokens = declaration.split(",")
#     for token in tokens:
#         trimmed_token = token.strip()
#         parts = trimmed_token.split()
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
#     parts = declaration.split()
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


# I declare, upon my honor, that I did this machine problem assignment by myself
# using online resources from the following (please site the online sources).
#       https://www.youtube.com/watch?v=kqtD5dpn9C8&list=WL&index=4&t=738s
#       https://www.youtube.com/watch?v=GsO5fsxlQ3g
#       https://www.tutorialspoint.com/python_text_processing/python_tokenization.htm
#       https://www.w3schools.com/python/python_for_loops.asp
#       https://www.w3schools.com/python/ref_list_append.asp
#`      https://realpython.com/python-append/


# Further, my solution is not a copy from the aforementioned sources.


# import nltk

# if tokens[1] == 'int' or tokens[1] == 'double':
#             print("THIS IS AN INT OR DOUBLE")

def check_value(value):
    # Check if the value contains a hyphen or starts with a number
    if '-' in value or value[0].isdigit():
        return False
    else:
        return True

def split_line(line):
    tokens = []
    current_token = ''
    for char in line:
        if char in (',', '=',' ',';'):
            if current_token:
               # print("THIS IS THE CURRENT_TOKEN" + current_token)
                tokens.append(current_token)
                current_token = ''
            if char == '=' or char==';' or char ==',':
                tokens.append(char)
        elif char != ' ':
            current_token += char
    if current_token:
        tokens.append(current_token)
    return tokens

def split_line2(line):
    tokens = []
    current_token = ''
    for char in line:
        if char in (',', '=',' ',';','(',')'):
            if current_token:
               # print("THIS IS THE CURRENT_TOKEN" + current_token)
                tokens.append(current_token)
                current_token = ''
            if char == '=' or char==';' or char ==','or char==')' or char=='(':
                tokens.append(char)
        elif char != ' ':
            current_token += char
    if current_token:
        tokens.append(current_token)
    return tokens

def check_1(line):
    tokens = split_line(line)
    if tokens:  
        list = []
        return real_check_1(tokens, list)
    else:
        return False

def check_2(line):
    tokens = split_line2(line)
    if tokens:  
        return real_check_2(tokens)
    else:
        return False

def real_check_2(tokens):
    # print(tokens)
    maximum = 0
    comma = 0
    cur = 1
    datatypes = ['int', 'char', 'double', 'float', 'void']
    check = 0
    while cur < len(tokens):
        if check == 0:
            datatype = 'nothing'
            for x in datatypes:
                if x == tokens[cur]:
                    datatype = x
            if datatype == 'nothing':
                return False
            check =1
        elif check == 1:
            # print("to check value" + tokens[cur])
            if not check_value(tokens[cur]):
                return False
            for x in datatypes:
                if x == tokens[cur]:
                    return False
            check = 2
        elif check == 2:
            if tokens[cur]!='(':
                return False
            check =3
            
        elif check == 3:
            if tokens[cur] == ')':
                check =4
                maximum = 0
            
            elif tokens[cur] ==',':
                maximum = 0
            else:
                maximum+=1
                if(maximum==3):
                    #print(maximum)
                    return False
                    
        elif check ==4:
            # print(tokens[cur])
            if tokens[cur] == ',':
                maximum =0
                check = 1
            elif tokens[cur] == ';':
                check =0
            
            else:
                return False
        else:
            return False
        cur += 1
    if check !=0:
        return False
    return True

    
def real_check_1(tokens,list):
    initializer = 0
    current =3
    currentlist = []
    datatypes = ['int', 'char', 'double', 'float']
    valuessemi = []
    values = []
    valuesindex = 0
    semicolon = 0
    # print(tokens)
    if tokens[1] == 'int':
        initializer = 1
       #print("to for int")
        current = 3
        cur = 2
        rond = 0
        while cur < len(tokens):
            # print(tokens)
            if semicolon ==0:
                for x in datatypes:
                    if x == tokens[cur]:
                        print("in the datatypes" + tokens[cur])
                        return False
                for x in currentlist:
                    if x == tokens[cur]:
                        # print("in the current list" + tokens[cur])
                        return False
                if rond == 1:
                    # print(tokens[cur])
                    rond = 0
                    check = tokens[cur]
                    if not check.isdigit():
                        # print(check)
                        if len(check) >= 2 or (check[0] == "'" and check[-1] == "'"):
                            if not check[1:-1].isdigit():
                                # print("this wrong" + check)
                                return False
                        else:
                            # print(check)
                            return False

                    current = 0
                elif tokens[cur] == '=':
                    rond = 1
                elif tokens[cur] == ';' and current == 3:
                    # print("should have value")
                    return False
                elif tokens[cur] == ';':
                   #valuessemi.append(tokens)
                    semicolon = 1
                elif current == 3:
                    #print("vale: " + tokens[cur])
                    currentlist.append(tokens[cur])
                    if not check_value(tokens[cur]):
                        # print(tokens[cur])
                        return False
                    current = 0
                elif tokens[cur] == ',':
                    current = 3
            elif semicolon == 1:
                valuessemi.append(tokens[cur])
                
            cur += 1
        # print("done for int")
    
    elif tokens[1] == 'double':
        initializer = 1
        cur = 2
        rond = 0
        while cur < len(tokens):
            for x in datatypes:
                    if x == tokens[cur]:
                        return False
            if semicolon ==0:
                if rond == 1:
                    rond = 0
                    check = tokens[cur]
                    nextcheck = 1
                    for x in values:
                        if x == check:
                            nextcheck = 0
                    if nextcheck ==1:
                        try:
                            float(check)
                        except ValueError:
                            return False
                        current = 0
                elif tokens[cur] == '=':
                    rond = 1
                    values.append(tokens[cur-1])
                elif tokens[cur] == ';':
                    semicolon = 1
                elif current == 3:
                    currentlist.append(tokens[cur])
                    if not check_value(tokens[cur]):
                        # print(tokens[cur])
                        return False
                    current = 0
                elif tokens[cur] == ',':
                    current = 3
                else:
                    return False
                    
            elif semicolon == 1:
                valuessemi.append(tokens[cur])
                
            cur += 1
    
    elif tokens[1] == 'char':
        initializer = 1
        cur = 2
        rond = 0
        while cur < len(tokens):
            if semicolon ==0:
                for x in datatypes:
                    if x == tokens[cur]:
                        return False
                if rond == 1:
                    # print(tokens[cur])
                    rond = 0
                    check = tokens[cur]
                    if len(check) != 3 and check[0] != "'" and check[2] != "'":
                        return False
                    current = 0
                elif tokens[cur] == '=':
                    rond = 1
                elif tokens[cur] == ';':
                    semicolon = 1
                elif current == 3:
                    currentlist.append(tokens[cur])
                    if not check_value(tokens[cur]):
                        return False
                    current = 0
                elif tokens[cur] == ',':
                    current = 3
                else:
                    return False
            elif semicolon == 1:
                valuessemi.append(tokens[cur])
                
            cur += 1
    
    elif tokens[1] == 'float':
        initializer = 1
        cur = 2
        semicolon = 0
        current = 3
        rond = 0
        while cur < len(tokens):
            if semicolon == 0:
                for x in datatypes:
                    if x == tokens[cur]:
                        # print(tokens[cur])
                        return False
                if rond == 1:
                    # print(tokens[cur])
                    rond = 0
                    check = tokens[cur]
                    try:
                        # print(tokens[cur])
                        float(tokens[cur])
                    except ValueError:
                        return False
                    current = 0
                elif tokens[cur] == '=':
                    rond = 1
                elif tokens[cur] == ';':
                        semicolon = 1
                elif tokens[cur] == ',':
                        current = 3
                elif current == 3:
                    currentlist.append(tokens[cur])
                    if not check_value(tokens[cur]):
                        return False
                    current = 0
                elif tokens[cur] == ',':
                    current = 3
                else:
                    # print(tokens[cur])
                    return False
            elif semicolon == 1:
                valuessemi.append(tokens[cur])
            cur += 1

    if semicolon == 1:
        
        if valuessemi:
            return real_check_1(valuessemi, currentlist)
        else:
            return True
    else:
        return True

testcase = int(input(""))

while testcase > 0:
    line = input("")
    # print(line)
    tokens = line.split()
    if tokens:
        num = tokens[0]
    if num == '1':
        if check_1(line):
            print("VALID VARIABLE DECLARATION")
        else:
            print("INVALID VARIABLE DECLARATION")
    else:
        if check_2(line):
            print("VALID FUNCTION DECLARATION")
        else:
            print("INVALID FUNCTION DECLARATION")
    testcase -= 1

# 4
# 1 int x, y, z = 10;
# 1 double a int function();
# 2 INT function2(void);
# 2 int solve(int,char,double x,float,int,int);
    

# Proposed grade: 0.5 / 10
# Comments
# Failed tests
# Test 1: 1
# Test 2: 2
# Test 3: 3
# Test 4: 4
# Test 5: 5
# Test 7: 7
# Test 8: 8
# Test 9: 9
# Test 10: 10
# Test 11: 11
# Test 12: 12
# Test 13: 13
# Test 15: 15
# Test 1: 1
# Incorrect program output
# --- Input ---
# 3
# 1 int x       ;
# 1 int x,      y;
# 1 int x = 1, y =23      ;

# --- Program output ---
# INVALID VARIABLE DECLARATION
# INVALID VARIABLE DECLARATION
# INVALID VARIABLE DECLARATION

# --- Expected output (text)---
# VALID VARIABLE DECLARATION
# VALID VARIABLE DECLARATION
# VALID VARIABLE DECLARATION

# Test 2: 2
# Incorrect program output
# --- Input ---
# 2
# 1 char a;
# 1 char a = '1';

# --- Program output ---
# VALID VARIABLE DECLARATION
# INVALID VARIABLE DECLARATION

# --- Expected output (text)---
# VALID VARIABLE DECLARATION
# VALID VARIABLE DECLARATION

# Test 3: 3
# Incorrect program output
# --- Input ---
# 6
# 1 int x, y, z = 10;
# 1 double a, b, c;
# 1 double a=2, b=2.7, c=a;
# 1 char a = 'a';
# 1 int x, w, r;
# 1 int ab2, wxyz; char r='a';

# --- Program output ---
# INVALID VARIABLE DECLARATION
# INVALID VARIABLE DECLARATION
# INVALID VARIABLE DECLARATION
# INVALID VARIABLE DECLARATION
# INVALID VARIABLE DECLARATION
# INVALID VARIABLE DECLARATION

# --- Expected output (text)---
# VALID VARIABLE DECLARATION
# VALID VARIABLE DECLARATION
# VALID VARIABLE DECLARATION
# VALID VARIABLE DECLARATION
# VALID VARIABLE DECLARATION
# VALID VARIABLE DECLARATION

# Test 4: 4
# Incorrect program output
# --- Input ---
# 2
# 1 int a double x, y, z;
# 1 char a ='a' a;

# --- Program output ---
# INVALID VARIABLE DECLARATION
# VALID VARIABLE DECLARATION

# --- Expected output (text)---
# INVALID VARIABLE DECLARATION
# INVALID VARIABLE DECLARATION

# Test 5: 5
# Incorrect program output
# --- Input ---
# 4
# 1 char a, i, hellothisisavariablename2;
# 1 char a, i, hello_this_is_a_variable_name2;
# 1 char a, i, hello-this-is-a-variable-name2;
# 1 int 2x, 49;

# --- Program output ---
# INVALID VARIABLE DECLARATION
# INVALID VARIABLE DECLARATION
# INVALID VARIABLE DECLARATION
# INVALID VARIABLE DECLARATION

# --- Expected output (text)---
# VALID VARIABLE DECLARATION
# VALID VARIABLE DECLARATION
# INVALID VARIABLE DECLARATION
# INVALID VARIABLE DECLARATION

# Test 7: 7
# Incorrect program output
# --- Input ---
# 5
# 1 double int, char;
# 1 char ch, letter = 'a', digit = '0';
# 1 int a, b, c = d;
# 1 int num = '9';
# 1 char ch = 122;

# --- Program output ---
# INVALID VARIABLE DECLARATION
# INVALID VARIABLE DECLARATION
# INVALID VARIABLE DECLARATION
# INVALID VARIABLE DECLARATION
# INVALID VARIABLE DECLARATION

# --- Expected output (text)---
# INVALID VARIABLE DECLARATION
# VALID VARIABLE DECLARATION
# INVALID VARIABLE DECLARATION
# VALID VARIABLE DECLARATION
# VALID VARIABLE DECLARATION

# Test 8: 8
# Incorrect program output
# --- Input ---
# 2
# 1 int x, y, x = 45;
# 1 double a int x char ch;

# --- Program output ---
# INVALID VARIABLE DECLARATION
# VALID VARIABLE DECLARATION

# --- Expected output (text)---
# INVALID VARIABLE DECLARATION
# INVALID VARIABLE DECLARATION

# Test 9: 9
# Incorrect program output
# --- Input ---
# 3
# 1 int num1 = 10; char digit = 'a';
# 1 float f1_1 = 2.0; double d1_1 = 3.00;
# 1 int number = 53_a;

# --- Program output ---
# INVALID VARIABLE DECLARATION
# INVALID VARIABLE DECLARATION
# INVALID VARIABLE DECLARATION

# --- Expected output (text)---
# VALID VARIABLE DECLARATION
# VALID VARIABLE DECLARATION
# INVALID VARIABLE DECLARATION

# Test 10: 10
# Incorrect program output
# --- Input ---
# 3
# 2 int function();
# 2 INT function2(void);
# 2 int solve(int,    char,double x,float,int,   int);

# --- Program output ---
# INVALID FUNCTION DECLARATION
# INVALID FUNCTION DECLARATION
# INVALID FUNCTION DECLARATION

# --- Expected output (text)---
# VALID FUNCTION DECLARATION
# INVALID FUNCTION DECLARATION
# VALID FUNCTION DECLARATION

# Test 11: 11
# Incorrect program output
# --- Input ---
# 5
# 2 int power(int,int);
# 2 char toLower( char );
# 2 double squareRoot(float);
# 2 int gcd(int,int), lcm(  int, int);
# 2 int isPrime(int n);

# --- Program output ---
# INVALID FUNCTION DECLARATION
# INVALID FUNCTION DECLARATION
# INVALID FUNCTION DECLARATION
# INVALID FUNCTION DECLARATION
# INVALID FUNCTION DECLARATION

# --- Expected output (text)---
# VALID FUNCTION DECLARATION
# VALID FUNCTION DECLARATION
# VALID FUNCTION DECLARATION
# VALID FUNCTION DECLARATION
# VALID FUNCTION DECLARATION

# Test 12: 12
# Incorrect program output
# --- Input ---
# 5
# 2 void _f_();
# 2 int int();
# 2 int char();
# 2 int function(int)int a = 10;
# 2 void foo(void);

# --- Program output ---
# INVALID FUNCTION DECLARATION
# INVALID FUNCTION DECLARATION
# INVALID FUNCTION DECLARATION
# INVALID FUNCTION DECLARATION
# INVALID FUNCTION DECLARATION

# --- Expected output (text)---
# VALID FUNCTION DECLARATION
# INVALID FUNCTION DECLARATION
# INVALID FUNCTION DECLARATION
# INVALID FUNCTION DECLARATION
# VALID FUNCTION DECLARATION

# Test 13: 13
# Incorrect program output
# --- Input ---
# 5
# 2 int area(int a, int b);
# 2 int perimeter(int,int abc_cbn);
# 2 char isAlpha(char);
# 2 int function1(int), function2(int a);
# 2 void voids(void); int nextFunction(int);

# --- Program output ---
# INVALID FUNCTION DECLARATION
# INVALID FUNCTION DECLARATION
# INVALID FUNCTION DECLARATION
# INVALID FUNCTION DECLARATION
# INVALID FUNCTION DECLARATION

# --- Expected output (text)---
# VALID FUNCTION DECLARATION
# VALID FUNCTION DECLARATION
# VALID FUNCTION DECLARATION
# VALID FUNCTION DECLARATION
# VALID FUNCTION DECLARATION

# Test 15: 15
# Incorrect program output
# --- Input ---
# 6
# 1 int x = 2, y = 5, z = -10; float num = -1234.56; double dobol = z; int a = y = z;
# 1 double a int function();
# 2 INT function2(void);
# 2 int solve(int,char,double x,float,int,int); int test(); void anotherTest(); float lastTest(float);
# 1 int;x=0;
# 2 int;functionTest(void);

# --- Program output ---
# INVALID VARIABLE DECLARATION
# INVALID VARIABLE DECLARATION
# INVALID FUNCTION DECLARATION
# INVALID FUNCTION DECLARATION
# INVALID VARIABLE DECLARATION
# INVALID FUNCTION DECLARATION

# --- Expected output (text)---
# VALID VARIABLE DECLARATION
# INVALID VARIABLE DECLARATION
# INVALID FUNCTION DECLARATION
# VALID FUNCTION DECLARATION
# INVALID VARIABLE DECLARATION
# INVALID FUNCTION DECLARATION

# Summary of tests
# +------------------------------+
# | 15 tests run/ 2 tests passed |
# +------------------------------+