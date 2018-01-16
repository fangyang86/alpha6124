#include "stdafx.h"
#include "CMyST.h"


CMyST::CMyST()
{
}


CMyST::~CMyST()
{
}


int CMyST::testTDX(char *fname)
{
	FILE *fp;
	int n;
	union u_if uif[8];
	int m;

	printf("test\n");
	fp = fopen("r:\\sz000725.day", "rb");
	if (fp == NULL) {
		printf("open file error\nexit\n");
		return -1;
	}
	for (m=0;;m++) {
		n = fread(uif[0].buf, 4, 8, fp);
		if (n < 1)break;
		printf("%d %.3f %.3f %.3f %.3f %.4f %.4f\n", uif[0].i,uif[1].i*.01,uif[2].i*.01,uif[3].i*.01,uif[4].i*.01,uif[6].i*.0001*.0001,uif[5].f*.0001*.0001);
	}

	fclose(fp);
	return 0;
}


int CMyST::testRead(char * fname)
{
	return 0;
}


int CMyST::testTDX1(char* fname)
{
	FILE *fp;
	int n;
	union u_if uif;
	int m;

	printf("test\n");
	fp = fopen("r:\\sz000725.day", "rb");
	//fp = fopen("r:\\sz399006.lc1", "rb");
	if (fp == NULL) {
		printf("open file error\nexit\n");
		return -1;
	}
	for (m = 0;; m++) {
		n = fread(uif.buf, 4, 1, fp);
		if (n < 1)break;
		printf("%08X %d %.4f\n",uif.i, uif.i, uif.f);
	}

	fclose(fp);
	return 0;
}
