#include <iostream>
#include <string>
using namespace std;

void changeStr(const string* str)
{
	string* tmp = const_cast<string*>(str);
	(*tmp)[0] = 'i';
}
void changeInt(const int* value)
{
	int* tmp = const_cast<int*>(value);
	*tmp = 123;
	cout << "Test from func() : " << *value << " address : " << value << endl;
}
class Demo
{
public:
	Demo(int value = 0) : value(value)
	{}
	int getValue() const // 1. this      [const]  Demo * const this  = 0x123456    2. counter
	{
		//++const_cast<int&>(counter);// 2 way
		const_cast<Demo*>(this)->counter++;
		(const_cast<Demo*>(this))->value *= 2;
		return value;
	}
	int getCounter() const
	{
		return counter;
	}
private:
	int value;
	int counter = 0;


};
class Person {
public:
	Person(const string& name = "Vasiliy") { this->name = name; }
	void print()const;
private:
	string name;
};
void Person::print() const
{
	//const char* tmp = const_cast<const char*>(name);
	
	cout << name << endl;
}
// Person   name
int main()
{
	Person kaban("kaban");
	kaban.print();
	cout << "Next" << endl;
	const char Line[30] = "Hello";
	const_cast<char*>(Line)[0] = 'd';
	//string* tmp = const_cast<string*>(str);
	cout << Line << endl;
	return 0;
}