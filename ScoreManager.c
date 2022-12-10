#include "ScoreManager.h"


void test_print(pManager pM, pFileHelper pF) {

	printf("%s\n", ((_FILE_HELPER*)pF)->college_filename);
	printf("%s\n", ((_FILE_HELPER*)pF)->athlete_filename);
	printf("%s\n", ((_FILE_HELPER*)pF)->event_filename);
	printf("%s\n", ((_FILE_HELPER*)pF)->info_filename);


	printf("%d\n", pM->colleges->size(pM->colleges));
	printf("%d\n", pM->athletes->size(pM->athletes));
	printf("%d\n", pM->events->size(pM->events));
	printf("%d\n", pM->infos->size(pM->infos));


	for (size_t i = 0; i < pM->colleges->size(pM->colleges); i++) {

		pCollege pC = (pCollege)(pM->colleges->at(pM->colleges, i));

		printf("%d %s %d\n",
			pC->ID,
			pC->name,
			pC->total_score);

	}

	for (size_t i = 0; i < pM->athletes->size(pM->athletes); i++) {

		pAthlete pA = (pAthlete)(pM->athletes->at(pM->athletes,i));

		printf("%d %s %d %d\n",
			pA->ID,
			pA->name,
			pA->sex,
			pA->college_ID);

		for (unsigned int j = 0; j < pA->num_of_event; j++) {

			printf("项目ID%d 排名%d\n",
				pA->events[j],
				pA->ranking[j]);

		}

	}

	for (size_t i = 0; i < pM->events->size(pM->events); i++) {

		printf("%d %s\n",
			((pAthlete)(pM->events->at(pM->events, i)))->ID,
			((pAthlete)(pM->events->at(pM->events, i)))->name);

	}

	for (size_t i = 0; i < pM->infos->size(pM->infos); i++) {

		printf("%d %d %d\n",
			((pInfo)(pM->infos->at(pM->infos,i)))->athletes_ID,
			((pInfo)(pM->infos->at(pM->infos, i)))->event_ID,
			((pInfo)(pM->infos->at(pM->infos, i)))->ranking);

	}


}


int main()
{


	pM = Manager_init();
	pF = FileHelper_init();

	pF->SetFileName(pF, college_filename, "college.txt");
	pF->SetFileName(pF, athlete_filename, "athlete.txt");
	pF->SetFileName(pF, event_filename, "event.txt");
	pF->SetFileName(pF, info_filename, "info.txt");

	pF->GetCollegeData(pF, pM->colleges);
	pF->GetAthleteData(pF, pM->athletes);
	pF->GetEventData(pF, pM->events);
	pF->GetInfoData(pF, pM->infos);

	ProcessingData(pM);



	while (1)
	{
		//显示功能菜单,并获得选择的菜单项
		int menuitem = Menu();

		switch (menuitem)
		{
		case COLLEGE_FILE:

			COLLEGE_FILE_FUN();

			break;
		case ATHLETE_FILE:

			ATHLETE_FILE_FUN();

			break;
		case EVENT_FILE:

			EVENT_FILE_FUN();

			break;
		case INFO_FILE:

			INFO_FILE_FUN();

			break;
		case COLLEGE_FIND:

			COLLEGE_FIND_FUN();

			break;
		case ATHLETE_FIND:

			ATHLETE_FIND_FUN();

			break;
		case EVENT_FIND:

			EVENT_FIND_FUN();

			break;
		case COLLEGE_CHANGE:

			COLLEGE_CHANGE_FUN();

			break;
		case ATHLETE_CHANGE:

			ATHLETE_CHANGE_FUN();

			break;
		case EVENT_CHANGE:

			EVENT_CHANGE_FUN();

			break;
		case COLLEGE_ADD:

			COLLEGE_ADD_FUN();

			break;
		case ATHLETE_ADD:

			ATHLETE_ADD_FUN();

			break;
		case EVENT_ADD:

			EVENT_ADD_FUN();
			break;
		case COLLEGE_PATH:

			COLLEGE_PATH_FUN();

			break;
		case ATHLETE_PATH:

			ATHLETE_PATH_FUN();

			break;
		case EVENT_PATH:

			EVENT_PATH_FUN();

			break;

		case INFO_PATH:

			INFO_PATH_FUN();

			break;

		case COLLEGE_RANKING:

			COLLEGE_RANKING_FUN();

			break;

		}

		color(9);
		system("pause");
		color(7);
	}

	return 0;
}

