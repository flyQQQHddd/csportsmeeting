#include "vector.h"
#include "tool.h"




vector* Vector_init(size_t type_size)
{
	VECTOR* vec = malloc(sizeof(VECTOR));
	if (vec == NULL)return NULL;

	vec->_type = type_size;
	vec->_current = 0;
	vec->_size = 0;
	vec->_date = NULL;

	vec->clear = Vector_clear;//清空vector的队列，释放内存
	vec->push_back = Vector_Push_Back;//尾插
	vec->insert_front = Vector_insert_front;// 向量中指向元素p前增加一个元素x
	vec->insert_nfront = Vector_insert_nfront;// 向量中指向元素p前增加n个相同的元素x
	vec->insert = Vector_insert;// 向量中指向元素p前插入另一个相同类型向量的指针[p1,p2)间的数据
	vec->pop_back = Vector_pop_back;//尾删
	vec->erase_p = Vector_erase_p;//删除指针区间内的数据
	vec->erase_int = Vector_erase_int;//删除区间内的数据
	vec->at = Vector_at;//返回指定位置的指针
	vec->front = Vector_front;//返回向量头指针，指向第一个元素
	vec->back = Vector_back;//返回向量尾指针，指向向量最后一个元素
	vec->find = Vector_find;//查找数据，返回找到的指针，没有返回NULL
	vec->empty = Vector_empty;//检测vector内是否为空，空为真 O(1)
	vec->size = Vector_size;//返回vector内元素的个数 O(1)
	vec->capacity = Vector_capacity;//返回当前向量所能容纳的最大元素值
	vec->sort = Vector_sort;//排序
	vec->swap = Vector_swap;//交换两个同类型向量的数据
	vec->reserve = Vector_reserve;

	return vec;
}

void Vector_Push_Back(VECTOR* vec, const void* x)// 向量尾部增加一个元素X
{
	vec->reserve(vec);
	char* str1 = (char*)vec->_date + vec->_type * vec->_current;
	memcpy(str1, x, vec->_type);
	vec->_current++;
}
void Vector_insert_front(VECTOR* vec, const void* p, const void* x)// 向量中指向元素p前增加一个元素x
{
	vec->reserve(vec);
	if (p >= vec->front(vec) && p <= vec->back(vec))
	{
		int size = (char*)vec->back(vec) - p + vec->_type;
		void* ptr = malloc(size);
		memcpy(ptr, p, size);
		memcpy(p, x, vec->_type);
		memcpy((char*)p + vec->_type, ptr, size);
		vec->_current++;
		free(ptr);
	}
}
void Vector_insert_nfront(VECTOR* vec, const void* p, const int n, const void* x)// 向量中指向元素p前增加n个相同的元素x
{
	if (p >= vec->front(vec) && p <= vec->back(vec))
	{
		vec->reserve(vec);
		int size = (char*)vec->back(vec) - p + vec->_type;
		void* ptr = malloc(size);
		memcpy(ptr, p, size);
		int sizen = ((char*)p - vec->front(vec)) / vec->_type;
		for (size_t i = 0; i < n; i++)
		{
			vec->reserve(vec);
			memcpy((char*)vec->at(vec, sizen), x, vec->_type);
			sizen++;
			vec->_current++;
		}
		memcpy((char*)vec->at(vec, sizen), ptr, size);
		free(ptr);
	}
}
void Vector_insert(VECTOR* vec, const void* p, const void* p1, const void* p2)// 向量中指向元素p前插入另一个相同类型向量的指针[p1,p2)间的数据
{
	if (p >= vec->front(vec) && p <= vec->back(vec))
	{
		vec->reserve(vec);
		int size = (char*)vec->back(vec) - p + vec->_type;
		void* ptr = malloc(size);
		memcpy(ptr, p, size);
		int sizen = ((char*)p - vec->front(vec)) / vec->_type;
		int push_n = ((char*)p2 - (char*)p1) / vec->_type + 1;
		for (size_t i = 0; i < push_n; i++)
		{
			vec->reserve(vec);
			memcpy((char*)vec->at(vec, sizen), (char*)p1 + i * vec->_type, vec->_type);
			sizen++;
			vec->_current++;
		}
		memcpy((char*)vec->at(vec, sizen), ptr, size);
		free(ptr);
	}
}

void Vector_pop_back(struct VECTOR* vec)//删除向量中最后一个元素
{
	vec->_current--;
}
void Vector_erase_p(struct VECTOR* vec, const void* p1, const void* p2)//删除指针区间内的数据
{
	if (p1 <= p2 && vec->front(vec) <= p1 && p2 <= vec->back(vec))
	{
		memcpy(p1, (char*)p2 + vec->_type, (int)((char*)vec->back(vec) - (char*)p2));
		vec->_current -= (((int)((char*)p2 - (char*)p1)) / vec->_type + 1);
	}
}
void Vector_erase_int(struct VECTOR* vec, const int left, const int right)//删除区间内的数据
{
	if (left <= right && left >= 0 && right < vec->_current)
	{
		memcpy(vec->at(vec, left), vec->at(vec, right + 1), (vec->_current - 1 - right) * vec->_type);
		vec->_current -= (right - left + 1);
	}
}
void Vector_clear(struct VECTOR* vec)//清空vector的数组，释放内存
{
	if (vec->_date != NULL)
	{
		free(vec->_date);
		vec->_date = NULL;
		vec->_current = 0;
		vec->_size = 0;
	}
}

void* Vector_at(const struct VECTOR* vec, int i)// 返回元素的指针
{
	if (i + 1 > vec->_current)
	{
		return NULL;
	}
	return (void*)((char*)vec->_date + vec->_type * i);
}
void* Vector_front(const struct VECTOR* vec)//返回向量头指针，指向第一个元素
{
	return vec->_date;
}
void* Vector_back(const struct VECTOR* vec)//返回向量尾指针，指向向量最后一个元素
{
	char* _date = (char*)vec->_date + vec->_type * (vec->_current - 1);
	return _date;
}
void* Vector_find(const struct VECTOR* vec, const void* val, int(*fi)(const void* val1, const void* val2))//查找数据，返回找到的指针，没有返回NULL
{
	for (int i = 0; i < vec->size(vec); i++)
	{
		//if (memcmp(vec->at(vec, i), val, vec->_type) == 0)
		if (fi(vec->at(vec, i), val))
		{
			return vec->at(vec, i);
		}
	}
	return NULL;
}

int Vector_empty(const struct VECTOR* vec)//检测vector内是否为空，空为真 O(1)
{
	if (vec->_current == 0)return 1;
	else return 0;
}

int Vector_size(const struct VECTOR* vec)//返回vector内元素的个数 O(1)
{
	return vec->_current;
}
int Vector_capacity(const struct VECTOR* vec)//返回当前向量所能容纳的最大元素值
{
	return vec->_size;
}
void Vector_reserve(VECTOR* vec)
{
	if (vec->_size == 0)
	{
		vec->_date = malloc(vec->_type * VECTOR_INIT_SIZE);
		if (vec->_date == NULL)
		{
			perror("初始化vector失败");
			Exit(-1);
		}
		else
		{
			vec->_size = VECTOR_INIT_SIZE;
		}
	}
	else if (vec->_size == vec->_current)//空间已满需要扩容
	{
		void* _date = realloc(vec->_date, vec->_size * vec->_type * 2);
		if (_date == NULL)
		{
			perror("扩容失败vector");
			Exit(-1);
		}
		else
		{
			vec->_date = _date;
			vec->_size *= 2;
		}
	}
}

void Vector_sort(struct VECTOR* vec, int (*Sort)(void* x, void* y))//排序
{
	qsort(vec->_date, vec->_current, vec->_type, Sort);
}
void Vector_swap(struct VECTOR* vec1, struct VECTOR* vec2)
{
	swap(&vec1->_date, &vec2->_date, sizeof(void*));
	swap(&vec1->_current, &vec2->_current, sizeof(int));
	swap(&vec1->_size, &vec2->_size, sizeof(int));
}
