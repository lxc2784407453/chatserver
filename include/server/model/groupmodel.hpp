#ifndef GRUOPUSERMODEL_H
#define GRUOPUSERMODEL_H

#include"group.hpp"
#include<string>
#include<vector>
using namespace std;
class GroupModel
{
public:
    //创建群组
    bool createGruop(Group &group);
    //加入群组
    void addGroup(int userid,int groupid,string role);
    //查询用户所在群组信息
    vector<Group> queryGroups(int userid);
    //根据指定的userid查询用户id列表
    vector<int> queryGroupsUsers(int userid,int groupid);
};


#endif