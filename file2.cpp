#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN 15//������ѧ�ŵ�����ַ��� 
#define N 50//���ѧ������

int n = 0, t = 1;//n����ǰѧ������,t�����������������ִ�У��Լ�������˳�; 

void menu();
void help();
void seek();
void increase();
void del();
void modify();
void save();
void open();

struct student
{
	char StuID[LEN];//ѧ��ѧ�� 
	char Stuname[LEN];
	int Stuage;
	char Stusex;
	float score[3]; //���Ƴɼ�
}stu[N];

int main()
{
	int num;//num�ǲ˵�ѡ�� 
	while (t)//t��ȫ�ֱ�������tuichu����������ѭ���Ƿ���� 
	{
		menu();//������˵����� 
		printf("������˵���ţ�");
		scanf("%d", &num);
		switch (num)
		{
		case 1: help(); break;
		case 2: increase(); break;
		case 3: seek(); break;
		case 4: del(); break;
		case 5: modify(); break;
		case 6: save(); break;
		default:printf("�����������������룡");
		}
	}

	system("pause");
	return 0;
}
void menu()
{
	printf("\n\n");
	printf("*****************************************************\n");
	printf("*-------------------yuekaiyang---------------------\n");
	printf("*                 ѧ����Ϣ����ϵͳ                   *\n");
	printf("*****************************************************\n");
	printf("********************ϵͳ���ܲ˵�*********************\n");
	printf("----------------------     --------------------------\n");
	printf("*****************************************************\n");
	printf("**    1��ʹ�ð���        *     2������ѧ����Ϣ        **\n");
	printf("*****************************************************\n");
	printf("**    3����ѯѧ����Ϣ    *     4��ɾ��ѧ����Ϣ        **\n");
	printf("*****************************************************\n");
	printf("**    5���޸�ѧ����Ϣ    *     6������ѧ����Ϣ        **\n");
	printf("*****************************************************\n");
	printf("**                 7�� �˳�ϵͳ                    **\n");
	printf("----------------------     --------------------------\n");

}

void help()
{
	printf("\n����һ��ѧ����Ϣ����ϵͳ��Ϊ�˰�����������˽�ʹ������������ϸ�Ķ�����ע�����\n");
	printf("\n                  ע������:                    \n ");
	printf("\n       1���������ʾ���в�����\n");
	printf("\n       2������ʹ������ѡ������ѧ����Ϣ��\n");
	printf("\n       3���޸Ļ�������ѧ����Ϣ���мǱ��棡\n");
	printf("\n       4����������д��������޸��ٱ��棡\n");
	printf("\n       5�������ѧ��ʱ���������ַ�����ͬ���Ա𣬱������á�M������,Ů�á�W������!\n");
	printf("\n       6������ʱ��������ļ�����׺��ʹ��.txt,����: stu.txt,ϵͳ����Դ����\n");
	printf("\n          ��ѧ������ϵͳ.exe������ͬĿ¼����һ��.txt�ļ�������ѧ����Ϣ\n");
	printf("\n       7��ѧ����Ϣ������������ѧ�š��Ա����䡢C���Գɼ��������ɼ���Ӣ��ɼ��ȣ�\n");
	printf("\n       8������л����ʹ�ã�\n");
	system("pause");
}

void increase()
{
	int i = n, j, flag, m = 0;//i��������ѧ����Ϣ����������ʱ�̵�ѧ������ 
	printf("\n����������ӵ�ѧ��������\n");
	scanf("%d", &m);
	if (m > 0) 
	{
		do 
		{
			flag = 1;
			while (flag)
			{
				flag = 0;
				printf("�������%dλѧ����ѧ�ţ�\n", i + 1);//�ڼ�λѧ����1��ʼ����,��stu[]���㿪ʼ����Ҫ��1 
				scanf("%s", stu[i].StuID);
				//�ж�ѧ���Ƿ��ظ�
				for (j = 0; j < i; j++) 
				{
					if (strcmp(stu[i].StuID, stu[j].StuID) == 0)
					{
						printf("��ѧ���Ѿ����ڣ����������룡\n");
						flag = 1;
						break;
					}
				}
			}
			printf("�������%dλѧ������:\n", i + 1);
			scanf("%s", stu[i].Stuname);
			printf("�������%dλѧ������:\n", i + 1);
			scanf("%d", &stu[i].Stuage);
			getchar();//������������Ļ��з�����Ȼϵͳ��ѻ��з�����һ���ַ���ֵ���Ա� 
			printf("�������%dλѧ���Ա�:\n", i + 1);
			scanf("%c", &stu[i].Stusex);
			printf("�������%dλѧ����C���Գɼ�:\n", i + 1);
			scanf("%f", &stu[i].score[0]);
			printf("�������%dλѧ���ĸ����ɼ�:\n", i + 1);
			scanf("%f", &stu[i].score[1]);
			printf("�������%dλѧ���Ĵ�ѧӢ��ɼ�:\n", i + 1);
			scanf("%f", &stu[i].score[2]);
			i++;
		} while (i < n + m);//ֻҪ��ǰѧ��������û������Ӻ�����������͵ü������		
	}
	n += m;// �����ɣ�ϵͳ����n��ֵҲҪ���� 
	printf("�����ɣ�����\n");
	system("pause");
}

void seek()
{
	int i, num, flag;
	char s1[LEN + 1];
	printf("*****************************\n");
	printf("**-------1.��ѧ�Ų�ѯ------**\n");
	printf("**-------2.��������ѯ------**\n");
	printf("**-------3.�˳����˵�------**\n");
	printf("*****************************\n");
	while (1)
	{
		flag = 0;
		printf("�������Ӳ˵���");
		scanf("%d", &num);
		switch (num)
		{
		case 1:
			printf("��������Ҫ����ѧ����ѧ�ţ�\n");
			scanf("%s", s1);
			for (i = 0; i < n; i++)
			{
				if (strcmp(stu[i].StuID, s1) == 0)
				{
					flag = 1;
					printf("ѧ��\t\t����\t\t�Ա�\t\t����\t\tC����\t\t����\t\tӢ��\n");
					printf("%s\t\t%s\t\t%c\t\t%d\t\t%.2f\t\t%.2f\t\t%.2f\n", stu[i].StuID, stu[i].Stuname, stu[i].Stusex, stu[i].Stuage, stu[i].score[0], stu[i].score[1], stu[i].score[2]);
				}
			}break;
		case 2:
			printf("��������Ҫ����ѧ����������\n");
			scanf("%s", s1);
			for (i = 0; i < n; i++)
			{
				if (strcmp(stu[i].Stuname, s1) == 0)
				{
					flag = 1;
					printf("ѧ��\t\t����\t\t�Ա�\t\t����\t\tC����\t\t����\t\tӢ��\n");
					printf("%s\t\t%s\t\t%c\t\t%d\t\t%.2f\t\t%.2f\t\t%.2f\n", stu[i].StuID, stu[i].Stuname, stu[i].Stusex, stu[i].Stuage, stu[i].score[0], stu[i].score[1], stu[i].score[2]);
				}
			}break;
		case 3: return;
		default: printf("����1--3֮������\n");
		}
		if (flag == 0)
			printf("�Ҳ�����ѧ��!\n���������룡");
	}
}

void del()
{
	int i, j, flag;
	char s1[LEN];
	printf("��������Ҫɾ����ѧ��ѧ�ţ�\n");
	scanf("%s", s1);
	flag = 0;
	for (i = 0; i < n; i++)
	{
		if (strcmp(s1, stu[i].StuID) == 0)
		{
			flag = 1;
			for (j = i; j < n - 1; j++)
			{
				stu[j] = stu[j + 1];//ֱ�ӰѺ����ѧ������ǰ�ƶ�һλ 
			}
		}
		if (flag == 1) break;//˵���Ѿ��ҵ�����Ҫɾ����ѧ��������ѭ�� 
	}
	if (0 == flag)
	{
		printf("��ѧ�Ų����ڣ�����\n");
	}

	if (1 == flag)
	{
		printf("ɾ���ɹ�\n");
		n--;
	}
	system("pause");
}

void modify()
{
	int i, flag;
	char ID[LEN], name[LEN], sex;
	int age;
	float score;
	printf("��������Ҫ�޸ĵ�ѧ��������\n");
	getchar();
	gets(name);

	while (1)
	{
		flag = 0;
		for (i = 0; i < n; i++)
		{
			if (strcmp(name, stu[i].Stuname) == 0)
			{
				flag = 1;
				int num;//����switch�������Ӳ˵� 
				printf("***************************************************\n");
				printf("*----1.�޸�ѧ��--------  -  -----2.�޸��Ա�-------*\n");
				printf("*----3.�޸�����--------  -  -----4.�޸�C���Գɼ�--*\n");
				printf("*----5.�޸ĸ����ɼ�----  -  -----6.�޸�Ӣ��ɼ�---*\n");
				printf("*-------------------7.�˳����˵�------------------*\n");
				printf("***************************************************\n\n");
				printf("�������Ӳ˵���");
				scanf("%d", &num);
				switch (num)
				{
				case 1:
					printf("�������µ�ѧ��:\n");
					getchar();
					gets(ID);
					strcpy(stu[i].StuID, ID); break;
				case 2:
					getchar();
					printf("�������µ��Ա�:\n");
					scanf("%c", &sex);
					stu[i].Stusex = sex; break;
				case 3:
					printf("�������µ�����:\n");
					scanf("%d", &age);
					stu[i].Stuage = age; break;
				case 4:
					printf("�������µ�C���Գɼ�:\n");
					scanf("%f", &score);
					stu[i].score[0] = score; break;
				case 5:
					printf("�������µĸ����ɼ�:\n");
					scanf("%f", &score);
					stu[i].score[1] = score; break;
				case 6:
					printf("�������µ�Ӣ��ɼ�:\n");
					scanf("%f", &score);
					stu[i].score[2] = score; break;
				case 7:
					return; break;
				default:
					printf("����1--7֮��ѡ��\n");
				}
				if (num > 0 && num < 7)
					printf("�޸ĳɹ����ǵñ���Ӵ������\n");
				break;//�ҵ�ѧ��������ѭ��;	
			}
		}
		if (flag == 0)
		{
			printf("û���ҵ���ѧ����������������Ҫ�޸���Ϣ��ѧ��������\n");
			gets(name);
		}
	}
	system("pause");
}

void save()//��ѧ����Ϣ���浽�ļ� 
{
	int i;
	FILE* fp;
	char filename[LEN + 1];
	printf("������Ҫ������ļ�����\n");
	scanf("%s", filename);
	if ((fp = fopen(filename, "w")) == NULL)
	{
		printf("���ļ�ʧ�ܣ�\n");
		exit(0);
	}
	for (i = 0; i < n; i++)
		if (fwrite(&stu[i], sizeof(struct student), 1, fp) != 1)
			printf("����ʧ�ܣ���\n");
	printf("����ɹ�������\n");
	fclose(fp);
	system("pause");
}

void open()
{
	int h;//�����Ƿ�ȷ���˳� 
	printf("�����˳���ȷ���밴1��ȡ���밴0\n");
	scanf("%d", &h);
	if (h == 1)
	{
		t = 0;//t��main������while�����Ƿ����ִ�еĿ�����������һ��ȫ�ֱ���������ͷ�Ѿ����岢�Ҹ�ֵλ 1
		printf("�ɹ��˳�\n");
	}
	if (h == 0)
	{
		printf("�˳���ȡ��\n");
		system("pause");
	}

}

