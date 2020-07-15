# include<stdio.h>
# include<stdlib.h>
# include<assert.h>
# include "Seqlist.h"

//1.初始化,将结构体的三个成员都进行一个初始化
void InitSeq(SqList ps)
{
	//判空
	assert(ps != NULL);
	if(ps == NULL)
	{
		return;
	}
	//开辟SIZE格子的大小
	ps->elem = (int*)malloc(sizeof(int)*SIZE);
	ps->size = SIZE;
	ps->length = 0;
}
//2-1.判断格子是否满了,写为内部函数
static bool IsFull(SqList ps)
{
	return ps->length == ps->size;
}
//2-2.扩容函数
static void ReLength(SqList ps)
{
	ps->elem = (int*)realloc(ps->elem,sizeof(int)*ps->size*2);//表示在原来内存的基础上增加内存
	ps->size *= 2;
}
//2.向pos的位置插入val数值,返回是否插入成功,需要对参数进行判断
bool InsertSeq(SqList ps,int pos,int val)
{
	assert(ps!=NULL);
	if(ps==NULL)
		return false;
	if(pos < 0 || pos > ps->length)
	{
		return false;
	}
	if(IsFull(ps))//判满
	{
		ReLength(ps);//扩容
	}
	//后移插入
	for(int i = ps->length-1;i >= pos;i--)
	{
		ps->elem[i+1]=ps->elem[i];
	}
	ps->elem[pos] = val;
	ps->length++;
	return true;
}
//3.查找从头开始的第一个key,成功返回下标,失败返回-1
int Search(SqList ps,int key)
{
	assert(ps != NULL);
	if(ps == NULL)
		return -1;
	for(int i = 0;i< ps->length;i++)
	{
		if(ps->elem[i] == key)
			return i;
	}
	return -1;
}
//4.删除pos位置的值
bool DeletePos(SqList ps,int pos)
{
	assert(ps != NULL);
	if(ps == NULL)
		return false;
	
	if(pos < 0 || pos > ps->length)
	{
		return false;
	}
	//前移删除
	for(int i = pos;i < ps->length-1; i++)
	{
		ps->elem[i] = ps->elem[i+1];
	}
	ps->length--;//记住，不要忘了。
	return true;
}
//5.删除从头开始的第一个key
bool DeleteVal(SqList ps,int key)
{
	assert(ps != NULL);
	if(ps == NULL)
		return false;
	int pos = Search(ps,key);
	return DeletePos(ps,pos);
}
//6.销毁
void Destroy(SqList ps)
{
	assert(ps != NULL);
	free(ps->elem);
	ps->elem = NULL;
	ps->size = 0;
	ps->length = 0;
}
//打印函数
void Show(SqList ps)
{
	for(int i = 0;i < ps->length;i++)
	{
		printf("%d ",ps->elem[i]);
	}
	printf("\n");
}