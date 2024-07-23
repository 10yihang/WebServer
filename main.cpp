#include "config.h"

int main(int argc, char *argv[])
{
    //需要修改的数据库信息,登录名,密码,库名
    std::string user = "root";
    std::string passwd = "hyh621354";
    std::string databasename = "WebServer";

    //命令行解析
    Config config;
    config.parse_arg(argc, argv);

    WebServer server;

    //初始化
    server.init(config.PORT, user, passwd, databasename, config.LOGWrite, 
                config.OPT_LINGER, config.TRIGMode,  config.sql_num,  config.thread_num, 
                config.close_log, config.actor_model);
    

    //日志
    server.log_write();
    std::cerr<<"log success\n";

    //数据库
    server.sql_pool();
    std::cerr<<"sql success\n";

    //线程池
    server.thread_pool();
    std::cerr<<"threadpool success\n";

    //触发模式
    server.trig_mode();
    std::cerr<<"mode success\n";

    //监听
    server.eventListen();
    std::cerr<<"Listening\n";

    //运行
    server.eventLoop();

    return 0;
}