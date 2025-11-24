#include"offlinemessagemodel.hpp"
#include"db.h"
#include<iostream>
using namespace std;


//存储用户的离线消息
void OfflineMsgModel::insert(int userid,string msg)
{
    //组装sql语句
        char sql[1024]={0};
        sprintf(sql,"insert into offlinemessage values(%d,'%s')",userid,msg.c_str());
        MySQL mysql;
        if(mysql.connnect())
        {
            mysql.update(sql);
                
        }
        
        
}

//删除离线消息
void OfflineMsgModel::remove(int userid)
{
     //组装sql语句
        char sql[1024]={0};
        sprintf(sql,"delete from offlinemessage where user_id=%d ",userid);
        MySQL mysql;
        if(mysql.connnect())
        {
            mysql.update(sql);
                
        }
}

//查询离线消息
vector<string> OfflineMsgModel::query(int userid)
{
     //组装sql语句
        char sql[1024]={0};
        sprintf(sql,"select message from offlinemessage where user_id = %d",userid);
        vector<string> vec;
        MySQL mysql;
        if(mysql.connnect()){
           MYSQL_RES *res= mysql.query(sql);
           if(res!=nullptr)
           {
            MYSQL_ROW row;
            while((row=mysql_fetch_row(res))!=nullptr)
            {
                vec.push_back(row[0]);
            }
            
                mysql_free_result(res);//释放资源
                return vec;
                
           }
          
        }
      return vec; 
}