#include <iostream>

using namespace std;


//..........................dice class ..........................................
class Dice
{
public:
	void initialize();
	Dice roll();
private:

};


//........................... counter class........................................ fully implemented
class Counter
{
public:
	void reset();	
	int  getCount();
	void increment();

private:

	int count;
};

int Counter::getCount(){

	return count;
}

void Counter::increment() {
	if ( count < 101)
		count++;
	else {
		reset();
		cout << "there was overflow of count" << endl;
	}
}

void Counter::reset() {
count = 0;
}

//.............................class inspector..............................
class Inspector
{
public:
	void setLimits(float a, float b);	
	bool isInLimits(Dice myDice);

private:
float upperLimit, lowerLimit;
};

void Inspector::setLimits(float a, float b){
	upperLimit = b;
	lowerLimit = a;
}



// main..............................................................implemented


int main() {
	Dice dice;
	Counter counter1, counter2, i;
	Inspector inspector;
	dice.initialize();
	counter1.reset(); counter2.reset(), i.reset();
	inspector.setLimits(0.0, 0.5);
	while (i.getCount() < 100) {
		if (inspector.isInLimits(dice.roll()))
			counter1.increment();
		else
			counter2.increment();
		i.increment();
	}
	cout << counter1.getCount() << endl;
	cout << counter2.getCount() << endl;
	return 0;
}