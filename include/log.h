/**
 * @file log.h
 *
 */

#ifndef LOG_H_
#define LOG_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <time.h>

enum LogLevel {
	LOG_ERROR =0,/**< Error */
	LOG_WARNING,/**< Warning */
	LOG_DEBUG,/**< Debug */
	LOG_INFO/**< Info */
};/**< Log Level Enumeration */

#define LOGLEVELNUM  (LOG_INFO + 1)

void _log_print(enum LogLevel loglevel,const char* tag,const char* format,...);

#define LOGE(TAG,...) _log_print(LOG_ERROR,TAG,__VA_ARGS__)
#define LOGW(TAG,...) _log_print(LOG_WARNING,TAG,__VA_ARGS__)
#define LOGI(TAG,...) _log_print(LOG_INFO,TAG,__VA_ARGS__)

#ifdef _DEBUG
#define LOGD(TAG,...) _log_print(LOG_DEBUG,TAG,__VA_ARGS__)
#else
#define LOGD(TAG,...) do{} while(0)
#endif

#endif /* LOG_H_ */
