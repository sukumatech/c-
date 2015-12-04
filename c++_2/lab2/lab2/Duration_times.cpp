
#include <iostream>
#include <string>
using namespace std;


class Time
{
public:
	void read(string input);
	Time subtract(Time myTime);
	void display();
	bool lessThan(Time myTime);

private:
int hours;
int minutes;

};

void Time::read(string input)
{
	cout << input;
	cout << "Time in hours: ";
	cin >> hours;
	cout << "Time in minutes: ";
	cin >> minutes;
}

Time Time::subtract(Time myTime){

	Time temp;
	int t1min, t2min, diffMin;

	t1min = hours * 60 + minutes;
	t2min = myTime.hours *60 + myTime.minutes;
	diffMin = t1min - t2min;

	temp.hours = diffMin /60;
	temp.minutes= diffMin%60;
	
	return temp;
}

void Time::display(){
	cout <<  hours << ":" << minutes << endl;
}

bool Time::lessThan(Time myTime){

	Time temp;
	int t1min, t2min, diffMin;

	t1min = hours * 60 + minutes;
	t2min = myTime.hours *60 + myTime.minutes;

	if (t1min > t2min)
	{
		return 0;
	}
	return -1;
}




int main() {
	Time time1, time2, duration;
	time1.read("Enter time 1: ");
	time2.read("Enter time 2: ");
	if (time1.lessThan(time2)) {
		duration = time2.subtract(time1);
		cout << "Starting time was ";
		time1.display();
	} else {
		duration = time1.subtract(time2);
		cout << "Starting time was " ;
		time2.display();
	}
	cout << "Duration was " ;
	duration.display();
	return 0;
}