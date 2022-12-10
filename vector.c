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

	vec->clear = Vector_clear;//���vector�Ķ��У��ͷ��ڴ�
	vec->push_back = Vector_Push_Back;//β��
	vec->insert_front = Vector_insert_front;// ������ָ��Ԫ��pǰ����һ��Ԫ��x
	vec->insert_nfront = Vector_insert_nfront;// ������ָ��Ԫ��pǰ����n����ͬ��Ԫ��x
	vec->insert = Vector_insert;// ������ָ��Ԫ��pǰ������һ����ͬ����������ָ��[p1,p2)�������
	vec->pop_back = Vector_pop_back;//βɾ
	vec->erase_p = Vector_erase_p;//ɾ��ָ�������ڵ�����
	vec->erase_int = Vector_erase_int;//ɾ�������ڵ�����
	vec->at = Vector_at;//����ָ��λ�õ�ָ��
	vec->front = Vector_front;//��������ͷָ�룬ָ���һ��Ԫ��
	vec->back = Vector_back;//��������βָ�룬ָ���������һ��Ԫ��
	vec->find = Vector_find;//�������ݣ������ҵ���ָ�룬û�з���NULL
	vec->empty = Vector_empty;//���vector���Ƿ�Ϊ�գ���Ϊ�� O(1)
	vec->size = Vector_size;//����vector��Ԫ�صĸ��� O(1)
	vec->capacity = Vector_capacity;//���ص�ǰ�����������ɵ����Ԫ��ֵ
	vec->sort = Vector_sort;//����
	vec->swap = Vector_swap;//��������ͬ��������������
	vec->reserve = Vector_reserve;

	return vec;
}

void Vector_Push_Back(VECTOR* vec, const void* x)// ����β������һ��Ԫ��X
{
	vec->reserve(vec);
	char* str1 = (char*)vec->_date + vec->_type * vec->_current;
	memcpy(str1, x, vec->_type);
	vec->_current++;
}
void Vector_insert_front(VECTOR* vec, const void* p, const void* x)// ������ָ��Ԫ��pǰ����һ��Ԫ��x
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
void Vector_insert_nfront(VECTOR* vec, const void* p, const int n, const void* x)// ������ָ��Ԫ��pǰ����n����ͬ��Ԫ��x
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
void Vector_insert(VECTOR* vec, const void* p, const void* p1, const void* p2)// ������ָ��Ԫ��pǰ������һ����ͬ����������ָ��[p1,p2)�������
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

void Vector_pop_back(struct VECTOR* vec)//ɾ�����������һ��Ԫ��
{
	vec->_current--;
}
void Vector_erase_p(struct VECTOR* vec, const void* p1, const void* p2)//ɾ��ָ�������ڵ�����
{
	if (p1 <= p2 && vec->front(vec) <= p1 && p2 <= vec->back(vec))
	{
		memcpy(p1, (char*)p2 + vec->_type, (int)((char*)vec->back(vec) - (char*)p2));
		vec->_current -= (((int)((char*)p2 - (char*)p1)) / vec->_type + 1);
	}
}
void Vector_erase_int(struct VECTOR* vec, const int left, const int right)//ɾ�������ڵ�����
{
	if (left <= right && left >= 0 && right < vec->_current)
	{
		memcpy(vec->at(vec, left), vec->at(vec, right + 1), (vec->_current - 1 - right) * vec->_type);
		vec->_current -= (right - left + 1);
	}
}
void Vector_clear(struct VECTOR* vec)//���vector�����飬�ͷ��ڴ�
{
	if (vec->_date != NULL)
	{
		free(vec->_date);
		vec->_date = NULL;
		vec->_current = 0;
		vec->_size = 0;
	}
}

void* Vector_at(const struct VECTOR* vec, int i)// ����Ԫ�ص�ָ��
{
	if (i + 1 > vec->_current)
	{
		return NULL;
	}
	return (void*)((char*)vec->_date + vec->_type * i);
}
void* Vector_front(const struct VECTOR* vec)//��������ͷָ�룬ָ���һ��Ԫ��
{
	return vec->_date;
}
void* Vector_back(const struct VECTOR* vec)//��������βָ�룬ָ���������һ��Ԫ��
{
	char* _date = (char*)vec->_date + vec->_type * (vec->_current - 1);
	return _date;
}
void* Vector_find(const struct VECTOR* vec, const void* val, int(*fi)(const void* val1, const void* val2))//�������ݣ������ҵ���ָ�룬û�з���NULL
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

int Vector_empty(const struct VECTOR* vec)//���vector���Ƿ�Ϊ�գ���Ϊ�� O(1)
{
	if (vec->_current == 0)return 1;
	else return 0;
}

int Vector_size(const struct VECTOR* vec)//����vector��Ԫ�صĸ��� O(1)
{
	return vec->_current;
}
int Vector_capacity(const struct VECTOR* vec)//���ص�ǰ�����������ɵ����Ԫ��ֵ
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
			perror("��ʼ��vectorʧ��");
			Exit(-1);
		}
		else
		{
			vec->_size = VECTOR_INIT_SIZE;
		}
	}
	else if (vec->_size == vec->_current)//�ռ�������Ҫ����
	{
		void* _date = realloc(vec->_date, vec->_size * vec->_type * 2);
		if (_date == NULL)
		{
			perror("����ʧ��vector");
			Exit(-1);
		}
		else
		{
			vec->_date = _date;
			vec->_size *= 2;
		}
	}
}

void Vector_sort(struct VECTOR* vec, int (*Sort)(void* x, void* y))//����
{
	qsort(vec->_date, vec->_current, vec->_type, Sort);
}
void Vector_swap(struct VECTOR* vec1, struct VECTOR* vec2)
{
	swap(&vec1->_date, &vec2->_date, sizeof(void*));
	swap(&vec1->_current, &vec2->_current, sizeof(int));
	swap(&vec1->_size, &vec2->_size, sizeof(int));
}
