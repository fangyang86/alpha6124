#include "stdafx.h"
#include "CMyST.h"
#include <direct.h>
#include <Windows.h>


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
	fp = fopen("X:\\new_tdx_test\\vipdoc\\sz\\lday\\sz000725.day", "rb");
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
	fp = fopen("X:\\new_tdx_test\\vipdoc\\sz\\lday\\sz000725.day", "rb");
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


int CMyST::findFile(char * fname)
{
	int n = 0;
	WIN32_FIND_DATA ffd;
	//LARGE_INTEGER filesize;
	TCHAR szDir[MAX_PATH];
	char strName[110];
	//char szDir[200];
	//size_t length_of_arg;
	HANDLE hFind = INVALID_HANDLE_VALUE;
	//DWORD dwError = 0;

	//_tcscpy(szDir, _T("x:\\*.*"));
	//_tcscpy(szDir, _T("X:\\new_tdx_test\\vipdoc\\sz\\lday\\*.day"));
	//_tcscpy(szDir, _T("X:\\new_tdx_test\\vipdoc\\sz\\lday\\sz00*.day"));
	_tcscpy(szDir, _T("X:\\new_tdx_test\\vipdoc\\sh\\lday\\sh60*.day"));
	hFind = FindFirstFile(szDir, &ffd);
	if (INVALID_HANDLE_VALUE == hFind){
		return -1;
	}

	do
	{
		if (ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			continue;
		//{
			//_tprintf(TEXT(" %s <DIR>\n"), ffd.cFileName);
		//}
		else{
			n++;
			//_tprintf(TEXT(" %s \n"), ffd.cFileName);
			//strcpy_s(strName,100, ffd.cFileName);
			//_tprintf(TEXT("    ......... %s \n"), strName);
			getREC1(ffd.cFileName);
		}
	} while (FindNextFile(hFind, &ffd) != 0);

	FindClose(hFind);
	printf("\n%d files found\n", n);

	return 0;
}


int CMyST::getREC1(TCHAR * fname)
{
	char buf[200];
	_tprintf(TEXT(" get rec1 : %s\n"), fname);
	
	return 0;
}
