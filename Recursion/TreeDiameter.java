/******************************************************************************
 * Write a function that returns the diameter of a tree
 *****************************************************************************/

import java.util.ArrayList;

public class TreeDiameter {
    public static void main(String[] args) {
        test();
    }

    public static class TreeNode {
        int distanceFromFather;
        ArrayList<TreeNode> sons;
    }

    private static class DiameterReturnValue {
        int diameter, distanceToMostDistantLeaf;
    }

    public static int diameter(TreeNode tree) {
        if (tree == null)
            return -1;

        return diameterRecursion(tree).diameter;
    }

    private static DiameterReturnValue diameterRecursion(TreeNode tree) {
        DiameterReturnValue returnValue = new DiameterReturnValue();
        if (tree.sons == null) {
            returnValue.distanceToMostDistantLeaf = tree.distanceFromFather;
            returnValue.diameter = 0;
            return returnValue;
        }

        returnValue.diameter = -1;
        int total_max_distance, total_2nd_max_distance;
        total_max_distance = total_2nd_max_distance = 0;
        for (TreeNode son : tree.sons) {
            DiameterReturnValue r = diameterRecursion(son);
            returnValue.diameter = Math.max(returnValue.diameter, r.diameter);
            if (r.distanceToMostDistantLeaf > total_max_distance) {
                total_2nd_max_distance = total_max_distance;
                total_max_distance = r.distanceToMostDistantLeaf;
            } else if (r.distanceToMostDistantLeaf > total_2nd_max_distance) {
                total_2nd_max_distance = r.distanceToMostDistantLeaf;
            }

        }
        returnValue.distanceToMostDistantLeaf = total_max_distance + tree.distanceFromFather;
        returnValue.diameter = Math.max(returnValue.diameter, total_max_distance + total_2nd_max_distance);

        return returnValue;
    }

    private static class TestCase {
        public TestCase(String t, int d) {
            tree = t;
            diameter = d;
        }

        String tree;
        int diameter;
    }

    private static int index;
    private static TreeNode buildTree(String s) {
        index = 0;
        return buildTree(s.toCharArray());
    }

    private static int readNumber(char[] s) {
        int d = 0;
        while(Character.isDigit(s[index])) {
            d *= 10;
            d += s[index++] - '0';
        }
        return d;
    }

    private static TreeNode buildTree(char[] s) {
        index++; // '{'
        TreeNode node = new TreeNode();

        node.distanceFromFather = readNumber(s);
        index++; // ','
        int number_of_sons = readNumber(s);
        index++; // ',' or '}'
        if (number_of_sons == 0)
            return node;
        node.sons = new ArrayList<TreeNode>();
        while (number_of_sons-- > 0) {
            node.sons.add(buildTree(s));
            index++;
        }
        return node;
    }

    private static TestCase tests[] = {
            // One node - no diameter
            new TestCase("{0,0}", 0),
            // One leaf
            new TestCase("{0,1,{5,0}}", 5),
            // Still one leaf
            new TestCase("{0,1,{5,1,{4,1,{7,0}}}}", 16),
            // The diameter of the first son is the diameter of the tree
            new TestCase("{0,1,{5,2,{8,0},{7,0}}}", 15),
            // The diameter of the last son is the diameter of the tree
            new TestCase("{0,3,{1,2,{5,0},{7,0}},{1,2,{6,0},{5,0}},{1,2,{10,0},{9,0}}}", 19),
            // Now the diameter is between a leaf in the first son and a leaf in the third son
            new TestCase("{0,3,{5,2,{8,0},{7,0}},{5,2,{9,0},{8,0}},{5,2,{10,0},{9,0}}}", 29)
    };

    private static void test() {
        int result;
        int errors = 0;
        for (int i = 0; i < tests.length; ++i) {
            System.out.println("-------");
            TreeNode tree = buildTree(tests[i].tree);
            result = diameter(tree);
            if (result != tests[i].diameter) {
                System.out.println(
                        "Error: diameter of test case number " + i + " is " + tests[i].diameter + ". Got " + result + " instead");
                errors++;
            }
        }

        if (errors > 0)
            System.out.println("Got " + errors + " errors");
        else
            System.out.println("Good work");
    }
}
