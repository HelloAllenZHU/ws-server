#include <iostream>

using namespace std;


//使用独立版的Asio需要定义ASIO_STANDALONE，否则使用Boost.Asio
#define ASIO_STANDALONE

#include "websocketpp/config/asio_no_tls.hpp"
#include "websocketpp/server.hpp"

#include <functional>

typedef websocketpp::server<websocketpp::config::asio> server;

//服务器定义
class WS_Server
{
public:
    WS_Server() {
        //日志设置
        m_endpoint.set_error_channels( websocketpp::log::elevel::all );
        m_endpoint.set_access_channels( websocketpp::log::alevel::all ^ websocketpp::log::alevel::frame_payload );
        //初始化Asio
        m_endpoint.init_asio();
    }

    void run() {
        //监听9002端口
        m_endpoint.listen( 9000 );
        //接受连接插入队列
        m_endpoint.start_accept();
        //开启Asio io_service循环
        m_endpoint.run();
    }

private:
    server m_endpoint;
};

int main()
{
    cout << "Hello World!" << endl;

    WS_Server wss;
    wss.run();
    return 0;
}
