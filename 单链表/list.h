#pragma once 

//��ͷ�ڵ�ĵ�����,β�ڵ��nextΪNULL
//������ŵ�:�����ɾ���ٶȿ�

typedef struct Node
{
	int data;//������
	struct Node *next;//ָ����һ���ڵ��ָ�룬�������ͱ���Ϊ�ڵ�����struct Node*
}Node,*List;
//List == Node *

//1.��ʼ��
void InitList(List plist);
//2.ͷ��
bool Insert_Head(List plist,int val);
//3.β��
bool Insert_Tail(List plist,int val);
//4.ɾ���ؼ���
bool Delete(List plist,int key);
//5.������������
void Destroy(List plist);
//6��ӡ
void Show(List plist);
//7.��������
void Reverse(List plist);//���Ե��ص�*****
void Reverse1(List plist);