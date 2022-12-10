#include "structs.h"

pFileHelper FileHelper_init()
{

	_FILE_HELPER* filehelper = (_FILE_HELPER*)malloc(sizeof(_FILE_HELPER));
	if (filehelper == NULL)return NULL;

	strcpy(filehelper->college_filename, "\0");
	strcpy(filehelper->athlete_filename, "\0");
	strcpy(filehelper->event_filename, "\0");
	strcpy(filehelper->info_filename, "\0");

	filehelper->GetCollegeData = FileHelper_GetCollegeData;
	filehelper->GetAthleteData = FileHelper_GetAthleteData;
	filehelper->GetEventData = FileHelper_GetEventData;
	filehelper->GetInfoData = FileHelper_GetInfoData;
	filehelper->OutputCollegeData = FileHelper_OutputCollegeData;
	filehelper->OutputAthleteData = FileHelper_OutputAthleteData;
	filehelper->OutputEventData = FileHelper_OutputEventData;
	filehelper->OutputInfoData = FileHelper_OutputInfoData;
	filehelper->SetFileName = FileHelper_SetFileName;

	return filehelper;
}

int FileHelper_GetCollegeData(struct _FILE_HELPER* filehelper, vector* colleges)
{

	//计算文件路径
	const char filepath[MAX_FILENAME_LENGTH + 5] = "\0";
	strcat(filepath, DATA_PATH);
	strcat(filepath, filehelper->college_filename);

	//打开文件
	FILE* fp = fopen(filepath, "r");
	if (fp == NULL) 
	{
		perror("fail to read");
		Exit(-1);
	}

	//读取文件
	char* head[3];
	int num = 0;

	//读取数量
	fscanf(fp, "%d", &num);
	//printf("%d\n",num);
	
	//head
	head[0] = (char*)malloc(3000);
	head[1] = (char*)malloc(3000);
	head[2] = (char*)malloc(3000);
	fscanf(fp, "%s %s %s", head[0], head[1], head[2]);
	free(head[0]);
	free(head[1]);
	free(head[2]);



	for (int i = 0; i < num; i++) {


		pCollege college = (pCollege)malloc(sizeof(College));

		fscanf(fp, "%d %s %d", &college->ID, college->name, &college->total_score);

		colleges->push_back(colleges, college);

		//printf("%d %s %d\n", ((pCollege)(colleges->back(colleges)))->ID, ((pCollege)(colleges->at(colleges, i)))->name, ((pCollege)(colleges->at(colleges, i)))->total_score);

	}

	//printf("%d\n", colleges->size(colleges));

	fclose(fp);

	return 0;
}
int FileHelper_GetAthleteData(struct _FILE_HELPER* filehelper, vector* athletes)
{
	//计算文件路径
	const char filepath[MAX_FILENAME_LENGTH + 5] = "\0";
	strcat(filepath, DATA_PATH);
	strcat(filepath, filehelper->athlete_filename);

	//打开文件
	FILE* fp = fopen(filepath, "r");
	if (fp == NULL)
	{
		perror("fail to read");
		Exit(-1);
	}

	//读取文件
	char* head[4];
	int num = 0;

	//读取数量
	fscanf(fp, "%d", &num);
	//printf("%d\n",num);

	//head
	head[0] = (char*)malloc(3000);
	head[1] = (char*)malloc(3000);
	head[2] = (char*)malloc(3000);
	head[3] = (char*)malloc(3000);
	fscanf(fp, "%s %s %s %s", head[0], head[1], head[2], head[3]);
	free(head[0]);
	free(head[1]);
	free(head[2]);
	free(head[3]);



	for (int i = 0; i < num; i++) {


		pAthlete athlete = (pAthlete)malloc(sizeof(Athlete));

		fscanf(fp, "%d %s %d %d", &athlete->ID, athlete->name, &athlete->sex, &athlete->college_ID);

		athlete->num_of_event = 0;

		athletes->push_back(athletes, athlete);

	}


	fclose(fp);

	return 0;
}
int FileHelper_GetEventData(struct _FILE_HELPER* filehelper, vector* events)
{
	//计算文件路径
	const char filepath[MAX_FILENAME_LENGTH + 5] = "\0";
	strcat(filepath, DATA_PATH);
	strcat(filepath, filehelper->event_filename);

	//打开文件
	FILE* fp = fopen(filepath, "r");
	if (fp == NULL)
	{
		perror("fail to read");
		Exit(-1);
	}

	//读取文件
	char* head[2];
	int num = 0;

	//读取数量
	fscanf(fp, "%d", &num);
	//printf("%d\n",num);

	//head
	head[0] = (char*)malloc(3000);
	head[1] = (char*)malloc(3000);
	fscanf(fp, "%s %s", head[0], head[1]);
	free(head[0]);
	free(head[1]);



	for (int i = 0; i < num; i++) {


		pEvent event = (pEvent)malloc(sizeof(Event));

		fscanf(fp, "%d %s", &event->ID, event->name);

		events->push_back(events, event);

	}

	fclose(fp);

	return 0;
}
int FileHelper_GetInfoData(struct _FILE_HELPER* filehelper, vector* infos)
{
	//计算文件路径
	const char filepath[MAX_FILENAME_LENGTH + 5] = "\0";
	strcat(filepath, DATA_PATH);
	strcat(filepath, filehelper->info_filename);

	//打开文件
	FILE* fp = fopen(filepath, "r");
	if (fp == NULL)
	{
		perror("fail to read");
		Exit(-1);
	}

	//读取文件
	char* head[3];
	int num = 0;

	//读取数量
	fscanf(fp, "%d", &num);
	//printf("%d\n",num);

	//head
	head[0] = (char*)malloc(3000);
	head[1] = (char*)malloc(3000);
	head[2] = (char*)malloc(3000);
	fscanf(fp, "%s %s %s", head[0], head[1], head[2]);
	free(head[0]);
	free(head[1]);
	free(head[2]);



	for (int i = 0; i < num; i++) {


		pInfo info = (pInfo)malloc(sizeof(Info));

		fscanf(fp, "%d %d %d", &info->athletes_ID, &info->event_ID, &info->ranking);

		infos->push_back(infos, info);


	}


	fclose(fp);

	return 0;
}
int FileHelper_OutputCollegeData(struct _FILE_HELPER* filehelper, const vector* colleges)
{
	return 0;
}
int FileHelper_OutputAthleteData(struct _FILE_HELPER* filehelper, const vector* athletes)
{
	return 0;
}
int FileHelper_OutputEventData(struct _FILE_HELPER* filehelper, const vector* events)
{
	return 0;
}
int FileHelper_OutputInfoData(struct _FILE_HELPER* filehelper, const vector* infos)
{
	return 0;
}
int FileHelper_SetFileName(struct _FILE_HELPER* filehelper, enum file filetype, const char* filename)
{

	switch (filetype) {

	case college_filename:

		strcpy(filehelper->college_filename, filename);

		break;

	case athlete_filename:

		strcpy(filehelper->athlete_filename, filename);

		break;

	case event_filename:

		strcpy(filehelper->event_filename, filename);

		break;

	case info_filename:

		strcpy(filehelper->info_filename, filename);

		break;

	default:

		break;

	}

	return 0;
}

pManager Manager_init()
{

	pManager manager = (pManager)malloc(sizeof(Manager));
	if (manager == NULL)return NULL;

	manager->colleges = Vector_init(sizeof(College));
	manager->athletes = Vector_init(sizeof(Athlete));
	manager->events = Vector_init(sizeof(Event));
	manager->infos = Vector_init(sizeof(Info));

	return manager;

}

void ProcessingData(struct _manager* manager)
{

	for (size_t i = 0; i < manager->infos->size(manager->infos); i++) {

		unsigned int athletes_ID = ((pInfo)(manager->infos->at(manager->infos, i)))->athletes_ID;
		unsigned int event_ID = ((pInfo)(manager->infos->at(manager->infos, i)))->event_ID;
		unsigned int ranking = ((pInfo)(manager->infos->at(manager->infos, i)))->ranking;
		unsigned int college_ID;

		//记录运动员参赛记录
		for (size_t j = 0; j < manager->athletes->size(manager->athletes); j++) {

			if (((pAthlete)manager->athletes->at(manager->athletes, j))->ID == athletes_ID) {

				pAthlete p = ((pAthlete)manager->athletes->at(manager->athletes, j));
				p->events[p->num_of_event] = event_ID;
				p->ranking[p->num_of_event] = ranking;
				p->num_of_event++;
				college_ID = p->college_ID;

			}

		}

		//计算学院总分
		if (ranking <= 3) {

			for (size_t j = 0; j < manager->colleges->size(manager->colleges); j++) {

				if (((pCollege)manager->colleges->at(manager->colleges, j))->ID == college_ID) {

					((pCollege)manager->colleges->at(manager->colleges, j))->total_score += ((3 - ranking) * 2 + 1);

				}

			}

		}



	}

}
void Sort(struct _manager* manager, enum sort sort_type)
{
	switch (sort_type) {

	case college_score:
		manager->colleges->sort(manager->colleges, sort_college_score);
		break;

	case colleges_ID:
		manager->colleges->sort(manager->colleges, sort_college_id);
		break;

	}
}
int sort_college_score(const void* a, const void* b) {

	return ((pCollege)b)->total_score - ((pCollege)a)->total_score;

}
int sort_college_id(const void* a, const void* b) {

	return ((pCollege)a)->ID - ((pCollege)b)->ID;

}
void* Search(struct _manager* manager, enum data data_type, unsigned int* id)
{

	void* pV = NULL;


	switch (data_type) {

	case college:

		pV = manager->colleges->find(manager->colleges, id, search_college);

		break;

	case athlete:

		pV = manager->athletes->find(manager->athletes, id, search_athlete);

		break;

	case event:

		pV = manager->events->find(manager->events, id, search_event);

		break;


	}


	return pV;
}
int search_college(const void* val1, const void* val2)
{
	if (((pCollege)val1)->ID == *(unsigned int*)val2) return 1;
	else return 0;
}
int search_athlete(const void* val1, const void* val2)
{
	if (((pAthlete)val1)->ID == *(unsigned int*)val2) return 1;
	else return 0;
}
int search_event(const void* val1, const void* val2)
{
	if (((pEvent)val1)->ID == *(unsigned int*)val2) return 1;
	else return 0;
}

int Menu()
{
	int menuitem;
	int item;
	while (1)
	{
		menuitem = -1;
		item = -1;
		while (menuitem != 1 && menuitem != 2 && menuitem != 3 && menuitem != 4 && menuitem != 5 && menuitem != 6)
		{
			system("cls");	//清屏 
			color(9);
			printf("                主功能菜单                 \n");
			color(4);
			printf("请按0退出，直接关闭cmd可能会引起程序异常退出！\n");
			color(7);

			printf("*******************************************\n");
			printf("**                                       **\n");
			printf("**           1. 数据展示                 **\n");
			printf("**           2. 信息查询                 **\n");
			printf("**           3. 修改信息                 **\n");
			printf("**           4. 添加信息                 **\n");
			printf("**           5. 生成学院排名             **\n");
			printf("**           6. 更改链接数据文件路径     **\n");
			printf("**           0. 退出                     **\n");
			printf("**                                       **\n");
			printf("*******************************************\n");
			color(9);
			printf("请选择(0-6):");
			color(7);


			int flag = scanf("%d", &menuitem);
			scanf("%*[^\n]"); scanf("%*c");
			while (flag != 1 || menuitem < 0 || menuitem > 6) {
				color(4);
				printf("请输入正确的指令\n");
				color(7);
				flag = scanf("%d", &menuitem);
				scanf("%*[^\n]"); scanf("%*c");
			}



			if (menuitem == 0)
			{
				printf("欢迎下次使用！（按回车键继续...）");
				getchar();
				Exit(0);
			}
		}
		switch (menuitem)
		{
		case 1:
		{
			while (item != 1 && item != 2 && item != 3 && item != 4)
			{

				system("cls");	//清屏 

				color(9);
				printf("               数据展示菜单                \n");
				color(4);
				printf("请按0退出，直接关闭cmd可能会引起程序异常退出！\n");
				color(7);

				printf("*******************************************\n");
				printf("**                                       **\n");
				printf("**           1. 学院信息文件             **\n");
				printf("**           2. 运动员信息文件           **\n");
				printf("**           3. 项目信息文件             **\n");
				printf("**           4. 参赛信息文件             **\n");
				printf("**           0. 返回                     **\n");
				printf("**                                       **\n");
				printf("*******************************************\n");

				color(9);
				printf("请选择(0-4):");
				color(7);


				int flag = scanf("%d", &item);
				scanf("%*[^\n]"); scanf("%*c");
				while (flag != 1 || item < 0 || item > 4) {
					color(4);
					printf("请输入正确的指令\n");
					color(7);
					flag = scanf("%d", &item);
					scanf("%*[^\n]"); scanf("%*c");
				}


				if (item == 0) break;
			}

			switch (item)
			{
			case 1:
				return COLLEGE_FILE;
			case 2:
				return ATHLETE_FILE;
			case 3:
				return EVENT_FILE;
			case 4:
				return INFO_FILE;
			}
			break;
		}
		case 2:
		{
			while (item != 1 && item != 2 && item != 3)
			{
				system("cls");	//清屏 
				color(9);
				printf("               信息查询菜单                \n");
				color(4);
				printf("请按0退出，直接关闭cmd可能会引起程序异常退出！\n");
				color(7);
				printf("*******************************************\n");
				printf("**                                       **\n");
				printf("**           1. 查询学院信息             **\n");
				printf("**           2. 查询运动员信息           **\n");
				printf("**           3. 查询项目信息             **\n");
				printf("**           0. 返回                     **\n");
				printf("**                                       **\n");
				printf("*******************************************\n");

				color(9);
				printf("请选择(0-3):");
				color(7);

				int flag = scanf("%d", &item);
				scanf("%*[^\n]"); scanf("%*c");
				while (flag != 1 || item < 0 || item > 3) {
					color(4);
					printf("请输入正确的指令\n");
					color(7);
					flag = scanf("%d", &item);
					scanf("%*[^\n]"); scanf("%*c");
				}				if (item == 0) break;
			}

			switch (item)
			{
			case 1:
				return COLLEGE_FIND;
			case 2:
				return ATHLETE_FIND;
			case 3:
				return EVENT_FIND;
			}
			break;
		}
		case 3:
		{
			while (item != 1 && item != 2 && item != 3)
			{
				system("cls");	//清屏 
				color(9);
				printf("               修改信息菜单                \n");
				color(4);
				printf("请按0退出，直接关闭cmd可能会引起程序异常退出！\n");
				color(7);
				printf("*******************************************\n");
				printf("**                                       **\n");
				printf("**           1. 修改学院信息             **\n");
				printf("**           2. 修改运动员信息           **\n");
				printf("**           3. 修改项目信息             **\n");
				printf("**           0. 返回                     **\n");
				printf("**                                       **\n");
				printf("*******************************************\n");

				color(9);
				printf("请选择(0-3):");
				color(7);
				int flag = scanf("%d", &item);
				scanf("%*[^\n]"); scanf("%*c");
				while (flag != 1 || item < 0 || item > 3) {
					color(4);
					printf("请输入正确的指令\n");
					color(7);
					flag = scanf("%d", &item);
					scanf("%*[^\n]"); scanf("%*c");
				}				if (item == 0) break;
			}

			switch (item)
			{
			case 1:
				return COLLEGE_CHANGE;
			case 2:
				return ATHLETE_CHANGE;
			case 3:
				return EVENT_CHANGE;
			}
			break;

		}
		case 4:
		{
			while (item != 1 && item != 2 && item != 3)
			{
				system("cls");	//清屏 
				color(9);
				printf("               添加信息菜单                \n");
				color(4);
				printf("请按0退出，直接关闭cmd可能会引起程序异常退出！\n");
				color(7);
				printf("*******************************************\n");
				printf("**                                       **\n");
				printf("**           1. 添加学院信息             **\n");
				printf("**           2. 添加运动员信息           **\n");
				printf("**           3. 添加项目信息             **\n");
				printf("**           0. 返回                     **\n");
				printf("**                                       **\n");
				printf("*******************************************\n");

				color(9);
				printf("请选择(0-3):");
				color(7);
				int flag = scanf("%d", &item);
				scanf("%*[^\n]"); scanf("%*c");
				while (flag != 1 || item < 0 || item > 3) {
					color(4);
					printf("请输入正确的指令\n");
					color(7);
					flag = scanf("%d", &item);
					scanf("%*[^\n]"); scanf("%*c");
				}				if (item == 0) break;
			}

			switch (item)
			{
			case 1:
				return COLLEGE_ADD;
			case 2:
				return ATHLETE_ADD;
			case 3:
				return EVENT_ADD;
			}
			break;

		}

		case 5:
		{

			return COLLEGE_RANKING;

		}
		case 6:
		{
			while (item != 1 && item != 2 && item != 3 && item != 4)
			{
				system("cls");	//清屏 
				color(9);
				printf("           更改链接数据文件路径            \n");
				color(4);
				printf("请按0退出，直接关闭cmd可能会引起程序异常退出！\n");
				color(7);
				printf("*******************************************\n");
				printf("**                                       **\n");
				printf("**         1. 学院信息文件路径           **\n");
				printf("**         2. 运动员信息文件路径         **\n");
				printf("**         3. 项目信息文件路径           **\n");
				printf("**         4. 参赛信息文件路径           **\n");
				printf("**         0. 返回                       **\n");
				printf("**                                       **\n");
				printf("*******************************************\n");

				color(9);
				printf("请选择(0-4):");
				color(7);
				int flag = scanf("%d", &item);
				scanf("%*[^\n]"); scanf("%*c");
				while (flag != 1 || item < 0 || item > 4) {
					color(4);
					printf("请输入正确的指令\n");
					color(7);
					flag = scanf("%d", &item);
					scanf("%*[^\n]"); scanf("%*c");
				}				if (item == 0) break;
			}

			switch (item)
			{
			case 1:
				return COLLEGE_PATH;
			case 2:
				return ATHLETE_PATH;
			case 3:
				return EVENT_PATH;
			case 4:
				return INFO_PATH;
			}
			break;

		}

		}
		
	}

}

void Exit(int info)
{

	pM->athletes->clear(pM->athletes);
	pM->colleges->clear(pM->colleges);
	pM->events->clear(pM->events);
	pM->infos->clear(pM->infos);
	free(pM);
	free(pF);

	exit(info);
}

void COLLEGE_FILE_FUN() {

	color(9);
	printf("\n学院编号  学院名称\n");
	color(7);
	for (size_t i = 0; i < pM->colleges->size(pM->colleges); i++) {

		pCollege pC = (pCollege)(pM->colleges->at(pM->colleges, i));


		printf(" %d\t  %s\n",

			pC->ID,
			pC->name);

	}
}
void ATHLETE_FILE_FUN() {


	color(9);
	printf("\n运动员编号  运动员名称  性别  所属学院\n");
	color(7);

	for (size_t i = 0; i < pM->athletes->size(pM->athletes); i++) {

		pAthlete pA = (pAthlete)(pM->athletes->at(pM->athletes, i));

		printf("  %d     %s\t%s    %d\n",
			pA->ID,
			pA->name,
			pA->sex?"男":"女",
			pA->college_ID);

	}

}
void EVENT_FILE_FUN() {


	color(9);
	printf("\n项目编号  项目名称\n");
	color(7);

	for (size_t i = 0; i < pM->events->size(pM->events); i++) {

		printf(" %d    %s\n",
			((pAthlete)(pM->events->at(pM->events, i)))->ID,
			((pAthlete)(pM->events->at(pM->events, i)))->name);

	}

}
void INFO_FILE_FUN() {


	color(9);
	printf("\n运动员编号  项目编号  排名\n");
	color(7);


	for (size_t i = 0; i < pM->infos->size(pM->infos); i++) {

		printf("  %d     %d     %d\n",
			((pInfo)(pM->infos->at(pM->infos, i)))->athletes_ID,
			((pInfo)(pM->infos->at(pM->infos, i)))->event_ID,
			((pInfo)(pM->infos->at(pM->infos, i)))->ranking);

	}

}
void COLLEGE_FIND_FUN() {

	color(9);
	printf("请输入要查找的学院编号（五位编号）：\n");
	color(7);

	unsigned int id = 0;
	int flag = 0;

	flag = scanf("%d", &id);
	scanf("%*[^\n]"); scanf("%*c");


	while (flag != 1 || id < 10000 || id >= 100000) {


		color(4);
		printf("请输入正确的格式，例如：10032\n");
		color(7);

		flag = scanf("%d", &id);

		scanf("%*[^\n]"); scanf("%*c");

	}



	pCollege pC = Search(pM, college, &id);

	if (pC == NULL) {

		color(4);
		printf("没找到！\n");
		color(7);
		return;

	}
	else {

		printf("编号：%d  名称：%s  总分：%d\n", pC->ID, pC->name, pC->total_score);
		return;

	}

}
void ATHLETE_FIND_FUN() {

	color(9);
	printf("请输入要查找的运动员编号（五位编号）：\n");
	color(7);

	unsigned int id = 0;
	int flag = 0;

	flag = scanf("%d", &id);
	scanf("%*[^\n]"); scanf("%*c");


	while (flag != 1 || id < 10000 || id >= 100000) {


		color(4);
		printf("请输入正确的格式，例如：10032\n");
		color(7);

		flag = scanf("%d", &id);

		scanf("%*[^\n]"); scanf("%*c");

	}


	pAthlete pA = Search(pM, athlete, &id);

	if (pA == NULL) {

		color(4);
		printf("没找到！\n");
		color(7);
		return;

	}
	else {

		pCollege pC = Search(pM, college, &pA->college_ID);

		printf("编号：%d  姓名：%s  性别：%s  所属学院：%s\n", pA->ID, pA->name, pA->sex ? "男" : "女", pC->name);
		if (pA->num_of_event == 0)printf("该运动员未参加项目\n");
		else {

			printf("该运动员参加的项目：\n");
			for (int i = 0; i < pA->num_of_event; i++) {

				pEvent pE = Search(pM, event, &pA->events[i]);

				printf("项目名称：%s  名次：%d\n", pE->name, pA->ranking[i]);

			}
			printf("\n");

		}

		return;

	}

}
void EVENT_FIND_FUN() {

	color(9);
	printf("请输入要查找的项目编号（五位编号）：\n");
	color(7);

	unsigned int id = 0;
	int flag = 0;

	flag = scanf("%d", &id);
	scanf("%*[^\n]"); scanf("%*c");


	while (flag != 1 || id < 10000 || id >= 100000) {


		color(4);
		printf("请输入正确的格式，例如：10032\n");
		color(7);

		flag = scanf("%d", &id);

		scanf("%*[^\n]"); scanf("%*c");

	}


	pEvent pE = Search(pM, event, &id);

	if (pE == NULL) {

		color(4);
		printf("没找到！\n");
		color(7);

		return;

	}
	else {

		printf("编号：%d  名称：%s\n", pE->ID, pE->name);
		return;

	}

}
void COLLEGE_CHANGE_FUN() {


	color(9);
	printf("请输入要修改的学院编号（五位编号）：\n");
	color(7);

	unsigned int id = 0;
	int flag = 0;

	flag = scanf("%d", &id);
	scanf("%*[^\n]"); scanf("%*c");


	while (flag != 1 || id < 10000 || id >= 100000) {


		color(4);
		printf("请输入正确的格式，例如：10032\n");
		color(7);

		flag = scanf("%d", &id);

		scanf("%*[^\n]"); scanf("%*c");


	}


	pCollege pC = Search(pM, college, &id);

	if (pC == NULL) {

		color(4);
		printf("没找到！\n");
		color(7);
		return;

	}
	else {

		printf("学院信息：");
		printf("编号：%d  名称：%s  总分：%d\n", pC->ID, pC->name, pC->total_score);
		color(9);
		printf("请输入修改后的名称（在50字节内）：\n");
		color(7);



		char new_name[1024];
		flag = 0;
		size_t size = 0;

		flag = scanf("%s", new_name);
		size = strlen(new_name);
		scanf("%*[^\n]"); scanf("%*c");

		while (flag != 1 || size > MAX_NAME_LENGTH) {

			color(4);
			printf("请输入正确的格式，例如：网安学院\n");
			color(7);
			flag = scanf("%s", new_name);
			size = strlen(new_name);
			scanf("%*[^\n]"); scanf("%*c");

		}

		color(9);
		printf("确认修改吗？（ Yes 1 \ No 0 ）%s\n", new_name);
		color(7);

		int yes = -1;
		flag = scanf("%d", &yes);
		scanf("%*[^\n]"); scanf("%*c");

		while (flag != 1 || yes < 0 || yes>1) {

			color(4);
			printf("请输入正确的格式\n");
			color(7);
			flag = scanf("%d", &yes);
			scanf("%*[^\n]"); scanf("%*c");

		}
		color(9);
		if (yes == 1) {
			strcpy(pC->name, new_name);
			printf("修改成功！\n");
			color(7);

		}
		else {
			printf("取消修改！\n");
			color(7);

		}



	}

}
void ATHLETE_CHANGE_FUN() {


	color(9);
	printf("请输入要修改的运动员编号（五位编号）：\n");
	color(7);

	unsigned int id = 0;
	int flag = 0;

	flag = scanf("%d", &id);
	scanf("%*[^\n]"); scanf("%*c");


	while (flag != 1 || id < 10000 || id >= 100000) {


		color(4);
		printf("请输入正确的格式，例如：10032\n");
		color(7);

		flag = scanf("%d", &id);

		scanf("%*[^\n]"); scanf("%*c");

	}



	pAthlete pA = Search(pM, athlete, &id);

	if (pA == NULL) {

		color(4);
		printf("没找到！\n");
		color(7);
		return;

	}
	else {

		pCollege pC = Search(pM, college, &pA->college_ID);

		printf("编号：%d  姓名：%s  性别：%s  所属学院：%s\n", pA->ID, pA->name, pA->sex ? "男" : "女", pC->name);
		if (pA->num_of_event == 0)printf("该运动员未参加项目\n");
		else {

			printf("该运动员参加的项目：\n");
			for (int i = 0; i < pA->num_of_event; i++) {

				pEvent pE = Search(pM, event, &pA->events[i]);

				printf("项目名称：%s  名次：%d\n", pE->name, pA->ranking[i]);

			}

		}

		char new_name[1024];
		flag = 0;
		size_t size = 0;

		flag = scanf("%s", new_name);
		size = strlen(new_name);
		scanf("%*[^\n]"); scanf("%*c");

		while (flag != 1 || size > MAX_NAME_LENGTH) {

			color(4);
			printf("请输入正确的格式，例如：小王\n");
			color(7);
			flag = scanf("%s", new_name);
			size = strlen(new_name);
			scanf("%*[^\n]"); scanf("%*c");

		}

		color(9);
		printf("确认修改吗？（ Yes 1 \ No 0 ）%s\n", new_name);
		color(7);

		int yes = -1;
		flag = scanf("%d", &yes);
		scanf("%*[^\n]"); scanf("%*c");

		while (flag != 1 || yes < 0 || yes>1) {

			color(4);
			printf("请输入正确的格式\n");
			color(7);
			flag = scanf("%d", &yes);
			scanf("%*[^\n]"); scanf("%*c");

		}
		color(9);
		if (yes == 1) {
			strcpy(pA->name, new_name);
			printf("修改成功！\n");
			color(7);

		}
		else {
			printf("取消修改！\n");
			color(7);

		}

		return;

	}

}
void EVENT_CHANGE_FUN() {


	color(9);
	printf("请输入要修改的项目编号（五位编号）：\n");
	color(7);

	unsigned int id = 0;
	int flag = 0;

	flag = scanf("%d", &id);
	scanf("%*[^\n]"); scanf("%*c");


	while (flag != 1 || id < 10000 || id >= 100000) {


		color(4);
		printf("请输入正确的格式，例如：10032\n");
		color(7);

		flag = scanf("%d", &id);

		scanf("%*[^\n]"); scanf("%*c");

	}



	pEvent pE = Search(pM, event, &id);

	if (pE == NULL) {

		color(4);
		printf("没找到！\n");
		color(7);

		return;

	}
	else {

		printf("编号：%d  名称：%s\n", pE->ID, pE->name);
		color(9);
		printf("请输入修改后的名称：\n");
		color(7);



		char new_name[1024];
		flag = 0;
		size_t size = 0;

		flag = scanf("%s", new_name);
		size = strlen(new_name);
		scanf("%*[^\n]"); scanf("%*c");

		while (flag != 1 || size > MAX_NAME_LENGTH) {

			color(4);
			printf("请输入正确的格式，例如：男子800米\n");
			color(7);
			flag = scanf("%s", new_name);
			size = strlen(new_name);
			scanf("%*[^\n]"); scanf("%*c");

		}

		color(9);
		printf("确认修改吗？（ Yes 1 \ No 0 ）%s\n", new_name);
		color(7);

		int yes = -1;
		flag = scanf("%d", &yes);
		scanf("%*[^\n]"); scanf("%*c");

		while (flag != 1 || yes < 0 || yes>1) {

			color(4);
			printf("请输入正确的格式\n");
			color(7);
			flag = scanf("%d", &yes);
			scanf("%*[^\n]"); scanf("%*c");

		}
		color(9);
		if (yes == 1) {
			strcpy(pE->name, new_name);
			printf("修改成功！\n");
			color(7);

		}
		else {
			printf("取消修改！\n");
			color(7);

		}

		return;

	}

}


void COLLEGE_ADD_FUN() {

	color(9);
	printf("请输入要添加学院的编号：\n");
	color(7);


	unsigned int id = 0;
	int flag = 0;

	flag = scanf("%d", &id);
	scanf("%*[^\n]"); scanf("%*c");


	while (flag != 1 || id < 10000 || id >= 100000) {


		color(4);
		printf("请输入正确的格式，例如：10032\n");
		color(7);

		flag = scanf("%d", &id);

		scanf("%*[^\n]"); scanf("%*c");

	}



	pCollege pC = Search(pM, college, &id);

	if (pC != NULL) {

		color(4);
		printf("该编号的学院已经存在\n");
		color(7);

		return;

	}
	else {

		pCollege new_pC = (pCollege)malloc(sizeof(College));

		new_pC->ID = id;
		new_pC->total_score = 0;

		color(9);
		printf("请输入要添加学院的名称：\n");
		color(7);



		char new_name[1024];
		flag = 0;
		size_t size = 0;

		flag = scanf("%s", new_name);
		size = strlen(new_name);
		scanf("%*[^\n]"); scanf("%*c");

		while (flag != 1 || size > MAX_NAME_LENGTH) {

			color(4);
			printf("请输入正确的格式，例如：网安学院\n");
			color(7);
			flag = scanf("%s", new_name);
			size = strlen(new_name);
			scanf("%*[^\n]"); scanf("%*c");

		}

		strcpy(new_pC->name, new_name);

		color(9);
		printf("确认添加吗？（ Yes 1 \ No 0 ）%s\n", new_name);
		color(7);

		int yes = -1;
		flag = scanf("%d", &yes);
		scanf("%*[^\n]"); scanf("%*c");

		while (flag != 1 || yes < 0 || yes>1) {

			color(4);
			printf("请输入正确的格式\n");
			color(7);
			flag = scanf("%s", new_name);
			size = strlen(new_name);
			scanf("%*[^\n]"); scanf("%*c");

		}
		if (yes == 1) {
			pM->colleges->push_back(pM->colleges, new_pC);
			color(9);
			printf("添加成功！\n");
			color(7);

		}
		else {
			free(new_pC);
			color(9);
			printf("取消添加！\n");
			color(7);

		}


		return;
	}


}
void ATHLETE_ADD_FUN() {

	color(9);
	printf("请输入要添加运动员的编号：\n");
	color(7);
	unsigned int id = 0;
	int flag = 0;

	flag = scanf("%d", &id);
	scanf("%*[^\n]"); scanf("%*c");


	while (flag != 1 || id < 10000 || id >= 100000) {


		color(4);
		printf("请输入正确的格式，例如：10032\n");
		color(7);

		flag = scanf("%d", &id);

		scanf("%*[^\n]"); scanf("%*c");

	}




	pAthlete pC = Search(pM, athlete, &id);

	if (pC != NULL) {

		color(4);
		printf("该编号的运动员已经存在\n");
		color(7);
		return;

	}
	else {

		pAthlete new_pA = (pAthlete)malloc(sizeof(Athlete));

		new_pA->ID = id;
		new_pA->num_of_event = 0;

		color(9);
		printf("请输入要添加运动员的名称：\n");
		color(7);

		char new_name[1024];
		flag = 0;
		size_t size = 0;

		flag = scanf("%s", new_name);
		size = strlen(new_name);
		scanf("%*[^\n]"); scanf("%*c");

		while (flag != 1 || size > MAX_NAME_LENGTH) {

			color(4);
			printf("请输入正确的格式，例如：小王\n");
			color(7);
			flag = scanf("%s", new_name);
			size = strlen(new_name);
			scanf("%*[^\n]"); scanf("%*c");

		}

		strcpy(new_pA->name, new_name);






		printf("请输入要添加运动员的性别：（男生为 1，女生为0）\n");

		int sex = -1;
		flag = scanf("%d", &sex);
		scanf("%*[^\n]"); scanf("%*c");

		while (flag != 1 || sex < 0 || sex>1) {

			color(4);
			printf("请输入正确的格式\n");
			color(7);
			flag = scanf("%d", &sex);
			scanf("%*[^\n]"); scanf("%*c");

		}

		new_pA->sex = sex;




		color(9);
		printf("确认添加吗？（ Yes 1 \ No 0 ）%s\n", new_name);
		color(7);

		int yes = -1;
		flag = scanf("%d", &yes);
		scanf("%*[^\n]"); scanf("%*c");

		while (flag != 1 || yes < 0 || yes>1) {

			color(4);
			printf("请输入正确的格式\n");
			color(7);
			flag = scanf("%d", &yes);
			scanf("%*[^\n]"); scanf("%*c");

		}

		if (yes == 1) {
			pM->athletes->push_back(pM->athletes, new_pA);
			color(9);
			printf("添加成功！\n");
			color(7);

		}
		else {
			free(new_pA);
			color(9);
			printf("取消添加！\n");
			color(7);

		}

		return;
	}

}
void EVENT_ADD_FUN() {

	color(9);
	printf("请输入要添加项目的编号：\n");
	color(7);
	unsigned int id = 0;
	int flag = 0;

	flag = scanf("%d", &id);
	scanf("%*[^\n]"); scanf("%*c");


	while (flag != 1 || id < 10000 || id >= 100000) {


		color(4);
		printf("请输入正确的格式，例如：10032\n");
		color(7);

		flag = scanf("%d", &id);

		scanf("%*[^\n]"); scanf("%*c");

	}

	pEvent pE = Search(pM, event, &id);

	if (pE != NULL) {

		color(4);
		printf("该编号的项目已经存在\n");
		color(7);
		return;

	}
	else {


		pEvent new_pE = (pEvent)malloc(sizeof(Event));

		new_pE->ID = id;

		color(9);
		printf("请输入要添加项目的名称：\n");
		color(7);
		char new_name[1024];
		flag = 0;
		size_t size = 0;

		flag = scanf("%s", new_pE->name);
		size = strlen(new_name);
		scanf("%*[^\n]"); scanf("%*c");

		while (flag != 1 || size > MAX_NAME_LENGTH) {

			color(4);
			printf("请输入正确的格式，例如：男子800米\n");
			color(7);
			flag = scanf("%s", new_name);
			size = strlen(new_name);
			scanf("%*[^\n]"); scanf("%*c");

		}

		strcpy(new_pE->name, new_name);

		color(9);
		printf("确认添加吗？（ Yes 1 \ No 0 ）%s\n", new_name);
		color(7);
		int yes = -1;
		flag = scanf("%d", &yes);
		scanf("%*[^\n]"); scanf("%*c");

		while (flag != 1 || yes < 0 || yes>1) {

			color(4);
			printf("请输入正确的格式\n");
			color(7);
			flag = scanf("%s", new_name);
			size = strlen(new_name);
			scanf("%*[^\n]"); scanf("%*c");

		}
		if (yes == 1) {
			pM->events->push_back(pM->events, new_pE);
			color(9);
			printf("添加成功！\n");
			color(7);
		}
		else {
			free(new_pE);
			color(9);
			printf("取消添加！\n");
			color(7);
		}

		return;
	}

}


void COLLEGE_PATH_FUN() {

	printf("当前文件：%s\n", ((_FILE_HELPER*)pF)->college_filename);
	color(9);
	printf("请输入新的文件名，并确保文件在\\data\\目录下：\n");
	color(7);
	char new_name[1024];
	int flag = 0;
	size_t size = 0;

	flag = scanf("%s", new_name);
	size = strlen(new_name);
	scanf("%*[^\n]"); scanf("%*c");

	while (flag != 1 || size > MAX_FILENAME_LENGTH) {

		color(4);
		printf("请输入正确的格式，例如：data.txt\n");
		color(7);
		flag = scanf("%s", new_name);
		size = strlen(new_name);
		scanf("%*[^\n]"); scanf("%*c");

	}

	color(9);
	printf("确认修改吗？（ Yes 1 \ No 0 ）%s\n", new_name);
	color(7);
	int yes = -1;
	flag = scanf("%d", &yes);
	scanf("%*[^\n]"); scanf("%*c");

	while (flag != 1 || yes < 0 || yes>1) {

		color(4);
		printf("请输入正确的格式\n");
		color(7);
		flag = scanf("%d", &yes);
		scanf("%*[^\n]"); scanf("%*c");

	}

	if (yes == 1) {
		pF->SetFileName(pF, college_filename, new_name);
		color(9);

		printf("修改成功！\n");
		color(7);
	}
	else {
		color(9);

		printf("取消修改！\n");
		color(7);

	}



}
void ATHLETE_PATH_FUN() {

	printf("当前文件：%s\n", ((_FILE_HELPER*)pF)->athlete_filename);
	color(9);
	printf("请输入新的文件名，并确保文件在\\data\\目录下：\n");
	color(7);

	char new_name[1024];
	int flag = 0;
	size_t size = 0;

	flag = scanf("%s", new_name);
	size = strlen(new_name);
	scanf("%*[^\n]"); scanf("%*c");

	while (flag != 1 || size > MAX_FILENAME_LENGTH) {

		color(4);
		printf("请输入正确的格式，例如：data.txt\n");
		color(7);
		flag = scanf("%s", new_name);
		size = strlen(new_name);
		scanf("%*[^\n]"); scanf("%*c");

	}

	color(9);
	printf("确认修改吗？（ Yes 1 \ No 0 ）%s\n", new_name);
	color(7);
	int yes = -1;
	flag = scanf("%d", &yes);
	scanf("%*[^\n]"); scanf("%*c");

	while (flag != 1 || yes < 0 || yes>1) {

		color(4);
		printf("请输入正确的格式\n");
		color(7);
		flag = scanf("%d", &yes);
		scanf("%*[^\n]"); scanf("%*c");

	}

	if (yes == 1) {
		pF->SetFileName(pF, athlete_filename, new_name);
		color(9);

		printf("修改成功！\n");
		color(7);
	}
	else {
		color(9);

		printf("取消修改！\n");
		color(7);

	}



}
void EVENT_PATH_FUN() {

	printf("当前文件：%s\n", ((_FILE_HELPER*)pF)->event_filename);
	color(9);
	printf("请输入新的文件名，并确保文件在\\data\\目录下：\n");
	color(7);


	char new_name[1024];
	int flag = 0;
	size_t size = 0;

	flag = scanf("%s", new_name);
	size = strlen(new_name);
	scanf("%*[^\n]"); scanf("%*c");

	while (flag != 1 || size > MAX_FILENAME_LENGTH) {

		color(4);
		printf("请输入正确的格式，例如：data.txt\n");
		color(7);
		flag = scanf("%s", new_name);
		size = strlen(new_name);
		scanf("%*[^\n]"); scanf("%*c");

	}

	color(9);
	printf("确认修改吗？（ Yes 1 \ No 0 ）%s\n", new_name);
	color(7);
	int yes = -1;
	flag = scanf("%d", &yes);
	scanf("%*[^\n]"); scanf("%*c");

	while (flag != 1 || yes < 0 || yes>1) {

		color(4);
		printf("请输入正确的格式\n");
		color(7);
		flag = scanf("%d", &yes);
		scanf("%*[^\n]"); scanf("%*c");

	}
	if (yes == 1) {
		pF->SetFileName(pF, event_filename, new_name);
		color(9);

		printf("修改成功！\n");
		color(7);
	}
	else {
		color(9);

		printf("取消修改！\n");
		color(7);

	}



}
void INFO_PATH_FUN() {

	printf("当前文件：%s\n", ((_FILE_HELPER*)pF)->info_filename);
	color(9);
	printf("请输入新的文件名，并确保文件在\\data\\目录下：\n");
	color(7);


	char new_name[1024];
	int flag = 0;
	size_t size = 0;

	flag = scanf("%s", new_name);
	size = strlen(new_name);
	scanf("%*[^\n]"); scanf("%*c");

	while (flag != 1 || size > MAX_FILENAME_LENGTH) {

		color(4);
		printf("请输入正确的格式，例如：data.txt\n");
		color(7);
		flag = scanf("%s", new_name);
		size = strlen(new_name);
		scanf("%*[^\n]"); scanf("%*c");

	}
	color(9);
	printf("确认修改吗？（ Yes 1 \ No 0 ）%s\n", new_name);
	color(7);
	int yes = -1;
	flag = scanf("%d", &yes);
	scanf("%*[^\n]"); scanf("%*c");

	while (flag != 1 || yes < 0 || yes>1) {

		color(4);
		printf("请输入正确的格式\n");
		color(7);
		flag = scanf("%d", &yes);
		scanf("%*[^\n]"); scanf("%*c");

	}

	if (yes == 1) {
		pF->SetFileName(pF, info_filename, new_name);
		color(9);

		printf("修改成功！\n");
		color(7);
	}
	else {
		color(9);

		printf("取消修改！\n");
		color(7);

	}




}
void COLLEGE_RANKING_FUN() {

	Sort(pM, college_score);

	color(9);
	printf("编号\t名称");
	for (int j = 0; j < 20 - strlen("名称"); j++)printf(" ");
	printf("总分\t排名\n");
	color(7);

	for (size_t i = 0; i < pM->colleges->size(pM->colleges); i++) {

		pCollege pC = (pCollege)(pM->colleges->at(pM->colleges, i));

		printf("%d\t%s",
			pC->ID,
			pC->name);

		for (int j = 0; j < 20 - strlen(pC->name); j++)printf(" ");

		printf("%d\t\t%d\n",
			pC->total_score,
			(int)i + 1);

	}

	Sort(pM, colleges_ID);

}