#pragma once

#ifndef __NORMALMEMBERSHIP_H__
#define __NORMALMEMBERSHIP_H__
#include "CommonThings.h"
#include "String.h"

class NormalMembership :public Membership {
private:
	int n_dis = 10;
public:
	NormalMembership(int id, int money,String name, int dsn_id)
	:Membership(id,money,name,dsn_id)
	{
		//this.name = name;
		type = NORMAL;
	};
	 void Deposit(int money) {
		Membership::Deposit(money);
	}
	 void ShowMemInfo() const {
		 cout << "---------------" << endl;
		 cout << "ID: " << memID << endl;
		 cout << "Name: " << cusName << endl;
		 cout << "Membership Type : Normal" << endl;
		 cout << "Balance: " << balance << endl;

	 }
	 int getDisRate() {
		 //cout << "n_dis: " << n_dis<<endl;
		return n_dis;
	}
};





#endif