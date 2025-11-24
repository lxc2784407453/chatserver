#include <muduo/net/TcpServer.h>
#include <muduo/base/Logging.h>
#include<string>
#include <muduo/net/EventLoop.h>
#include<iostream>
#include<functional>

using namespace std;
using namespace muduo;
using namespace muduo::net;
using namespace placeholders;

class ChatSever
{
private:
    TcpServer _server;
    EventLoop *_loop; // epoll
    void onConnection(const TcpConnectionPtr &conn)
    {
        if(conn->connected())
        {
       cout<<conn->peerAddress().toIpPort()<<"->"<<conn->localAddress().toIpPort()<<"online"<<endl;
        }
        else{
           cout<<conn->peerAddress().toIpPort()<<"->"<<conn->localAddress().toIpPort()<<"offline"<<endl;
           conn->shutdown();
           
        }
    }

    void onMessage(const TcpConnectionPtr&conn, //连接
                            Buffer*buffer,  //缓冲区
                            Timestamp time)  //时间信息
     {
       string buf=buffer->retrieveAllAsString();
       cout<<"data:"<<buf<<"time:"<<time.toString()<<endl;
       conn->send(buf);
    }
public:
ChatSever(EventLoop* loop,
            const InetAddress& listenAddr,
            const string& nameArg)
            :_server(loop,listenAddr,nameArg)
            ,_loop(loop)
            {
                         _server.setConnectionCallback(std::bind(&ChatSever::onConnection,this, _1));
                         _server.setMessageCallback(std::bind(&ChatSever::onMessage,this, _1,_2,_3));
                         _server.setThreadNum(4);
            }
   void strat()
   {
    _server.start();
   }
};

int main()
{
    EventLoop loop;
    InetAddress addr("127.0.0.1",6000);
    ChatSever server(&loop,addr,"ChatServer");
    server.strat();
    loop.loop();

    return 0;
}
