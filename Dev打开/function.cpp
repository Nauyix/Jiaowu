#include "resource.h"
int stu_n, rew_n, acc_n, sit=-1;
int stu_del=0, rew_del=0, acc_del=0;
//�û�Ȩ�ޣ�1Ϊ����Ա��2Ϊ��ʦ��3Ϊ����Ա��4Ϊѧ��
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
		//Ϊ�˱����Ű棬�ֳ�����д,��ͬ
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
	cout << "�������˺ţ�";
	cin >> name_tr;
	cout << "���������룺";
	cin >> pwd_tr;
	for (int i = 0; i < acc_n; i++)
	{
		if (name_tr == acc[i].acc&&pwd_tr == acc[i].pwd)
		{
			sit = acc[i].auth;
			return;
		}
	}
	cout << "�˺Ż������������\n";
}

void welcome()
{
	system("CLS");
	cout << "\t\t\t\t\t************************************" << endl;
	cout << "\t\t\t\t\t*         ѧ�����͹���ϵͳ         *" << endl;
	cout << "\t\t\t\t\t*                     V1.0         *" << endl;
	cout << "\t\t\t\t\t*         �������                 *" << endl;
	cout << "\t\t\t\t\t*         1.�˺Ź���               *" << endl;
	cout << "\t\t\t\t\t*         2.���͹���               *" << endl;
	cout << "\t\t\t\t\t*         3.ѧ������               *" << endl;
	cout << "\t\t\t\t\t*         4.�˳�����               *" << endl;
	cout << "\t\t\t\t\t*                                  *" << endl;
	cout << "\t\t\t\t\t*  ע����������������Ϊ�˳�ϵͳ    *" << endl;
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
		//Ϊ�˱����Ű棬�ֳ�����д,��ͬ
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
		cout << "��ǰ�˺���Ȩ�����˺Ų���\n";
		system("pause");
		return;
	}
	cout << "\t\t\t\t\t************************************" << endl;
	cout << "\t\t\t\t\t*             �˺Ź���             *" << endl;
	cout << "\t\t\t\t\t*                                  *" << endl;
	cout << "\t\t\t\t\t*         �������                 *" << endl;
	cout << "\t\t\t\t\t*         1.�˺�����               *" << endl;
	cout << "\t\t\t\t\t*         2.�˺�ɾ��               *" << endl;
	cout << "\t\t\t\t\t*         3.�����޸�               *" << endl;
	cout << "\t\t\t\t\t*                                  *" << endl;
	cout << "\t\t\t\t\t*                                  *" << endl;
	cout << "\t\t\t\t\t*   ע�����������������˻����˵�   *" << endl;
	cout << "\t\t\t\t\t*                                  *" << endl;
	cout << "\t\t\t\t\t************************************" << endl;
	int tr;
	cout << "��ѡ��Ҫ���еĲ�����";
	while (cin >> tr)
	{
		if (tr == 1)
		{
			cout << "������Ҫ��ӵ��˺ţ�";
			cin >> acc[acc_n].acc;
			cout << "���������룺";
			cin >> acc[acc_n].pwd;
			cout << "�������û���� 1Ϊ����Ա��2Ϊ��ʦ��3Ϊ����Ա��4Ϊѧ��\n";
			cin >> acc[acc_n].auth;
			acc_n++;
			cout << "��ӳɹ���\n";
			system("pause");
		}
		else if (tr == 2)
		{
			cout << "������Ҫɾ���˺ŵ��û���";
			string tr;
			cin >> tr;
			for (int i = 0; i < acc_n; i++)
			{
				if (acc[i].acc == tr) acc[i].dele = 1;
				cout << "ɾ���ɹ���\n";
				acc_del++;
				system("pause");
				break;
			}
		}
		else if (tr == 3)
		{
			cout << "������Ҫ�޸�������˺ŵ��û���";
			string tr;
			cin >> tr;
			for (int i = 0; i < acc_n; i++)
			{
				if (acc[i].acc == tr)
				{
					string tr2;
					cout << "���ҵ���Ӧ�˺ţ�������Ҫ�޸ĵ����룺";
					cin >> tr2;
					acc[i].pwd = tr2;
					cout << "�޸ĳɹ���\n";
					system("pause");
					break;
				}
			}
			cout << "δ�ҵ���Ӧ�˺�\n";
			system("pause");
			break;
		}
		else
		{
			welcome();
			return;
		}
		cout << "��ѡ��Ҫ���еĲ�����";
	}
}

void reward()
{
	system("CLS");
	cout << "\t\t\t\t\t************************************" << endl;
	cout << "\t\t\t\t\t*             ���͹���             *" << endl;
	cout << "\t\t\t\t\t*                                  *" << endl;
	cout << "\t\t\t\t\t*         �������                 *" << endl;
	cout << "\t\t\t\t\t*         1.��������               *" << endl;
	cout << "\t\t\t\t\t*         2.����ɾ��               *" << endl;
	cout << "\t\t\t\t\t*         3.�����޸�               *" << endl;
	cout << "\t\t\t\t\t*         4.���Ͳ�ѯ               *" << endl;
	cout << "\t\t\t\t\t*                                  *" << endl;
	cout << "\t\t\t\t\t*                                  *" << endl;
	cout << "\t\t\t\t\t*   ע�����������������˻����˵�   *" << endl;
	cout << "\t\t\t\t\t*                                  *" << endl;
	cout << "\t\t\t\t\t************************************" << endl;
	cout << "��ѡ��Ҫ���еĲ�����";
	int tr,tr1,tr3;
	string tr2;
	while (cin >> tr)
	{
		if (tr == 1)
		{
			if (sit == 4)
			{
				cout << "��ǰ�û�û�н��иò�����Ȩ��\n";
				continue;
			}
			cout << "�����뱻����/�ͷ���ѧ��ѧ�ţ�";
			cin >> rew[rew_n].ID;
			cout << "�����뱻����/�ͷ���ȫ�ƣ�";
			cin >> rew[rew_n].name;
			//cout << rew[rew_n].name<<"\n";
			cout << "������䷢�ý���/�ͷ�����֯��";
			cin >> rew[rew_n].org;
			//cout << rew[rew_n].org << "\n";
			cout << "������ý���/�ͷ��ĵȼ���";
			cin >> rew[rew_n].level;
			cout << "�����뱻����/�ͷ������ڣ�";
			cin >> rew[rew_n].date;
			cout << "���¼����Ϊ������������1�����Ϊ�ͷ���������2��";
			cin >> rew[rew_n].pd;
			rew_n++;
			cout << "¼��ɹ���\n";
			system("pause");
		}
		else if (tr == 2)
		{
			if (sit == 4)
			{
				cout << "��ǰ�û�û�н��иò�����Ȩ��\n";
				continue;
			}
			int tot = 0;
			cout << "������Ҫɾ���Ľ���/�ͷ�����ѧ����ѧ�ţ�";
			cin >> tr2;
			for (int i = 0; i < rew_n; i++)
			{
				if (rew[i].ID == tr2)
				{
					tot++;
					printrew(i);
				}
			}
			if (tot == 0) cout << "δ��ѯ�������н���/�ͷ�\n";
			else
			{
				cout << "����Ϊ�������еĽ���/�ͷ���������Ҫɾ������ţ�";
				cin >> tr1;
				rew[tr1].dele = 1;
				cout << "ɾ���ɹ���\n";
				system("pause");
			}
		}
		else if (tr == 3)
		{
			if (sit == 4)
			{
				cout << "��ǰ�û�û�н��иò�����Ȩ��\n";
				continue;
			}
			int tot = 0;
			cout << "������Ҫ�޸ĵĽ���/�ͷ�����ѧ����ѧ�ţ�";
			cin >> tr2;
			for (int i = 0; i < rew_n; i++)
			{
				if (rew[i].ID == tr2)
				{
					tot++;
					printrew(i);
				}
			}
			if (tot == 0) cout << "δ��ѯ�������н���/�ͷ�\n";
			else
			{
				cout << "����Ϊ�������еĽ���/�ͷ���������Ҫ�޸ĵ���ţ�";
				cin >> tr1;
				cout << "������Ҫ�޸ĵ����ݣ�\n";
				cout << "1.����ѧ��ID\n";
				cout << "2.����/�ͷ�����\n";
				cout << "3.����/�ͷ��䷢��֯\n";
				cout << "4.����/�ͷ��ȼ�\n";
				cout << "5.����/�ͷ��䷢����\n";
				cin >> tr3;
				if (tr3 == 1)
				{
					cout << "�������޸ĺ�����ѧ��ID��";
					cin >> rew[tr1].ID;
					cout << "�޸ĳɹ���\n";
				}
				else if (tr3 == 2)
				{
					cout << "�������޸ĺ�����ƣ�";
					cin >> rew[tr1].name;
					cout << "�޸ĳɹ���\n";
				}
				else if (tr3 == 3)
				{
					cout << "�������޸ĺ����֯����";
					cin >> rew[tr1].org;
					cout << "�޸ĳɹ���\n";
				}
				else if (tr3 == 4)
				{
					cout << "�������µĵȼ���";
					cin >> rew[tr1].level;
					cout << "�޸ĳɹ���\n";
				}
				else if (tr3 == 5)
				{
					cout << "�����������ڣ�";
					cin >> rew[tr1].date;
					cout << "�޸ĳɹ���\n";
				}
				else cout << "���������޸Ĳ��ɹ�\n";
				system("pause");
			}
		}
		else if (tr == 4)
		{
			cout << "��ѡ�������\n";
			cout << "1.��ѯĳһѧ�����н�����Ϣ\n";
			cout << "2.�������ڷ�Χ��ѯ��Χ�����н�����Ϣ\n";
			cin >> tr1;
			int reward=0, punishment=0;
			if (tr1 == 1)
			{
				int tot = 0;
				cout << "������Ҫ��ѯ�Ľ���/�ͷ�����ѧ����ѧ�ţ�";
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
				if (tot == 0) cout << "δ��ѯ�������н���/�ͷ�\n";
				else
				{
					printf("��������%d��������Ϣ�����н���%d�����ͷ�%d��\n", tot, reward, punishment);
				}
			}
			else if (tr1 == 2)
			{
				int begin = 0, end = 0, tot = 0;
				cout << "��������ֹ���ڣ���20100102 20200202\n";
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
				printf("��ʱ��ι���%d��������Ϣ�����н���%d�����ͷ�%d��\n", tot, reward, punishment);
			}
			else cout << "��������\n";
		}
		else
		{
			welcome();
			return;
		}
		cout << "��ѡ��Ҫ���еĲ�����";
	}
}

void printrew(int n)
{
	cout << "��ţ�" << n << "\n";
	cout << "����ѧ��ID��" << rew[n].ID << "\n";
	cout << "���ƣ�" << rew[n].name << "\n";
	cout << "�䷢��֯��" << rew[n].org << "\n";
	cout << "�ȼ���" << rew[n].level << "\n";
	cout << "���ڣ�" << setfill('0') << setw(8) << rew[n].date << "\n";
	cout << "���ͣ�";
	if (rew[n].pd == 1) cout << "��\n";
	else cout << "��\n";
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
		cout << "��ǰ�˺���Ȩ�����˺Ų���\n";
		system("pause");
		return;
	}
	cout << "\t\t\t\t\t************************************" << endl;
	cout << "\t\t\t\t\t*           ѧ����Ϣ����           *" << endl;
	cout << "\t\t\t\t\t*                                  *" << endl;
	cout << "\t\t\t\t\t*         �������                 *" << endl;
	cout << "\t\t\t\t\t*         1.ѧ����Ϣ¼��           *" << endl;
	cout << "\t\t\t\t\t*         2.ѧ����Ϣɾ��           *" << endl;
	cout << "\t\t\t\t\t*         3.ѧ����Ϣ�޸�           *" << endl;
	cout << "\t\t\t\t\t*         4.ѧ����Ϣ��ѯ           *" << endl;
	cout << "\t\t\t\t\t*                                  *" << endl;
	cout << "\t\t\t\t\t*                                  *" << endl;
	cout << "\t\t\t\t\t*   ע�����������������˻����˵�   *" << endl;
	cout << "\t\t\t\t\t*                                  *" << endl;
	cout << "\t\t\t\t\t************************************" << endl;
	cout << "��ѡ��Ҫ���еĲ�����";
	int tr;
	while (cin >> tr)
	{
		if (tr == 1)
		{
			string tr1;
			int tr2;
			cout << "������ѧ�ţ�";
			cin >> tr1;
			stu[stu_n].ID = tr1;
			cout << "������������";
			cin >> tr1;
			stu[stu_n].name = tr1;
			cout << "������רҵ��";
			cin >> tr1;
			stu[stu_n].major = tr1;
			cout << "������绰��";
			cin >> tr1;
			stu[stu_n].cont = tr1;
			cout << "������༶�����������֣���";
			cin >> tr2;
			stu[stu_n].cla = tr2;
			cout << "�����빫Ԣ�����������֣���";
			cin >> tr2;
			stu[stu_n].apa = tr2;
			cout << "���������Һţ����������֣���";
			cin >> tr2;
			stu[stu_n].room = tr2;
			stu_n++;
			cout << "��ӳɹ���\n";
		}
		else if (tr == 2)
		{
			int now = -1;
			string tr;
			cout << "������Ҫɾ����ѧ������";
			cin >> tr;
			for (int i = 0; i < stu_n; i++)
			{
				if (stu[i].name == tr) 
				{
					stu[i].dele = 1;
					cout << "ɾ���ɹ���\n";
					now = 0;
					stu_del++;
					system("pause");
					break;
				}
			}
			if (now == -1) cout << "δ��ѯ����Ӧѧ��";
		}
		else if (tr == 3)
		{
			int now = -1;
			string tr;
			int tr2;
			cout << "������Ҫ�޸ĵ�ѧ������";
			cin >> tr;
			for (int i = 0; i < stu_n; i++)
			{
				if (stu[i].name == tr)
				{
					cout << "��ѡ��Ҫ�޸ĵ�ѧ����Ϣ�\n";
					cout << "1.ѧ��ѧ��\n";
					cout << "2.ѧ������\n";
					cout << "3.ѧ��רҵ\n";
					cout << "4.ѧ���绰\n";
					cout << "5.ѧ���༶\n";
					cout << "6.ѧ�����Һ�\n";
					cout << "7.ѧ����Ԣ��\n";
					cin >> tr2;
					if (tr2 == 1)
					{
						cout << "��������ѧ�ţ�";
						cin >> tr;
						stu[i].ID = tr;
					}
					else if (tr2 == 2)
					{
						cout << "��������������";
						cin >> tr;
						stu[i].name = tr;
					}
					else if (tr2 == 3)
					{
						cout << "��������רҵ��";
						cin >> tr;
						stu[i].major = tr;
					}
					else if (tr2 == 4)
					{
						cout << "�������µ绰��";
						cin >> tr;
						stu[i].cont = tr;
					}
					else if (tr2 == 5)
					{
						cout << "�������°༶��";
						cin >> tr2;
						stu[i].cla = tr2;
					}
					else if (tr2 == 6)
					{
						cout << "�����������Һţ�";
						cin >> tr2;
						stu[i].apa = tr2;
					}
					else if (tr2 == 7)
					{
						cout << "�������¹�Ԣ�ţ�";
						cin >> tr2;
						stu[i].room = tr2;
					}
					else cout << "��������\n";
					now = 0;
					system("pause");
				}
			}
			if (now == -1) cout << "δ��ѯ����Ӧѧ��\n";
		}
		else if (tr == 4)
		{
			int now = -1;
			string tr;
			int tr2;
			cout << "��ѡ��Ҫ��ѯ��ѧ����Ϣ�\n";
			cout << "1.ѧ��ѧ��\n";
			cout << "2.ѧ������\n";
			cout << "3.ѧ��רҵ\n";
			cout << "4.ѧ���绰\n";
			cin >> tr2;
			if (tr2 == 1)
			{
				cout << "������ѧ�ţ�";
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
				if (now == -1) cout << "δ�ҵ���Ӧ��Ϣ\n";
			}
			else if (tr2 == 2)
			{
				cout << "������������";
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
				if (now == -1) cout << "δ�ҵ���Ӧ��Ϣ\n";
			}
			else if (tr2 == 3)
			{
				cout << "������רҵ��";
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
				if (now == -1) cout << "δ�ҵ���Ӧ��Ϣ\n";
			}
			else if (tr2 == 4)
			{
				cout << "������绰��";
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
				if (now == -1) cout << "δ�ҵ���Ӧ��Ϣ\n";
			}
			else cout << "��������\n";
		}
		else
		{
			welcome();
			return;
		}
		cout << "��ѡ��Ҫ���еĲ�����";
	}
}

void printstu(int n)
{
	cout << "ѧ�ţ�" << stu[n].ID << "\n";
	cout << "������" << stu[n].name << "\n";
	cout << "רҵ��" << stu[n].major << "\n";
	cout << "��ϵ��ʽ��" << stu[n].cont << "\n";
	cout << "�༶��" << stu[n].cla << "\n";
	cout << "��Ԣ¥��" << stu[n].apa << "\n";
	cout << "����ţ�" << stu[n].room << "\n";
	cout << "\n";
}
