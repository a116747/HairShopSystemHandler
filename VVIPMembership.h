#pragma once

#ifndef __VVIPMEMBERSHIP_H__
#define __VVIPMEMBERSHIP_H__
#include "CommonThings.h"
#include "Membership.h"
#include "String.h"

class VVipMembership :public Membership {
private:
	int vv_dis = 30;
public:
	VVipMembership(int id, int money, String name, int dsn_id)
		:Membership(id, money, name, dsn_id)
	{
		type = VVIP;
	};
	void ShowMemInfo() const {
		cout << "---------------" << endl;
		cout << "ID: " << memID << endl;
		cout << "Name: " << cusName << endl;
		cout << "Membership Type : VVIP" << endl;
		cout << "Balance: " << balance << endl;

	}
	 void Deposit(int money) {
		Membership::Deposit(money);
	}
	 int getDisRate() {
		// cout << "vv_dis: " << vv_dis<<endl;
		return vv_dis;
	}

};


#endif