#pragma once 

//带头节点的单链表,尾节点的next为NULL
//链表的优点:插入和删除速度快

typedef struct Node
{
	int data;//数据域
	struct Node *next;//指向下一个节点的指针，所以类型必须为节点类型struct Node*
}Node,*List;
//List == Node *

//1.初始化
void InitList(List plist);
//2.头插
bool Insert_Head(List plist,int val);
//3.尾插
bool Insert_Tail(List plist,int val);
//4.删除关键字
bool Delete(List plist,int key);
//5.销毁整个链表
void Destroy(List plist);
//6打印
void Show(List plist);
//7.链表逆置
void Reverse(List plist);//考试的重点*****
void Reverse1(List plist);