#ifndef _VECTOR_H
#define _VECTOR_H




//-----------------------     ��C����ʵ��vector     ----------------------------
//VECTOR��ʵ�ʴ����Ľṹ��
//vector���û��ɼ��Ľṹ��
//����ͨ��ָ��ǿתʵ��������private�Ĺ���



#include <stdio.h>
#include <stdlib.h>


#define VECTOR_INIT_SIZE 4                    //��ʼ�����С



//--------------------------------------------------------------------------------------------------------------


typedef struct VECTOR
{
	//���뺯��
	void (*push_back)(struct VECTOR*, const void*);                                                 // β��
	void (*insert_front)(struct VECTOR*, const void*, const void*);                                 // ������ָ��Ԫ��pǰ����һ��Ԫ��x
	void (*insert_nfront)(struct VECTOR*, const void*, const int, const void*);                     // ������ָ��Ԫ��pǰ����n����ͬ��Ԫ��x
	void (*insert)(struct VECTOR*, const void*, const void*, const void*);                          // ������ָ��Ԫ��pǰ������һ����ͬ����������ָ��[p1,p2)�������
	//ɾ������
	void (*pop_back)(struct VECTOR*);                                                               // βɾ
	void (*erase_p)(struct VECTOR*, const void*, const void*);                                      // ɾ��ָ�������ڵ�����
	void (*erase_int)(struct VECTOR*, const int, const int);                                        // ɾ�������ڵ�����
	void (*clear)(struct VECTOR*);                                                                  // ���vector�Ķ��У��ͷ��ڴ�
	//�������� 
	void* (*at)(const struct VECTOR*, int);                                                         // ���ص�0-n��Ԫ�ص�ָ��
	void* (*front)(const struct VECTOR*);                                                           // ��������ͷָ�룬ָ���һ��Ԫ��
	void* (*back)(const struct VECTOR*);                                                            // ��������βָ�룬ָ���������һ��Ԫ��
	void* (*find)(const struct VECTOR*, const void*, int(*)(const void*, const void*));             // �������ݣ������ҵ���ָ�룬û�з���NULL
	//��С����
	int (*empty)(const struct VECTOR*);                                                             // ���vector���Ƿ�Ϊ�գ���Ϊ�� O(1)
	int (*size)(const struct VECTOR*);                                                              // ����vector��Ԫ�صĸ��� O(1)
	int (*capacity)(const struct VECTOR*);                                                          // ���ص�ǰ�����������ɵ����Ԫ�ظ���
	void (*reserve)(const struct VECTOR*);                                                          // ����
	//��������
	void (*sort)(struct VECTOR*, int (*)(void*, void*));                                            // ����
	void (*swap)(struct VECTOR*, struct VECTOR*);                                                   // ��������ͬ��������������

	void* _date;                                                                                    //ָ���Զ�����������
	int  _current;                                                                                  //��ǰԪ�ظ���
	int _size;                                                                                      //Ԫ��������
	int _type;                                                                                      //����ռ���ֽ���

}VECTOR;


typedef struct vector
{
	//���뺯��
	void (*push_back)(struct vector*, const void*);                                                 // β��
	void (*insert_front)(struct vector*, const void*, const void*);                                 // ������ָ��Ԫ��pǰ����һ��Ԫ��x
	void (*insert_nfront)(struct vector*, const void*, const int, const void*);                     // ������ָ��Ԫ��pǰ����n����ͬ��Ԫ��x
	void (*insert)(struct vector*, const void*, const void*, const void*);                          // ������ָ��Ԫ��pǰ������һ����ͬ����������ָ��[p1,p2)�������
	//ɾ������
	void (*pop_back)(struct vector*);                                                               // βɾ
	void (*erase_p)(struct vector*, const void*, const void*);                                      // ɾ��ָ�������ڵ�����
	void (*erase_int)(struct vector*, const int, const int);                                        // ɾ�������ڵ�����
	void (*clear)(struct vector*);                                                                  // ���vector�Ķ��У��ͷ��ڴ�
	//�������� 
	void* (*at)(const struct vector*, int);                                                         // ���ص�0-n��Ԫ�ص�ָ��
	void* (*front)(const struct vector*);                                                           // ��������ͷָ�룬ָ���һ��Ԫ��
	void* (*back)(const struct vector*);                                                            // ��������βָ�룬ָ���������һ��Ԫ��
	void* (*find)(const struct vector*, const void*, int(*)(const void*, const void*));             // �������ݣ������ҵ���ָ�룬û�з���NULL
	//��С����
	int (*empty)(const struct vector*);                                                             // ���vector���Ƿ�Ϊ�գ���Ϊ�� O(1)
	int (*size)(const struct vector*);                                                              // ����vector��Ԫ�صĸ��� O(1)
	int (*capacity)(const struct vector*);                                                          // ���ص�ǰ�����������ɵ����Ԫ�ظ���
	void (*reserve)(const struct vector*);                                                          // ����
	//��������
	void (*sort)(struct vector*, int (*)(void*, void*));                                            // ����
	void (*swap)(struct vector*, struct vector*);                                                   // ��������ͬ��������������

}vector;



//--------------------------------------------------------------------------------------------------------------



vector* Vector_init(size_t type_size);

void Vector_Push_Back(VECTOR* vec, const void* x);                                                  // ����β������һ��Ԫ��X
void Vector_insert_front(VECTOR* vec, const void* p, const void* x);                                // ������ָ��Ԫ��pǰ����һ��Ԫ��x
void Vector_insert_nfront(VECTOR* vec, const void* p, const int n, const void* x);                  // ������ָ��Ԫ��pǰ����n����ͬ��Ԫ��x
void Vector_insert(VECTOR* vec, const void* p, const void* p1, const void* p2);                     // ������ָ��Ԫ��pǰ������һ����ͬ����������ָ��[p1,p2]�������

void Vector_pop_back(VECTOR* vec);                                                                  // ɾ�����������һ��Ԫ��
void Vector_erase_p(VECTOR* vec, const void* p1, const void* p2);                                   // ɾ��ָ�������ڵ�����
void Vector_erase_int(VECTOR* vec, const int left, const int right);                                // ɾ�������ڵ�����
void Vector_clear(VECTOR* vec);                                                                     // ���vector�Ķ��У��ͷ��ڴ�

void* Vector_at(const VECTOR* vec, int i);                                                          // ����Ԫ�ص�ָ��
void* Vector_front(const VECTOR* vec);                                                              // ��������ͷָ�룬ָ���һ��Ԫ��
void* Vector_back(const VECTOR* vec);                                                               // ��������βָ�룬ָ���������һ��Ԫ��
void* Vector_find(const VECTOR* vec, const void* val, int(*fi)(const void* val1, const void* val2));// �������ݣ������ҵ���ָ�룬û�з���NULL

int Vector_empty(const  VECTOR* vec);                                                               // ���vector���Ƿ�Ϊ�գ���Ϊ�� O(1)
int Vector_size(const  VECTOR* vec);                                                                // ����vector��Ԫ�صĸ��� O(1)
int Vector_capacity(const  VECTOR* vec);                                                            // ���ص�ǰ�����������ɵ����Ԫ�ظ���
void Vector_reserve(VECTOR* vec);                                                                   // ����

void Vector_sort(VECTOR* vec, int (*Sort)(void* x, void* y));                                       // ����
void Vector_swap(VECTOR* vec1, VECTOR* vec2);                                                       // ��������ͬ��������������


#endif





//int mysort(const void* a, const void* b)
//{
//	return (*(int*)a - *(int*)b);//升序
//	//return (*(int*)b - *(int*)a);//降序
//}
//
//int test_vector()
//{
//	vector* vec = Vector_init(sizeof(int));
//	int num = 10;
//	vec->push_back(vec, &num);
//
//	num = 21;
//	vec->push_back(vec, &num);
//
//	num = 123;
//	vec->push_back(vec, &num);
//	num = 245;
//	vec->push_back(vec, &num);
//	num = 16;
//	vec->push_back(vec, &num);
//	num = 55;
//	vec->push_back(vec, &num);
//
//
//	printf("��Ԫ��:%d\n", *(int*)vec->front(vec));
//	printf("βԪ��:%d\n", *(int*)vec->back(vec));
//	printf("%d\n", vec->size(vec));
//
//
//	printf("����ǰ����");
//	for (size_t i = 0; i < vec->size(vec); i++)
//	{
//		printf("%d\t", *(int*)vec->at(vec, i));
//	}
//	vec->sort(vec, mysort);
//	printf("\n����ǰ����");
//	for (size_t i = 0; i < vec->size(vec); i++)
//	{
//		printf("%d\t", *(int*)vec->at(vec, i));
//	}
//	vec->clear(vec);
//	return 0;
//}

