 i < tokens.length; i++) {
//             String token = tokens[i];
//             if (token.endsWith(";")) {
//                 // Remove the semicolon at the end of the declaration
//                 token = token.substring(0, token.length() - 1);

//                 // Check if the token is a valid variable name or initialization
//                 if (!isValidVariable(token)) {
//                     return false;
//                 }
//             } else if (token.endsWith(",")) {
//                 // Invalid token found
//                 return false;
//             }
//         }

//         return true;
//     }

//     private static boolean isValidType(String type) {
//         return type.equals("int") || type.equals("char") || type.equals("float") || type.equals("double");
//     }

//     private static boolean isValidVariable(String token) {
//         // Split the token by '=' to check for initialization
//         String[] parts = token.split("=");
//         if (parts.length == 0) {
//             return false; // Invalid initialization
//         }

//         // Check if the variable name is valid
//         String variableName = parts[0].trim();
//         if (variableName.isEmpty() || !isValidVariableName(variableName)) {
//             return false;
//         }

//         // Check if there are initialization values
//         for (int i = 1; i < parts.length; i++) {
//             String initializationValue = parts[i].trim();
//             if (initializationValue.isEmpty() || !isValidInitializationValue(initializationValue)) {
//                 return false;
//             }
//         }

//         return true;
//     }

//     private static boolean isValidVariableName(String variableName) {
//         // Check if the variable name starts with a letter or underscore
//         char firstChar = variableName.charAt(0);
//         if (!Character.isLetter(firstChar) && firstChar != '_') {
//             return false;
//         }
    
//         // Check if the remaining characters are letters, digits, or underscores
//         for (int i = 1; i < variableName.length(); i++) {
//             char ch = variableName.charAt(i);
//             if (!Character.isLetterOrDigit(ch) && ch != '_') {
//                 return false;
//             }
//         }
    
//         return true;
//     }

//     private static boolean isValidInitializationValue(String initializationValue) {
//         // Trim leading and trailing whitespace
//         initializationValue = initializationValue.trim();

//         // Check if the initialization value is empty
//         if (initializationValue.isEmpty()) {
//             return false;
//         }

//         // Check if the initialization value is a valid numeric value
//         try {
//             Double.parseDouble(initializationValue);
//         } catch (NumberFormatException e) {
//             // Not a valid numeric value
//             return false;
//         }

//         return true;
//     }

//     private static boolean isValidFunctionDeclaration(String declaration) {
//         // Remove leading and trailing whitespace
//         declaration = declaration.trim();
    
//         // Check if the declaration starts with a valid return type
//         String[] tokens = declaration.split("\\s+");
//         if (tokens.length == 0 || !isValidType(tokens[0])) {
//             return false;
//         }
    
//         // Check if the declaration contains a valid function name and parameter list
//         if (tokens.length < 3 || !isValidFunctionName(tokens[1]) || !isValidParameterList(tokens[2])) {
//             return false;
//         }
    
//         // Check if the declaration ends with a semicolon
//         if (!declaration.endsWith(";")) {
//             return false;
//         }
    
//         return true;
//     }
    
//     private static boolean isValidFunctionName(String functionName) {
//         // Check if the function name starts with a letter or underscore
//         char firstChar = functionName.charAt(0);
//         if (!Character.isLetter(firstChar) && firstChar != '_') {
//             return false;
//         }
    
//         // Check if the remaining characters are letters, digits, or underscores
//         for (int i = 1; i < functionName.length(); i++) {
//             char ch = functionName.charAt(i);
//             if (!Character.isLetterOrDigit(ch) && ch != '_') {
//                 return false;
//             }
//         }
    
//         return true;
//     }
    
//     private static boolean isValidParameterList(String parameterList) {
//         // Remove leading and trailing parentheses
//         parameterList = parameterList.trim();
//         if (!parameterList.startsWith("(") || !parameterList.endsWith(")")) {
//             return false;
//         }
//         parameterList = parameterList.substring(1, parameterList.length() - 1);
    
//         // Split the parameter list into individual parameters
//         String[] parameters = parameterList.split(",");
//         for (String parameter : parameters) {
//             parameter = parameter.trim();
//             if (!isValidParameter(parameter)) {
//                 return false;
//             }
//         }
    
//         return true;
//     }
    
//     private static boolean isValidParameter(String parameter) {
//         // Split the parameter by whitespace to get the type and name
//         String[] parts = parameter.split("\\s+");
//         if (parts.length != 2) {
//             return false; // Invalid parameter format
//         }
    
//         // Check if the parameter type and name are valid
//         String parameterType = parts[0].trim();
//         String parameterName = parts[1].trim();
//         if (!isValidType(parameterType) || !isValidVariableName(parameterName)) {
//             return false;
//         }
    
//         return true;
//     }
// }


import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of test cases
        int numTestCases = scanner.nextInt();
        scanner.nextLine(); // Consume the newline

        // Process each test case
        for (int i = 0; i < numTestCases; i++) {
            // Read the test type (1 for variable declaration, 2 for function declaration)
            int testType = scanner.nextInt();
            scanner.nextLine(); // Consume the newline

            // Read the declaration
            String declaration = scanner.nextLine().trim();

            // Check and print the result
            if (testType == 1) {
                if (isValidVariableDeclaration(declaration)) {
                    System.out.println("VALID VARIABLE DECLARATION");
                } else {
                    System.out.println("INVALID VARIABLE DECLARATION");
                }
            } else if (testType == 2) {
                if (isValidFunctionDeclaration(declaration)) {
                    System.out.println("VALID FUNCTION DECLARATION");
                } else {
                    System.out.println("INVALID FUNCTION DECLARATION");
                }
            }
        }

        scanner.close();
    }

    private static boolean isValidVariableDeclaration(String declaration) {
        // Remove leading and trailing whitespace
        declaration = declaration.trim();

        // Check if the declaration starts with a valid type
        String[] tokens = declaration.split("\\s+");
        if (tokens.length == 0 || !isValidType(tokens[0])) {
            return false;
        }

        // Check if the declaration contains a valid variable name and optional initialization
        for (int i = 1; i < tokens.length; i++) {
            String token = tokens[i];
            if (token.endsWith(";")) {
                // Remove the semicolon at the end of the declaration
                token = token.substring(0, token.length() - 1);

                // Check if the token is a valid variable name or initialization
                if (!isValidVariable(token)) {
                    return false;
                }
            } else if (token.endsWith(",")) {
                return false;
            }
        }

        return true;
    }

    private static boolean isValidType(String type) {
        return type.equals("int") || type.equals("char") || type.equals("float") || type.equals("double");
    }

    private static boolean isValidVariable(String token) {
        // Split the token by '=' to check for initialization
        String[] parts = token.split("=");
        if (parts.length == 0) {
            return false; // Invalid initialization
        }

        // Check if the variable name is valid
        String variableName = parts[0].trim();
        if (variableName.isEmpty() || !isValidVariableName(variableName)) {
            return false;
        }

        // Check if there are initialization values
        for (int i = 1; i < parts.length; i++) {
            String initializationValue = parts[i].trim();
            if (initializationValue.isEmpty() || !isValidInitializationValue(initializationValue)) {
                return false;
            }
        }

        return true;
    }

    private static boolean isValidVariableName(String variableName) {
        // Check if the variable name starts with a letter or underscore
        char firstChar = variableName.charAt(0);
        if (!Character.isLetter(firstChar) && firstChar != '_') {
            return false;
        }

        // Check if the remaining characters are letters, digits, or underscores
        for (int i = 1; i < variableName.length(); i++) {
            char ch = variableName.charAt(i);
            if (!Character.isLetterOrDigit(ch) && ch != '_') {
                return false;
            }
        }

        return true;
    }

    private static boolean isValidInitializationValue(String initializationValue) {
        // Trim leading and trailing whitespace
        initializationValue = initializationValue.trim();

        // Check if the initialization value is empty
        if (initializationValue.isEmpty()) {
            return false;
        }

        // Check if the initialization value is a valid numeric value
        try {
            Double.parseDouble(initializationValue);
        } catch (NumberFormatException e) {
            // Not a valid numeric value
            return false;
        }

        return true;
    }

    private static boolean isValidFunctionDeclaration(String declaration) {
        // Remove leading and trailing whitespace
        declaration = declaration.trim();

        // Check if the declaration starts with a valid return type
        String[] tokens = declaration.split("\\s+");
        if (tokens.length == 0 || !isValidType(tokens[0])) {
            return false;
        }

        // Check if the declaration contains a valid function name and parameter list
        if (tokens.length < 3 || !isValidFunctionName(tokens[1]) || !isValidParameterList(tokens[2])) {
            return false;
        }

        // Check if the declaration ends with a semicolon
        if (!declaration.endsWith(";")) {
            return false;
        }

        return true;
    }

    private static boolean isValidFunctionName(String functionName) {
        // Check if the function name starts with a letter or underscore
        char firstChar = functionName.charAt(0);
        if (!Character.isLetter(firstChar) && firstChar != '_') {
            return false;
        }

        // Check if the remaining characters are letters, digits, or underscores
        for (int i = 1; i < functionName.length(); i++) {
            char ch = functionName.charAt(i);
            if (!Character.isLetterOrDigit(ch) && ch != '_') {
                return false;
            }
        }

        return true;
    }

    private static boolean isValidParameterList(String parameterList) {
        // Remove leading and trailing parentheses and whitespace
        parameterList = parameterList.trim();
        if (parameterList.isEmpty() || !parameterList.startsWith("(") || !parameterList.endsWith(")")) {
            return false;
        }

        // Remove the parentheses
        parameterList = parameterList.substring(1, parameterList.length() - 1).trim();

        // Check if the parameter list is empty
        if (parameterList.isEmpty()) {
            return true;
        }

        // Split the parameter list by commas
        String[] parameters = parameterList.split(",");
        for (String parameter : parameters) {
            parameter = parameter.trim();
            if (!isValidParameter(parameter)) {
                return false;
            }
        }

        return true;
    }

    private static boolean isValidParameter(String parameter) {
        // Split the parameter by spaces to check the type and name
        String[] tokens = parameter.split("\\s+");
        if (tokens.length != 2 || !isValidType(tokens[0]) || !isValidVariableName(tokens[1])) {
            return false;
        }

        return true;
    }
}