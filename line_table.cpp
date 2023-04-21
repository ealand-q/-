 #include <stdio.h>
#include<malloc.h>
#include<stddef.h>
//˳���Ļ���������
// ����˳���
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
    printf("�������ݸ���:");
    scanf_s("%d", &n);
    L.length = n;
    printf("��������:");
    for (i = 0; i < n; i++)
    {
        scanf_s("%d", &L.data[i]);
    }
}

void print(SqList L)
{
    int i = 0;
    printf("�������:");
    for (i = 0; i < L.length; i++)
    {
        printf("%d ", L.data[i]);
    }
}

// ����ָ��λ��Ԫ��
void getElem(SqList& L)
{
    int i;
    printf("��������ҵ�Ԫ�ص�λ�ã�");
    scanf_s("%d", &i);
    if (i < 1 || i > L.length)
    {
        printf("�������");
    }
    printf("���ҵ�Ԫ��Ϊ%d",L.data[i - 1]);
}
//����Ԫ��
void insertElem(SqList& L)
{
    int i, x;
    printf("����������Ԫ�ص�λ�ã�");
    scanf_s("%d", &i);
    printf("����������Ԫ�أ�");
    scanf_s("%d", &x);
    if (i < 1 || i > L.length + 1 || L.length >= MAXSIZE)
    {
        printf("�������");
    }
    for (int j = L.length; j >= i; j--)
    {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = x;
    L.length++;
    printf("������˳���Ϊ��");
    print(L);
}
//ɾ��ָ��λ��Ԫ��
void deleteElem(SqList& L)
{

    int i;
    printf("������Ҫɾ����Ԫ�ص�λ�ã�");
    scanf_s("%d", &i); 
    if (i < 1 || i > L.length)
    {
        printf("�������");
    }
    for (int j = i; j < L.length; j++)
    {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    printf("ɾ�����˳���Ϊ��");
    print(L);
}
//�ϲ�����˳���
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
    printf("�ϲ����˳���Ϊ��");
    print(C);  
}
int main()
{
    SqList L;
    init(L);  // ��ʼ��˳���
    int n, i, x;
    input(L);
    getElem(L);
    printf("\n");
    insertElem(L);
    printf("\n");
    deleteElem(L);
    printf("\n");
    printf("��������˳������Ժϲ��±�");
    printf("\n");
    SqList A, B, C;
    init(A);
    init(B);
    printf("�����A");
    input(A);  // ��ʼ��˳���A
    printf("�����B");
    input(B);  // ��ʼ��˳���B
    merge(A, B, C);  // �ϲ�����˳���
    return 0;
}

