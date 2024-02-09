// import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.ArrayList;

// public class Main {
//     public static void main(String[] args) {
//         Scanner scanner = new Scanner(System.in);

//         // Read the number of test cases
//         int numTestCases = scanner.nextInt();
//         scanner.nextLine(); // Consume the newline character

//         // Process each test case
//         for (int i = 0; i < numTestCases; i++) {
//             String testCase = scanner.nextLine();
//             SyntaxChecker syntaxChecker = new SyntaxChecker(testCase);

//             // Get the status and the original input string
//             boolean status = syntaxChecker.getStatus();
//             String input = syntaxChecker.getString();

//             // Print the result
//             if (status) {
//                 System.out.println("VALID ");
//             } else {
//                 System.out.println("INVALID ");
//             }
//         }

//         scanner.close();
//     }
// }

class SyntaxChecker {
    private boolean status;
    private String input;
    private String delims;
    private ArrayList<String> tokens;

    public SyntaxChecker(String str) {
        input = str;
        delims = " ,;";
        tokens = new ArrayList<String>();
        check();
    }

    private void check() {
        StringTokenizer st = new StringTokenizer(input, delims, true);
        int stage = 0;
        int i = 0;
        int s = tokens.size();

        while (st.hasMoreTokens())
            tokens.add(st.nextToken());

        do {
            String token = tokens.get(i);
            int inputType = getType(token);

            if (stage == 0 && inputType == 0)
                stage = 1;
            else if (stage == 0 && inputType == 1)
                stage = 0;
            else if (stage == 0 && inputType != 0) {
                status = false;
                break;
            } else if (stage == 1) {
                if (inputType == 3) {
                    stage = 0;
                } else if (inputType == 4) {
                    if (i != s - 2) {
                        status = false;
                        break;
                    }
                } else if (inputType != 2) {
                    status = false;
                    break;
                }
            }
            i++;
        } while (i < s);

        // Check if all tokens have been processed
        if (i == s)
            status = true;
    }

    private int getType(String str) {
        if (str.equals("int") || str.equals("char") || str.equals("float") || str.equals("double"))
            return 0;
        else if (str.equals(" "))
            return 1;
        else if (isIdentifier(str))
            return 2;
        else if (str.equals(","))
            return 3;
        else if (str.equals(";"))
            return 4;
        else
            return 5;
    }

    private boolean isIdentifier(String str) {
        int len = str.length();

        if (str.charAt(0) == '_' || (str.charAt(0) >= 'A' && str.charAt(0) <= 'Z')
                || (str.charAt(0) >= 'a' && str.charAt(0) <= 'z')) {
            for (int i = 1; i < len; i++) {
                if (!(str.charAt(i) == '_' || Character.isLetterOrDigit(str.charAt(i))))
                    return false;
            }
            return true;
        } else
            return false;
    }

    public boolean getStatus() {
        return status;
    }

    public String getString() {
        return input;
    }
}

// # stage 0 check datatype
//     # stage 1 check variable name, if variable name, store in declared_variables[] or some array to store declared variables
//     # stage 2 check ff
// 	#     = go to stage 3
// 	#     , go to stage 1
//     # stage 3 check for value or if variable, check if declared already, then check the ff
//     #     , go to stage 1
//     #     else return False
//     datatypes = ['int', 'char', 'float', 'double']
//     stage = 0
//     for i, token in enumerate(tokens):
//         if stage == 0:
//             if token not in datatypes:
//                 return False
//             stage = 1
//         elif stage == 1:
//             if not token.isidentifier():
//                 return False
//             stage = 2
//         # elif stage == 2: