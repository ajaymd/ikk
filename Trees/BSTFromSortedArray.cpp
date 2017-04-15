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

#include<iostream>
#include<queue>

using namespace std;

struct Node{
	int val;
	Node *leftChild;
	Node *rightChild;
	Node(int val){
		this->val = val;
		leftChild = NULL;
		rightChild = NULL;
	}
};

void printTreeInLevelOrder(Node *rootNode){
	if(rootNode == NULL) return;
	queue<Node*> nodesToBePrinted;
	nodesToBePrinted.push(rootNode);
	while(!nodesToBePrinted.empty()){
		int sizeOfCurrentLevel = nodesToBePrinted.size();
		while(sizeOfCurrentLevel > 0){
			Node *currentNodeToPrint = nodesToBePrinted.front();
			nodesToBePrinted.pop();
			cout<<currentNodeToPrint->val<<" ";
			if(currentNodeToPrint->leftChild != NULL)
				nodesToBePrinted.push(currentNodeToPrint->leftChild);
			if(currentNodeToPrint->rightChild != NULL)
				nodesToBePrinted.push(currentNodeToPrint->rightChild);
			sizeOfCurrentLevel--;
		}
		cout<<endl;
	}
}
Node* createBSTFromSortedArray(vector<int> &sortedArray, int leftIndex, int rightIndex){
	if(leftIndex > rightIndex)
		return NULL;
	int middleIndex = (leftIndex + rightIndex)/2;
	Node *currentRoot = new Node(sortedArray[middleIndex]);
	currentRoot->leftChild = createBSTFromSortedArray(sortedArray, leftIndex, middleIndex-1);
	currentRoot->rightChild = createBSTFromSortedArray(sortedArray, middleIndex+1, rightIndex);
	return currentRoot;
}

void createBSTFromSortedArray(vector<int>inputSortedArray){
	int lengthOfInputArray = inputSortedArray.size();
	if(lengthOfInputArray == 0) return;
	Node *rootNodeOfBalancedBST = createBSTFromSortedArray(inputSortedArray, 0, lengthOfInputArray-1);
	printTreeInLevelOrder(rootNodeOfBalancedBST);
}

int main(){
	int n; cin>>n;
	vector<int>v(n);
	for(int i=0;i<n;i++) cin>>v[i];
	createBSTFromSortedArray(v);
	return 0;
}
/**
 * Time complexity: O(N log N)
 * Space complexity: 3*N*size_of_the(Node)
 */
