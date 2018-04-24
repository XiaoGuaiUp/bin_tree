#include <stdio.h>

#include "seqqueue.h"


//初始化
void SeqQueueInit(SeqQueue* q)
{
    if(q==NULL)
    {
        return;
    }
    q->size=0;
    q->head=0;
    q->tail=0;
    return;
}
//销毁
void SeqQueueDestroy(SeqQueue* q)
{
    if(q==NULL)
    {
        return;
    }
    q->size=0;
    q->head=0;
    q->tail=0;
    return;
}
//入队列(尾插)
void SeqQueuePush(SeqQueue* q,SeqQueueType value)
{
    if(q==NULL)
    {
        return;
    }
    if(q->size>=SeqQueueMaxSize)
    {//满了
        return;
    }
    q->data[q->tail++]=value;
    //加完元素之后，需要再次判断顺序表的长度是否满了
    if(q->tail>=SeqQueueMaxSize)
    {
        q->tail=0;
    }
    //此时入栈一个元素后，需要更新size
    ++q->size;
    return;
}


//出队列（头删）
void SeqQueuePop(SeqQueue* q)
{
    if(q==NULL)
    {
        return;
    }
    if(q->size==0)
    {
        return;
    }
    //出队列：删队首元素，头删
    ++q->head;
    if(q->head>=SeqQueueMaxSize)
    {
        q->head=0;
    }
    --q->size;
    return;
}

//取队首元素
int SeqQueueTop(SeqQueue* q,SeqQueueType* value)
{
    if(q==NULL&&value==NULL)
    {
        return 0;
    }
    if(q->size==0)
    {
        return 0;
    }
    value=&(q->data[q->head]);
    return 1;
}

/////////////////////////////////////////////////////////
//以下为测试函数
///////////////////////////////////////////////////////
#if 0
void SeqPrintChar(SeqQueue* q,const char* msg)
{
    if(q==NULL)
    {
        return;
    }
    printf("[ %s ]\n",msg);
    size_t i=0;
    for(;i<q->size;++i)
    {
        printf("[ %c ]",q->data[q->head+i]);
    }
    printf("\n");
    return;
}

void Test()
{
    printf("========== Test() ============\n");

    SeqQueue q;
    SeqQueueInit(&q);

    printf("测试入对列（尾插) 4 个元素\n");
    SeqQueuePush(&q,'a');
    SeqQueuePush(&q,'b');
    SeqQueuePush(&q,'c');
    SeqQueuePush(&q,'d');
    SeqPrintChar(&q,"入队列尾插4个元素");

    SeqQueuePop(&q);
    SeqPrintChar(&q,"出队列一个元素");
    SeqQueuePop(&q);
    SeqPrintChar(&q,"再出队列一个元素");

    SeqQueueType* value=NULL;
    int ret=SeqQueueTop(&q,value);
    printf("取队首元素的返回值为%d\n",ret);
}


int main()
{
    Test();
    return 0;
}
#endif
