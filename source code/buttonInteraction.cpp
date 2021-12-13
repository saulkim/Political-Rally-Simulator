#include "poliRalSimFluid.h"
#include "imageManager.h"

ImageManager* imgMng = new ImageManager;

void UserInterface::dialogue1_cb(Fl_Widget* obj, void* p) {

	//Organizing groups together
	Fl_Group* entireWindow = obj->parent()->parent();
	Fl_Group* rallyViewGroup = (Fl_Group*) entireWindow->child(0);
	Fl_Group* audienceGroup = (Fl_Group*)rallyViewGroup->child(1);
	Fl_Group* dataViewGroup = (Fl_Group*)entireWindow->child(1);

	//display setup
	Fl_Output* textBox = (Fl_Output*)rallyViewGroup->child(0);
	textBox->value("Taxes go up");

	//pie chart variable initializing
	Fl_Chart* pie = (Fl_Chart*)dataViewGroup->child(0);
	//bar charts ("bar graph") variable initializing
	Fl_Chart* carBar = (Fl_Chart*)dataViewGroup->child(1);
	carBar->type(FL_BAR_CHART);
	Fl_Chart* musicBar = (Fl_Chart*)dataViewGroup->child(2);
	musicBar->type(FL_BAR_CHART);
	Fl_Chart* swordBar = (Fl_Chart*)dataViewGroup->child(3);
	swordBar->type(FL_BAR_CHART);
	Fl_Chart* treeBar = (Fl_Chart*)dataViewGroup->child(4);
	treeBar->type(FL_BAR_CHART);


	//hides all faces, done to delete last data
	////per row (4 rows total)
	for (int i = 0; i < 4; i++) {
		Fl_Group* rowGroup = (Fl_Group*)audienceGroup->child(i);
		//per column (4 columns total)
		for (int j = 0; j < 4; j++) {
			Fl_Group* person = (Fl_Group*)rowGroup->child(j);
			Fl_Group* head = (Fl_Group*)person->child(0);

			//setting emotion
			for (int k = 0; k < 3; k++) {
				Fl_Group* face = (Fl_Group*)head->child(k);
				face->hide();
			}
		}
	}

	//hides all demographics, done to delete last data
	////per row (4 rows total)
	for (int i = 0; i < 4; i++) {
		Fl_Group* rowGroup = (Fl_Group*)audienceGroup->child(i);
		//per column (4 columns total)
		for (int j = 0; j < 4; j++) {
			Fl_Group* person = (Fl_Group*)rowGroup->child(j);
			Fl_Group* body = (Fl_Group*)person->child(1);

			//setting emotion
			for (int k = 0; k < 4; k++) {
				Fl_Group* chest = (Fl_Group*)body->child(k);
				chest->hide();
			}
		}
	}


	//clears out previous data charts
	pie->clear();
	pie->redraw();
	carBar->clear();
	musicBar->clear();
	swordBar->clear();
	treeBar->clear();

	//face changes
	imgMng->speechOption1();
	////per row (4 rows total)
	for (int i = 0; i < 4; i++) {
		Fl_Group* rowGroup = (Fl_Group*)audienceGroup->child(i);
		//per column (4 columns total)
		for (int j = 0; j < 4; j++) {
			Fl_Group* person = (Fl_Group*)rowGroup->child(j);
			Fl_Group* head = (Fl_Group*)person->child(0);

			//setting emotion
			int faceValue = imgMng->getAudienceFace(i, j);
			Fl_Group* face = (Fl_Group*)head->child(faceValue);
			face->show();
		}
	}

	//demographic changes
	////per row (4 rows total)
	for (int i = 0; i < 4; i++) {
		Fl_Group* rowGroup = (Fl_Group*)audienceGroup->child(i);
		//per column (4 columns total)
		for (int j = 0; j < 4; j++) {
			Fl_Group* person = (Fl_Group*)rowGroup->child(j);
			Fl_Group* body = (Fl_Group*)person->child(1);

			//setting emotion
			int bodyValue = imgMng->getAudienceDemographics(i, j);
			Fl_Group* chest = (Fl_Group*)body->child(bodyValue);
			chest->show();
		}
	}


	//adds face data to chart
	imgMng->calcTotalFaces();
	int totalHappy = imgMng->getTotalHappyFaces();
	int totalAngry = imgMng->getTotalAngryFaces();
	int totalNeutral = imgMng->getTotalNeutralFaces();

	pie->add(totalHappy, "happy", FL_GREEN);
	pie->add(totalAngry, "angry", FL_RED);
	pie->add(totalNeutral, "neutral", FL_GRAY);


	//adds demographics data to chart
	imgMng->calcTotalEmotionsPerDemo();
	int totalCarEmotions[3];
	int totalMusicEmotions[3];
	int totalSwordEmotions[3];
	int totalTreeEmotions[3];

	for (int i = 0; i < 3; i++) {
		totalCarEmotions[i] = imgMng->getCarEmotions(i);
		totalMusicEmotions[i] = imgMng->getMusicEmotions(i);
		totalSwordEmotions[i] = imgMng->getSwordEmotions(i);
		totalTreeEmotions[i] = imgMng->getTreeEmotions(i);
	}


	carBar->add(totalCarEmotions[0], "happy", FL_GREEN);
	carBar->add(totalCarEmotions[1], "angry", FL_RED);
	carBar->add(totalCarEmotions[2], "neutral", FL_GRAY);

	musicBar->add(totalMusicEmotions[0], "happy", FL_GREEN);
	musicBar->add(totalMusicEmotions[1], "angry", FL_RED);
	musicBar->add(totalMusicEmotions[2], "neutral", FL_GRAY);

	swordBar->add(totalSwordEmotions[0], "happy", FL_GREEN);
	swordBar->add(totalSwordEmotions[1], "angry", FL_RED);
	swordBar->add(totalSwordEmotions[2], "neutral", FL_GRAY);

	treeBar->add(totalTreeEmotions[0], "happy", FL_GREEN);
	treeBar->add(totalTreeEmotions[1], "angry", FL_RED);
	treeBar->add(totalTreeEmotions[2], "neutral", FL_GRAY);

}
void UserInterface::dialogue2_cb(Fl_Widget* obj, void* p) {

	//Organizing groups together
	Fl_Group* entireWindow = obj->parent()->parent();
	Fl_Group* rallyViewGroup = (Fl_Group*)entireWindow->child(0);
	Fl_Group* audienceGroup = (Fl_Group*)rallyViewGroup->child(1);
	Fl_Group* dataViewGroup = (Fl_Group*)entireWindow->child(1);

	//display setup
	Fl_Output* textBox = (Fl_Output*)rallyViewGroup->child(0);
	textBox->value("Taxes go down");

	//pie chart variable initializing
	Fl_Chart* pie = (Fl_Chart*)dataViewGroup->child(0);
	//bar charts ("bar graph") variable initializing
	Fl_Chart* carBar = (Fl_Chart*)dataViewGroup->child(1);
	carBar->type(FL_BAR_CHART);
	Fl_Chart* musicBar = (Fl_Chart*)dataViewGroup->child(2);
	musicBar->type(FL_BAR_CHART);
	Fl_Chart* swordBar = (Fl_Chart*)dataViewGroup->child(3);
	swordBar->type(FL_BAR_CHART);
	Fl_Chart* treeBar = (Fl_Chart*)dataViewGroup->child(4);
	treeBar->type(FL_BAR_CHART);


	//hides all faces, done to delete last data
	////per row (4 rows total)
	for (int i = 0; i < 4; i++) {
		Fl_Group* rowGroup = (Fl_Group*)audienceGroup->child(i);
		//per column (4 columns total)
		for (int j = 0; j < 4; j++) {
			Fl_Group* person = (Fl_Group*)rowGroup->child(j);
			Fl_Group* head = (Fl_Group*)person->child(0);

			//setting emotion
			for (int k = 0; k < 3; k++) {
				Fl_Group* face = (Fl_Group*)head->child(k);
				face->hide();
			}
		}
	}

	//hides all demographics, done to delete last data
	////per row (4 rows total)
	for (int i = 0; i < 4; i++) {
		Fl_Group* rowGroup = (Fl_Group*)audienceGroup->child(i);
		//per column (4 columns total)
		for (int j = 0; j < 4; j++) {
			Fl_Group* person = (Fl_Group*)rowGroup->child(j);
			Fl_Group* body = (Fl_Group*)person->child(1);

			//setting emotion
			for (int k = 0; k < 4; k++) {
				Fl_Group* chest = (Fl_Group*)body->child(k);
				chest->hide();
			}
		}
	}


	//clears out previous data charts
	pie->clear();
	pie->redraw();
	carBar->clear();
	musicBar->clear();
	swordBar->clear();
	treeBar->clear();

	//face changes
	imgMng->speechOption2();
	////per row (4 rows total)
	for (int i = 0; i < 4; i++) {
		Fl_Group* rowGroup = (Fl_Group*)audienceGroup->child(i);
		//per column (4 columns total)
		for (int j = 0; j < 4; j++) {
			Fl_Group* person = (Fl_Group*)rowGroup->child(j);
			Fl_Group* head = (Fl_Group*)person->child(0);

			//setting emotion
			int faceValue = imgMng->getAudienceFace(i, j);
			Fl_Group* face = (Fl_Group*)head->child(faceValue);
			face->show();
		}
	}

	//demographic changes
	////per row (4 rows total)
	for (int i = 0; i < 4; i++) {
		Fl_Group* rowGroup = (Fl_Group*)audienceGroup->child(i);
		//per column (4 columns total)
		for (int j = 0; j < 4; j++) {
			Fl_Group* person = (Fl_Group*)rowGroup->child(j);
			Fl_Group* body = (Fl_Group*)person->child(1);

			//setting emotion
			int bodyValue = imgMng->getAudienceDemographics(i, j);
			Fl_Group* chest = (Fl_Group*)body->child(bodyValue);
			chest->show();
		}
	}


	//adds face data to chart
	imgMng->calcTotalFaces();
	int totalHappy = imgMng->getTotalHappyFaces();
	int totalAngry = imgMng->getTotalAngryFaces();
	int totalNeutral = imgMng->getTotalNeutralFaces();

	pie->add(totalHappy, "happy", FL_GREEN);
	pie->add(totalAngry, "angry", FL_RED);
	pie->add(totalNeutral, "neutral", FL_GRAY);


	//adds demographics data to chart
	imgMng->calcTotalEmotionsPerDemo();
	int totalCarEmotions[3];
	int totalMusicEmotions[3];
	int totalSwordEmotions[3];
	int totalTreeEmotions[3];

	for (int i = 0; i < 3; i++) {
		totalCarEmotions[i] = imgMng->getCarEmotions(i);
		totalMusicEmotions[i] = imgMng->getMusicEmotions(i);
		totalSwordEmotions[i] = imgMng->getSwordEmotions(i);
		totalTreeEmotions[i] = imgMng->getTreeEmotions(i);
	}


	carBar->add(totalCarEmotions[0], "happy", FL_GREEN);
	carBar->add(totalCarEmotions[1], "angry", FL_RED);
	carBar->add(totalCarEmotions[2], "neutral", FL_GRAY);

	musicBar->add(totalMusicEmotions[0], "happy", FL_GREEN);
	musicBar->add(totalMusicEmotions[1], "angry", FL_RED);
	musicBar->add(totalMusicEmotions[2], "neutral", FL_GRAY);

	swordBar->add(totalSwordEmotions[0], "happy", FL_GREEN);
	swordBar->add(totalSwordEmotions[1], "angry", FL_RED);
	swordBar->add(totalSwordEmotions[2], "neutral", FL_GRAY);

	treeBar->add(totalTreeEmotions[0], "happy", FL_GREEN);
	treeBar->add(totalTreeEmotions[1], "angry", FL_RED);
	treeBar->add(totalTreeEmotions[2], "neutral", FL_GRAY);

}
void UserInterface::dialogue3_cb(Fl_Widget* obj, void* p) {

	//Organizing groups together
	Fl_Group* entireWindow = obj->parent()->parent();
	Fl_Group* rallyViewGroup = (Fl_Group*)entireWindow->child(0);
	Fl_Group* audienceGroup = (Fl_Group*)rallyViewGroup->child(1);
	Fl_Group* dataViewGroup = (Fl_Group*)entireWindow->child(1);

	//display setup
	Fl_Output* textBox = (Fl_Output*)rallyViewGroup->child(0);
	textBox->value("Fix the roads");

	//pie chart variable initializing
	Fl_Chart* pie = (Fl_Chart*)dataViewGroup->child(0);
	//bar charts ("bar graph") variable initializing
	Fl_Chart* carBar = (Fl_Chart*)dataViewGroup->child(1);
	carBar->type(FL_BAR_CHART);
	Fl_Chart* musicBar = (Fl_Chart*)dataViewGroup->child(2);
	musicBar->type(FL_BAR_CHART);
	Fl_Chart* swordBar = (Fl_Chart*)dataViewGroup->child(3);
	swordBar->type(FL_BAR_CHART);
	Fl_Chart* treeBar = (Fl_Chart*)dataViewGroup->child(4);
	treeBar->type(FL_BAR_CHART);


	//hides all faces, done to delete last data
	////per row (4 rows total)
	for (int i = 0; i < 4; i++) {
		Fl_Group* rowGroup = (Fl_Group*)audienceGroup->child(i);
		//per column (4 columns total)
		for (int j = 0; j < 4; j++) {
			Fl_Group* person = (Fl_Group*)rowGroup->child(j);
			Fl_Group* head = (Fl_Group*)person->child(0);

			//setting emotion
			for (int k = 0; k < 3; k++) {
				Fl_Group* face = (Fl_Group*)head->child(k);
				face->hide();
			}
		}
	}

	//hides all demographics, done to delete last data
	////per row (4 rows total)
	for (int i = 0; i < 4; i++) {
		Fl_Group* rowGroup = (Fl_Group*)audienceGroup->child(i);
		//per column (4 columns total)
		for (int j = 0; j < 4; j++) {
			Fl_Group* person = (Fl_Group*)rowGroup->child(j);
			Fl_Group* body = (Fl_Group*)person->child(1);

			//setting emotion
			for (int k = 0; k < 4; k++) {
				Fl_Group* chest = (Fl_Group*)body->child(k);
				chest->hide();
			}
		}
	}


	//clears out previous data charts
	pie->clear();
	pie->redraw();
	carBar->clear();
	musicBar->clear();
	swordBar->clear();
	treeBar->clear();

	//face changes
	imgMng->speechOption3();
	////per row (4 rows total)
	for (int i = 0; i < 4; i++) {
		Fl_Group* rowGroup = (Fl_Group*)audienceGroup->child(i);
		//per column (4 columns total)
		for (int j = 0; j < 4; j++) {
			Fl_Group* person = (Fl_Group*)rowGroup->child(j);
			Fl_Group* head = (Fl_Group*)person->child(0);

			//setting emotion
			int faceValue = imgMng->getAudienceFace(i, j);
			Fl_Group* face = (Fl_Group*)head->child(faceValue);
			face->show();
		}
	}

	//demographic changes
	////per row (4 rows total)
	for (int i = 0; i < 4; i++) {
		Fl_Group* rowGroup = (Fl_Group*)audienceGroup->child(i);
		//per column (4 columns total)
		for (int j = 0; j < 4; j++) {
			Fl_Group* person = (Fl_Group*)rowGroup->child(j);
			Fl_Group* body = (Fl_Group*)person->child(1);

			//setting emotion
			int bodyValue = imgMng->getAudienceDemographics(i, j);
			Fl_Group* chest = (Fl_Group*)body->child(bodyValue);
			chest->show();
		}
	}


	//adds face data to chart
	imgMng->calcTotalFaces();
	int totalHappy = imgMng->getTotalHappyFaces();
	int totalAngry = imgMng->getTotalAngryFaces();
	int totalNeutral = imgMng->getTotalNeutralFaces();

	pie->add(totalHappy, "happy", FL_GREEN);
	pie->add(totalAngry, "angry", FL_RED);
	pie->add(totalNeutral, "neutral", FL_GRAY);


	//adds demographics data to chart
	imgMng->calcTotalEmotionsPerDemo();
	int totalCarEmotions[3];
	int totalMusicEmotions[3];
	int totalSwordEmotions[3];
	int totalTreeEmotions[3];

	for (int i = 0; i < 3; i++) {
		totalCarEmotions[i] = imgMng->getCarEmotions(i);
		totalMusicEmotions[i] = imgMng->getMusicEmotions(i);
		totalSwordEmotions[i] = imgMng->getSwordEmotions(i);
		totalTreeEmotions[i] = imgMng->getTreeEmotions(i);
	}


	carBar->add(totalCarEmotions[0], "happy", FL_GREEN);
	carBar->add(totalCarEmotions[1], "angry", FL_RED);
	carBar->add(totalCarEmotions[2], "neutral", FL_GRAY);

	musicBar->add(totalMusicEmotions[0], "happy", FL_GREEN);
	musicBar->add(totalMusicEmotions[1], "angry", FL_RED);
	musicBar->add(totalMusicEmotions[2], "neutral", FL_GRAY);

	swordBar->add(totalSwordEmotions[0], "happy", FL_GREEN);
	swordBar->add(totalSwordEmotions[1], "angry", FL_RED);
	swordBar->add(totalSwordEmotions[2], "neutral", FL_GRAY);

	treeBar->add(totalTreeEmotions[0], "happy", FL_GREEN);
	treeBar->add(totalTreeEmotions[1], "angry", FL_RED);
	treeBar->add(totalTreeEmotions[2], "neutral", FL_GRAY);
}
void UserInterface::dialogue4_cb(Fl_Widget* obj, void* p) {
	
	//Organizing groups together
	Fl_Group* entireWindow = obj->parent()->parent();
	Fl_Group* rallyViewGroup = (Fl_Group*)entireWindow->child(0);
	Fl_Group* audienceGroup = (Fl_Group*)rallyViewGroup->child(1);
	Fl_Group* dataViewGroup = (Fl_Group*)entireWindow->child(1);

	//display setup
	Fl_Output* textBox = (Fl_Output*)rallyViewGroup->child(0);
	textBox->value("More bicycle lanes");

	//pie chart variable initializing
	Fl_Chart* pie = (Fl_Chart*)dataViewGroup->child(0);
	//bar charts ("bar graph") variable initializing
	Fl_Chart* carBar = (Fl_Chart*)dataViewGroup->child(1);
	carBar->type(FL_BAR_CHART);
	Fl_Chart* musicBar = (Fl_Chart*)dataViewGroup->child(2);
	musicBar->type(FL_BAR_CHART);
	Fl_Chart* swordBar = (Fl_Chart*)dataViewGroup->child(3);
	swordBar->type(FL_BAR_CHART);
	Fl_Chart* treeBar = (Fl_Chart*)dataViewGroup->child(4);
	treeBar->type(FL_BAR_CHART);


	//hides all faces, done to delete last data
	////per row (4 rows total)
	for (int i = 0; i < 4; i++) {
		Fl_Group* rowGroup = (Fl_Group*)audienceGroup->child(i);
		//per column (4 columns total)
		for (int j = 0; j < 4; j++) {
			Fl_Group* person = (Fl_Group*)rowGroup->child(j);
			Fl_Group* head = (Fl_Group*)person->child(0);

			//setting emotion
			for (int k = 0; k < 3; k++) {
				Fl_Group* face = (Fl_Group*)head->child(k);
				face->hide();
			}
		}
	}

	//hides all demographics, done to delete last data
	////per row (4 rows total)
	for (int i = 0; i < 4; i++) {
		Fl_Group* rowGroup = (Fl_Group*)audienceGroup->child(i);
		//per column (4 columns total)
		for (int j = 0; j < 4; j++) {
			Fl_Group* person = (Fl_Group*)rowGroup->child(j);
			Fl_Group* body = (Fl_Group*)person->child(1);

			//setting emotion
			for (int k = 0; k < 4; k++) {
				Fl_Group* chest = (Fl_Group*)body->child(k);
				chest->hide();
			}
		}
	}


	//clears out previous data charts
	pie->clear();
	pie->redraw();
	carBar->clear();
	musicBar->clear();
	swordBar->clear();
	treeBar->clear();

	//face changes
	imgMng->speechOption4();
	////per row (4 rows total)
	for (int i = 0; i < 4; i++) {
		Fl_Group* rowGroup = (Fl_Group*)audienceGroup->child(i);
		//per column (4 columns total)
		for (int j = 0; j < 4; j++) {
			Fl_Group* person = (Fl_Group*)rowGroup->child(j);
			Fl_Group* head = (Fl_Group*)person->child(0);

			//setting emotion
			int faceValue = imgMng->getAudienceFace(i, j);
			Fl_Group* face = (Fl_Group*)head->child(faceValue);
			face->show();
		}
	}

	//demographic changes
	////per row (4 rows total)
	for (int i = 0; i < 4; i++) {
		Fl_Group* rowGroup = (Fl_Group*)audienceGroup->child(i);
		//per column (4 columns total)
		for (int j = 0; j < 4; j++) {
			Fl_Group* person = (Fl_Group*)rowGroup->child(j);
			Fl_Group* body = (Fl_Group*)person->child(1);

			//setting emotion
			int bodyValue = imgMng->getAudienceDemographics(i, j);
			Fl_Group* chest = (Fl_Group*)body->child(bodyValue);
			chest->show();
		}
	}


	//adds face data to chart
	imgMng->calcTotalFaces();
	int totalHappy = imgMng->getTotalHappyFaces();
	int totalAngry = imgMng->getTotalAngryFaces();
	int totalNeutral = imgMng->getTotalNeutralFaces();

	pie->add(totalHappy, "happy", FL_GREEN);
	pie->add(totalAngry, "angry", FL_RED);
	pie->add(totalNeutral, "neutral", FL_GRAY);


	//adds demographics data to chart
	imgMng->calcTotalEmotionsPerDemo();
	int totalCarEmotions[3];
	int totalMusicEmotions[3];
	int totalSwordEmotions[3];
	int totalTreeEmotions[3];

	for (int i = 0; i < 3; i++) {
		totalCarEmotions[i] = imgMng->getCarEmotions(i);
		totalMusicEmotions[i] = imgMng->getMusicEmotions(i);
		totalSwordEmotions[i] = imgMng->getSwordEmotions(i);
		totalTreeEmotions[i] = imgMng->getTreeEmotions(i);
	}


	carBar->add(totalCarEmotions[0], "happy", FL_GREEN);
	carBar->add(totalCarEmotions[1], "angry", FL_RED);
	carBar->add(totalCarEmotions[2], "neutral", FL_GRAY);

	musicBar->add(totalMusicEmotions[0], "happy", FL_GREEN);
	musicBar->add(totalMusicEmotions[1], "angry", FL_RED);
	musicBar->add(totalMusicEmotions[2], "neutral", FL_GRAY);

	swordBar->add(totalSwordEmotions[0], "happy", FL_GREEN);
	swordBar->add(totalSwordEmotions[1], "angry", FL_RED);
	swordBar->add(totalSwordEmotions[2], "neutral", FL_GRAY);

	treeBar->add(totalTreeEmotions[0], "happy", FL_GREEN);
	treeBar->add(totalTreeEmotions[1], "angry", FL_RED);
	treeBar->add(totalTreeEmotions[2], "neutral", FL_GRAY);
}
void UserInterface::dialogue5_cb(Fl_Widget* obj, void* p) {

	//Organizing groups together
	Fl_Group* entireWindow = obj->parent()->parent();
	Fl_Group* rallyViewGroup = (Fl_Group*)entireWindow->child(0);
	Fl_Group* audienceGroup = (Fl_Group*)rallyViewGroup->child(1);
	Fl_Group* dataViewGroup = (Fl_Group*)entireWindow->child(1);

	//display setup
	Fl_Output* textBox = (Fl_Output*)rallyViewGroup->child(0);
	textBox->value("New audience");
	Fl_Output* cityTextBox = (Fl_Output*)rallyViewGroup->child(2);

	//cityTextBox->value("qwe");
	std::string cityName = imgMng->getCityName();
	const char* c = cityName.c_str();
	cityTextBox->value(c);
	

	//refreshes audience data
	imgMng->newAudience();

	//activates the graphs
	dataViewGroup->show();

	//pie chart initializing
	Fl_Chart* pie = (Fl_Chart*)dataViewGroup->child(0);
	pie->type(FL_PIE_CHART);

	//bar charts ("bar graph") initializing
	Fl_Chart* carBar = (Fl_Chart*)dataViewGroup->child(1);
	carBar->type(FL_BAR_CHART);
	Fl_Chart* musicBar = (Fl_Chart*)dataViewGroup->child(2);
	musicBar->type(FL_BAR_CHART);
	Fl_Chart* swordBar = (Fl_Chart*)dataViewGroup->child(3);
	swordBar->type(FL_BAR_CHART);
	Fl_Chart* treeBar = (Fl_Chart*)dataViewGroup->child(4);
	treeBar->type(FL_BAR_CHART);

	//activates the rest of the buttons for use
	Fl_Group* clickyPortionViewGroup = (Fl_Group*)entireWindow->child(2);
	for (int i = 0; i < 6; i++) {
		Fl_Button* btn = (Fl_Button*)clickyPortionViewGroup->child(i);
		btn->activate();
	}


	//hides all faces, done to delete last data
	////per row (4 rows total)
	for (int i = 0; i < 4; i++) {
		Fl_Group* rowGroup = (Fl_Group*) audienceGroup->child(i);
		//per column (4 columns total)
		for (int j = 0; j < 4; j++) {
			Fl_Group* person = (Fl_Group*) rowGroup->child(j);
			Fl_Group* head = (Fl_Group*) person->child(0);

			//setting emotion
			for (int k = 0; k < 3; k++) {
				Fl_Group* face = (Fl_Group*) head->child(k);
				face->hide();
			}
		}
	}

	//hides all demographics, done to delete last data
	////per row (4 rows total)
	for (int i = 0; i < 4; i++) {
		Fl_Group* rowGroup = (Fl_Group*)audienceGroup->child(i);
		//per column (4 columns total)
		for (int j = 0; j < 4; j++) {
			Fl_Group* person = (Fl_Group*)rowGroup->child(j);
			Fl_Group* body = (Fl_Group*)person->child(1);

			//setting emotion
			for (int k = 0; k < 4; k++) {
				Fl_Group* chest = (Fl_Group*)body->child(k);
				chest->hide();
			}
		}
	}

	//clears out previous data charts
	pie->clear();
	carBar->clear();
	musicBar->clear();
	swordBar->clear();
	treeBar->clear();


	//face changes
	////per row (4 rows total)
	for (int i = 0; i < 4; i++) {
		Fl_Group* rowGroup = (Fl_Group*)audienceGroup->child(i);
		//per column (4 columns total)
		for (int j = 0; j < 4; j++) {
			Fl_Group* person = (Fl_Group*)rowGroup->child(j);
			Fl_Group* head = (Fl_Group*)person->child(0);

			//setting emotion
			int faceValue = imgMng->getAudienceFace(i, j);
			Fl_Group* face = (Fl_Group*)head->child(faceValue);
			face->show();
		}
	}

	//demographic changes
	////per row (4 rows total)
	for (int i = 0; i < 4; i++) {
		Fl_Group* rowGroup = (Fl_Group*)audienceGroup->child(i);
		//per column (4 columns total)
		for (int j = 0; j < 4; j++) {
			Fl_Group* person = (Fl_Group*)rowGroup->child(j);
			Fl_Group* body = (Fl_Group*)person->child(1);

			//setting emotion
			int bodyValue = imgMng->getAudienceDemographics(i, j);
			Fl_Group* chest = (Fl_Group*)body->child(bodyValue);
			chest->show();
		}
	}
	

	//adds face data to chart
	imgMng->calcTotalFaces();
	int totalHappy = imgMng->getTotalHappyFaces();
	int totalAngry = imgMng->getTotalAngryFaces();
	int totalNeutral = imgMng->getTotalNeutralFaces();

	pie->add(totalHappy, "happy", FL_GREEN);
	pie->add(totalAngry, "angry", FL_RED);
	pie->add(totalNeutral, "neutral", FL_GRAY);


	//adds demographics data to chart
	imgMng->calcTotalEmotionsPerDemo();
	int totalCarEmotions[3];
	int totalMusicEmotions[3];
	int totalSwordEmotions[3];
	int totalTreeEmotions[3];

	for (int i = 0; i < 3; i++) {
		totalCarEmotions[i] = imgMng->getCarEmotions(i);
		totalMusicEmotions[i] = imgMng->getMusicEmotions(i);
		totalSwordEmotions[i] = imgMng->getSwordEmotions(i);
		totalTreeEmotions[i] = imgMng->getTreeEmotions(i);
	}


	carBar->add(totalCarEmotions[0], "happy", FL_GREEN);
	carBar->add(totalCarEmotions[1], "angry", FL_RED);
	carBar->add(totalCarEmotions[2], "neutral", FL_GRAY);

	musicBar->add(totalMusicEmotions[0], "happy", FL_GREEN);
	musicBar->add(totalMusicEmotions[1], "angry", FL_RED);
	musicBar->add(totalMusicEmotions[2], "neutral", FL_GRAY);

	swordBar->add(totalSwordEmotions[0], "happy", FL_GREEN);
	swordBar->add(totalSwordEmotions[1], "angry", FL_RED);
	swordBar->add(totalSwordEmotions[2], "neutral", FL_GRAY);

	treeBar->add(totalTreeEmotions[0], "happy", FL_GREEN);
	treeBar->add(totalTreeEmotions[1], "angry", FL_RED);
	treeBar->add(totalTreeEmotions[2], "neutral", FL_GRAY);

}
void UserInterface::dialogue6_cb(Fl_Widget* obj, void* p) {

	//Organizing groups together
	Fl_Group* entireWindow = obj->parent()->parent();
	Fl_Group* rallyViewGroup = (Fl_Group*)entireWindow->child(0);

	//display setup
	Fl_Output* textBox = (Fl_Output*)rallyViewGroup->child(0);
	textBox->value("???");
}