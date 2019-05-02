#pragma once
#ifndef __RECORD_H__
#define __RECORD_H__
#include "String.h"
#include "CommonThings.h"

class Record {
private:
	int count=1;
	int type;
	int length;
public:
	Record(int t,int l) 
		:type(t),length(l){
	}
	void showRecord() {
		String s;
		String len;
		switch(type) {

		case CUT: s = "cut"; break;
		case PERM: s = "perm"; break;
		case COLOR: s = "color"; break;
		case TREATMENT: s = "treatment"; break;
		default: s = "error";

		}
		switch (length) {
		case MEDIUM_LENGTH: len = "medium-length"; break;
		case LONG: len = "long"; break;

		}
		cout <<s<<", "<< len <<endl;

	}
};


#endif