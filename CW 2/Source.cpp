#include <iostream>
#include <vector>
#include "Classes.h"
using namespace std;
void callClassMethodsS1(vector<Grandpa* >list) {
	//for (auto& p : list)
	//{
	//	tmpSt = dynamic_cast<Student*>(p);
	//	if (tmpSt != nullptr) // �������, ���� p ������ �� �������� ��� ���������!!!!
	//	{
	//		tmpSt->learn();
	//	}
	//	tmp = dynamic_cast<Aspirant*>(p);
	//	if (tmp != nullptr) // �������, ���� p ������ �� �������� ��� ���������!!!!
	//	{
	//		tmp->writeDyplom();
	//	}
	//	cout << endl;
	//}
	Daddy* tmp1;
	Son* tmp2;
	for (auto& p : list)
	{
		
		if (typeid(*p) == typeid(Grandpa))
		{
			p->Sleep();
		}
		else if (typeid(*p) == typeid(Daddy)) 
		{
		
			tmp1 = static_cast<Daddy*>(p);
			tmp1->Sleep();
			tmp1->walk();
		}
		else if (typeid(*p) == typeid(Son))
		{
			
			tmp2 = static_cast<Son*>(p);
			p->Sleep();
			tmp2->walk();
			tmp2->play();
		}
	}
}
void callClassMethodsS2(vector<Grandpa* >list) {
	//for (auto& p : list)
	//{
	//	tmpSt = dynamic_cast<Student*>(p);
	//	if (tmpSt != nullptr) // �������, ���� p ������ �� �������� ��� ���������!!!!
	//	{
	//		tmpSt->learn();
	//	}
	//	tmp = dynamic_cast<Aspirant*>(p);
	//	if (tmp != nullptr) // �������, ���� p ������ �� �������� ��� ���������!!!!
	//	{
	//		tmp->writeDyplom();
	//	}
	//	cout << endl;
	//}
	Daddy* tmpSt;
	Son* tmpSon;
	Grandpa* tmpGf;
	for (auto& p : list)
	{
		tmpGf = dynamic_cast<Grandpa*>(p);
		tmpSt = dynamic_cast<Daddy*>(p);
		tmpGf->Sleep();
		if (tmpSt!=nullptr)
		{
			tmpSt->walk();
		}
		tmpSon = dynamic_cast<Son*>(p);
		if (tmpSon != nullptr) 
		{
			tmpSon->play();
		}
	}
}
int main() {
	Grandpa grandfather("Igor");
	Daddy daddy("Witalii");
	Son son("Oleg");
	grandfather.Sleep();
	daddy.Sleep();
	son.play();
	cout << "-----Next----" << endl;
	vector<Grandpa* >list{new Grandpa("Igor"),new Daddy("Witalii"),new Son("Oleg")};
	//callClassMethodsS1(list);
	callClassMethodsS2(list);
	return 0;
}