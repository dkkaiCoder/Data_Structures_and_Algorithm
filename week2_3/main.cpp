#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0

typedef int ElemType;
typedef struct DuLNode {
	ElemType data;
	struct DuLNode* prior, * next;
}DuLNode,*DuLinkList;

typedef int Status;

//初始化双向链表
Status InitDuLinkList_DuL(DuLinkList* L) {
	L = (DuLinkList*)malloc(sizeof(DuLNode));
	if (!L) return ERROR;
	(*L)->prior = NULL;
	(*L)->prior = NULL;
	return OK;
}

//判断双向链表是否为空
int IsEmpty(DuLinkList L) {
	return L->next == NULL;
}

//销毁双向链表
Status DestoryLis_DuL(DuLinkList* L) {
	DuLNode* p ;
	while (p) {
		p = *L;
		(*L) = (*L)->next;
		p->prior = NULL;
		p->next = NULL;
		free(p);
	}
	return OK;
}

//双向链表的插入
Status  ListInsert_DuL(DuLinkList* L,int i,ElemType e) {
	DuLNode* p = (*L);
	int j = 0;
	while (p&&j<i-1) {
		p = p->next;
		j++;
	}
	if (!p || j > i - 1) return ERROR;
	DuLNode* q = (DuLNode*)malloc(sizeof(DuLNode));
	q->data = e;
	q->next = NULL;
	q->prior = p;
	q->next = p->next;
	p->next->prior = q;
	p->next = q;
	return OK;
}


//双向链表的删除
Status ListDelete_DuL(DuLinkList* L,int i,ElemType* e) {
	DuLNode* p=(*L);
	int j = 0;
	while (p && j < i ) {
		p = p->next;
		j++;
	}
	if (!p || j > i ) return ERROR;
	*e = p->data;
	p->next->prior = p->prior;
	p->prior->next= p->next;
	free(p);
	return OK;
}