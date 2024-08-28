#include <iostream>
using namespace std;
void program();
int main(){
	cout << "Welcome to Simple Calculator\n";
	cout << "Basic Arithmetic operations\n";
	program();
	return 0;
}
void program(){
	float a,b;
	char operation;
	float result;
	char again;
	
	cout << "Enter any 2 numbers: ";
	cin >> a;cin >> b;
	cout << "Enter an operation to perform : ";
	cin >> operation;
	if(operation == '+'){
		result = a + b;
		cout << "Addition of " << a << " and " << b << " is : " << result;
	}else if(operation == '-'){
		result = a - b;
		cout << "Subtraction of " << a << " and " << b << " is : " << result;
	}
	else if(operation == '*'){
		result = a * b;
		cout << "Multiplication of " << a << " and " << b << " is : " << result;
	}else if(operation == '/'){
		result = a / b;
		cout << "Division of " << a << " and " << b << " is : " << result;
	}else{
		cout << "The operation is invalid\n";
	}
	cout << "\nDo you want to calculate again? [y/n] : ";
	cin >> again;
	if(again == 'y' || again == 'Y'){
		program();
	}else{
		exit;
	}
}
