#include <iostream>
#include "counter.h"

using namespace std;

class LimitedCounter:public Counter
{
	//friend ostream &operator<<(ostream &out, const LimitedCounter &c);
public:
	LimitedCounter(int low, int up);
	~LimitedCounter();
	void setLimit(int setUpperLimit);
	Counter operator++();
	Counter operator++(int);

private:
	 int upperLimit;
};

LimitedCounter::LimitedCounter(int low, int up):Counter(low){

	upperLimit = up;
	if (Counter::getCount() >= upperLimit  )
	{
		cout << upperLimit;
	}
};

void LimitedCounter::setLimit(int setUpperLimit){
	upperLimit = setUpperLimit;
};

Counter LimitedCounter::operator++(){
	if(Counter::getCount() < upperLimit){
		Counter::operator++();
		return *this;
	}	
	return upperLimit;
};

Counter LimitedCounter::operator++(int){
	if(Counter::getCount() < upperLimit){
		Counter::operator++(1);
		return *this;
	}
	else{
		return upperLimit;
	}
};


LimitedCounter::~LimitedCounter(){
}


//_______________________________________________________________ Round up counter



class RoundupCounter:public Counter
{
	//friend ostream &operator<<(ostream &out, const LimitedCounter &c);
public:
	RoundupCounter(int low, int up);
	~RoundupCounter();
	void setLimit(int setUpperLimit);
	Counter operator++();
	Counter operator++(int);

private:
	 int upperLimit;
};

RoundupCounter::RoundupCounter(int low, int up):Counter(low){

	upperLimit = up;
	if (Counter::getCount() >= upperLimit  )
	{
		cout << upperLimit;
	}
};

void RoundupCounter::setLimit(int setUpperLimit){
	upperLimit = setUpperLimit;
};

Counter RoundupCounter::operator++(){
	if(Counter::getCount() < upperLimit){
		Counter::operator++();
		return *this;
	}	
	return upperLimit;
};

Counter RoundupCounter::operator++(int){
	if(Counter::getCount() < upperLimit){
		Counter::operator++(1);
		return *this;
	}
	else{
		return upperLimit;
	}
};


RoundupCounter::~RoundupCounter(){
};

/*int main() {
	LimitedCounter lc(0, 5); //initial value 0, upper limit 5
	cout << lc++ << endl; //output should be 0
	cout << ++lc << endl; //output should be 2
	lc.reset();
	for (int i = 0; i < 9; i++) {
		lc++;
		cout << lc << endl; //output is 1 2 3 4 5 5 5 5 5
	}
	cout << lc.getCount() << endl; //output is 5
	cout << (lc < 7) << endl;;//Testing the comparison operator //output is 1
	cout << (lc < 1) << endl;//Testing the comparison operator //output is 0
	return 0;
}*/

void UseCounter(Counter *counter, int lmt) {

	if (counter = LimitedCounter)
	{
		counter->getCount;
		
	}else if (counter == RoundupCounter)
	{
		counter ->getCount;
	}
	
	
};


int main() {
	LimitedCounter counterA(0, 5);
	RoundupCounter counterB(0, 5);


	UseCounter(&counterA, 8);
	cout << "Counter A: " << counterA << endl; // output should be 5

	UseCounter(&counterB, 8);
	cout << "Counter B: " << counterB << endl; // output should be 2
	return 0;
}
