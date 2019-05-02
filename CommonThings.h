#pragma once
#ifndef __COMMONTHINGS_H__
#define __COMMONTHINGS_H__
const int NAME_LEN = 20;
enum //머리 종류
{
	CUT=1,
	PERM,
	COLOR,
	TREATMENT
};
enum //멤버십 종류
{ 
	NORMAL = 1, 
	VIP,
	VVIP
};
enum //머리 길이
{
	MEDIUM_LENGTH=1,
	LONG=2
};
enum // 회원인지 디자이너인지
{
	MEM = 1,
	DSN,
	EXIT
};
enum //멤버 메뉴 순서
{
	REGISTER=1,
	DEPOSIT,
	DOHAIR,
	PRINT,
	HISTORY_PRINT
};
enum //디자이너 메뉴 순서
{
	DREGISTER=1,
	PRINTD,
	SHOWCAR,
	SHOWPAY
};
#endif 
