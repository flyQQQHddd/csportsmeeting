#ifndef _VECTOR_H
#define _VECTOR_H




//-----------------------     用C语言实现vector     ----------------------------
//VECTOR是实际创建的结构体
//vector是用户可见的结构体
//二者通过指针强转实现类似于private的功能



#include <stdio.h>
#include <stdlib.h>


#define VECTOR_INIT_SIZE 4                    //初始数组大小



//--------------------------------------------------------------------------------------------------------------


typedef struct VECTOR
{
	//插入函数
	void (*push_back)(struct VECTOR*, const void*);                                                 // 尾插
	void (*insert_front)(struct VECTOR*, const void*, const void*);                                 // 向量中指向元素p前增加一个元素x
	void (*insert_nfront)(struct VECTOR*, const void*, const int, const void*);                     // 向量中指向元素p前增加n个相同的元素x
	void (*insert)(struct VECTOR*, const void*, const void*, const void*);                          // 向量中指向元素p前插入另一个相同类型向量的指针[p1,p2)间的数据
	//删除函数
	void (*pop_back)(struct VECTOR*);                                                               // 尾删
	void (*erase_p)(struct VECTOR*, const void*, const void*);                                      // 删除指针区间内的数据
	void (*erase_int)(struct VECTOR*, const int, const int);                                        // 删除区间内的数据
	void (*clear)(struct VECTOR*);                                                                  // 清空vector的队列，释放内存
	//遍历函数 
	void* (*at)(const struct VECTOR*, int);                                                         // 返回第0-n个元素的指针
	void* (*front)(const struct VECTOR*);                                                           // 返回向量头指针，指向第一个元素
	void* (*back)(const struct VECTOR*);                                                            // 返回向量尾指针，指向向量最后一个元素
	void* (*find)(const struct VECTOR*, const void*, int(*)(const void*, const void*));             // 查找数据，返回找到的指针，没有返回NULL
	//大小函数
	int (*empty)(const struct VECTOR*);                                                             // 检测vector内是否为空，空为真 O(1)
	int (*size)(const struct VECTOR*);                                                              // 返回vector内元素的个数 O(1)
	int (*capacity)(const struct VECTOR*);                                                          // 返回当前向量所能容纳的最大元素个数
	void (*reserve)(const struct VECTOR*);                                                          // 扩容
	//其他函数
	void (*sort)(struct VECTOR*, int (*)(void*, void*));                                            // 排序
	void (*swap)(struct VECTOR*, struct VECTOR*);                                                   // 交换两个同类型向量的数据

	void* _date;                                                                                    //指向自定义数组类型
	int  _current;                                                                                  //当前元素个数
	int _size;                                                                                      //元素最大个数
	int _type;                                                                                      //类型占用字节数

}VECTOR;


typedef struct vector
{
	//插入函数
	void (*push_back)(struct vector*, const void*);                                                 // 尾插
	void (*insert_front)(struct vector*, const void*, const void*);                                 // 向量中指向元素p前增加一个元素x
	void (*insert_nfront)(struct vector*, const void*, const int, const void*);                     // 向量中指向元素p前增加n个相同的元素x
	void (*insert)(struct vector*, const void*, const void*, const void*);                          // 向量中指向元素p前插入另一个相同类型向量的指针[p1,p2)间的数据
	//删除函数
	void (*pop_back)(struct vector*);                                                               // 尾删
	void (*erase_p)(struct vector*, const void*, const void*);                                      // 删除指针区间内的数据
	void (*erase_int)(struct vector*, const int, const int);                                        // 删除区间内的数据
	void (*clear)(struct vector*);                                                                  // 清空vector的队列，释放内存
	//遍历函数 
	void* (*at)(const struct vector*, int);                                                         // 返回第0-n个元素的指针
	void* (*front)(const struct vector*);                                                           // 返回向量头指针，指向第一个元素
	void* (*back)(const struct vector*);                                                            // 返回向量尾指针，指向向量最后一个元素
	void* (*find)(const struct vector*, const void*, int(*)(const void*, const void*));             // 查找数据，返回找到的指针，没有返回NULL
	//大小函数
	int (*empty)(const struct vector*);                                                             // 检测vector内是否为空，空为真 O(1)
	int (*size)(const struct vector*);                                                              // 返回vector内元素的个数 O(1)
	int (*capacity)(const struct vector*);                                                          // 返回当前向量所能容纳的最大元素个数
	void (*reserve)(const struct vector*);                                                          // 扩容
	//其他函数
	void (*sort)(struct vector*, int (*)(void*, void*));                                            // 排序
	void (*swap)(struct vector*, struct vector*);                                                   // 交换两个同类型向量的数据

}vector;



//--------------------------------------------------------------------------------------------------------------



vector* Vector_init(size_t type_size);

void Vector_Push_Back(VECTOR* vec, const void* x);                                                  // 向量尾部增加一个元素X
void Vector_insert_front(VECTOR* vec, const void* p, const void* x);                                // 向量中指向元素p前增加一个元素x
void Vector_insert_nfront(VECTOR* vec, const void* p, const int n, const void* x);                  // 向量中指向元素p前增加n个相同的元素x
void Vector_insert(VECTOR* vec, const void* p, const void* p1, const void* p2);                     // 向量中指向元素p前插入另一个相同类型向量的指针[p1,p2]间的数据

void Vector_pop_back(VECTOR* vec);                                                                  // 删除向量中最后一个元素
void Vector_erase_p(VECTOR* vec, const void* p1, const void* p2);                                   // 删除指针区间内的数据
void Vector_erase_int(VECTOR* vec, const int left, const int right);                                // 删除区间内的数据
void Vector_clear(VECTOR* vec);                                                                     // 清空vector的队列，释放内存

void* Vector_at(const VECTOR* vec, int i);                                                          // 返回元素的指针
void* Vector_front(const VECTOR* vec);                                                              // 返回向量头指针，指向第一个元素
void* Vector_back(const VECTOR* vec);                                                               // 返回向量尾指针，指向向量最后一个元素
void* Vector_find(const VECTOR* vec, const void* val, int(*fi)(const void* val1, const void* val2));// 查找数据，返回找到的指针，没有返回NULL

int Vector_empty(const  VECTOR* vec);                                                               // 检测vector内是否为空，空为真 O(1)
int Vector_size(const  VECTOR* vec);                                                                // 返回vector内元素的个数 O(1)
int Vector_capacity(const  VECTOR* vec);                                                            // 返回当前向量所能容纳的最大元素个数
void Vector_reserve(VECTOR* vec);                                                                   // 扩容

void Vector_sort(VECTOR* vec, int (*Sort)(void* x, void* y));                                       // 排序
void Vector_swap(VECTOR* vec1, VECTOR* vec2);                                                       // 交换两个同类型向量的数据


#endif





//int mysort(const void* a, const void* b)
//{
//	return (*(int*)a - *(int*)b);//鍗囧簭
//	//return (*(int*)b - *(int*)a);//闄嶅簭
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
//	printf("首元素:%d\n", *(int*)vec->front(vec));
//	printf("尾元素:%d\n", *(int*)vec->back(vec));
//	printf("%d\n", vec->size(vec));
//
//
//	printf("排序前遍历");
//	for (size_t i = 0; i < vec->size(vec); i++)
//	{
//		printf("%d\t", *(int*)vec->at(vec, i));
//	}
//	vec->sort(vec, mysort);
//	printf("\n排序前遍历");
//	for (size_t i = 0; i < vec->size(vec); i++)
//	{
//		printf("%d\t", *(int*)vec->at(vec, i));
//	}
//	vec->clear(vec);
//	return 0;
//}

