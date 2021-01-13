#pragma once
#include <iostream>

using namespace std;
class Grandpa {
protected:
	string name;
public:
	Grandpa(const string& name = "Boris");
	virtual void Sleep()const;
};
inline Grandpa::Grandpa(const string& name)
{
	if (!name.empty())
	{
		this->name = name;
	}
}

inline void Grandpa::Sleep() const
{
	cout << typeid(*this).name()+6 << "Is sleeping" << endl;
}
class Daddy : public Grandpa{
public:
	Daddy(const string&name="Father");
	virtual void walk()const;
private:

};

inline Daddy::Daddy(const string& name)
	:Grandpa(name)
{
}

inline void Daddy::walk() const
{
	cout << typeid(*this).name() + 6 << "Is walking" << endl;
}
class Son : public Daddy {
public:
	Son(const string& name = "Son");
	virtual void walk()const;
	void play()const;
private:

};

inline Son::Son(const string& name)
	:Daddy(name)
{
}

inline void Son::walk() const
{
	cout << typeid(*this).name() + 6 << "Is walking" << endl;
}

inline void Son::play() const
{
	cout << "Son is playing" << endl;
}
