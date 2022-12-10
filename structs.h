#ifndef _STRUCTS_H
#define _STRUCTS_H


#include <stdio.h>
#include "vector.h"
#include <wchar.h>
#include <string.h>


#define MAX_NUM_EVENTS           3              //每个运动员最多参加的项目数
#define MAX_NAME_LENGTH          50             //名字最长限制
#define MAX_ID_LENGTH            10             //ID最长限制
#define MAX_FILENAME_LENGTH      50             //文件名最长限制

#define DATA_PATH                "data\\"
   

struct _athlete;
struct _college;
struct _athlete;
struct _event;
struct _info;
struct _file_helper;
struct _manager;



//-----------     运动员结构体     ------------

typedef struct _athlete {

	unsigned int ID;                       //运动员编号
	char name[MAX_NAME_LENGTH];            //运动员姓名
	int sex;                               //性别；男生为1，女生为0
	unsigned int college_ID;               //所在学院ID
	char* events[MAX_NUM_EVENTS];          //参加的项目
	unsigned int ranking[MAX_NUM_EVENTS];  //参加项目获得的名次
	unsigned int num_of_event;

}Athlete, *pAthlete;

//-----------     学院结构体     ------------

typedef struct _college {

	unsigned int ID;                       //学院ID
	char name[MAX_NAME_LENGTH];            //学院名称
	unsigned int total_score;              //学院总分

}College,* pCollege;

//-----------     项目结构体     ------------

typedef struct _event {

	unsigned int ID;                       //项目ID
	char name[MAX_NAME_LENGTH];            //项目名称

}Event, * pEvent;

//-----------     参赛信息结构体     ------------

typedef struct _info {

	unsigned int athletes_ID;              //运动员ID
	unsigned int event_ID;               //项目ID
	unsigned int ranking;                  //排名

}Info, * pInfo;

//-----------     文件处理结构体     ------------

enum file { college_filename, athlete_filename, event_filename, info_filename };

typedef struct _FILE_HELPER {


	int (*GetCollegeData)(struct _FILE_HELPER* filehelper, vector** colleges);                //获取学院信息
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

pFileHelper FileHelper_init();

int FileHelper_GetCollegeData(struct _FILE_HELPER* filehelper, vector* colleges);                //获取学院信息
int FileHelper_GetAthleteData(struct _FILE_HELPER* filehelper, vector* athletes);                //获取运动员信息
int FileHelper_GetEventData(struct _FILE_HELPER* filehelper, vector* events);                    //获取项目信息
int FileHelper_GetInfoData(struct _FILE_HELPER* filehelper, vector* infos);                      //获取参赛信息

int FileHelper_OutputCollegeData(struct _FILE_HELPER* filehelper, const vector* colleges);       //获取学院信息
int FileHelper_OutputAthleteData(struct _FILE_HELPER* filehelper, const vector* athletes);       //获取运动员信息
int FileHelper_OutputEventData(struct _FILE_HELPER* filehelper, const vector* events);           //获取项目信息
int FileHelper_OutputInfoData(struct _FILE_HELPER* filehelper, const vector* infos);             //获取参赛信息

int FileHelper_SetFileName(struct _FILE_HELPER* filehelper, enum file filetype, const char* filename);



//-----------     管理系统结构体     ------------

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


//-----------     交互菜单     ------------

pManager pM;
pFileHelper pF;


#define COLLEGE_FILE             1   //11学院信息文件
#define ATHLETE_FILE             2   //12运动员信息文件
#define EVENT_FILE               3   //13项目信息文件
#define INFO_FILE                4   //14参赛信息文件
#define COLLEGE_FIND             5   //21查询学院信息
#define ATHLETE_FIND             6   //22查询运动员信息
#define EVENT_FIND               7   //23查询项目信息
#define COLLEGE_CHANGE           8   //21修改学院信息
#define ATHLETE_CHANGE           9   //22修改运动员信息
#define EVENT_CHANGE             10  //23修改项目信息
#define COLLEGE_ADD              11  //21添加学院信息
#define ATHLETE_ADD              12  //22添加运动员信息
#define EVENT_ADD                13  //23添加项目信息
#define COLLEGE_PATH             14  //11学院信息文件
#define ATHLETE_PATH             15  //12运动员信息文件
#define EVENT_PATH               16  //13项目信息文件
#define INFO_PATH                17  //14参赛信息文件
#define COLLEGE_RANKING          18  //学院排名报表


int Menu();

void Exit(int info);

void COLLEGE_FILE_FUN();
void ATHLETE_FILE_FUN();
void EVENT_FILE_FUN();
void INFO_FILE_FUN();
void COLLEGE_FIND_FUN();
void ATHLETE_FIND_FUN();
void EVENT_FIND_FUN();
void COLLEGE_CHANGE_FUN();
void ATHLETE_CHANGE_FUN();
void EVENT_CHANGE_FUN();
void COLLEGE_ADD_FUN();
void ATHLETE_ADD_FUN();
void EVENT_ADD_FUN();
void COLLEGE_PATH_FUN();
void ATHLETE_PATH_FUN();
void EVENT_PATH_FUN();
void INFO_PATH_FUN();
void COLLEGE_RANKING_FUN();

#endif