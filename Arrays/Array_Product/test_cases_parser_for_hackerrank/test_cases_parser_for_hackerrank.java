package Array_Product.test_cases_parser_for_hackerrank;

import java.io.*;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;

public class test_cases_parser_for_hackerrank {
    static String basePath;
    static int testCasesInputCount = -1;
    static int testCasesOutputCount = -1;
    static String myDelimiter = "\n\n";

    public static void main(String[] args) throws IOException {
        File file = new File(System.getProperty("user.dir"));
        basePath = file.toString() + "/Arrays/Array_Product";

        writeXTestCasesInputFrom(basePath + "/test_cases/sample_test_cases_input.txt", 2);
        writeXTestCasesOutputFrom(basePath + "/test_cases/sample_test_cases_expected_output.txt", 2);

        writeXTestCasesInputFrom(basePath + "/test_cases/handmade_test_cases_input.txt", 9);
        writeXTestCasesOutputFrom(basePath + "/test_cases/handmade_test_cases_expected_output.txt", 9);

        writeXTestCasesInputFrom(basePath + "/test_cases/generated_small_test_cases_input.txt", 14);
        writeXTestCasesOutputFrom(basePath + "/test_cases/generated_small_test_cases_expected_output.txt", 14);

        writeXTestCasesInputFrom(basePath + "/test_cases/generated_big_test_cases_input.txt", 5);
        writeXTestCasesOutputFrom(basePath + "/test_cases/generated_big_test_cases_expected_output.txt", 5);
    }

    private static void writeXTestCasesOutputFrom(String inputFilePath, int testCaseRequired) throws IOException {
        String fileContent = new String(Files.readAllBytes(Paths.get(inputFilePath)), StandardCharsets.UTF_8);
        String[] singleTestCase = fileContent.split(myDelimiter);
        for (int i = 0; i < testCaseRequired; i++) {
            testCasesOutputCount++;
            File file = new File(basePath + "/parsed_test_cases_for_hackerrank/output" + convertToThreeDigit(testCasesOutputCount) + ".txt");
            System.out.println(file + " creation status:");
            System.out.println(file.createNewFile());
            PrintWriter pw = new PrintWriter(file);
            pw.println(singleTestCase[i]);
            pw.close();
        }
    }

    private static void writeXTestCasesInputFrom(String inputFilePath, int testCaseRequired) throws IOException {
        String fileContent = new String(Files.readAllBytes(Paths.get(inputFilePath)), StandardCharsets.UTF_8);
        String[] singleTestCase = fileContent.split(myDelimiter);
        for (int i = 0; i < testCaseRequired; i++) {
            testCasesInputCount++;
            File file = new File(basePath + "/parsed_test_cases_for_hackerrank/input" + convertToThreeDigit(testCasesInputCount) + ".txt");
            System.out.println(file + " creation status:");
            System.out.println(file.createNewFile());
            PrintWriter pw = new PrintWriter(file);
            pw.println(singleTestCase[i+1]);
            pw.close();
        }
    }

    private static String convertToThreeDigit(int a) {
        String aStr = Integer.toString(a);
        String res = "";
        for (int i = 0; i < 3 - aStr.length(); i++) {
            res += '0';
        }
        res += aStr;
        return res;
    }

}
