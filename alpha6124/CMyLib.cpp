#include "stdafx.h"
#include <direct.h>
#include <stdio.h>
#include <stdlib.h>

#include "CMyLib.h"


CMyLib::CMyLib()
{
}


CMyLib::~CMyLib()
{
}

void CMyLib::initGPS()
{
	m_gps.nState = 0;
	m_gps.nField = 0;
	m_gps.nLen = 0;
	m_gps.nValidChar = 0;
}

int CMyLib::gpsParse(char *fn)
{
	FILE *fp;
	int c;

	initGPS();

	fp = fopen(fn, "rt");
	if (fp == NULL) return -1;
	printf(" open gps txt OK\n");
	while (!feof(fp))
	{
		c = fgetc(fp);
		printf("%c", c);

	}

	fclose(fp);

	gpsPrint();
	return 0;
}
int CMyLib::gpsPrint()
{
	char buf[200];
	_getcwd(buf, 100);
	buf[199] = 0;
	printf("current dir: %s\n", buf);

	printf("state:%d \n", m_gps.nState);

	return 0;
}

int CMyLib::test(int n)
{
	return n+1;
}
