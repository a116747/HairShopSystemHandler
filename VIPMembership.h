#pragma once

#ifndef __VIPMEMBERSHIP_H__
#define __VIPMEMBERSHIP_H__
#include "CommonThings.h"
#include "String.h"
class VipMembership :public Membership {
private:
	int v_dis = 20;
public:
	VipMembership(int id,int money, String name, int dsn_id)
	:Membership(id,money,name, dsn_id)
	{
		type = VIP;
	};
	 void Deposit(int money) {
		Membership::Deposit(money);
	}
	 void ShowMemInfo() const {
		 cout << "---------------" << endl;
		 cout << "ID: " << memID << endl;
		 cout << "Name: " << cusName << endl;
		 cout << "Membership Type : VIP" << endl;
		 cout << "Balance: " << balance << endl;

	 }
	 int getDisRate() {
		// cout << "v_dis: " << v_dis << endl;
		return v_dis;
	}
};





#endif