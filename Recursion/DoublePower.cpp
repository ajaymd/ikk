#include<iostream>
using namespace std;

double pow(double baseValue, int exponentValue){
	if(exponentValue < 0){
		exponentValue *= -1; // make exponent positive
		baseValue = 1.0 / baseValue; // take the inverse value of base
	}
	double resultValue=1.0;
	while(exponentValue > 0){
		if(exponentValue % 2 ==1) resultValue *= baseValue; // when exponent is odd number
		baseValue *= baseValue;
		exponentValue /= 2;
	}
	return resultValue;
}

int main(){
	double baseValue;
	int exponentValue;
	cin>>baseValue>>exponentValue;	
	double resultValue = pow(baseValue, exponentValue);
	cout<<resultValue<<endl;
	return 0;
}

