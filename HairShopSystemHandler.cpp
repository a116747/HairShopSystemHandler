
#include "pch.h"
#include <iostream>
#include "HairShopSystemHandler.h"
#include "CommonThings.h"
#include "NormalMembership.h"
#include "VIPMembership.h"
#include "VVIPMembership.h"
#include "String.h"
using namespace std;
//Membership * memArr[100];
//int dsnNum;
//int memNum;
//Designer *dsnArr[100];
HairShopSystemHandler::HairShopSystemHandler()
	:memNum(0),dsnNum(0) { }
HairShopSystemHandler::~HairShopSystemHandler() {
	for (int i = 0; i < memNum; i++)
		delete memArr[i];
}
void HairShopSystemHandler::ShowMenu(void) const {
	cout << "----------Menu-----------" << endl;

	cout << "1. Membership" << endl;
	cout << "2. Designer" << endl;
	cout << "3. Exit" << endl;

}
void HairShopSystemHandler::ShowMemMenu(void) const {

	cout << "---------Member----------" << endl;
	cout << "1. Register Membership" << endl;
	cout << "2. Deposit" << endl;
	cout << "3. Do Hair" << endl;
	cout << "4. Show All Members' Info" << endl;
	cout << "5. Show History " << endl;
}
void HairShopSystemHandler::ShowDsnMenu(void) const {
	cout << "--------Designer---------" << endl;
	cout << "1. Register Designer" << endl;
	cout << "2. Show All Designers' Info" << endl;
	cout << "3. Show Career" << endl;
	cout << "4. Show PayCheck" << endl;
}
void HairShopSystemHandler::Register(void) {
	
	int mem_sel; 
	cout << "[Membership Type]" << endl;
	cout << "1. Normal" << endl;
	cout << "2. VIP" << endl;
	cout<< "3. VVIP" << endl;
	cout << ">>"; cin >> mem_sel;
	if (mem_sel == NORMAL) {
		RegisterNormalMembership();
	}
	else if ((mem_sel == VIP)) {
		RegisterVIPMembership();
	}
	else if ((mem_sel == VVIP)) {
		RegisterVVIPMembership();
	}
}

void HairShopSystemHandler::RegisterNormalMembership() {
	int id;
	int money;
	int YorN;
	int dsn_sel;
	String name;
	cout << "[Register Membership]" << endl;
	cout << "Membership ID: ";	cin >> id;
	cout << "Name: ";	cin >> name;
	if (dsnNum == 0)
	{
		cout << "Designer Register First Please" << endl; return;
	}
	cout << "[Choose Designer]" << endl;
	ShowAllDesigner();
	cout << "Designer ID >>"; cin >> dsn_sel;
	//디자이너를 찾아 고객의 아이디를 추가해준다.
	for (int j = 0; j < dsnNum; j++)
	{
		if ((dsnArr[j]->GetDsnID()) == dsn_sel) {
			dsnArr[j]->addCus(id); break;
		}
	}
	cout << "Would you like to Deposit? (Yes:0, No:1)  "; cin >> YorN;
	if (!YorN)
	{
		cout << "How Much would you like to Deposit?  "; cin >> money;
	}
	else money = 0;
	memArr[memNum++] = new NormalMembership(id, money, name, dsn_sel);
}
void HairShopSystemHandler::RegisterVIPMembership() {
	int id;
	int money;
	int dsn_sel;
	String name;
	while (1) {
		cout << "[Register Membership]" << endl;
		cout << "Membership ID: ";	cin >> id;
		cout << "Name: ";	cin >> name;
		if (dsnNum == 0)
		{
			cout << " Register the Designer First Please" << endl; return;
		}
		cout << "[Choose Designer]" << endl;
		ShowAllDesigner();
		cout << "Designer ID >>"; cin >> dsn_sel;
		int find = 0;
		//디자이너를 찾아 고객의 아이디를 추가해준다.
		for (int j = 0; j < dsnNum; j++)
		{
			if ((dsnArr[j]->GetDsnID()) == dsn_sel) {
				dsnArr[j]->addCus(id); find = 1; break;
			}
		}
		if (find == 0) {
			cout << "Designer ID Doesn't Exist  " << endl;
			return;
		}
		
		while (1) { //예치금이 50만원 이상 입력될 수 있도록
			cout << "Deposit(At Least 50): "; cin >> money;
			if (money >= 50)
			{
				memArr[memNum++] = new VipMembership(id, money, name, dsn_sel);
				break;
			}
			else
			{
				cout << "at Least 50" << endl;
				continue;
			}
		}
		return;
	}
}
void HairShopSystemHandler::RegisterVVIPMembership() {
	int id;
	//char name[NAME_LEN];
	int money;
	int dsn_sel;
	String name;
	while (1) {
		cout << "[Register Membership]" << endl;
		cout << "Membership ID: ";	cin >> id;
		cout << "Name: ";	cin >> name;
		if (dsnNum == 0)
		{
			cout << " Register the Designer First Please" << endl; return;
		}
		cout << "[Choose Designer]" << endl;
		ShowAllDesigner();
		cout << "Designer ID >>"; cin >> dsn_sel;
		int find = 0;
		//디자이너를 찾아 고객의 아이디를 추가해준다.
		for (int j = 0; j < dsnNum; j++)
		{
			if ((dsnArr[j]->GetDsnID()) == dsn_sel) {
				dsnArr[j]->addCus(id); find = 1; break;
			}
		}
		if (find == 0) {
			cout << "Designer ID Doesn't Exist  " << endl;
			return;
		}

		while (1) { //예치금이 100만원 이상 입력될 수 있도록
			cout << "Deposit(At Least 100): "; cin >> money;
			if (money >= 100)
			{
				memArr[memNum++] = new VVipMembership(id, money, name, dsn_sel);
				break;
			}
			else
			{
				cout << "at Least 100" << endl;
				continue;
			}
		}
		return;
	}
}
void HairShopSystemHandler::DRegister(void) {
	int d_id=0;
	//char d_name[NAME_LEN];
	String d_name;
	cout << "[Register Designer]" << endl;
	cout << "Designer ID: ";	cin >> d_id;
	cout << "Name: ";	cin >> d_name;
	dsnArr[dsnNum++] = new Designer(d_id, d_name);
}
void HairShopSystemHandler::DepositMoney(void) {
	int money;
	int id;
	cout << "[Deposit Money]" << endl;
	cout << "MemberID: "; cin >> id;
	cout << "How Much would you like to Deposit?"; cin >> money;
	for (int i = 0; i < memNum; i++)
	{
		if (memArr[i]->GetMemID() == id) 
		{
			memArr[i]->Deposit(money);
			cout << "Deposit Completed" << endl << endl;
			return;
		}
	}
	cout << "Invalid ID ..." << endl << endl;
	
}
void HairShopSystemHandler::DepositMoney(int index) {
	int money;
	cout << "[Deposit Money]" << endl;
	cout << "How Much would you like to Deposit?"; cin >> money;
	memArr[index]->Deposit(money);
	cout << "Deposit Completed" << endl << endl;
	return;
		
}
void HairShopSystemHandler::doHair(void) {

	int id;	int type; int cost; int length; int d_id=0;
	int mem_index=0;
	int find = 0;
	while (find != 1) {
		cout << "MemberID: "; cin >> id;
		for (int i = 0; i < memNum; i++)
		{
			if (memArr[i]->GetMemID() == id)
			{
				mem_index=i;
				d_id = memArr[i]->GetDsnID();
				find = 1;
				break;
			}
		}
		//아이디를 못찾았으면
		if (find == 0)
			cout << "Invalid ID ..." << endl << endl;
		//else break;
	}
	while (1) {
		cout << "----------Menu-----------" << endl;
		cout << "1.Cut(2)" << endl;
		cout << "2.Perm(15)" << endl;
		cout << "3.Color(10)" << endl;
		cout << "4.Treatment(5)" << endl;
		cout << "What Kind of Hair Would you like? "; cin >> type;
		cout << "How long is your hair? (Medium=1, Long=2) "; cin >> length;

		if (!(type == CUT || type == PERM || type == COLOR || type == TREATMENT))
		{
			cout << "type: "<< type << endl;
			continue;
		}
		
		if (!(length == MEDIUM_LENGTH || length == LONG))
		{
			cout << "type: " << type << endl;
			continue;
		}
		
		//머리 서비스 종류에 따른 비용
		if (type == CUT)
		{
			cost = 2; break;
		}
		else { //커트를 제외한 나머지, 머리 길이에 따른 추가요금
			if (type == PERM)
				cost = 15;
			else if (type == COLOR)
				cost = 10;
			else if (type == TREATMENT)
				cost = 5;

			//머리 길이에 따른 추가요금
			if (length == MEDIUM_LENGTH)
			{
				cost += (int)(cost * 0.1); //10% 추가요금
				cout << "Additional Carhges 10% Occurred" << endl;
				break;
			}
			else if (length == LONG)
			{
				cost += (int)(cost * 0.2); //20% 추가요금
				cout << "Additional Carhges 20% Occurred" << endl;
				break;
			}
		}
	}

	//멤버십 종류에 따른 할인
	int discount=memArr[mem_index]->getDisRate();
	cout << "Before: " << cost << " " << discount << "% discounted" << endl;
	cout << "discountRate: " << discount << endl;
	cost = cost * (1-discount/100); 
	cout << "After: " << cost << endl;

	//기록하기
	memArr[mem_index]->record_history(type, length);

	int sel = 0;
	// 비용을 지불하게 한다.
	if(memArr[mem_index]->reserved(cost))
		memArr[mem_index]->hairCost(cost);
	else{
		cout << "[Short of Deposit] " << endl;
		cout << "1. Deposit Money " << endl;
		cout << "2. Pay the rest by cash or card" << endl;
		cout << ">>";
		cin >> sel;
		if (sel == 1)
		{
			while (1) {
				DepositMoney(mem_index);
				if (memArr[mem_index]->reserved(cost))
				{
					memArr[mem_index]->hairCost(cost); break;
				}
			else continue;
			}
		}
		else if(sel == 2)
			cout << "Payment Completed" << endl;
		else cout << "error" << endl;
		}
		//memArr[mem_index]->hairCost(cost);
	
	//d_id를 사용해 몇번 배열인지 찾고 경력 올려주기 
	//cout << "dsnNum  " << d_id << endl;
	for (int i = 0; i < dsnNum+1; i++)
	{
		//cout << "dsnArr[i]->GetDsnID()=" << dsnArr[i]->GetDsnID()<<", d_id"<<d_id << endl;
		if ((dsnArr[i]->GetDsnID()) == d_id)
		{
			//cout << "type: " << type << endl;
			dsnArr[i]->Career(type);
			dsnArr[i]->Paycheck(cost);
			break;
		}
	}

}
void HairShopSystemHandler::ShowAllMemInfo(void) const {

	for (int i = 0; i < memNum; i++)
	{
		memArr[i]->ShowMemInfo();
		cout << endl;
	}

}
void HairShopSystemHandler::showHistory() {
	int id;
	int mem_index = 0;
	int find = 0;

	cout << "[History]" << endl;
	while (find != 1) {
		cout << "MemberID: "; cin >> id;
		for (int i = 0; i < memNum; i++)
		{
			if (memArr[i]->GetMemID() == id)
			{
				mem_index = i;
				find = 1;
				break;
			}
		}
		//아이디를 못찾았으면
		if (find == 0)
			cout << "Invalid ID ..." << endl << endl;
	}
	memArr[mem_index]->showAllRecords();
}

void HairShopSystemHandler::ShowAllDesigner(void) const {

	for (int i = 0; i < dsnNum; i++)
	{
		dsnArr[i]->ShowCareerInfo();
	}

}
void HairShopSystemHandler::ShowCareerInfo(void) const {

	for (int i = 0; i < dsnNum; i++)
	{
		dsnArr[i]->ShowCareerInfo();
	}
}
void HairShopSystemHandler::ShowPayCheckInfo(void) const {

	for (int i = 0; i < dsnNum; i++)
	{
		dsnArr[i]->ShowPayCheckInfo();
	}
}