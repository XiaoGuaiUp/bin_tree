#pragma once

#include <stddef.h>

#define SeqQueueMaxSize 1000
#define FOR_BINTREE
#ifdef FOR_BINTREE
//struct TreeNode;
#include "bin_tree.h"
typedef struct TreeNode* SeqQueueType;
#else
typedef char SeqQueueType;
#endif

typedef struct SeqQueue{
    SeqQueueType data[SeqQueueMaxSize];
    size_t head;//队首元素的下标
    size_t tail;//队尾元素的下标
    size_t size;//顺序表的长度
} SeqQueue;

//初始化
void SeqQueueInit(SeqQueue* q);
//销毁
void SeqQueueDestroy(SeqQueue* q);
//入队列(尾插)
void SeqQueuePush(SeqQueue* q,SeqQueueType value);
//出队列（头删）
void SeqQueuePop(SeqQueue* q);
//取队首元素
int SeqQueueTop(SeqQueue* q,SeqQueueType* value);
