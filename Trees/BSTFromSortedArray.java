/**
 *
Problem statement: Create and print a balanced BST from a sorted array

* Output tree should be a valid BST and balanced. Balanced tree can have the difference of at most ONE between left and right.
* Input array is sorted!
* Assume distinct integers in the input array.
* Create a standard Tree node structure, without the parent pointer.
* Print the resultant tree, level by level.

For example:

1:
Input: 1,2,3

Output:
2
1 3

2.
Input:
8,10,12,15,16,20,15

Output:
15
10 20
8 12 16 25

*/

import java.io.*;
import java.util.*;

public class BSTFromSortedArray{
	static class Node{
		public int val;
		public Node leftChild;
		public Node rightChild;
		public Node(int val){
			this.val = val;
			leftChild = null;
			rightChild = null;
		}
	}

	static void printTreeInLevelOrder(Node rootNode){
		if(rootNode == null) return;
		Queue<Node> nodesToBePrinted = new LinkedList<>();
		nodesToBePrinted.add(rootNode);
		while(!nodesToBePrinted.isEmpty()){
			int sizeOfCurrentLevel = nodesToBePrinted.size();
			while(sizeOfCurrentLevel > 0){
				Node currentNodeToPrint = nodesToBePrinted.remove(); // remove the head of the queue
				System.out.print(currentNodeToPrint.val+" ");
				if(currentNodeToPrint.leftChild != null)
					nodesToBePrinted.add(currentNodeToPrint.leftChild);
				if(currentNodeToPrint.rightChild != null)
					nodesToBePrinted.add(currentNodeToPrint.rightChild);
				sizeOfCurrentLevel--;
			}
			System.out.println();
		}
	}
	static Node createBSTFromSortedArray(int[] sortedArray, int leftIndex, int rightIndex){
		if(leftIndex > rightIndex)
			return null;
		int middleIndex = (leftIndex + rightIndex)/2;
		Node currentRoot = new Node(sortedArray[middleIndex]);
		currentRoot.leftChild = createBSTFromSortedArray(sortedArray, leftIndex, middleIndex-1);
		currentRoot.rightChild = createBSTFromSortedArray(sortedArray, middleIndex+1, rightIndex);
		return currentRoot;
	}
	static void createBSTFromSortedArray(int[] inputSortedArray){
		int lengthOfInputArray = inputSortedArray.length;
		if(lengthOfInputArray == 0) return;
		Node rootNodeOfBalancedBST = createBSTFromSortedArray(inputSortedArray, 0, lengthOfInputArray-1);
		printTreeInLevelOrder(rootNodeOfBalancedBST);
	}
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
		int lengthOfTheSortedArray = scanner.nextInt();
		int[] inputSortedArray = new int[lengthOfTheSortedArray];
		for(int currentIndex = 0; currentIndex < lengthOfTheSortedArray; currentIndex++){
			inputSortedArray[currentIndex] = scanner.nextInt();
		}
		createBSTFromSortedArray(inputSortedArray);
	}
}

/**
 * Time complexity: O(N log N)
 * Space complexity: 3*N*size_of_the(Node)
 */
