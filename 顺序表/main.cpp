# include<stdio.h>
# include<stdlib.h>
# include<assert.h>
# include "Seqlist.h"


int main()
{
	SeqList ps;
	InitSeq(&ps);
	for(int i=0;i<10;i++)
	{
		InsertSeq(&ps,i,i);
	}
	printf("插入0~9的数值：\n");
	Show(&ps);
	printf("---------------\n");
	int pos= Search(&ps,3);
	printf("查找3的位置为：%d\n",pos);
	printf("---------------\n");
	DeletePos(&ps,pos);
	printf("按照下标删除元素3：\n");
	Show(&ps);
	printf("---------------\n");
	DeleteVal(&ps,5);
	printf("按照元素删除5：\n");

	Show(&ps);
	printf("---------------\n");
	Destroy(&ps);
	printf("销毁\n");
	Destroy(&ps);
	Show(&ps);
}