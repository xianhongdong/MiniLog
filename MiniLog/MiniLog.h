#pragma once
#include <fstream>
#include <string>
using namespace std;
namespace LogUtil
{
	enum MinLogLevel
	{
		LEVEL_DEBUG,
		LEVEL_INFO,
		LEVEL_WARN,
		LEVEL_ERROR,
	};
	class MiniLog
	{
	public:
		MiniLog();
		~MiniLog();
		void SetLogLevel(MinLogLevel level) { m_GlobalLevel = level; }
		std::string GetDateTimeStr();
		MiniLog& Debug();
		MiniLog& Info();
		MiniLog& Warn();
		MiniLog& Error();
		void Debug(char* log);
		void Info(char* log);
		void Warn(char* log);
		void Error(char* log);
		void Close() { m_fStream.close(); }
		template<class T>
		MiniLog& operator<<(T& obj)
		{
			if (m_CurLevel < m_GlobalLevel)
				return *this;
			m_fStream << obj;
			return *this;
		}
		template<class T>
		MiniLog& operator<<(const T& obj)
		{
			if (m_CurLevel < m_GlobalLevel)
				return *this;
			m_fStream << obj;
			return *this;
		}
		
		MiniLog& operator<<(const char* str)
		{
			if (m_CurLevel < m_GlobalLevel)
				return *this;
			m_fStream << str;
			return *this;
		}
		
	private:
		MinLogLevel m_GlobalLevel;
		MinLogLevel m_CurLevel;
		ofstream m_fStream;
	};
	static const char* const endl = "\n";
}
extern LogUtil::MiniLog LogDefault;

