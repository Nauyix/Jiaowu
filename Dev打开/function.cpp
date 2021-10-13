#include "resource.h"
int stu_n, rew_n, acc_n, sit=-1;
int stu_del=0, rew_del=0, acc_del=0;
//用户权限：1为管理员，2为教师，3为辅导员，4为学生
Stu stu[1000];
Acc acc[1000];
Rew rew[1000];
void csh()
{
	
	freopen("stu.xy", "r", stdin);
	cin >> stu_n;
	for (int i = 0; i < stu_n; i++)
	{
		cin >> stu[i].ID >> stu[i].name >> stu[i].major >> stu[i].major;
		cin >> stu[i].cla >> stu[i].apa >> stu[i].room;
		//为了便于排版，分成两行写,下同
	}
	fclose(stdin);
	cin.clear();
	cout.clear();
	freopen("rew.xy", "r", stdin);
	cin >> rew_n;
	for (int i = 0; i < rew_n; i++)
	{
		cin >> rew[i].ID >> rew[i].name >> rew[i].org;
		cin >> rew[i].level >> rew[i].pd >> rew[i].date;
	}
	fclose(stdin);
	cin.clear();
	cout.clear();
	freopen("acc.xy", "r", stdin);
	cin >> acc_n;
	for (int i = 0; i < acc_n; i++)
	{
		cin >> acc[i].acc >> acc[i].pwd >> acc[i].auth;
	}
	fclose(stdin);
	cin.clear();
	cout.clear();
	freopen("CON", "r", stdin);
	while(sit==-1) login();
}

void login()
{
	string name_tr, pwd_tr;
	cout << "请输入账号：";
	cin >> name_tr;
	cout << "请输入密码：";
	cin >> pwd_tr;
	for (int i = 0; i < acc_n; i++)
	{
		if (name_tr == acc[i].acc&&pwd_tr == acc[i].pwd)
		{
			sit = acc[i].auth;
			return;
		}
	}
	cout << "账号或密码输入错误\n";
}

void welcome()
{
	system("CLS");
	cout << "\t\t\t\t\t************************************" << endl;
	cout << "\t\t\t\t\t*         学生奖惩管理系统         *" << endl;
	cout << "\t\t\t\t\t*                     V1.0         *" << endl;
	cout << "\t\t\t\t\t*         请操作：                 *" << endl;
	cout << "\t\t\t\t\t*         1.账号管理               *" << endl;
	cout << "\t\t\t\t\t*         2.奖惩管理               *" << endl;
	cout << "\t\t\t\t\t*         3.学生管理               *" << endl;
	cout << "\t\t\t\t\t*         4.退出程序               *" << endl;
	cout << "\t\t\t\t\t*                                  *" << endl;
	cout << "\t\t\t\t\t*  注：输入其他数字视为退出系统    *" << endl;
	cout << "\t\t\t\t\t*                           By lxy *" << endl;
	cout << "\t\t\t\t\t************************************" << endl;
	int tr;
	cin >> tr;
	if (tr == 1) account();
	else if (tr == 2) reward();
	else if (tr == 3) student();
	else return;
}

void end()
{
	freopen("stu.xy", "w", stdout);
	cout << stu_n - stu_del << "\n";
	for (int i = 0; i < stu_n; i++)
	{
		if (stu[i].dele == 1) continue;
		cout << stu[i].ID <<"\n"<< stu[i].name << "\n" << stu[i].major << "\n" << stu[i].cont << "\n";
		cout << stu[i].cla << "\n" << stu[i].apa << "\n" << stu[i].room << "\n";
		//为了便于排版，分成两行写,下同
	}
	fclose(stdout);
	cin.clear();
	cout.clear();
	freopen("rew.xy", "w", stdout);
	cout << rew_n - rew_del<<"\n";
	for (int i = 0; i < rew_n; i++)
	{
		if (rew[i].dele == 1) continue;
		cout << rew[i].ID << "\n" << rew[i].name << "\n" << rew[i].org << "\n";
		cout << rew[i].level << "\n" << rew[i].pd << "\n" << rew[i].date << "\n";
	}
	fclose(stdout);
	cin.clear();
	cout.clear();
	freopen("acc.xy", "w", stdout);
	cout << acc_n - acc_del << "\n";
	for (int i = 0; i < acc_n; i++)
	{
		if (acc[i].dele == 1) continue;
		cout << acc[i].acc << "\n" << acc[i].pwd << "\n" << acc[i].auth << "\n";
	}
	fclose(stdout);
	cin.clear();
	cout.clear();
}

void account()
{
	system("CLS");
	if (sit != 1)
	{
		cout << "当前账号无权进行账号操作\n";
		system("pause");
		return;
	}
	cout << "\t\t\t\t\t************************************" << endl;
	cout << "\t\t\t\t\t*             账号管理             *" << endl;
	cout << "\t\t\t\t\t*                                  *" << endl;
	cout << "\t\t\t\t\t*         请操作：                 *" << endl;
	cout << "\t\t\t\t\t*         1.账号增加               *" << endl;
	cout << "\t\t\t\t\t*         2.账号删除               *" << endl;
	cout << "\t\t\t\t\t*         3.密码修改               *" << endl;
	cout << "\t\t\t\t\t*                                  *" << endl;
	cout << "\t\t\t\t\t*                                  *" << endl;
	cout << "\t\t\t\t\t*   注：输入其他数字则退回主菜单   *" << endl;
	cout << "\t\t\t\t\t*                                  *" << endl;
	cout << "\t\t\t\t\t************************************" << endl;
	int tr;
	cout << "请选择要进行的操作：";
	while (cin >> tr)
	{
		if (tr == 1)
		{
			cout << "请输入要添加的账号：";
			cin >> acc[acc_n].acc;
			cout << "请输入密码：";
			cin >> acc[acc_n].pwd;
			cout << "请输入用户身份 1为管理员，2为教师，3为辅导员，4为学生\n";
			cin >> acc[acc_n].auth;
			acc_n++;
			cout << "添加成功！\n";
			system("pause");
		}
		else if (tr == 2)
		{
			cout << "请输入要删除账号的用户名";
			string tr;
			cin >> tr;
			for (int i = 0; i < acc_n; i++)
			{
				if (acc[i].acc == tr) acc[i].dele = 1;
				cout << "删除成功！\n";
				acc_del++;
				system("pause");
				break;
			}
		}
		else if (tr == 3)
		{
			cout << "请输入要修改密码的账号的用户名";
			string tr;
			cin >> tr;
			for (int i = 0; i < acc_n; i++)
			{
				if (acc[i].acc == tr)
				{
					string tr2;
					cout << "查找到相应账号，请输入要修改的密码：";
					cin >> tr2;
					acc[i].pwd = tr2;
					cout << "修改成功！\n";
					system("pause");
					break;
				}
			}
			cout << "未找到相应账号\n";
			system("pause");
			break;
		}
		else
		{
			welcome();
			return;
		}
		cout << "请选择要进行的操作：";
	}
}

void reward()
{
	system("CLS");
	cout << "\t\t\t\t\t************************************" << endl;
	cout << "\t\t\t\t\t*             奖惩管理             *" << endl;
	cout << "\t\t\t\t\t*                                  *" << endl;
	cout << "\t\t\t\t\t*         请操作：                 *" << endl;
	cout << "\t\t\t\t\t*         1.奖惩增加               *" << endl;
	cout << "\t\t\t\t\t*         2.奖惩删除               *" << endl;
	cout << "\t\t\t\t\t*         3.奖惩修改               *" << endl;
	cout << "\t\t\t\t\t*         4.奖惩查询               *" << endl;
	cout << "\t\t\t\t\t*                                  *" << endl;
	cout << "\t\t\t\t\t*                                  *" << endl;
	cout << "\t\t\t\t\t*   注：输入其他数字则退回主菜单   *" << endl;
	cout << "\t\t\t\t\t*                                  *" << endl;
	cout << "\t\t\t\t\t************************************" << endl;
	cout << "请选择要进行的操作：";
	int tr,tr1,tr3;
	string tr2;
	while (cin >> tr)
	{
		if (tr == 1)
		{
			if (sit == 4)
			{
				cout << "当前用户没有进行该操作的权限\n";
				continue;
			}
			cout << "请输入被奖励/惩罚的学生学号：";
			cin >> rew[rew_n].ID;
			cout << "请输入被奖励/惩罚的全称：";
			cin >> rew[rew_n].name;
			//cout << rew[rew_n].name<<"\n";
			cout << "请输入颁发该奖励/惩罚的组织：";
			cin >> rew[rew_n].org;
			//cout << rew[rew_n].org << "\n";
			cout << "请输入该奖励/惩罚的等级：";
			cin >> rew[rew_n].level;
			cout << "请输入被奖励/惩罚的日期：";
			cin >> rew[rew_n].date;
			cout << "如果录入项为奖励，请输入1，如果为惩罚，请输入2：";
			cin >> rew[rew_n].pd;
			rew_n++;
			cout << "录入成功！\n";
			system("pause");
		}
		else if (tr == 2)
		{
			if (sit == 4)
			{
				cout << "当前用户没有进行该操作的权限\n";
				continue;
			}
			int tot = 0;
			cout << "请输入要删除的奖励/惩罚所属学生的学号：";
			cin >> tr2;
			for (int i = 0; i < rew_n; i++)
			{
				if (rew[i].ID == tr2)
				{
					tot++;
					printrew(i);
				}
			}
			if (tot == 0) cout << "未查询到该生有奖励/惩罚\n";
			else
			{
				cout << "以上为该生现有的奖励/惩罚，请输入要删除的序号：";
				cin >> tr1;
				rew[tr1].dele = 1;
				cout << "删除成功！\n";
				system("pause");
			}
		}
		else if (tr == 3)
		{
			if (sit == 4)
			{
				cout << "当前用户没有进行该操作的权限\n";
				continue;
			}
			int tot = 0;
			cout << "请输入要修改的奖励/惩罚所属学生的学号：";
			cin >> tr2;
			for (int i = 0; i < rew_n; i++)
			{
				if (rew[i].ID == tr2)
				{
					tot++;
					printrew(i);
				}
			}
			if (tot == 0) cout << "未查询到该生有奖励/惩罚\n";
			else
			{
				cout << "以上为该生现有的奖励/惩罚，请输入要修改的序号：";
				cin >> tr1;
				cout << "请输入要修改的内容：\n";
				cout << "1.所属学生ID\n";
				cout << "2.奖励/惩罚名称\n";
				cout << "3.奖励/惩罚颁发组织\n";
				cout << "4.奖励/惩罚等级\n";
				cout << "5.奖励/惩罚颁发日期\n";
				cin >> tr3;
				if (tr3 == 1)
				{
					cout << "请输入修改后所属学生ID：";
					cin >> rew[tr1].ID;
					cout << "修改成功！\n";
				}
				else if (tr3 == 2)
				{
					cout << "请输入修改后的名称：";
					cin >> rew[tr1].name;
					cout << "修改成功！\n";
				}
				else if (tr3 == 3)
				{
					cout << "请输入修改后的组织名：";
					cin >> rew[tr1].org;
					cout << "修改成功！\n";
				}
				else if (tr3 == 4)
				{
					cout << "请输入新的等级：";
					cin >> rew[tr1].level;
					cout << "修改成功！\n";
				}
				else if (tr3 == 5)
				{
					cout << "请输入新日期：";
					cin >> rew[tr1].date;
					cout << "修改成功！\n";
				}
				else cout << "输入有误，修改不成功\n";
				system("pause");
			}
		}
		else if (tr == 4)
		{
			cout << "请选择操作：\n";
			cout << "1.查询某一学生所有奖惩信息\n";
			cout << "2.输入日期范围查询范围内所有奖惩信息\n";
			cin >> tr1;
			int reward=0, punishment=0;
			if (tr1 == 1)
			{
				int tot = 0;
				cout << "请输入要查询的奖励/惩罚所属学生的学号：";
				cin >> tr2;
				for (int i = 0; i < rew_n; i++)
				{
					if (rew[i].ID == tr2&&rew[i].dele==0)
					{
						tot++;
						if (rew[i].pd == 1) reward++;
						else punishment++;
						printrew(i);
					}
				}
				if (tot == 0) cout << "未查询到该生有奖励/惩罚\n";
				else
				{
					printf("该生共有%d条奖惩信息，其中奖励%d条，惩罚%d条\n", tot, reward, punishment);
				}
			}
			else if (tr1 == 2)
			{
				int begin = 0, end = 0, tot = 0;
				cout << "请输入起止日期，如20100102 20200202\n";
				cin >> begin >> end;
				sort(rew, rew + rew_n - rew_del, cmp);
				for (int i = 0; i < rew_n; i++)
				{
					if (rew[i].date >= begin && rew[i].date <= end && rew[i].dele == 0)
					{
						tot++;
						printrew(i);
						if (rew[i].pd == 1) reward++;
						else punishment++;
					}
				}
				printf("该时间段共有%d条奖惩信息，其中奖励%d条，惩罚%d条\n", tot, reward, punishment);
			}
			else cout << "输入有误\n";
		}
		else
		{
			welcome();
			return;
		}
		cout << "请选择要进行的操作：";
	}
}

void printrew(int n)
{
	cout << "序号：" << n << "\n";
	cout << "所属学生ID：" << rew[n].ID << "\n";
	cout << "名称：" << rew[n].name << "\n";
	cout << "颁发组织：" << rew[n].org << "\n";
	cout << "等级：" << rew[n].level << "\n";
	cout << "日期：" << setfill('0') << setw(8) << rew[n].date << "\n";
	cout << "类型：";
	if (rew[n].pd == 1) cout << "奖\n";
	else cout << "惩\n";
	cout << "\n";
}

int cmp(Rew a, Rew b)
{
	return a.date < b.date;
}

void student()
{
	system("CLS");
	if (sit == 4)
	{
		cout << "当前账号无权进行账号操作\n";
		system("pause");
		return;
	}
	cout << "\t\t\t\t\t************************************" << endl;
	cout << "\t\t\t\t\t*           学生信息管理           *" << endl;
	cout << "\t\t\t\t\t*                                  *" << endl;
	cout << "\t\t\t\t\t*         请操作：                 *" << endl;
	cout << "\t\t\t\t\t*         1.学生信息录入           *" << endl;
	cout << "\t\t\t\t\t*         2.学生信息删除           *" << endl;
	cout << "\t\t\t\t\t*         3.学生信息修改           *" << endl;
	cout << "\t\t\t\t\t*         4.学生信息查询           *" << endl;
	cout << "\t\t\t\t\t*                                  *" << endl;
	cout << "\t\t\t\t\t*                                  *" << endl;
	cout << "\t\t\t\t\t*   注：输入其他数字则退回主菜单   *" << endl;
	cout << "\t\t\t\t\t*                                  *" << endl;
	cout << "\t\t\t\t\t************************************" << endl;
	cout << "请选择要进行的操作：";
	int tr;
	while (cin >> tr)
	{
		if (tr == 1)
		{
			string tr1;
			int tr2;
			cout << "请输入学号：";
			cin >> tr1;
			stu[stu_n].ID = tr1;
			cout << "请输入姓名：";
			cin >> tr1;
			stu[stu_n].name = tr1;
			cout << "请输入专业：";
			cin >> tr1;
			stu[stu_n].major = tr1;
			cout << "请输入电话：";
			cin >> tr1;
			stu[stu_n].cont = tr1;
			cout << "请输入班级（阿拉伯数字）：";
			cin >> tr2;
			stu[stu_n].cla = tr2;
			cout << "请输入公寓（阿拉伯数字）：";
			cin >> tr2;
			stu[stu_n].apa = tr2;
			cout << "请输入寝室号（阿拉伯数字）：";
			cin >> tr2;
			stu[stu_n].room = tr2;
			stu_n++;
			cout << "添加成功！\n";
		}
		else if (tr == 2)
		{
			int now = -1;
			string tr;
			cout << "请输入要删除的学生姓名";
			cin >> tr;
			for (int i = 0; i < stu_n; i++)
			{
				if (stu[i].name == tr) 
				{
					stu[i].dele = 1;
					cout << "删除成功！\n";
					now = 0;
					stu_del++;
					system("pause");
					break;
				}
			}
			if (now == -1) cout << "未查询到相应学生";
		}
		else if (tr == 3)
		{
			int now = -1;
			string tr;
			int tr2;
			cout << "请输入要修改的学生姓名";
			cin >> tr;
			for (int i = 0; i < stu_n; i++)
			{
				if (stu[i].name == tr)
				{
					cout << "请选择要修改的学生信息项：\n";
					cout << "1.学生学号\n";
					cout << "2.学生姓名\n";
					cout << "3.学生专业\n";
					cout << "4.学生电话\n";
					cout << "5.学生班级\n";
					cout << "6.学生寝室号\n";
					cout << "7.学生公寓号\n";
					cin >> tr2;
					if (tr2 == 1)
					{
						cout << "请输入新学号：";
						cin >> tr;
						stu[i].ID = tr;
					}
					else if (tr2 == 2)
					{
						cout << "请输入新姓名：";
						cin >> tr;
						stu[i].name = tr;
					}
					else if (tr2 == 3)
					{
						cout << "请输入新专业：";
						cin >> tr;
						stu[i].major = tr;
					}
					else if (tr2 == 4)
					{
						cout << "请输入新电话：";
						cin >> tr;
						stu[i].cont = tr;
					}
					else if (tr2 == 5)
					{
						cout << "请输入新班级：";
						cin >> tr2;
						stu[i].cla = tr2;
					}
					else if (tr2 == 6)
					{
						cout << "请输入新寝室号：";
						cin >> tr2;
						stu[i].apa = tr2;
					}
					else if (tr2 == 7)
					{
						cout << "请输入新公寓号：";
						cin >> tr2;
						stu[i].room = tr2;
					}
					else cout << "操作有误\n";
					now = 0;
					system("pause");
				}
			}
			if (now == -1) cout << "未查询到相应学生\n";
		}
		else if (tr == 4)
		{
			int now = -1;
			string tr;
			int tr2;
			cout << "请选择要查询的学生信息项：\n";
			cout << "1.学生学号\n";
			cout << "2.学生姓名\n";
			cout << "3.学生专业\n";
			cout << "4.学生电话\n";
			cin >> tr2;
			if (tr2 == 1)
			{
				cout << "请输入学号：";
				cin >> tr;
				for (int i = 0; i < stu_n; i++)
				{
					if (stu[i].ID == tr)
					{
						printstu(i);
						now = 0;
						system("pause");
					}
				}
				if (now == -1) cout << "未找到相应信息\n";
			}
			else if (tr2 == 2)
			{
				cout << "请输入姓名：";
				cin >> tr;
				for (int i = 0; i < stu_n; i++)
				{
					if (stu[i].name == tr)
					{
						printstu(i);
						now = 0;
						system("pause");
					}
				}
				if (now == -1) cout << "未找到相应信息\n";
			}
			else if (tr2 == 3)
			{
				cout << "请输入专业：";
				cin >> tr;
				for (int i = 0; i < stu_n; i++)
				{
					if (stu[i].major == tr)
					{
						printstu(i);
						now = 0;
						system("pause");
					}
				}
				if (now == -1) cout << "未找到相应信息\n";
			}
			else if (tr2 == 4)
			{
				cout << "请输入电话：";
				cin >> tr;
				for (int i = 0; i < stu_n; i++)
				{
					if (stu[i].cont == tr)
					{
						printstu(i);
						now = 0;
						system("pause");
					}
				}
				if (now == -1) cout << "未找到相应信息\n";
			}
			else cout << "操作有误\n";
		}
		else
		{
			welcome();
			return;
		}
		cout << "请选择要进行的操作：";
	}
}

void printstu(int n)
{
	cout << "学号：" << stu[n].ID << "\n";
	cout << "姓名：" << stu[n].name << "\n";
	cout << "专业：" << stu[n].major << "\n";
	cout << "联系方式：" << stu[n].cont << "\n";
	cout << "班级：" << stu[n].cla << "\n";
	cout << "公寓楼：" << stu[n].apa << "\n";
	cout << "宿舍号：" << stu[n].room << "\n";
	cout << "\n";
}
