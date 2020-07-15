#pragma once//防止头文件重复包含
# define SIZE 20 //格子的大小
typedef struct SeqList
{
	int* elem;//指向动态内存的地址
	int size;//保存顺序表的大小
	int length;//保存有效数据长度
}SeqList,*SqList;

//1.初始化
void InitSeq(SqList ps);
//2.向pos的位置插入val数值,返回是否插入成功
bool InsertSeq(SqList ps,int pos,int val);
//3.查找从头开始的第一个key,成功返回下标,失败返回-1
int Search(SqList ps,int key);
//4.删除pos位置的值
bool DeletePos(SqList ps,int pos);
//5.删除从头开始的第一个key
bool DeleteVal(SqList ps,int key);
//6.销毁
void Destroy(SqList ps);
//7.打印函数
void Show(SqList ps);
