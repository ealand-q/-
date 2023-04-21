#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
//���嵥����ڵ�ṹ��
typedef struct node {

	int data;

	node* next;

}node;
//�������
void print(node* head) {

	node* p;

	p = (node*)malloc(sizeof(node));//��p�����ڴ�ռ䣬ʹ�����Դ������ 

	p = head->next;//��pָ��ʼ�ڵ� 

	printf("����������������Ԫ�أ�");

	while (p != NULL) {//��p���ǿձ�ʱִ��������� 

		printf("%d ", p->data);

		p = p->next;
	}

}
//β�巨�������� 
node* create() {

	node* p, * q, * head;//��������ָ�룬����p���������������������� 

	int n;//��ʾ��Ҫ������������ݸ��� 

	int i = 0;//��ʾ�Ѿ�������������ݸ���

	head = (node*)malloc(sizeof(node));//����ͷ�ڵ�

	head->next = NULL;//��ʼ����������Ϊ�ձ� 

	q = head;//qʼ��ָ��β�ڵ㣬��ʼʱͷ�ڵ��β�ڵ�ʱͬһ��

	printf("����Ҫ������ٸ����ݣ�");

	scanf_s("%d", &n);

	printf("���������֣�");

	for (i = 0; i < n; i++) {

		p = (node*)malloc(sizeof(node));//�������ݽڵ㣬������������ȴ����p���� 

		scanf_s("%d", &p->data);// ������������ 

		p->next = q->next;

		q->next = p;

		q = p;
	}
	print(head);
	return head;

}
//���㵥����ĳ��� 
int ListLength(node* head) {

	printf("\n");

	node* p = head;//��pָ��ͷ�ڵ� 

	int i = 0;

	while (p->next != NULL) {//��p�ĺ�̽ڵ㲻Ϊ��ʱִ��������� 

		p = p->next;

		i++;//ִ��һ��ѭ����1��ֱ��p�ĺ�̽ڵ�Ϊ��ʱ����ѭ�� 

	}

	printf("������ĳ��ȣ�%d", i);

	return 0;
}
//��Ԫ��ֵ���� 
int LoacteElem(node* head)
 {

	printf("\n");

	node* p = head;//��pָ��ͷ�ڵ� 

	int j = 0, e;

	printf("����Ҫ���ҵ�����ֵ��");

	scanf_s("%d", &e);

	while (p->next != NULL && p->data != e) {

		p = p->next;

		j++;

	}

	printf("���ҵ����ݵ�λ�ã�%d", j);

	return 0;
}
//����Ԫ��
int GetElem(node* head) { 

	printf("\n");

	int i, e, m;//i�������൱��ָ��������ڼ����ڵ㡢e��ʾ��Ҫ���ҵڼ���λ�õ�Ԫ�ء�m��ʾ�ҵ���Ҫ���ҵ����ݵ�ֵ�� 

	node* p = head;

	printf("������Ҫ�������ݵ�λ�ã�");

	scanf_s("%d", &e);

	for (i = 0; i < e; i++) {

		p = p->next;

	}

	m = p->data;

	printf("λ��Ϊ%d��������%d", e, m);

	return 0;
}
//����Ԫ�� 
node* Insert(node* head) {

	printf("\n");

	node* p = head;

	node* q;

	int j = 0, i, e;//ͬ����j��ʾָ��p�������������ݵ�λ�ã�i��e��ʾҪ�ڵ�i��λ�ò�������e�� 

	printf("����Ҫ�����Ԫ�ص�λ�ã�");

	scanf_s("%d", &i);

	printf("����Ҫ�����Ԫ�ص�ֵ��");

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
//ɾ��Ԫ�� 
node* Delete(node* head) {

	printf("\n");

	node* p = head;

	node* q, * r;

	int j = 0, i;//j��ʾָ��p����������ĵڼ������ݣ�i��ʾɾ����i��λ�õ����� 

	printf("������ɾ�����ݵ�λ�ã�");

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
//�ϲ�
node* merge(node* head1, node* head2, node* head3)
{
	node* p1, * p2, * p3;
	p1 = head1->next, 
	p2 = head2->next; 
	head3 = head1;
	p3 = head3;//�ӵ�һ������ֵ�Ľ�㿪ʼ�Ƚ� 
	while (p1 && p2 )//������û������ 
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
	if (p1 != NULL) p3->next = p1;//������ˣ�ֱ�ӽ��ϱ�һ 
	if (p2 != NULL) p3->next = p2;//��һ���ˣ����ϱ�� 
	delete head2;
	return head3;
}
int main() {

	node* head;

	node* head_;
	
	node* c{};
	
	head = create();//���ô�����������β�巨�� 

	print(head);//����������������������������� 

	ListLength(head);//������ĳ��� 

	LoacteElem(head);//������ֵ���ң���n�����ݵ�λ���ǵ�m���� 

	GetElem(head);//�������ݣ���n��λ�õ������ǵ�m���� 

	Insert(head);//���ò��뺯�� 

	print(head);//������������� 

	Delete(head);//����ɾ������ 

	print(head);//���ɾ��������� 

	printf("\n");

	printf("����list����1");

	head = create();//���ô�����������β�巨��

	printf("\n");

	printf("����list����2");

	head_ = create();//���ô�����������β�巨�� 
	
	printf("\n");
	print(merge(head,head_,c));

	printf("\n");

	return 0;
}
