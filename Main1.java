import java.util.ArrayList;
import java.util.StringTokenizer;

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

        while (st.hasMoreTokens())
            tokens.add(st.nextToken());

        int s = tokens.size();
        int i = 0;
        int stage = 0;

        do {
            String token = tokens.get(i);
            int inputType = getType(token);

            if (stage == 0 && inputType == 0) {
                stage = 1;
            } else if (stage == 0 && inputType == 1) {
                // Skip spaces
            } else if (stage == 0 && inputType != 0) {
                status = false;
                break;
            } else if (stage == 1) {
                if (inputType == 3) {
                    stage = 0;
                } else if (inputType == 4) {
                    if (i != s - 1) {
                        status = false;
                        break;
                    } else {
                        stage = 0;
                    }
                } else if (inputType != 2) {
                    status = false;
                    break;
                }
            }
            i++;
        } while (i < s);

        // Check if all tokens have been processed
        if (i == s && stage != 1)
            status = false;
        else if (i == s && stage == 1)
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
        int currentState = 0;

        for (int i = 0; i < len; i++) {
            char ch = str.charAt(i);

            switch (currentState) {
                case 0:
                    if (ch == '_' || Character.isLetter(ch)) {
                        currentState = 1;
                    } else {
                        return false;
                    }
                    break;
                case 1:
                    if (ch == '_' || Character.isLetterOrDigit(ch)) {
                        currentState = 1;
                    } else {
                        return false;
                    }
                    break;
                default:
                    return false;
            }
        }

        return currentState == 1;
    }

    public boolean getStatus() {
        return status;
    }
}

public class Main1 {
    public static void main(String[] args) {
        // Read the number of test cases
        int numTestCases = Integer.parseInt(System.console().readLine());

        // Process each test case
        for (int i = 0; i < numTestCases; i++) {
            String[] testCase = System.console().readLine().split(" ", 2);
            int declarationType = Integer.parseInt(testCase[0]);
            String declaration = testCase[1];

            if (declarationType == 1) {
                if (isValidVariableDeclaration(declaration)) {
                    System.out.println("VALID VARIABLE DECLARATION");
                } else {
                    System.out.println("INVALID VARIABLE DECLARATION");
                }
            } else if (declarationType == 2) {
                if (isValidFunctionDeclaration(declaration)) {
                    System.out.println("VALID FUNCTION DECLARATION");
                } else {
                    System.out.println("INVALID FUNCTION DECLARATION");
                }
            }
        }
    }

    private static boolean isValidVariableDeclaration(String declaration) {
        SyntaxChecker syntaxChecker = new SyntaxChecker(declaration);
        return syntaxChecker.getStatus();
    }

    private static boolean isValidFunctionDeclaration(String declaration) {
        SyntaxChecker syntaxChecker = new SyntaxChecker(declaration);
        return syntaxChecker.getStatus();
    }
}