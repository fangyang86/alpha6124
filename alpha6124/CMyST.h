#pragma once

union u_if
{
	int i;
	float f;
	char buf[4];
};

struct st_ohlc
{
	int d;
	int t;
	double o;
	double h;
	double l;
	double c;
	double v;
	double a;
};
struct st_rec {
	struct st_ohlc ohlc;
	struct st_ohlc db_ohlc;
};

class CMyST
{
public:
	CMyST();
	~CMyST();
	int testTDX(char *fname);
	int testRead(char * fname);
};

