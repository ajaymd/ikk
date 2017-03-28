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

