#include <iostream>
#include <nlohmann/json.hpp>  // 引入json库头文件
#include<vector>
#include<map>
#include<string>

using json = nlohmann::json;  // 为json类型创建别名
using namespace std;
string func1()
{
    json js;
    js["msg_type"]=2;
    js["from"]="zhang san";
    js["to"]="li si";
    js["msg"]="hello";
    string sendbuf=js.dump();
    //cout<<sendbuf.c_str()<<endl;
    return sendbuf;
}

void func2()
{
    json js;
    js["id"]={1,2,3,4,5};
    js["name"]="zhang san";
    js["msg"]["zhang san"]="hello world";
    js["msg"]["li si0"]="hello china";
    js["msg"]={{"zhang san","hello world"},{"li si","hello china"}};
    cout<<js<<endl;
}

void func3()
{
    json js;
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    js["list"]=vec;

    map<int,string> m;
    m.insert({1,"黄山"});
    m.insert({2,"华山"});
    m.insert({3,"泰山"});

    js["path"]=m;

     string sendbuf=js.dump();
    cout<<sendbuf.c_str()<<endl;

}

int main() {
    string recvbuf=func1();
    json jsbuf=json::parse(recvbuf);
    cout<<jsbuf["msg_type"]<<endl;

    return 0;
}
