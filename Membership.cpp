
#include "pch.h"
#include <iostream>
#include "Membership.h"
#include <cstring>
#include "CommonThings.h"
#include "String.h"

using namespace std;

	Membership::Membership(int id, int money, String name, int dsn_sel)
	:memID(id),balance(money),d_id(dsn_sel)
	{
		cusName= name;
	}
	
	void Membership::Deposit(int money){
		balance += money;
	}
	/*void Membership::ShowMemInfo() const{
		cout<< "---------------"<<endl;
		cout << "ID: " << memID<<endl;
		cout << "Name: " << cusName<<endl;
		cout << "Membership Type (N=1,V=2,VV=3): " << type << endl;
		cout << "Balance: " << balance<<endl;

	}*/
	bool  Membership::reserved(int cost)  {
		//잔액이 충분하면 비용 지불
		if (balance >= cost)
			return true;
		else return false;
		
	}
	void Membership::hairCost(int cost)
	{
		//예치금에서 비용 차감
		balance -= cost;
		cout << "Cost: " << cost << endl;
		cout << "Balance: " << balance << endl;
		cout << "Payment Completed " << endl;
			//cout << "Short amount of Balance: "<< cost-balance << endl;
	}
	void Membership::record_history(int t, int length) {
		record[record_count++] = new Record(t, length);
	}
	int Membership::GetMemID() const{
		return memID;
	}
	Membership::Membership(const Membership &ref)
	:memID(ref.memID),balance(ref.balance)
	{
		cusName= ref.cusName;
	}
	int Membership::GetDsnID() const {
		return d_id;
	}
	void Membership::showAllRecords() {
		for (int i = 0; i < record_count; i++) {
			record[i]->showRecord();
		}
	}
	
	Membership::~Membership() {
		//delete[]cusName;
	}