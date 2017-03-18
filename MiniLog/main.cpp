#include "MiniLog.h"

//using namespace LogUtil;

int main()
{
	LogDefault.SetLogLevel(LogUtil::LEVEL_DEBUG);
	
	LogDefault.Debug() << "debug hello world" << 100 << LogUtil::endl;
	LogDefault.Debug("hello\n");
	LogDefault.Info() << "info hello world" << "2222" << LogUtil::endl;
	LogDefault.Warn() << "warn hello world" << 2222 << LogUtil::endl;
	LogDefault.Error() << "error hello world" << 2222 << LogUtil::endl;
	

	LogDefault.SetLogLevel(LogUtil::LEVEL_INFO);
	LogDefault.Debug() << "debug hello world" << 100 << LogUtil::endl;	
	LogDefault.Info() << "info hello world" << "2222" << LogUtil::endl;
	LogDefault.Info("hello \n");
	LogDefault.Warn() << "warn hello world" << 2222 << LogUtil::endl;
	LogDefault.Error() << "error hello world" << 2222 << LogUtil::endl;

	LogDefault.SetLogLevel(LogUtil::LEVEL_WARN);
	LogDefault.Debug() << "debug hello world" << 100 << LogUtil::endl;
	LogDefault.Info() << "info hello world" << "2222" << LogUtil::endl;
	LogDefault.Warn() << "warn hello world" << 2222 << LogUtil::endl;
	LogDefault.Warn("hello \n");
	LogDefault.Error() << "error hello world" << 2222 << LogUtil::endl;

	LogDefault.SetLogLevel(LogUtil::LEVEL_ERROR);
	LogDefault.Debug() << "debug hello world" << 100 << LogUtil::endl;
	LogDefault.Info() << "info hello world" << "2222" << LogUtil::endl;
	LogDefault.Warn() << "warn hello world" << 2222 << LogUtil::endl;
	LogDefault.Error() << "error hello world" << 2222 << LogUtil::endl;
	LogDefault.Error("hello\n");
	LogDefault.Close();
	return 0;
}