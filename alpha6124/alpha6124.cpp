// alpha6124.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<string>

#include "CMyLib.h"
#include "CMyST.h"

int testTDX()
{
	CMyST myst;
	char fname[20];

	strcpy(fname, "filename");
	myst.testTDX1(fname);
	return 0;
}

int testGPS()
{
	CMyLib mylib;
	char filename[30];

	printf("hello : %d\n",mylib.test(100));

	//sprintf(filename, "filename");
	strcpy_s(filename, "gps.txt");
	mylib.gpsParse(filename);

    return 0;
}

int main()
{
	testTDX();
	return 0;
}

