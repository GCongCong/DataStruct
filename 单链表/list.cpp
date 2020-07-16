# include<stdio.h>
# include<stdlib.h>
# include<assert.h>
# include "list.h"
//1.��ʼ��
void InitList(List plist)
{
	assert(plist != NULL);
	if(plist == NULL)
	{
		return;
	}
	plist->next = NULL;
}
//2.ͷ�� O(1)
bool Insert_Head(List plist,int val)
{
	assert(plist != NULL);
	if(plist == NULL)
	{
		return false;
	}
	//1.����ڵ�
	Node* p = (Node*)malloc(sizeof(Node));
	//2.���Ӻ����
	p->next = plist->next;
	//3.���̣�����������
	plist->next = p;
	p->data = val;
	return true;
}
//3.β��,���һ��nextΪNULL,O(N)
bool Insert_Tail(List plist,int val)
{
	assert(plist != NULL);
	if(plist == NULL)
	{
		return false;
	}
	//��Ҫ�ҵ����һ���ڵ�
	Node* q = plist;//ָ�����һ���ڵ�
	while(q->next != NULL)
	{
		q = q->next;
	}
	//���ӵ����һ���ڵ�q�ϣ�����ڵ�
	Node* p = (Node*)malloc(sizeof(Node));
	q->next = p;
	p->next=NULL;
	p->data=val;
	return true;
}
//4.ɾ���ؼ���,��Ҫ֪������ؼ��ֵ�ǰ���ſ���ɾ��
bool Delete(List plist,int key)
{
	assert(plist != NULL);
	if(plist == NULL)
	{
		return false;
	}
	//�ҹؼ���
	Node* r = plist;//ָ��ؼ��ֵ�ǰ��
	Node* q = r->next;//ָ��ؼ���
	while(q != NULL)
	{
		if(q->data == key)
		{
			break;
		}
		q = q->next;
		r = r->next;
	}
	//ɾ���������ӣ����ͷ�
	r->next = q->next;
	free(q);
	return true;
}
//5.������������,�ͷ�ÿ���ڵ�
void Destroy(List plist)
{
	Node* p = plist;//ָ�������е�ÿһ���ڵ㣬Ȼ���ͷ���
	while(plist->next != NULL)//һֱ��ɾ����֪��ֻʣ�Լ�
	{
		p = plist->next;
		plist->next = p->next;
		free(p);
	}
}
//6��ӡ
void Show(List plist)
{
	Node* q = plist->next;
	while(q != NULL)
	{
		printf("%d ",q->data);
		q = q->next;
	}
	printf("\n");
}
//7.��������,����ͷ��ķ�ʽʵ��
//7-1
void Reverse1(List plist)//���Ե��ص�*****
{
	if(plist == NULL || plist == NULL ||plist->next->next== NULL)
		return;
	/* �Ƚ��鷳��ÿ��ͨ����һ���ڵ��ҵ���һ���ڵ㣬�ӵڶ����ڵ㿪ʼ�����ڵ���뵽ͷ�ڵ���棬��Ϊ��һ���ڵ���������һ����*/
	Node* q = plist->next;
	Node* r = q->next;//��rָ��Ľڵ���뵽plist�ĺ��棬ͷ��
	while(r != NULL)
	{
		q->next=r->next;//��һ��ָ��ǰ�ڵ����һ���ڵ�
		r->next=plist->next;//��ǰ�ڵ�ָ��ͷ�ڵ�ԭ�����ŵĽڵ�
		plist->next=r;//ͷ�ڵ�ָ��ǰ�ڵ�

		r = q->next;//��һ����������Ľڵ�
	}
}
//7-2
void Reverse(List plist)
{
	if(plist == NULL || plist == NULL ||plist->next->next== NULL)
		return;
	/*�ӵ�һ���ڵ㿪ʼ�����ڵ�ͷ���뵽plist����*/
	Node* p = plist->next;//�Ѿ������˺���Ľڵ㣬��һ���ڵ㿪ʼ
	Node* q;//������һ���ڵ�
	plist->next=NULL;//ͷ�ڵ�Ͽ����ӣ���֤�������һ��nextָ���
	while(p != NULL)
	{
		q=p->next;//ָ����һ���ڵ�
		p->next=plist->next;//ָ��ͷ�ڵ����һ���ڵ�
		plist->next=p;//ͷ�ڵ�ָ�����Ľڵ�

		p=q;//��һ���ڵ㣬��������
	}
}
