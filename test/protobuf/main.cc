#include<iostream>
#include"test.pb.h"
#include<string>
using namespace fixbug;

int main()
{
    // 封装了login请求对象数据
    // LoginResponse rsp;
    // Res *rc = rsp.mutable_result();
    // rc->set_errcode(1);
    // rc->set_errmsg("登陆处理失败了");

    GetFriendListResponse rsp;
    Res *rc = rsp.mutable_result();
    rc->set_errcode(0);

    User *user1 = rsp.add_friend_list();
    user1->set_name("li si");
    user1->set_age(20);
    user1->set_sex(User::MAN);

    std::cout<<rsp.friend_list_size()<<std::endl;
    return 0;
}

int main1()
{
    // 封装了login请求对象数据
    LoginRequest req;
    req.set_name("zhang san");
    req.set_pwd("123456");

    // 数据对象序列化成 char
    std::string send_str;
    if(req.SerializeToString(&send_str))
    {
        std::cout<<send_str.c_str()<<std::endl;
    }

    // 从send_str反序列化一个login请求对象
    LoginRequest reqB;
    if(reqB.ParseFromString(send_str))
    {
        std::cout<<reqB.name()<<std::endl;
        std::cout<<reqB.pwd()<<std::endl;
    }

    return 0;
}