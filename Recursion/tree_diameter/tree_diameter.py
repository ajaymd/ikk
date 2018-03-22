from collections import namedtuple


class TreeNode:
    def __init__(self, height=0, children=None):
        self.children = children if children else []
        self.height = height

def compute_diameter(T):
    HeightAndDiameter = namedtuple('HeightAndDiameter', ('height', 'diameter'))

    def compute_height_and_diameter(node):
        diameter = float('-inf')
        heights = [0, 0]  # Stores the max two heights.

        for child in node.children:
            height_diameter = compute_height_and_diameter(child)
            max_height_with_this_child = height_diameter.height + child.height
            if max_height_with_this_child > heights[0]:
                heights[0], heights[1] = max_height_with_this_child, heights[0]
            elif max_height_with_this_child > heights[1]:
                heights[1] = max_height_with_this_child

            diameter = max(diameter, height_diameter.diameter)

        return HeightAndDiameter(heights[0], max(diameter, heights[0] + heights[1]))

    return compute_height_and_diameter(T).diameter if T else 0


n1 = TreeNode()
n2 = TreeNode(5)
n1.children = [n2]
print compute_diameter(n1)

n1 = TreeNode()
n2 = TreeNode(5)
n3 = TreeNode(4)
n4 = TreeNode(7)
n1.children = [n2]
n2.children = [n3]
n3.children = [n4]
print compute_diameter(n1)

n1 = TreeNode()
n2 = TreeNode(5)
n3 = TreeNode(8)
n4 = TreeNode(7)
n1.children = [n2]
n2.children = [n3, n4]
print compute_diameter(n1)

n1 = TreeNode()
n2 = TreeNode(1)
n3 = TreeNode(1)
n4 = TreeNode(1)
n5 = TreeNode(5)
n6 = TreeNode(7)
n7 = TreeNode(6)
n8 = TreeNode(5)
n9 = TreeNode(10)
n10 = TreeNode(9)
n1.children = [n2, n3, n4]
n2.children = [n5, n6]
n3.children = [n7, n8]
n4.children = [n9, n10]
print compute_diameter(n1)


n1 = TreeNode()
n2 = TreeNode(5)
n3 = TreeNode(5)
n4 = TreeNode(5)
n5 = TreeNode(8)
n6 = TreeNode(7)
n7 = TreeNode(9)
n8 = TreeNode(8)
n9 = TreeNode(10)
n10 = TreeNode(9)
n1.children = [n2, n3, n4]
n2.children = [n5, n6]
n3.children = [n7, n8]
n4.children = [n9, n10]
print compute_diameter(n1)