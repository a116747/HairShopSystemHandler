#pragma once
#ifndef _DESIGNER_H__
#define _DESIGNER_H__
#include "Membership.h"
#include "String.h"

class Designer
{
private:
	int d_id;
	String d_name;
	int memID[100];
	int memNum;
	int cut, perm, color, treatment;
	int paycheck;
public:
	Designer(int id, String name);
	
	~Designer() {
		delete []memID;
	}
	virtual void Career(int hair);
	virtual void Paycheck(int cost);
	void ShowCareerInfo() const;
	void ShowPayCheckInfo() const;
	
	int GetDsnID() const;
	void addCus(int c);
	Designer(const Designer &ref);
	void ShowDesigner() const;




};
#endif