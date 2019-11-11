#include "AsyncLogging.h"
#include "Logger.h"
#include <unistd.h>
#include <signal.h>

bool running = true;
void sig_handler(int num)
{
	//printf("????????\n");
	//LOG_INFO << "receive the signal ctrl_c";
	running = false;
}
int main()
{
	signal(SIGINT, sig_handler);
	AsyncLogging async_logging("Logger.txt");
	//设置日志
	Logger::SetLevel(Logger::Level::DEBUG);
	Logger::SetOutput(std::bind(&AsyncLogging::Append, &async_logging, std::placeholders::_1,std::placeholders:: _2));
	Logger::SetFlush(std::bind(&AsyncLogging::Flush, &async_logging));
	long long i = 0;
	while(running)
		LOG_DEBUG << "FPX NIUBI " <<i;
	LOG_DEBUG << "石方炎";
	
		
	//sleep(5);
    return 0;
}