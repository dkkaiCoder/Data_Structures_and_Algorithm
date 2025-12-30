//线性表的基本操作:
//InitList(&L)			初始化，建立一个空的线性表
//Destory(&L)			销毁已存在的线性表
//ClearList(&L)			将线性表清空
//ListInsert(&L,i,e)	在线性表L第i个位置插入新元素e
//ListDelete(&L,i,&e)	删除线性表L中第i个元素位置，用e返回
//isEmpty(L)			若线性表为空则返回true 否则返回false
//ListLength(L)			返回线性表L元素个数
//LocateElem(L,e)		在L中查找与给定值e相等的元素，若成功返回该元素在表中的序号，否则返回0



//下面对上述操作进行实现
#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;
typedef int ElemType;

typedef struct {
	ElemType* elem;
	int length;
}SqList;

Status InitList_Sq(SqList* L) {										//构建空的顺序表
	(*L).elem = (ElemType*)calloc(MAX_SIZE,sizeof(ElemType));		//为顺序表分配内存
	if (!(*L).elem)	exit(OVERFLOW);									//存储分配失败
	(*L).length = 0;												//空表长度为0
	return OK;
}

void DestoryList(SqList* L) {										//销毁线性表
	if ((*L).elem) free((*L).elem);									//释放存储内存
}

void ClearList(SqList* L) {											//清空线性表
	(*L).length = 0;												//将线性表的长度置为0
}

int  GetLength(SqList L) {											//求线性表的长度
	return (L.length);												
}

int isEmpty(SqList L) {												//判断线性表是否为空
	if (L.length == 0) return 1;
	return 0;
}

int LocateElem(SqList L, ElemType e) {								//顺序表的查找	在线性表L中查找值为e的数据元素，返回其序号（是第几个元素）
	for (int i = 0; i < L.length; i++) {							
		if (L.elem[i] == e) return i + 1;							//查找成功，返回序号
		return 0;													//查找失败，返回0	
	}
}

//顺序表的插入
//1.判断插入位置i是否合法（1<=i<=n+1）
//2.判断顺序表的存储空间是否已满，若已满返回ERROR
//3.将第n至第i位的元素依次向后移动一个位置，空出第i个位置
//4.将要插入的新元素e放到第i个位置
//5.表长加1,插入成功返回OK
int ListInsert_Sq(SqList* L, int i, ElemType e) {
	if (i<1 || i>(*L).length + 1) return ERROR;						//值不合法
	if ((*L).length == MAX_SIZE)  return ERROR;						//当前存储空间已满
	for (int j = (*L).length - 1; j >= i - 1; j--) {			
		(*L).elem[j + 1] = (*L).elem[j];							//插入位置及之后的元素后移
	}
	(*L).elem[i - 1] = e;											//将新元素放到第i个位置
	(*L).length++;													//表长加1
	return OK;
}

//顺序表的删除
//1.判断删除位置i是否合法
//2.将欲删除的元素保留在e中
//3.将第i+1至第n位的元素依次向前移动一个位置
//4.表长减1，删除成功返回OK
int ListDelete(SqList* L, int i, ElemType* e) {
	if (i<1 || i>(*L).length) return ERROR;
	*e = (*L).elem[i-1];
	for (int j = i - 1; j <= (*L).length-1; j++) {
		(*L).elem[j -1] = (*L).elem[j];
	}
	(*L).length--;
	return OK;
}

