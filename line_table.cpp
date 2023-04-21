 #include <stdio.h>
#include<malloc.h>
#include<stddef.h>
//顺序表的基本操作：
// 创建顺序表
#define MAXSIZE 100
#define NULL 0
typedef struct
{
    int data[MAXSIZE];
    int length;
} SqList;

void init(SqList& L)
{
    L.length = 0;
}
void input(SqList& L)
{
    int i, n;
    printf("输入数据个数:");
    scanf_s("%d", &n);
    L.length = n;
    printf("输入数据:");
    for (i = 0; i < n; i++)
    {
        scanf_s("%d", &L.data[i]);
    }
}

void print(SqList L)
{
    int i = 0;
    printf("输出数据:");
    for (i = 0; i < L.length; i++)
    {
        printf("%d ", L.data[i]);
    }
}

// 查找指定位置元素
void getElem(SqList& L)
{
    int i;
    printf("请输入查找的元素的位置：");
    scanf_s("%d", &i);
    if (i < 1 || i > L.length)
    {
        printf("输入错误");
    }
    printf("查找的元素为%d",L.data[i - 1]);
}
//插入元素
void insertElem(SqList& L)
{
    int i, x;
    printf("请输入插入的元素的位置：");
    scanf_s("%d", &i);
    printf("请输入插入的元素：");
    scanf_s("%d", &x);
    if (i < 1 || i > L.length + 1 || L.length >= MAXSIZE)
    {
        printf("输入错误");
    }
    for (int j = L.length; j >= i; j--)
    {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = x;
    L.length++;
    printf("插入后的顺序表为：");
    print(L);
}
//删除指定位置元素
void deleteElem(SqList& L)
{

    int i;
    printf("请输入要删除的元素的位置：");
    scanf_s("%d", &i); 
    if (i < 1 || i > L.length)
    {
        printf("输入错误");
    }
    for (int j = i; j < L.length; j++)
    {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    printf("删除后的顺序表为：");
    print(L);
}
//合并两个顺序表
void merge(SqList A, SqList B, SqList& C)
{
    int i = 0, j = 0, k = 0;
    while (i < A.length && j < B.length)
    {
        if (A.data[i] < B.data[j])
        {
            C.data[k++] = A.data[i++];
        }
        else
        {
            C.data[k++] = B.data[j++];
        }
    }
    while (i < A.length)
    {
        C.data[k++] = A.data[i++];
    }
    while (j < B.length)
    {
        C.data[k++] = B.data[j++];
    }
    C.length = k;
    printf("合并后的顺序表为：");
    print(C);  
}
int main()
{
    SqList L;
    init(L);  // 初始化顺序表
    int n, i, x;
    input(L);
    getElem(L);
    printf("\n");
    insertElem(L);
    printf("\n");
    deleteElem(L);
    printf("\n");
    printf("输入两个顺序表用以合并新表：");
    printf("\n");
    SqList A, B, C;
    init(A);
    init(B);
    printf("输入表A");
    input(A);  // 初始化顺序表A
    printf("输入表B");
    input(B);  // 初始化顺序表B
    merge(A, B, C);  // 合并两个顺序表
    return 0;
}

