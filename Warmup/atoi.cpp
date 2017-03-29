#include<iostream>

using namespace std;


bool isDigit(char candidateCharacter){
	return (candidateCharacter>='0' && candidateCharacter<='9');
}

int atoi(string inputString){
	if(inputString.length() == 0) return 0;
	int leftNonSpaceCharacterPosition = 0;
	int rightNonSpaceCharacterPosition = inputString.length()-1;
	while(leftNonSpaceCharacterPosition <= rightNonSpaceCharacterPosition && inputString[leftNonSpaceCharacterPosition] == ' '){
		leftNonSpaceCharacterPosition++;
	}
	while(rightNonSpaceCharacterPosition >= leftNonSpaceCharacterPosition && inputString[rightNonSpaceCharacterPosition] == ' '){
		rightNonSpaceCharacterPosition--;
	}
	if(leftNonSpaceCharacterPosition > rightNonSpaceCharacterPosition) return 0;
	int startPosition = leftNonSpaceCharacterPosition;
	int endPosition = rightNonSpaceCharacterPosition;
	bool isNegative = false;
	if(inputString[startPosition] == '+'){
		startPosition++;
	}
	else if(inputString[startPosition] == '-'){
		isNegative = true;
		startPosition++;
	}
	int resultedNumberSoFar = 0;
	for(int currentIndex = startPosition; currentIndex <= endPosition; currentIndex++){
		if(isDigit(inputString[currentIndex])){
			resultedNumberSoFar = resultedNumberSoFar * 10 + (inputString[currentIndex] - '0');
		}
		else
			break;
	}
	if( isNegative ){
		resultedNumberSoFar *= -1;
	}
	return resultedNumberSoFar;
}

int main(){
	string inputString;
	getline(cin,inputString);
	cout<<atoi(inputString)<<endl;
	return 0;
}
