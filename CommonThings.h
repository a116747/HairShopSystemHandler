#pragma once
#ifndef __COMMONTHINGS_H__
#define __COMMONTHINGS_H__
const int NAME_LEN = 20;
enum //�Ӹ� ����
{
	CUT=1,
	PERM,
	COLOR,
	TREATMENT
};
enum //����� ����
{ 
	NORMAL = 1, 
	VIP,
	VVIP
};
enum //�Ӹ� ����
{
	MEDIUM_LENGTH=1,
	LONG=2
};
enum // ȸ������ �����̳�����
{
	MEM = 1,
	DSN,
	EXIT
};
enum //��� �޴� ����
{
	REGISTER=1,
	DEPOSIT,
	DOHAIR,
	PRINT,
	HISTORY_PRINT
};
enum //�����̳� �޴� ����
{
	DREGISTER=1,
	PRINTD,
	SHOWCAR,
	SHOWPAY
};
#endif 
