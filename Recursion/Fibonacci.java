/******************************************************************************
 *
 *  Write a function that returns the n-th element in a Fibonacci series
 *
 *****************************************************************************/
public class Fibonacci {
    public static void main(String [] args) {
        System.out.println(fib(Integer.parseInt(args[0])));
    }

    private static long fib(int n) {
        if (n == 0 || n == 1)
            return n;

        return fib(n - 1) + fib(n - 2);
    }
}
