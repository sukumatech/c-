/*
geraldm
28.8.14
lab 1 diffrences in c and c++

*/

#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
#include <stdio.h>

//using namespace std;

void f();

int main() {

	//variables
	int c = 0;
	float x = 0.0;

	//1.0
	f();
	f(1);			//fuction doesnt take any arguments ????????
	f("abc", 2.0);			//fuction doesnt take any arguments

	//2. standard c
	printf("Enter value of int c: ");
	scanf("%d", &c);
	printf("Enter value of int x: ");
	scanf("%f", &x);

	printf("%d \n", c);
	printf("%f \n", x);

	//3. using i/o stream objects			............ objects not defined
	//cout <<"value of int c: ";
	//cin >> c;
	//cout <<"value of float x: ";
	//cin >> x;

	//cout << c;
	//cout << x;
	return 0;
}

void f(){
	printf  ("hello \n");
}