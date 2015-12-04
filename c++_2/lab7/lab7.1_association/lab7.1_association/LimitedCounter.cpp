#include <iostream>
#include "counter.h"

using namespace std;

class LimitedCounter
{
	friend ostream &operator<<(ostream &out, const LimitedCounter &theLimitedCounter);
public:

	LimitedCounter(int low, int up);
	LimitedCounter();
	~LimitedCounter();
	void setLimit(int up);
	int getCount() const;
	void reset();
	LimitedCounter &operator++();
	LimitedCounter operator++(int);
	bool operator<(const Counter &c2) const;

private:
	int upperLimit;
	int lowerLimit;
	Counter count;
};

LimitedCounter::LimitedCounter(){
};

LimitedCounter::LimitedCounter(int lo, int up):count(lo)
{
	lowerLimit = lo;
	upperLimit = up;
}

LimitedCounter::~LimitedCounter()
{
}

void LimitedCounter::setLimit(int up){
	upperLimit = up;

}

int LimitedCounter::getCount() const{
	return count.getCount();
}

void LimitedCounter::reset(){
	count.reset();
}

LimitedCounter& LimitedCounter::operator++(){
	if(count.getCount() == upperLimit){
		return *this;
	}	
	++count;
	return *this;
}

LimitedCounter LimitedCounter::operator++(int){
	if(count.getCount() == upperLimit){
		return *this;
	}
else{
	LimitedCounter buff = *this;
		count++;
		return buff;
	}
}


ostream &operator<<(ostream &out, const LimitedCounter &theLimitedCounter){
	out << theLimitedCounter.getCount() << endl;
	return out;
}

bool operator<(const LimitedCounter &limitc, int n){
	return limitc.getCount() < n;
}

int main() {
	LimitedCounter lc(0, 5); //initial value 0, upper limit 5
	cout << lc++ << endl; //output should be 0
	cout << ++lc << endl; //output should be 2
	lc.reset();
	for (int i = 0; i < 9; i++) {
		lc++;
		cout << lc << endl; //output is 1 2 3 4 5 5 5 5 5
	}
	cout << lc.getCount() << endl; //output is 5
	cout << (lc < 7) << endl;//Testing the comparison operator //output is 1
	cout << (lc < 1) << endl;//Testing the comparison operator //output is 0
	return 0;
}