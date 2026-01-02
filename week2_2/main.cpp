//链表的基本操作
#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2

//typedef struct {								//数据域
//	char* num;
//	char* name;
//	float score;
//}ElemType;

typedef int ElemType;

typedef int Status;

typedef struct Lnode {							//声明节点的类型和指向节点的指针类型
	ElemType data;								//节点的数据域
	struct Lnode* next;							//节点的指针域
}Lnode,*LinkList;								//LinkList为指向结构体Lnode的指针类型

Status InitList_L(LinkList* L) {				//链表的初始化
	(*L) = (LinkList)malloc(sizeof(Lnode));
	(*L)->next = NULL;
	return OK;
}

int IsEmpty(LinkList L) {						//判断链表是否为空，若L为空返回1，否则返回0
	if (L->next)
		return 0;
	else return 1;
}

Status DestoryList_L(LinkList* L) {				//销毁单链表
	Lnode* p;
	while (L) {
		p = *L;
		*L = (*L)->next;
		free(p);
	}
	return OK;
}

Status ClearList(LinkList* L) {					//将L重置为空表
	Lnode* p, * q;
	p = (*L)->next;
	while (p) {									//没到表尾
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL;							//头节点指针域为空
	return OK;
}

int ListLength_L(LinkList L) {
	Lnode* p;
	p = L->next;
	int i = 0;
	while (p) {
		i++;
		p = p->next;
	}
	return i;
}

Status GetElem_L(LinkList L,int i,ElemType* e) {					//获取线性表L中的某个数据元素的内容，通过变量e返回
	Lnode* p = L ->next;										//初始化
	int j = 1;
	while (p && j < i) {										//向后扫描，直到p指向第i个元素或p为空
		p = p->next;
		++j;
	}
	if (!p || j > i)  return ERROR;								//第i个元素不存在
	*e = p->data;												//去第i个元素
	return OK;
}

Lnode* LocateElem_L1(LinkList L,ElemType e) {						//在线性表L中查找值为e的数据元素
	Lnode* p = L->next;											//找到则返回L中值为e的数据元素的地址,查找失败则返回NULL
	while (p && p->data != e) {									//这里结构体类型不能直接比较，需要自己重新定义一个比较函数
		p = p->next;
	}
	return p;
}

int LocateElem_L2(LinkList L, ElemType e) {						//在线性表L中查找值为e的数据元素的位置序号,返回L中值为e的数据元素的位置，查找失败返回0
	Lnode* p = L->next;											
	int j = 1;
	while (p && p->data != e) {
		p = p->next;
		j++;
	}
	if (p) return j;
	else return 0;
}

//在L中第i个元素之前插入数据元素e
Status ListInsert_L(LinkList* L, int i, ElemType e) {
	Lnode* p = *L;
	int j = 0;
	while (p && j < i - 1) {										//寻找第i-1个结点，p指向第i-1结点
		p = p->next;									
		j++;
	}
	if (!p || j > i - 1) {											//i大于表长+1或者小于1插入位置非法
		return ERROR;
	}

	Lnode* s = (Lnode*)malloc(sizeof(Lnode));					//生成新结点，将结点的数据域置为e
	s->data = e;		
	s->next = p->next;												//将结点插入L中
	p -> next = s;
	return OK;
}

//将线性表中第i个数据元素删除
Status ListDelete_L(LinkList* L,int i,ElemType* e) {
	Lnode* p = *L;
	int j = 0;
	while ((p->next) && j < i - 1) {								//寻找第i个结点，并令p指向其前驱
		p = p->next;
		j++;
	}
	if (!(p->next) || j > i - 1) return ERROR;						//删除位置不合理
	Lnode* q = p->next;												//临时保存被删结点的地址以备释放
	p->next = q->next;												//改变删除结点前驱结点的指针域
	*e = q->data;													//保存删除结点的数据域
	free(q);														//释放删除结点的空间
	return OK;
}

//头插法建立单链表
void CreateList_H(LinkList* L, int n) {
	*L = (Lnode*)malloc(sizeof(Lnode));								//先建立一个带头结点的单链表
	(*L)->next = NULL;
	for (int i = n; i > 0; i--) {
		Lnode* p = (Lnode*)malloc(sizeof(Lnode));					//生成新结点
		scanf("%d",&(p->data));										//输入元素值			
		p->next = (*L)->next;										//插入到表头
		(*L)->next = p;
	}
}

//尾插法建立单链表
void CreateList_R(LinkList* L, int n) {								//正位序输入n个元素的值，建立带表头结点的单链表L
	(*L) = (Lnode*)malloc(sizeof(Lnode));
	(*L)->next = NULL;
	Lnode* r = (*L);												//尾指针r指向头结点
	for (int i = 0; i < n; i++) {
		Lnode* p = (Lnode*)malloc(sizeof(Lnode));					//生成新结点，输入元素值
		scanf("%d",&(p->data));
		p->next = NULL;
		r->next = p;												//插入到表尾
		r = p;														//指向新的尾结点
	}
}

//带尾指针的循环链表的合并
LinkList Connect(LinkList Ta, LinkList Tb) {						//假设Ta Tb都是非空的单循环链表
	Lnode* p = Ta->next;											//p存表头结点
	Ta->next = Tb->next->next;										//Tb表头连接Ta表尾
	free(Tb->next);													//释放Tb表头结点
	Tb->next = p;													//修改指针
	return Tb;
}