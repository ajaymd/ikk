/**
 * ***************** PROBLEM DESCRIPTION ************************
 * Given an array of numbers, nums, return an array of numbers products, where products[i]is the product of all nums[j], j != i.

Input : [1, 2, 3, 4, 5]
Output: [(2*3*4*5), (1*3*4*5), (1*2*4*5), (1*2*3*5), (1*2*3*4)]
      = [120, 60, 40, 30, 24]
You must do this in O(N) time, and constant space, without using division. Usage of products array is not considered extra space.

Without using division is the key constraint to remember.
*/

#include<iostream>
#include<vector>

using namespace std;

vector<int> arrayProduct(vector<int>inputArray){
	if(inputArray.size() == 0) return inputArray;
	vector<int>productArray;
	int leftProduct = 1;
	for(int currentIndex = 0; currentIndex < inputArray.size(); currentIndex++){
		productArray.push_back(leftProduct);
		leftProduct *= inputArray[currentIndex];
	}
	int rightProduct = 1;
	for(int currentIndex = inputArray.size()-1; currentIndex >= 0; currentIndex--){
		productArray[currentIndex] *= rightProduct;
		rightProduct *= inputArray[currentIndex];
	}
	return productArray;
}

int main(){
	int numberOfElements;
	cin>>numberOfElements;
	vector<int> inputArray(numberOfElements);
	for(int currentIndex = 0; currentIndex < numberOfElements; currentIndex++){
		cin>>inputArray[currentIndex];
	}
	vector<int>productArray = arrayProduct(inputArray);
	for(int currentIndex = 0; currentIndex < productArray.size(); currentIndex++){
		cout<<productArray[currentIndex]<<" ";
	}
	cout<<endl;
	return 0;
}
/**
 * Time complexity: O(N)
 * Space complexity: O(N)
*/
