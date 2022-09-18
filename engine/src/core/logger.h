#pragma once
#include "defines.h"

#define LOG_WARNING_ENABLED 1
#define LOG_INFO_ENABLED 1
#define LOG_DEBUG_ENABLED 1
#define LOG_TRACE_ENABLED 1

#if KRELEASE == 1
#define LOG_DEBUG_ENABLED 1
#define LOG_TRACE_ENABLED 1
#endif

typedef enum Log_Level
{
    LOG_LEVEL_FATAL = 0,
    LOG_LEVEL_ERROR = 1,
    LOG_LEVEL_WARNING = 2,
    LOG_LEVEL_INFO = 3,
    LOG_LEVEL_DEBUG = 4,
    LOG_LEVEL_TRACE = 5
} LogLevel;

b8 Initialize_Logging();
void Shutdown_Logging();

KAPI void Log_Output(LogLevel Level,const char* Message,... );
#define KFATAL(Message,...) Log_Output(LOG_LEVEL_FATAL,Message,#__VA_ARGS__);

#ifndef KERROR
// Logs an error-level message.
#define KERROR(Message, ...) Log_Output(LOG_LEVEL_ERROR, Message, ##__VA_ARGS__);
#endif

#if LOG_WARN_ENABLED == 1
// Logs a warning-level message.
#define KWARN(Message, ...) Log_Output(LOG_LEVEL_WARN, Message, ##__VA_ARGS__);
#else
// Does nothing when LOG_WARN_ENABLED != 1
#define KWARN(Message, ...)
#endif

#if LOG_INFO_ENABLED == 1
// Logs a info-level message.
#define KINFO(Message, ...) Log_Output(LOG_LEVEL_INFO, Message, ##__VA_ARGS__);
#else
// Does nothing when LOG_INFO_ENABLED != 1
#define KINFO(Message, ...)
#endif

#if LOG_DEBUG_ENABLED == 1
// Logs a debug-level message.
#define KDEBUG(Message, ...) Log_Output(LOG_LEVEL_DEBUG, Message, ##__VA_ARGS__);
#else
// Does nothing when LOG_DEBUG_ENABLED != 1
#define KDEBUG(Message, ...)
#endif

#if LOG_TRACE_ENABLED == 1
// Logs a trace-level message.
#define KTRACE(Message, ...) Log_Output(LOG_LEVEL_TRACE, Message, ##__VA_ARGS__);
#else
// Does nothing when LOG_TRACE_ENABLED != 1
#define KTRACE(Message, ...)
#endif