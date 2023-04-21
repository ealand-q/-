#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
//定义单链表节点结构体
typedef struct node {

	int data;

	node* next;

}node;
//输出链表
void print(node* head) {

	node* p;

	p = (node*)malloc(sizeof(node));//给p分配内存空间，使它可以存放数据 

	p = head->next;//让p指向开始节点 

	printf("输出单链表里的所有元素：");

	while (p != NULL) {//当p不是空表时执行下面语句 

		printf("%d ", p->data);

		p = p->next;
	}

}
//尾插法创建链表 
node* create() {

	node* p, * q, * head;//定义三个指针，其中p用来存放所输入的链表数据 

	int n;//表示想要输入的链表数据个数 

	int i = 0;//表示已经输入的链表数据个数

	head = (node*)malloc(sizeof(node));//创建头节点

	head->next = NULL;//初始化链表，让它为空表 

	q = head;//q始终指向尾节点，开始时头节点和尾节点时同一个

	printf("你想要输入多少个数据：");

	scanf_s("%d", &n);

	printf("请输入数字：");

	for (i = 0; i < n; i++) {

		p = (node*)malloc(sizeof(node));//创建数据节点，让输入的数据先存放在p里面 

		scanf_s("%d", &p->data);// 输入链表数据 

		p->next = q->next;

		q->next = p;

		q = p;
	}
	print(head);
	return head;

}
//计算单链表的长度 
int ListLength(node* head) {

	printf("\n");

	node* p = head;//让p指向头节点 

	int i = 0;

	while (p->next != NULL) {//当p的后继节点不为空时执行下面语句 

		p = p->next;

		i++;//执行一次循环加1，直到p的后继节点为空时跳出循环 

	}

	printf("单链表的长度：%d", i);

	return 0;
}
//按元素值查找 
int LoacteElem(node* head)
 {

	printf("\n");

	node* p = head;//让p指向头节点 

	int j = 0, e;

	printf("输入要查找的数据值：");

	scanf_s("%d", &e);

	while (p->next != NULL && p->data != e) {

		p = p->next;

		j++;

	}

	printf("查找的数据的位置：%d", j);

	return 0;
}
//查找元素
int GetElem(node* head) { 

	printf("\n");

	int i, e, m;//i的作用相当于指针遍历到第几个节点、e表示想要查找第几个位置的元素、m表示找到想要查找的数据的值） 

	node* p = head;

	printf("请输入要查找数据的位置：");

	scanf_s("%d", &e);

	for (i = 0; i < e; i++) {

		p = p->next;

	}

	m = p->data;

	printf("位置为%d的数据是%d", e, m);

	return 0;
}
//插入元素 
node* Insert(node* head) {

	printf("\n");

	node* p = head;

	node* q;

	int j = 0, i, e;//同样，j表示指针p遍历到链表数据的位置，i、e表示要在第i个位置插入数据e） 

	printf("输入要插入的元素的位置：");

	scanf_s("%d", &i);

	printf("输入要插入的元素的值：");

	scanf_s("%d", &e);

	for (j = 0; j < i - 1; j++) {

		p = p->next;

	}

	q = (node*)malloc(sizeof(node));

	q->data = e; 

	q->next = p->next;

	p->next = q;

	return head;

}
//删除元素 
node* Delete(node* head) {

	printf("\n");

	node* p = head;

	node* q, * r;

	int j = 0, i;//j表示指针p遍历到链表的第几个数据，i表示删除第i个位置的数据 

	printf("请输入删除数据的位置：");

	scanf_s("%d", &i);

	for (j = 0; j < i - 1; j++) {

		p = p->next;

	}

	q = (node*)malloc(sizeof(node));

	q = p;

	r = q->next;

	p->next = r->next;

	return head;
}
//合并
node* merge(node* head1, node* head2, node* head3)
{
	node* p1, * p2, * p3;
	p1 = head1->next, 
	p2 = head2->next; 
	head3 = head1;
	p3 = head3;//从第一个有数值的结点开始比较 
	while (p1 && p2 )//当两表都没遍历完 
	{
		if (p1->data <= p2->data)
		{
			p3->next = p1;
			p3 = p1;
			p1 = p1->next;
		}
		else
		{
			p3->next = p2;
			p3 = p2;
			p2 = p2->next;
		}
	}
	if (p1 != NULL) p3->next = p1;//表二空了，直接接上表一 
	if (p2 != NULL) p3->next = p2;//表一空了，接上表二 
	delete head2;
	return head3;
}
int main() {

	node* head;

	node* head_;
	
	node* c{};
	
	head = create();//调用创建链表函数（尾插法） 

	print(head);//调用输出函数，输出链表的所有数据 

	ListLength(head);//求链表的长度 

	LoacteElem(head);//按数据值查找（第n个数据的位置是第m个） 

	GetElem(head);//查找数据（第n个位置的数据是第m个） 

	Insert(head);//调用插入函数 

	print(head);//输出插入后的链表 

	Delete(head);//调用删除函数 

	print(head);//输出删除后的链表 

	printf("\n");

	printf("输入list——1");

	head = create();//调用创建链表函数（尾插法）

	printf("\n");

	printf("输入list——2");

	head_ = create();//调用创建链表函数（尾插法） 
	
	printf("\n");
	print(merge(head,head_,c));

	printf("\n");

	return 0;
}
