/*
geraldm
28.8.14
lab 1 diffrences in c and c++

*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>  
using namespace std;

//prototype
void f();

void initialize_xy(float *x, float *y, float xValue = 0.0, float yValue = 0.0){
	*x = xValue;
	*y = yValue;

	cout << "value of x: ..."<< *x <<endl;
	cout << "value of y: ..."<<*y <<endl;
}

void initialize_xy(float *x, float *y, float &xValue, float &yValue ){
	*x = xValue;
	*y = yValue;

	cout << "value of x: ..."<< *x <<endl;
	cout << "value of y: ..."<<*y <<endl;

}


int main() {

	//variables
	int c = 0;
	float x = 0.0;
	float a = 1.1;
	float b = 2.2;
	int arraySize = 0;

	//1
	f();
	//f(1);			fuction doesnt take any arguments
	//f("abc", 2.0);			fuction doesnt take any arguments

	//2. standard c
	printf("Enter value of int c: ");
	scanf("%d", &c);
	printf("Enter value of int x: ");
	scanf("%f", &x);

	printf("%d \n", c);
	printf("%f \n", x);

	//3. using i/o stream objects
	cout <<"value of int c: ";
	cin >> c;
	cout <<"value of float x: ";
	cin >> x;

	cout << c << endl;
	cout << x << endl;
	cout << "......................." << endl;
	//4.0
	initialize_xy(&a, &b, 1.0, 2.0);
	initialize_xy(&a, &b);

	//5.0

	//6.0

	//7.0
	cout << "enter size of array" << endl;
	cin >> arraySize;   //size of the array
	int *d = new int [arraySize];

	for (int i = 0; i < arraySize; i++)
	{
		d[i] = rand() % 100;
		cout << d[i] << ",";
	}

	delete d;


	return 0;
}

void f(){
	cout << "hello" << endl;
}