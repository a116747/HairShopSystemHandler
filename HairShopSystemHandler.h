#pragma once

#ifndef _HAIRSHOPSYSTEMHANDLER_H__
#define _HAIRSHOPSYSTEMHANDLER_H__
#include "Membership.h"
#include "Designer.h"

class HairShopSystemHandler {
private:
	Membership * memArr[100];   
	Designer *dsnArr[100];
	int memNum;        
	int dsnNum;
public:
	HairShopSystemHandler();
	~HairShopSystemHandler();
	void ShowMenu(void) const;
	void ShowMemMenu(void) const;
	void ShowDsnMenu(void) const;
	void Register(void);
	void DepositMoney(void);
	void DepositMoney(int id);
	void doHair(void);
	void showHistory();
	void ShowAllMemInfo(void) const;
	void ShowAllDesigner(void) const;
	void ShowCareerInfo(void) const;
	void ShowPayCheckInfo(void) const;
	void DRegister(void);
	

protected:
	void RegisterNormalMembership();
	void RegisterVIPMembership();
	void RegisterVVIPMembership();
};

#endif 
