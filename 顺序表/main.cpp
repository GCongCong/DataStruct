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
	printf("����0~9����ֵ��\n");
	Show(&ps);
	printf("---------------\n");
	int pos= Search(&ps,3);
	printf("����3��λ��Ϊ��%d\n",pos);
	printf("---------------\n");
	DeletePos(&ps,pos);
	printf("�����±�ɾ��Ԫ��3��\n");
	Show(&ps);
	printf("---------------\n");
	DeleteVal(&ps,5);
	printf("����Ԫ��ɾ��5��\n");

	Show(&ps);
	printf("---------------\n");
	Destroy(&ps);
	printf("����\n");
	Destroy(&ps);
	Show(&ps);
}