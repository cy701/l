#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>

typedef struct Node
{
    int data;
    struct Node *npx;//前后两个节点xor运算结果
}Node;


Node * XOR(Node *a,Node * b){

    return (uintptr_t) (a) ^ (uintptr_t)(b);   //ptr是指针的意思，但这种类型不是真的指针，是用来存放指针的 t没有实际含义 
                                                //UINTPTR_MAX 是一个宏常量，表示 uintptr_t 类型的最大值,uintptr_t 类型可以容纳指针的所有位数，因此其最大值可以达到 2^64 - 1
}
/**
 * 用下面代码体现了UINTPTR_DEFINED的作用，用来检擦当前系统是否支持uintptr_t定义
 * #ifdef UINTPTR_DEFINED
    // 使用 uintptr_t 类型的代码
    #else
    // 处理未定义 uintptr_t 类型的情况
    #endif   
 * 
*/


//向xor linked list 添加结点


void insert(Node **head_ref,int data){   //head_ref指向最后一个
    Node *new_node=(Node *)malloc(sizeof(Node));  //新插入的
    new_node->data =data;
    
    new_node->npx=XOR(*head_ref,NULL);
    //该Node不为空，防止出错  下面代码是为新插入的下一个节点做准备
    if(*head_ref!=NULL){
        Node * next =XOR((*head_ref)->npx,NULL);
        (*head_ref)->npx=XOR(new_node,next);  //前^后
    }
    *head_ref=new_node;
}

void printList(Node * head){
    Node *curr=head;
    Node *prev=NULL;
    Node * next;
    while (curr !=NULL)
    {
        printf("%d",curr->data);
        next=XOR(prev,curr->npx);  //curr->npx = prev^next  
        prev=curr;
        curr=next;
    }
    
}



int main(void){
    Node * head=NULL;  //分配好了地址  head 指针作为遍历的起点 head地址代表了链表

    insert(&head,1);
    insert(&head,2);
    insert(&head,3);
    insert(&head,4);

    printList(head);
    printf("1111");

    
    return 0;
}
