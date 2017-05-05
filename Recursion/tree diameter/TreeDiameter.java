/******************************************************************************
 * Write a function that returns the diameter of a tree
 *****************************************************************************/

import java.util.ArrayList;

public class TreeDiameter {
    public static void main(String[] args) {
        test();
    }

    public static class TreeNode {
        int distanceFromParent;
        ArrayList<TreeNode> children;
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
        if (tree.children == null) {
            returnValue.distanceToMostDistantLeaf = tree.distanceFromParent;
            returnValue.diameter = 0;
            return returnValue;
        }

        returnValue.diameter = -1;
        int distanceToMostDistantLeaf, distanceTo2ndMostDistantLeaf;
        distanceToMostDistantLeaf = distanceTo2ndMostDistantLeaf = 0;
        for (TreeNode child : tree.children) {
            DiameterReturnValue r = diameterRecursion(child);
            returnValue.diameter = Math.max(returnValue.diameter, r.diameter);
            if (r.distanceToMostDistantLeaf > distanceToMostDistantLeaf) {
                distanceTo2ndMostDistantLeaf = distanceToMostDistantLeaf;
                distanceToMostDistantLeaf = r.distanceToMostDistantLeaf;
            } else if (r.distanceToMostDistantLeaf > distanceTo2ndMostDistantLeaf) {
                distanceTo2ndMostDistantLeaf = r.distanceToMostDistantLeaf;
            }

        }
        returnValue.distanceToMostDistantLeaf = distanceToMostDistantLeaf + tree.distanceFromParent;
        returnValue.diameter = Math.max(returnValue.diameter, distanceToMostDistantLeaf + distanceTo2ndMostDistantLeaf);

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

        node.distanceFromParent = readNumber(s);
        index++; // ','
        int numberOfChildren = readNumber(s);
        index++; // ',' or '}'
        if (numberOfChildren == 0)
            return node;
        node.children = new ArrayList<TreeNode>();
        while (numberOfChildren-- > 0) {
            node.children.add(buildTree(s));
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
            // The diameter of the first child is the diameter of the tree
            new TestCase("{0,1,{5,2,{8,0},{7,0}}}", 15),
            // The diameter of the last child is the diameter of the tree
            new TestCase("{0,3,{1,2,{5,0},{7,0}},{1,2,{6,0},{5,0}},{1,2,{10,0},{9,0}}}", 19),
            // Now the diameter is between a leaf in the first child and a leaf in the third child
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
