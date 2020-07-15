# include<stdio.h>
# include<stdlib.h>
# include<assert.h>
# include "Seqlist.h"

//1.��ʼ��,���ṹ���������Ա������һ����ʼ��
void InitSeq(SqList ps)
{
	//�п�
	assert(ps != NULL);
	if(ps == NULL)
	{
		return;
	}
	//����SIZE���ӵĴ�С
	ps->elem = (int*)malloc(sizeof(int)*SIZE);
	ps->size = SIZE;
	ps->length = 0;
}
//2-1.�жϸ����Ƿ�����,дΪ�ڲ�����
static bool IsFull(SqList ps)
{
	return ps->length == ps->size;
}
//2-2.���ݺ���
static void ReLength(SqList ps)
{
	ps->elem = (int*)realloc(ps->elem,sizeof(int)*ps->size*2);//��ʾ��ԭ���ڴ�Ļ����������ڴ�
	ps->size *= 2;
}
//2.��pos��λ�ò���val��ֵ,�����Ƿ����ɹ�,��Ҫ�Բ��������ж�
bool InsertSeq(SqList ps,int pos,int val)
{
	assert(ps!=NULL);
	if(ps==NULL)
		return false;
	if(pos < 0 || pos > ps->length)
	{
		return false;
	}
	if(IsFull(ps))//����
	{
		ReLength(ps);//����
	}
	//���Ʋ���
	for(int i = ps->length-1;i >= pos;i--)
	{
		ps->elem[i+1]=ps->elem[i];
	}
	ps->elem[pos] = val;
	ps->length++;
	return true;
}
//3.���Ҵ�ͷ��ʼ�ĵ�һ��key,�ɹ������±�,ʧ�ܷ���-1
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
//4.ɾ��posλ�õ�ֵ
bool DeletePos(SqList ps,int pos)
{
	assert(ps != NULL);
	if(ps == NULL)
		return false;
	
	if(pos < 0 || pos > ps->length)
	{
		return false;
	}
	//ǰ��ɾ��
	for(int i = pos;i < ps->length-1; i++)
	{
		ps->elem[i] = ps->elem[i+1];
	}
	ps->length--;//��ס����Ҫ���ˡ�
	return true;
}
//5.ɾ����ͷ��ʼ�ĵ�һ��key
bool DeleteVal(SqList ps,int key)
{
	assert(ps != NULL);
	if(ps == NULL)
		return false;
	int pos = Search(ps,key);
	return DeletePos(ps,pos);
}
//6.����
void Destroy(SqList ps)
{
	assert(ps != NULL);
	free(ps->elem);
	ps->elem = NULL;
	ps->size = 0;
	ps->length = 0;
}
//��ӡ����
void Show(SqList ps)
{
	for(int i = 0;i < ps->length;i++)
	{
		printf("%d ",ps->elem[i]);
	}
	printf("\n");
}