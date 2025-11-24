#ifndef GRUOPUSER_H
#define GRUOPUSER_H

#include"user.hpp"

//群组成员，从User类继承
class GroupUser:public User
{
public:
    void setRole(string role){this->role=role;}
    string getRole(){return this->role;}

private:
  string role;

};

#endif