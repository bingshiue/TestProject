/**
 * @file log.cpp
 *
 */

#include "../include/log.h"

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
static FILE *logFile;
static char logFileName[256];

#define LOGS_DIR  "./logs/"
void OpenLogFile(void){

    mkdir(LOGS_DIR,S_IRUSR|S_IWUSR|S_IXUSR |/* rwx */
	S_IRGRP|S_IWGRP|S_IXGRP |/* rwx */
	S_IROTH|S_IXOTH|S_IXOTH);/* rwx */

	memset( logFileName,0,sizeof(logFileName)/sizeof(logFileName[0]));
	time(&now);
	now_tm = localtime(&now);
	sprintf(logFileName,"./logs/logfile-%d-%d-%d-%d:%d.txt",
			READ_RTC_YEAR(now_tm->tm_year),
			READ_RTC_MONTH(now_tm->tm_mon),
			READ_RTC_DAY(now_tm->tm_mday),
			READ_RTC_HOUR(now_tm->tm_hour),
			READ_RTC_MINUTE(now_tm->tm_min));

	logFile = fopen(logFileName,"w+");
	if(logFile==NULL){
		fprintf(stderr,"Open Log File Failed ! \n");
		return;
	}
}

void CloseLogFile(void){
	fclose(logFile);
}

static const char* LogLevelStr[LOGLEVELNUM] = {
	"E	",
	"W	",
	"D	",
	"I	",
};/**< Log Prefix */

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

	// Print To stdout
	va_list arglist;
	va_start(arglist,prefix);

	vprintf(prefix,arglist);
	va_end(arglist);

	// Print To File
	va_start(arglist,prefix);

	vfprintf(logFile,prefix,arglist);
	va_end(arglist);
}



