#pragma once//��ֹͷ�ļ��ظ�����
# define SIZE 20 //���ӵĴ�С
typedef struct SeqList
{
	int* elem;//ָ��̬�ڴ�ĵ�ַ
	int size;//����˳���Ĵ�С
	int length;//������Ч���ݳ���
}SeqList,*SqList;

//1.��ʼ��
void InitSeq(SqList ps);
//2.��pos��λ�ò���val��ֵ,�����Ƿ����ɹ�
bool InsertSeq(SqList ps,int pos,int val);
//3.���Ҵ�ͷ��ʼ�ĵ�һ��key,�ɹ������±�,ʧ�ܷ���-1
int Search(SqList ps,int key);
//4.ɾ��posλ�õ�ֵ
bool DeletePos(SqList ps,int pos);
//5.ɾ����ͷ��ʼ�ĵ�һ��key
bool DeleteVal(SqList ps,int key);
//6.����
void Destroy(SqList ps);
//7.��ӡ����
void Show(SqList ps);
