public class Expression {
    int evaluateExpression(String digits, char[] operators) {
        int result = 0;
        boolean multiplication = false;
        int factor = 1;

        for(int i = 0; ; ++i) {
            int operand = digits.charAt(i) - '0';
            while(i < operators.length && operators[i] == '.')
                operand = 10 * operand + digits.charAt(++i) - '0';

            if (multiplication) {
                operand *= factor;
                multiplication = false;
            }

            if (i == operators.length) {
                result += operand;
                break;
            }

            if (operators[i] == '+') {
                result += operand;
                continue;
            }

            multiplication = true;
            factor = operand;
        }

        return result;
    }

    void expression(String digits, char[] operators, int write, int k) {
        if (write == operators.length) {
            if (evaluateExpression(digits, operators) != k)
                return;

            for (int i = 0; i < operators.length; ++i) {
                System.out.print("" + digits.charAt(i));
                if (operators[i] != '.')
                    System.out.print("" + operators[i]);
            }
            System.out.println(digits.charAt(operators.length) + "=" + k);
            return;
        }

        operators[write] = '*';
        expression(digits, operators, write + 1, k);
        operators[write] = '+';
        expression(digits, operators, write + 1, k);
        operators[write] = '.';
        expression(digits, operators, write + 1, k);
    }

    void expression(String digits, int k) {
        expression(digits, new char[digits.length() - 1], 0, k);
    }

    public static void  main(String[] args) {
        int[] testsK = {1, 2, 24, 8, 6, 14, 222};
        String[] testsS = {"2", "2", "222", "222", "222", "1234", "222"};

        Expression e = new Expression();

        for(int i = 0; i < testsK.length; ++i) {
            System.out.println("---" + testsS[i] + "->" + testsK[i] + "---");
            e.expression(testsS[i], testsK[i]);
        }
    }
}
