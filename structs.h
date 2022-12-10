#ifndef _STRUCTS_H
#define _STRUCTS_H


#include <stdio.h>
#include "vector.h"
#include <wchar.h>
#include <string.h>


#define MAX_NUM_EVENTS           3              //ÿ���˶�Ա���μӵ���Ŀ��
#define MAX_NAME_LENGTH          50             //���������
#define MAX_ID_LENGTH            10             //ID�����
#define MAX_FILENAME_LENGTH      50             //�ļ��������

#define DATA_PATH                "data\\"
   

struct _athlete;
struct _college;
struct _athlete;
struct _event;
struct _info;
struct _file_helper;
struct _manager;



//-----------     �˶�Ա�ṹ��     ------------

typedef struct _athlete {

	unsigned int ID;                       //�˶�Ա���
	char name[MAX_NAME_LENGTH];            //�˶�Ա����
	int sex;                               //�Ա�����Ϊ1��Ů��Ϊ0
	unsigned int college_ID;               //����ѧԺID
	char* events[MAX_NUM_EVENTS];          //�μӵ���Ŀ
	unsigned int ranking[MAX_NUM_EVENTS];  //�μ���Ŀ��õ�����
	unsigned int num_of_event;

}Athlete, *pAthlete;

//-----------     ѧԺ�ṹ��     ------------

typedef struct _college {

	unsigned int ID;                       //ѧԺID
	char name[MAX_NAME_LENGTH];            //ѧԺ����
	unsigned int total_score;              //ѧԺ�ܷ�

}College,* pCollege;

//-----------     ��Ŀ�ṹ��     ------------

typedef struct _event {

	unsigned int ID;                       //��ĿID
	char name[MAX_NAME_LENGTH];            //��Ŀ����

}Event, * pEvent;

//-----------     ������Ϣ�ṹ��     ------------

typedef struct _info {

	unsigned int athletes_ID;              //�˶�ԱID
	unsigned int event_ID;               //��ĿID
	unsigned int ranking;                  //����

}Info, * pInfo;

//-----------     �ļ�����ṹ��     ------------

enum file { college_filename, athlete_filename, event_filename, info_filename };

typedef struct _FILE_HELPER {


	int (*GetCollegeData)(struct _FILE_HELPER* filehelper, vector** colleges);                //��ȡѧԺ��Ϣ
	int (*GetAthleteData)(struct _FILE_HELPER* filehelper, vector* athletes);                //��ȡ�˶�Ա��Ϣ
	int (*GetEventData)(struct _FILE_HELPER* filehelper, vector* events);                    //��ȡ��Ŀ��Ϣ
	int (*GetInfoData)(struct _FILE_HELPER* filehelper, vector* infos);                      //��ȡ������Ϣ

	int (*OutputCollegeData)(struct _FILE_HELPER* filehelper, const vector* colleges);       //��ȡѧԺ��Ϣ
	int (*OutputAthleteData)(struct _FILE_HELPER* filehelper, const vector* athletes);       //��ȡ�˶�Ա��Ϣ
	int (*OutputEventData)(struct _FILE_HELPER* filehelper, const vector* events);           //��ȡ��Ŀ��Ϣ
	int (*OutputInfoData)(struct _FILE_HELPER* filehelper, const vector* infos);             //��ȡ������Ϣ

	int (*SetFileName)(struct _FILE_HELPER* filehelper, enum file filetype, const char* filename);


	char college_filename[MAX_FILENAME_LENGTH];
	char athlete_filename[MAX_FILENAME_LENGTH];
	char event_filename[MAX_FILENAME_LENGTH];
	char info_filename[MAX_FILENAME_LENGTH];


}_FILE_HELPER;

typedef struct _file_helper {


	int (*GetCollegeData)(struct _file_helper* filehelper, vector* colleges);                //��ȡѧԺ��Ϣ
	int (*GetAthleteData)(struct _file_helper* filehelper, vector* athletes);                //��ȡ�˶�Ա��Ϣ
	int (*GetEventData)(struct _file_helper* filehelper, vector* events);                    //��ȡ��Ŀ��Ϣ
	int (*GetInfoData)(struct _file_helper* filehelper, vector* infos);                      //��ȡ������Ϣ

	int (*OutputCollegeData)(struct _file_helper* filehelper, const vector* colleges);       //��ȡѧԺ��Ϣ
	int (*OutputAthleteData)(struct _file_helper* filehelper, const vector* athletes);       //��ȡ�˶�Ա��Ϣ
	int (*OutputEventData)(struct _file_helper* filehelper, const vector* events);           //��ȡ��Ŀ��Ϣ
	int (*OutputInfoData)(struct _file_helper* filehelper, const vector* infos);             //��ȡ������Ϣ

	int (*SetFileName)(struct _file_helper* filehelper, enum file filetype, const char* filename);



}FileHelper, * pFileHelper;

pFileHelper FileHelper_init();

int FileHelper_GetCollegeData(struct _FILE_HELPER* filehelper, vector* colleges);                //��ȡѧԺ��Ϣ
int FileHelper_GetAthleteData(struct _FILE_HELPER* filehelper, vector* athletes);                //��ȡ�˶�Ա��Ϣ
int FileHelper_GetEventData(struct _FILE_HELPER* filehelper, vector* events);                    //��ȡ��Ŀ��Ϣ
int FileHelper_GetInfoData(struct _FILE_HELPER* filehelper, vector* infos);                      //��ȡ������Ϣ

int FileHelper_OutputCollegeData(struct _FILE_HELPER* filehelper, const vector* colleges);       //��ȡѧԺ��Ϣ
int FileHelper_OutputAthleteData(struct _FILE_HELPER* filehelper, const vector* athletes);       //��ȡ�˶�Ա��Ϣ
int FileHelper_OutputEventData(struct _FILE_HELPER* filehelper, const vector* events);           //��ȡ��Ŀ��Ϣ
int FileHelper_OutputInfoData(struct _FILE_HELPER* filehelper, const vector* infos);             //��ȡ������Ϣ

int FileHelper_SetFileName(struct _FILE_HELPER* filehelper, enum file filetype, const char* filename);



//-----------     ����ϵͳ�ṹ��     ------------

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


//-----------     �����˵�     ------------

pManager pM;
pFileHelper pF;


#define COLLEGE_FILE             1   //11ѧԺ��Ϣ�ļ�
#define ATHLETE_FILE             2   //12�˶�Ա��Ϣ�ļ�
#define EVENT_FILE               3   //13��Ŀ��Ϣ�ļ�
#define INFO_FILE                4   //14������Ϣ�ļ�
#define COLLEGE_FIND             5   //21��ѯѧԺ��Ϣ
#define ATHLETE_FIND             6   //22��ѯ�˶�Ա��Ϣ
#define EVENT_FIND               7   //23��ѯ��Ŀ��Ϣ
#define COLLEGE_CHANGE           8   //21�޸�ѧԺ��Ϣ
#define ATHLETE_CHANGE           9   //22�޸��˶�Ա��Ϣ
#define EVENT_CHANGE             10  //23�޸���Ŀ��Ϣ
#define COLLEGE_ADD              11  //21���ѧԺ��Ϣ
#define ATHLETE_ADD              12  //22����˶�Ա��Ϣ
#define EVENT_ADD                13  //23�����Ŀ��Ϣ
#define COLLEGE_PATH             14  //11ѧԺ��Ϣ�ļ�
#define ATHLETE_PATH             15  //12�˶�Ա��Ϣ�ļ�
#define EVENT_PATH               16  //13��Ŀ��Ϣ�ļ�
#define INFO_PATH                17  //14������Ϣ�ļ�
#define COLLEGE_RANKING          18  //ѧԺ��������


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