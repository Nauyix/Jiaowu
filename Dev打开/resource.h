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
    int auth;//1����Ա��2��ʦ��3����Ա��4ѧ��
    int dele;
};

void csh();//����ʼʱ��������
void welcome();//���˵�
void end();//�������ʱ�����ݴ����ļ�
void login();//��¼����Ȩ
void account();//�˺Ź���
void reward();//�������
void student();//ѧ����Ϣ����
void printrew(int);//������Ϣ���
void printstu(int);//ѧ����Ϣ���
int cmp(Rew, Rew);//������Ϣ������������

