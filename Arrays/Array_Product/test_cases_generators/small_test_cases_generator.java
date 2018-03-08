package Array_Product.test_cases_generators;

import Array_Product.solutions.optimal_solution;

import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;

public class small_test_cases_generator {
    static Random random = new Random();
    static String myDelimiter="";
    static String endStr="";//"-------------------------------------------------";
    public static void main(String[] args) throws IOException {
        File file = new File(System.getProperty("user.dir"));
        PrintWriter pw = new PrintWriter(new File(file.toString() + "/Arrays/Array_Product/test_cases/generated_small_test_cases_input.txt"));
        int totalTestCases = 25;
        pw.println(totalTestCases);
        pw.println();
        for (int testCase = 0; testCase < totalTestCases; testCase++) {
            boolean isPositiveTestCase = random.nextBoolean();
            int n = 20 + random.nextInt(1000);
            List<Integer> magicList = getMagicList();
            for (int i = magicList.size(); i < n; i++) {
                magicList.add(isPositiveTestCase ? 1 : (random.nextBoolean() ? 1 : -1));
            }
            Collections.shuffle(magicList);
            pw.println(n);
            for (int i : magicList) {
                pw.println(i);
            }
            pw.println(myDelimiter);
        }
        pw.println(endStr);
        pw.close();
        writeOutput();
    }

    private static void writeOutput() throws IOException {
        File file = new File(System.getProperty("user.dir"));
        BufferedReader br = new BufferedReader(new FileReader(file.toString() + "/Arrays/Array_Product/test_cases/generated_small_test_cases_input.txt"));
        PrintWriter pw = new PrintWriter(new File(file.toString() + "/Arrays/Array_Product/test_cases/generated_small_test_cases_expected_output.txt"));
        int totalTestCases=Integer.parseInt(br.readLine());
        br.readLine();
        for (int testCase=0 ; testCase<totalTestCases ; testCase++){
            int numberOfArrayElements = Integer.parseInt(br.readLine().trim());
            int[] inputArray = new int[numberOfArrayElements];
            for (int currentIndex = 0; currentIndex < numberOfArrayElements; currentIndex++) {
                inputArray[currentIndex] = Integer.parseInt(br.readLine().trim());
            }

            int[] productArray = optimal_solution.arrayProduct(inputArray);

            for (int currentIndex = 0; currentIndex < productArray.length; currentIndex++) {
                pw.println(productArray[currentIndex]);
            }
            pw.println(myDelimiter);
            br.readLine();
        }
        pw.println(endStr);
        pw.close();
    }

    public static List<Integer> getMagicList() {
        int magic = 1 + random.nextInt(Integer.MAX_VALUE - 1);

        List<Integer> magicList = new ArrayList<>();
        magicList.add(1);
        while (magic % 2 == 0) {
            magic /= 2;
            magicList.add(2);
        }
        for (int i = 3; i <= Math.sqrt(magic); i += 2) {
            while (magic % i == 0) {
                magic /= i;
                magicList.add(i);
            }
        }
        if (magic != 1)
            magicList.add(magic);
        return magicList;
    }


}
