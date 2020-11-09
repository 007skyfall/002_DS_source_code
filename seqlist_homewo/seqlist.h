#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef int datatype;
typedef int postype;

typedef struct list{
	datatype data[N];
	postype last;
}SeqList,* SeqList_t;

//函数：创建空表的函数；
SeqList_t create_seqlist(void);
//判满
int is_full_seqlist(SeqList_t L);
//判断空
int is_empty_seqlist(SeqList_t L);
//插入数据
int insert_seqlist(SeqList_t L, postype pos, datatype x);
//查看函数
void show_seqlist(SeqList_t L);
//删除函数
int delete_seqlist(SeqList_t L, postype pos);
//释放表函数
void free_seqlist(SeqList_t *L);

//作业１：必须实现
void clear_seqlist(SeqList_t L);
int len_seqlist(SeqList_t L);
//根据位置查找数据
datatype getdata_seqlist(SeqList_t L,postype pos);
//根据数据查找位置
postype loacte_seqlist(SeqList_t L , datatype value);
//根据pos, 修改数据
int change_seqlist(SeqList_t L,postype  pos,datatype value);

//作业２：
//两个表的合并, LA, LB, LA U LB = LA;
int union_seqlist(SeqList_t LA, SeqList_t LB);
//去重: L, 多个相同的数据，去掉, L';
int delre_seqlist(SeqList_t L);

#endif
