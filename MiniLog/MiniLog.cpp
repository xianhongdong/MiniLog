#include "MiniLog.h"
#include <time.h>
using namespace LogUtil;
LogUtil::MiniLog LogDefault;
MiniLog::MiniLog()
{
	m_fStream.open("default.log");
}


MiniLog::~MiniLog()
{
}

std::string LogUtil::MiniLog::GetDateTimeStr()
{
	char buf[32] = {};
	time_t rawtime;
	time(&rawtime);
	struct tm * timeinfo = localtime(&rawtime);
	strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", timeinfo);
	return std::string(buf);
}

MiniLog& LogUtil::MiniLog::Debug()
{
	m_CurLevel = LEVEL_DEBUG;
	
	if (m_CurLevel >= m_GlobalLevel)
		m_fStream << GetDateTimeStr() << " [d] ";
	return *this;
}

MiniLog& LogUtil::MiniLog::Info()
{
	m_CurLevel = LEVEL_INFO;
	if (m_CurLevel >= m_GlobalLevel)
		m_fStream << GetDateTimeStr() << " [i] ";
	return *this;
}

MiniLog & LogUtil::MiniLog::Warn()
{
	m_CurLevel = LEVEL_WARN;
	if (m_CurLevel >= m_GlobalLevel)
		m_fStream << GetDateTimeStr() << " [w] ";
	return *this;
}

void LogUtil::MiniLog::Error(char* log)
{
	Error() << log;	
}

MiniLog & LogUtil::MiniLog::Error()
{
	m_CurLevel = LEVEL_ERROR;
	if (m_CurLevel >= m_GlobalLevel)
		m_fStream << GetDateTimeStr() << " [e] ";
	return *this;
}

void LogUtil::MiniLog::Debug(char * log)
{
	Debug() << log;
}

void LogUtil::MiniLog::Info(char * log)
{
	Info() << log;
}

void LogUtil::MiniLog::Warn(char * log)
{
	Warn() << log;
}
