#pragma once
#ifndef __MEMBERSHIP_H__
#define __MEMBERSHIP_H__
#include "String.h"
#include "Record.h"
class Membership {
protected:
	int memID;
	int balance; //�ܾ�
	int d_id; 
	int cost; //�Ӹ��ϴµ� �����ϴ� ���
	String cusName;
	Record *record[100];
	int record_count=0;
	//Designer *dsnArr[100];
protected:
	int type; //����� ����
public:
	Membership(int id, int money, String name, int dsn_sel);
	~Membership();
	void Deposit(int money);
	virtual void ShowMemInfo() const=0;
	virtual int getDisRate() = 0;
	void hairCost(int cost);
	int GetMemID() const;
	int GetDsnID() const;
	bool reserved(int cost) ;
	Membership(const Membership &ref);
	void showAllRecords();
	void record_history(int t, int length);
#endif
};
