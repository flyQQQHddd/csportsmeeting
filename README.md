# C语言实现的运动会成绩管理系统

### 软件介绍
程序通过C语言实现了一个简单的运动会成绩管理系统。


### 功能介绍

1. 文件数据展示
2. 信息查询
3. 信息修改
4. 信息添加
5. 生成学院排名
6. 更改链接数据文件路径
7. 程序退出

### 数据结构的实现 vector

代码使用C语言模仿微软 STL 中 vector 的功能，基于面向对象的编程思想，在 vector.h 中定义，在 vector.c 中实现。

vector.h 中定义 struct vector 、 struct VECTOR 两个结构体和若干函数，实现 vector的变量和函数管理。

struct vector 中包含操作函数的指针，具体定义如下：

```
typedef struct vector
{

    void (*push_back)(struct vector*, const void*);
    void (*insert_front)(struct vector*, const void*, const void*);
    void (*insert_nfront)(struct vector*, const void*, const int, const void*);
    void (*insert)(struct vector*, const void*, const void*, const void*);
    void (*pop_back)(struct vector*);
    void (*erase_p)(struct vector*, const void*, const void*);
    void (*erase_int)(struct vector*, const int, const int);
    void (*clear)(struct vector*);
    void* (*at)(const struct vector*, int);
    void* (*front)(const struct vector*);
    void* (*back)(const struct vector*);
    void* (*find)(const struct vector*, const void*, int(*)(const void*, const void*));
    int (*empty)(const struct vector*);
    int (*size)(const struct vector*);
    int (*capacity)(const struct vector*);
    void (*reserve)(const struct vector*);
    void (*sort)(struct vector*, int (*)(void*, void*));
    void (*swap)(struct vector*, struct vector*);

}vector;
```
struct VECTOR 中包含操作函数的指针及内置变量，具体定义如下：
```
typedef struct VECTOR
{

    void (*push_back)(struct vector*, const void*);
    void (*insert_front)(struct vector*, const void*, const void*);
    void (*insert_nfront)(struct vector*, const void*, const int, const void*);
    void (*insert)(struct vector*, const void*, const void*, const void*);
    void (*pop_back)(struct vector*);
    void (*erase_p)(struct vector*, const void*, const void*);
    void (*erase_int)(struct vector*, const int, const int);
    void (*clear)(struct vector*);
    void* (*at)(const struct vector*, int);
    void* (*front)(const struct vector*);
    void* (*back)(const struct vector*);
    void* (*find)(const struct vector*, const void*, int(*)(const void*, const void*));
    int (*empty)(const struct vector*);
    int (*size)(const struct vector*);
    int (*capacity)(const struct vector*);
    void (*reserve)(const struct vector*);
    void (*sort)(struct vector*, int (*)(void*, void*));
    void (*swap)(struct vector*, struct vector*);
    
    void* _date;             //指向自定义数组类型
    int  _current;           //当前元素个数
    int _size;               //元素最大个数
    int _type;               //类型占用字节数

}VECTOR;
```
###### 在C语言中实现数据结构往往存在以下两个问题：
1. C语言在创建数据结构时，往往需要提前知道要存储的数据类型，当数据类型改变时，代码需要大量改动，复用性差，
2. C语言中没有 public , private 等概念，但在数据结构的使用过程中，往往不期望使用者直接对 _data 等内置变量进行操作，因为不合法的操作可能对数据结构造成不可逆的损坏。


###### 定义双结构体的想法及优势来源于C++语言中的面向对象编程思想、模板和类等功能：
1. 在本项目中，利用了C语言指针强转方便的优势，实现了类似于 C++ 中 private 的功能。
在使用过程中，使用者通过 Vector_Init 函数获取一个初始化过的 vector * 类型的指针，并利用这个指针调用 vector 的各项功能。而在 Vector_Init 的实现过程中，
实际上创建的是一个 VECTOR * 类型的指针，通过这种方式，实际上创建了 _data 等内置变量的空间，但使用者无法通过手中的 vector * 指针直接调用他们。
但在 vector 实现的各种操作函数中，通过指针强转的方式，将 vector * 强转为 VECTOR * 类型，从而可以读取到只定义在 VECTOR 中的 _data 变量，
一定程度上提醒编程者通过调用内置函数来操作数据结构，保证了数据的安全性。
Vector_init函数的实现如下：



```
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

    return (vector*)vec;
}
```
2. 可以见到在初始化 vector 的过程中，需要传入一个 size_t type_size 变量，该变量使得 vector 知道每个数据的内存大小。
从而可以直接通过内存操作实现顺序存储中的各项操作，例如，交换元素顺序。在根本上解决了定义数据结构时代码复用性差的问题。
以下函数可以实现已知位置和大小的内存的直接交换，使得交换两个变量的过程可以跳过元素类型这一环节：
```
static void swap(void* x, void* y, const int n)
{
    void* p = malloc(n);
    if (p == NULL)
    {
    	perror("交换函数创建p临时空间失败");
    	Exit(-1);
    }
    memcpy(p, x, n);
    memcpy(x, y, n);
    memcpy(y, p, n);
    free(p);
}
```

### 程序中定义的其他结构体和函数

程序中的其他结构体和函数在 structs.h 中定义，在 structs.c 中实现

###### 运动会主体对应的结构体
1. 基于面向对象编程思想，定义了_athlete、_college、_event和_info等结构体，分别对应运动会中的运动员、学院、项目和参赛信息等对象。
同时在.h文件中宏定义了一些数据长度最大值，对功能的实现进行限制，保证代码安全性。
宏定义如下：
```
#define MAX_NUM_EVENTS           3              //每个运动员最多参加的项目数
#define MAX_NAME_LENGTH          50             //名字最长限制
#define MAX_ID_LENGTH            10             //ID最长限制
#define MAX_FILENAME_LENGTH      50             //文件名最长限制
#define DATA_PATH                "data\\"       //数据文件所在文件夹的相对目录
```

###### 文件处理结构体
该结构体中包含了文件处理的各种函数指针和文件名，同样通过双结构体的方法对文件名加以保护，定义如下：

```
typedef struct _FILE_HELPER {

    int (*GetCollegeData)(struct _FILE_HELPER* filehelper, vector** colleges);               //获取学院信息
    int (*GetAthleteData)(struct _FILE_HELPER* filehelper, vector* athletes);                //获取运动员信息
    int (*GetEventData)(struct _FILE_HELPER* filehelper, vector* events);                    //获取项目信息
    int (*GetInfoData)(struct _FILE_HELPER* filehelper, vector* infos);                      //获取参赛信息

    int (*OutputCollegeData)(struct _FILE_HELPER* filehelper, const vector* colleges);       //获取学院信息
    int (*OutputAthleteData)(struct _FILE_HELPER* filehelper, const vector* athletes);       //获取运动员信息
    int (*OutputEventData)(struct _FILE_HELPER* filehelper, const vector* events);           //获取项目信息
    int (*OutputInfoData)(struct _FILE_HELPER* filehelper, const vector* infos);             //获取参赛信息

    int (*SetFileName)(struct _FILE_HELPER* filehelper, enum file filetype, const char* filename);

    char college_filename[MAX_FILENAME_LENGTH];
    char athlete_filename[MAX_FILENAME_LENGTH];
    char event_filename[MAX_FILENAME_LENGTH];
    char info_filename[MAX_FILENAME_LENGTH];

}_FILE_HELPER;
```
```
typedef struct _file_helper {

    int (*GetCollegeData)(struct _file_helper* filehelper, vector* colleges);                //获取学院信息
    int (*GetAthleteData)(struct _file_helper* filehelper, vector* athletes);                //获取运动员信息
    int (*GetEventData)(struct _file_helper* filehelper, vector* events);                    //获取项目信息
    int (*GetInfoData)(struct _file_helper* filehelper, vector* infos);                      //获取参赛信息

    int (*OutputCollegeData)(struct _file_helper* filehelper, const vector* colleges);       //获取学院信息
    int (*OutputAthleteData)(struct _file_helper* filehelper, const vector* athletes);       //获取运动员信息
    int (*OutputEventData)(struct _file_helper* filehelper, const vector* events);           //获取项目信息
    int (*OutputInfoData)(struct _file_helper* filehelper, const vector* infos);             //获取参赛信息

    int (*SetFileName)(struct _file_helper* filehelper, enum file filetype, const char* filename);

}FileHelper, * pFileHelper;
```
在设置文件名的函数中，定义了辅助枚举类型实现不同的名称设置：
```
enum file { college_filename, athlete_filename, event_filename, info_filename };
```

###### 管理系统数据结构体及函数
该结构体运用了先前写好的 vector 数据结构，定义了四个 vector 变量，分别对四个类型的主题进行信息存储，
同时运用枚举变量实现了按照不同指标进行排序和查询的功能：
```
enum sort { colleges_ID, college_score };
enum data { college, athlete, event, info };

typedef struct _manager {

	vector* colleges;
	vector* athletes;
	vector* events;
	vector* infos;

}Manager, * pManager;

pManager Manager_init();

void ProcessingData(struct _manager* manager);

void Sort(struct _manager* manager, enum sort sort_type);
int sort_college_score(const void* a, const void* b);
int sort_college_id(const void* a, const void* b);

void* Search(struct _manager* manager, enum data data_type, unsigned int* id);
int search_college(const void* val1, const void* val2);
int search_athlete(const void* val1, const void* val2);
int search_event(const void* val1, const void* val2);
```

### 输入检测
程序中有较多的交互输入过程，所以代码中对用户的输入进行了检测，避免用户的非法输入导致程序崩溃，
以下以两段代码为例做分析：

第一段代码是对无符号整型数据的输入检测。
```
int flag = scanf("%d", &menuitem);
scanf("%*[^\n]"); scanf("%*c");
while (flag != 1 || menuitem < 0 || menuitem > 6) 
{
	printf("请输入正确的指令\n");
	flag = scanf("%d", &menuitem);
	scanf("%*[^\n]"); scanf("%*c");
}
```

以上是一个菜单选项的输入，程序意图达到的功能是：用户通过输入0~6中的一个整数，进入不同的功能。
这里考虑到用户可能存在的两类错误输入：
1. 输入字符或字符串
2. 输入小于0或大于6的数

第一类错误输入通过 scanf 函数的返回值来实现检测，
scanf 函数如果成功，该函数返回成功匹配和赋值的个数，如果到达文件末尾或发生读错误，则返回 EOF。
通过定义整型变量 flag 接受 scanf 函数的返回值，当 flag 值为 1 时，代表用户输入了一个整数，检测了第一类输入错误。
此时通过对 id 的范围限定，检测第二类输入错误。

同时，通过 scanf 支持的正则表达式 
```
scanf("%*[^\n]"); scanf("%*c");
```
实现清理输入缓冲区的功能，避免在 while 循环中 scanf 一直在读取第一个输入，程序陷入死循环。

第二段代码是对字符串数据的输入检测
```
char new_name[MAX_NAME_LENGTH + 1];
int flag = 0;
size_t size = 0;
flag = scanf_s("%s", new_name, MAX_NAME_LENGTH);
size = strlen(new_name);
scanf("%*[^\n]"); scanf("%*c");
while (flag != 1 || size > MAX_NAME_LENGTH)
{

    printf("请输入正确的格式，例如：小王\n");
    flag = scanf_s("%s", new_name, MAX_NAME_LENGTH);
    size = strlen(new_name);
	scanf("%*[^\n]"); scanf("%*c");
}
```
以上是一个名称的录入，程序意图达到的功能是：用户输入一个字符串，作为将要插入到管理系统中的运动员的名称。
这里考虑到用户可能存在的两类错误输入：
1. 输入了非字符串的其他数据类型
2. 输入的字符串超过了存储名称的数组已经分配的空间，造成内存泄露

第一类错误输入检测解决方案同上。考虑到 scanf 函数在读取字符串时不检查边界，所以这里采用了专为此类问题设计的 scanf_s 函数，
scanf_s 用于读取字符串时，必须提供一个数字以表明最多读取多少位字符，以防止溢出。





















