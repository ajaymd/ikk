/**
 * **************** PROBLEM DESCRIPTION ******************
 * Convert a string to an integer.

atoi() first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, it takes an optional plus or minus sign, followed by as many numerical digits as possible and interprets them as numerical value.

The string can contain additional characters after those that form the integral numbers, which are ignored and have no effect on the behavior of this function.
If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty, or it contains only whitespace characters, then no conversion is performed.

If no valid conversion is performed, a zero value is returned.

e.g.
"-3924x8fc" = -3924
"c++" = 0
"++1" = 0


Solution:  Aim for a linear order solution with constant space.

Estimated time given in a real interview: 15 minutes
*/

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
/**
 * Time complexity: O(N)
 * Space complexity: O(1)
 */
