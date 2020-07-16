# include<stdio.h>
# include<stdlib.h>
# include<assert.h>
# include "list.h"
//1.初始化
void InitList(List plist)
{
	assert(plist != NULL);
	if(plist == NULL)
	{
		return;
	}
	plist->next = NULL;
}
//2.头插 O(1)
bool Insert_Head(List plist,int val)
{
	assert(plist != NULL);
	if(plist == NULL)
	{
		return false;
	}
	//1.申请节点
	Node* p = (Node*)malloc(sizeof(Node));
	//2.连接后面的
	p->next = plist->next;
	//3.剪短，进行新连接
	plist->next = p;
	p->data = val;
	return true;
}
//3.尾插,最后一个next为NULL,O(N)
bool Insert_Tail(List plist,int val)
{
	assert(plist != NULL);
	if(plist == NULL)
	{
		return false;
	}
	//需要找到最后一个节点
	Node* q = plist;//指向最后一个节点
	while(q->next != NULL)
	{
		q = q->next;
	}
	//连接到最后一个节点q上，申请节点
	Node* p = (Node*)malloc(sizeof(Node));
	q->next = p;
	p->next=NULL;
	p->data=val;
	return true;
}
//4.删除关键字,需要知道这个关键字的前驱才可以删除
bool Delete(List plist,int key)
{
	assert(plist != NULL);
	if(plist == NULL)
	{
		return false;
	}
	//找关键字
	Node* r = plist;//指向关键字的前驱
	Node* q = r->next;//指向关键字
	while(q != NULL)
	{
		if(q->data == key)
		{
			break;
		}
		q = q->next;
		r = r->next;
	}
	//删除，先连接，再释放
	r->next = q->next;
	free(q);
	return true;
}
//5.销毁整个链表,释放每个节点
void Destroy(List plist)
{
	Node* p = plist;//指向链表中的每一个节点，然后释放它
	while(plist->next != NULL)//一直到删除，知道只剩自己
	{
		p = plist->next;
		plist->next = p->next;
		free(p);
	}
}
//6打印
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
//7.链表逆置,按照头插的方式实现
//7-1
void Reverse1(List plist)//考试的重点*****
{
	if(plist == NULL || plist == NULL ||plist->next->next== NULL)
		return;
	/* 比较麻烦，每次通过第一个节点找到下一个节点，从第二个节点开始，将节点插入到头节点后面，因为第一个节点绝对是最后一个。*/
	Node* q = plist->next;
	Node* r = q->next;//把r指向的节点插入到plist的后面，头插
	while(r != NULL)
	{
		q->next=r->next;//第一个指向当前节点的下一个节点
		r->next=plist->next;//当前节点指向头节点原来连着的节点
		plist->next=r;//头节点指向当前节点

		r = q->next;//下一个继续插入的节点
	}
}
//7-2
void Reverse(List plist)
{
	if(plist == NULL || plist == NULL ||plist->next->next== NULL)
		return;
	/*从第一个节点开始，将节点头插入到plist后面*/
	Node* p = plist->next;//已经保存了后面的节点，从一个节点开始
	Node* q;//保存下一个节点
	plist->next=NULL;//头节点断开连接，保证链表最后一个next指向空
	while(p != NULL)
	{
		q=p->next;//指向下一个节点
		p->next=plist->next;//指向头节点的下一个节点
		plist->next=p;//头节点指向插入的节点

		p=q;//下一个节点，继续插入
	}
}
