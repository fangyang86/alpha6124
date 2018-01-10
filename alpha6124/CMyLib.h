#pragma once
struct st_gps {
	int nState;
	int nValidChar;
	int nField;
	char bufLine[200];
	int nLen;
	double x;
	double y;
};
class CMyLib
{
public:
	struct st_gps m_gps;

	CMyLib();
	~CMyLib();
	int test(int n);

	void initGPS();
	int gpsParse1(char c);
	int gpsParse(char *fn);
	int gpsPrint();
};

