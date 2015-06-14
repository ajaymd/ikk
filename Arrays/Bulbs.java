public class Bulbs {

    public static void main(String[] args) {
        int n = 9;
        BulbsArray b = new BulbsArray(n);
        b.switchState(3, 6);
        System.out.println(b.isOn(0));
        System.out.println(b.isOn(1));
        System.out.println(b.isOn(2));
        System.out.println(b.isOn(3));
        System.out.println(b.isOn(4));
        System.out.println(b.isOn(5));
        System.out.println(b.isOn(6));
        System.out.println(b.isOn(7));
        System.out.println(b.isOn(8));
        System.out.println("--------------");
        b.switchState(0, 7);
        System.out.println(b.isOn(0));
        System.out.println(b.isOn(1));
        System.out.println(b.isOn(2));
        System.out.println(b.isOn(3));
        System.out.println(b.isOn(4));
        System.out.println(b.isOn(5));
        System.out.println(b.isOn(6));
        System.out.println(b.isOn(7));
        System.out.println(b.isOn(8));
    }

    private static class BulbsArray {
        int size;
        Switch tree;

        public BulbsArray(int n) {
            size = n;
            tree = buildTree(0, n - 1);
        }

        public boolean isOn(int bulb) {
            return tree.isOn(bulb);
        }

        public void switchState(int start, int end) {
            if (end + 1 >= size)
                return;
            tree.switchState(start, end);
        }

        private Switch buildTree(int start, int end) {
            if (start == end)
                return new Switch(start, end, start, null, null);

            int size = end - start + 1;
            int d = findSmallerPower(size);
            if (size == d)
                return buildFullTree(start, end);
            return new Switch(start, end, start + d - 1, buildFullTree(start, start + d - 1), buildTree(start + d, end));

        }

        private Switch buildFullTree(int start, int end) {
            if (start == end)
                return new Switch(start, end, start, null, null);
            int d = start + (end - start) / 2;
            return new Switch(start, end, d, buildFullTree(start, d), buildFullTree(d + 1, end));
        }

        private int findSmallerPower(int i) {
            int p = 1;
            while (i != 1) {
                i /= 2;
                p *= 2;
            }
            return p;
        }

        private class Switch {
            public Switch(int s, int e, int d, Switch l, Switch r) {
                start = s;
                end = e;
                divider = d;
                left = l;
                right = r;
            }

            public boolean isOn(int b) {
                if (left == null && right == null)
                    return state;
                assert left != null;
                return state ^ (b <= divider ? left.isOn(b) : right.isOn(b));
            }

            public void switchState(int s, int e) {
                if (start == s && end == e)
                    state = !state;
                else if (e <= divider) {
                    left.switchState(s, e);
                } else if (s > divider) {
                    right.switchState(s, e);
                } else {
                    left.switchStateLeft(s);
                    right.switchStateRight(e);
                }
            }

            private void switchStateLeft(int s) {
                if (start == s) {
                    state = !state;
                } else if (s > divider) {
                    right.switchStateLeft(s);
                } else {
                    right.state = !right.state;
                    left.switchStateLeft(s);
                }
            }

            private void switchStateRight(int e) {
                if (end == e) {
                    state = !state;
                } else if (e <= divider) {
                    left.switchStateRight(e);
                } else {
                    left.state = !right.state;
                    right.switchStateRight(e);
                }
            }

            private Switch left, right;
            private boolean state;
            private int start, end, divider;
        }
    }
}
