/**
 * @file log.cpp
 *
 */

#include "../include/log.h"

static const char* LogLevelStr[LOGLEVELNUM] = {
	"E	",
	"W	",
	"D	",
	"I	",
};/**< Log Prefix */

#define READ_RTC_YEAR(Y) (Y+1900)
#define READ_RTC_MONTH(M) (M+1)
#define READ_RTC_DAY(D) (D)
#define READ_RTC_HOUR(H) (H)
#define READ_RTC_MINUTE(M) (M)
#define READ_RTC_SECOND(S) (S)

static char prefix[1024];
static char nowtime[256];
static time_t now;
static struct tm* now_tm;
/**
 * @brief Log print function.
 */
void _log_print(enum LogLevel loglevel,const char* tag,const char* format,...){
	//
	memset( prefix,0,sizeof(prefix)/sizeof(prefix[0]));
	memset( nowtime,0,sizeof(nowtime)/sizeof(nowtime[0]));
	//
	time(&now);
	now_tm = localtime(&now);
	sprintf(nowtime,"[%d-%2d-%2d-%2d:%2d] ",
			READ_RTC_YEAR(now_tm->tm_year),
			READ_RTC_MONTH(now_tm->tm_mon),
			READ_RTC_DAY(now_tm->tm_mday),
			READ_RTC_HOUR(now_tm->tm_hour),
			READ_RTC_MINUTE(now_tm->tm_min));
	//
	sprintf(prefix,"%s%s%s: ",LogLevelStr[loglevel],nowtime,tag);
	strncat(prefix,format,sizeof(prefix));

	va_list arglist;
	va_start(arglist,prefix);

	vprintf(prefix,arglist);
	va_end(arglist);
}



