/*

geraldm
11.9.14

*/

#ifdef _DEBUG // Active only in Debug Configuration
#define _CRTDBG_MAP_ALLOC // Visual Studio Mem Leak detector activated
#define _CRT_SECURE_NO_DEPRECATE
#include <crtdbg.h> // runtime debug functions are declared here
#include <iostream>
using namespace std;

#endif

class String {
private:
    //char c_string [11]; ..........static member
    char *c_string;   //............dynamic member
public:
    String();
    String (const char *theCString);
    void list();
    String(const String &str);
    ~String();
    
};

String::String (const char *theCString){
    c_string = new char [strlen(theCString)+1];
    strcpy(c_string, theCString);
};

void String::list(){
    cout << c_string << endl;
};

String::String(const String &str){
    c_string = new char [strlen(str.c_string)+1];
    strcpy(c_string, str.c_string);
};

String::~String(){
    //delete c_string;
   //cout << ("destruction done!!!!!") << endl;
};



void f(int i) {
	String s("abcdefghijklmnopqrstuvwxyz");
	if (i % 100 == 0)
		s.list();
}
int main() {
	int i = 0;
	_CrtMemState memory; // C/C++ runtime memory management state storage
	while (i < 1000) {
		f(i++);
		// dump memory management state
		_CrtMemCheckpoint(&memory); _CrtMemDumpStatistics(&memory);
	}
	_CrtDumpMemoryLeaks(); // check if there were memory leaks
	return 0;
}