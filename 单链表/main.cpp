# include<stdio.h>
# include<stdlib.h>
# include<assert.h>
# include "Seqlist.h"
# include "list.h"

int main()
{
	/*SeqList ps;
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
	Show(&ps);*/
	Node plist;
	InitList(&plist);
	for(int i=0;i<10;i++)
	{
		Insert_Head(&plist,i);
	}
	printf("ǰ����0~9����ֵ��\n");
	Show(&plist);
	printf("---------------\n");
	Destroy(&plist);
	Destroy(&plist);
	printf("����\n");
	Show(&plist);
	for(int i=0;i<10;i++)
	{
		Insert_Tail(&plist,i);
	}
	printf("���ٺ�,β����0~9����ֵ��\n");
	Show(&plist);
	printf("---------------\n");
	Delete(&plist,0);
	printf("ɾ��Ԫ��0��\n");
	Show(&plist);
	printf("---------------\n");
	Reverse1(&plist);
	printf("��һ�ְ취���õ�����\n");
	Show(&plist);
	printf("---------------\n");
	Reverse(&plist);
	printf("�ڶ��ְ취���õ�����\n");
	Show(&plist);
	printf("---------------\n");

}