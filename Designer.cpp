
#include "pch.h"
#include <iostream>
#include "Designer.h"
#include "Membership.h"
#include "CommonThings.h"
#include "String.h"

/* int d_id;
	char *d_name;
	int memID[100];
	int memNum;
	int cut, perm, color, treatment;
*/
using namespace std;

Designer::Designer(int id, String name)
	:d_id(id),memNum(0), cut(0), perm(0), color(0), treatment(0),paycheck(0)
{
	d_name = name;
}

void Designer::Career(int hair){
	//cout << "hair type: " << hair << endl;
	switch (hair) {
	case CUT:cut++; break;
	case PERM:perm++; break;
	case COLOR:color++; break;
	case TREATMENT:treatment++; break;
	default: break;
	}
}
void Designer::Paycheck(int cost) {
	//고객이 지불한 비용의 60%를 급여로 받는다.
	paycheck = paycheck+cost*0.6;
 }

void Designer::ShowCareerInfo() const{
	cout << "-------------------" << endl;
	cout << ">ID: " << d_id << endl;
	cout << ">Name: " << d_name << endl;
	cout << "<Career>" << endl;
	cout << "-Cut: " << cut<< endl;
	cout << "-Perm: " <<perm << endl;
	cout << "-Color: " << color << endl;
	cout << "-Treatment: " << treatment << endl;
	cout << "-Total: " << cut+ perm+ color+treatment << endl;

}

void Designer::ShowPayCheckInfo() const {
	cout << "-------------------" << endl;
	cout << ">ID: " << d_id << endl;
	cout << ">Name: " << d_name << endl;
	cout << ">Paycheck: " << paycheck << endl;
}

void Designer::ShowDesigner()const {
	cout << "---------------" << endl;
	cout << ">ID: " << d_id << endl;
	cout << ">Name: " << d_name << endl;
	cout << ">Number of Cus: " << memNum<<endl;
	cout << "<Career>" << endl;
	cout << "-Cut: " <<cut<< endl;
	cout << "-Perm: " << perm << endl;
	cout << "-Color: " << color << endl;
	cout << "-Treatment: " << treatment << endl;
	cout << ">Paycheck: " << paycheck << endl;

}
//고객의 아이디를 저장해둠
void Designer::addCus(int id) {
	memID[memNum++] = id;
}
int Designer::GetDsnID() const { return d_id; }
Designer::Designer(const Designer &ref){
	d_id = ref.d_id;
	memNum = ref.memNum;
	d_name= ref.d_name;

}

