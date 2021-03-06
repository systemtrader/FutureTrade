
#ifndef TRADE_UTIL_H
#define TRADE_UTIL_H
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include<iostream>

#if 0
#ifdef WIN32
#   include <windows.h>
#else
#   include <sys/time.h>
#endif

#if 0
#ifdef WIN32
static inline int gettimeofday(struct timeval *tp, void *tzp)
{
	time_t clock;
	struct tm tm;
	SYSTEMTIME wtm;

	GetLocalTime(&wtm);
	tm.tm_year     = wtm.wYear - 1900;
	tm.tm_mon     = wtm.wMonth - 1;
	tm.tm_mday     = wtm.wDay;
	tm.tm_hour     = wtm.wHour;
	tm.tm_min     = wtm.wMinute;
	tm.tm_sec     = wtm.wSecond;
	tm. tm_isdst    = -1;
	clock = mktime(&tm);
	tp->tv_sec = clock;
	tp->tv_usec = wtm.wMilliseconds * 1000;

	return (0);
}
#endif /* WIN32 */
#endif
#endif


static inline unsigned long long time_convert(int year, int month, int day, int hour, int min, int sec, int micro_sec)
{
	struct tm timein;
	timein.tm_year = year > 1980 ? (year - 1900) : year;
	timein.tm_mon = month-1;
	timein.tm_mday = day;//?
	timein.tm_hour = hour;
	timein.tm_min = min;
	timein.tm_sec = sec;
	time_t tm = mktime(&timein);

	//time_t tm = time(NULL);

	return (unsigned long long)tm*1000+micro_sec;
}

static int CaculateWeekday(int y, int m, int d)
{
	int w;  
	if (m==1 || m==2)
	{
		m += 12;
		y--;
	}

	w = (d+1 + 2*m + 3*(m+1)/5 + y + y/4 - y/100 + y/400)%7;

	return w;
}

static void CalculateYesterday(int& year, int& month, int& day,int step)
{
	 time_t ltime;
	 long long MilionSecond;
	 struct   tm   tmcur;

	 //计算70/01/01至今的秒数
	 time( &ltime );
	 MilionSecond = ltime;

	 MilionSecond  = MilionSecond  - 60 * 60 * 24*step;
	 ltime = MilionSecond;
	 tmcur = *localtime(&ltime); 

	 year = tmcur.tm_year+1900;
	 month = tmcur.tm_mon+1;
	 day = tmcur.tm_mday;

}

#endif
