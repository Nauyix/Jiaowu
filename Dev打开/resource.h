#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include<iomanip>
using namespace std;

struct Stu
{
    string ID, name, major, cont;
    int cla, apa, room;
    int dele;
};

struct Rew
{
    string ID, name, org, level;
    int pd, date;
    int dele;
};

struct Acc
{
    string acc, pwd;
    int auth;//1管理员，2老师，3辅导员，4学生
    int dele;
};

void csh();//程序开始时读入数据
void welcome();//主菜单
void end();//程序结束时将数据存入文件
void login();//登录，鉴权
void account();//账号管理
void reward();//奖项管理
void student();//学生信息管理
void printrew(int);//奖惩信息输出
void printstu(int);//学生信息输出
int cmp(Rew, Rew);//奖惩信息按照日期排序

