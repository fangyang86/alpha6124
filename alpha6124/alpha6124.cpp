// alpha6124.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<string>

#include "CMyLib.h"


int main()
{
	CMyLib mylib;
	char filename[30];

	printf("hello : %d\n",mylib.test(100));

	//sprintf(filename, "filename");
	strcpy_s(filename, "gps.txt");
	mylib.gpsParse(filename);

    return 0;
}

