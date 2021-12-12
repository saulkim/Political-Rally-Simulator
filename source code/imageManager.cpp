#include "imageManager.h"

int ImageManager::getAudienceFace(int row, int col) {
	int value = -1;

	value = audienceFaces[row][col];

	return value;
}

int ImageManager::getAudienceDemographics(int row, int col) {
	int value = -1;

	value = audienceDemographics[row][col];

	return value;

}

int ImageManager::getTotalHappyFaces() {
	return totalHappyFaces;
}
int ImageManager::getTotalAngryFaces() {
	return totalAngryFaces;
}
int ImageManager::getTotalNeutralFaces() {
	return totalNeutralFaces;
}

int ImageManager::getCarEmotions(int index) {
	int value = -1;

	value = totalCarEmotions[index];

	return value;
}

int ImageManager::getMusicEmotions(int index) {
	int value = -1;

	value = totalMusicEmotions[index];

	return value;
}

int ImageManager::getSwordEmotions(int index) {
	int value = -1;

	value = totalSwordEmotions[index];

	return value;
}

int ImageManager::getTreeEmotions(int index) {
	int value = -1;

	value = totalTreeEmotions[index];

	return value;
}

void ImageManager::calcTotalFaces() {

	totalHappyFaces = 0;
	totalAngryFaces = 0;
	totalNeutralFaces = 0;


	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (audienceFaces[i][j] == 0) {
				totalHappyFaces++;
			}
			else if (audienceFaces[i][j] == 1) {
				totalAngryFaces++;
			}
			else {
				totalNeutralFaces++;
			}
		}
	}
}

void ImageManager::calcTotalEmotionsPerDemo() {
	
	for (int i = 0; i < 3; i++) {
		totalCarEmotions[i] = 0;
		totalMusicEmotions[i] = 0;
		totalSwordEmotions[i] = 0;
		totalTreeEmotions[i] = 0;
	}

	//for each person, check the demographics, then increment value of that demographic array's index corresponding to the emotion index;
	//TODO probably a more graceful way to do this
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			//checking car enthusiasts
			if (audienceDemographics[i][j] == 0) {
				if (audienceFaces[i][j] == 0) {
					totalCarEmotions[0]++;
				}
				else if (audienceFaces[i][j] == 1) {
					totalCarEmotions[1]++;
				}
				else {
					totalCarEmotions[2]++;
				}
			}

			//checking music enthusiasts
			if (audienceDemographics[i][j] == 1) {
				if (audienceFaces[i][j] == 0) {
					totalMusicEmotions[0]++;
				}
				else if (audienceFaces[i][j] == 1) {
					totalMusicEmotions[1]++;
				}
				else {
					totalMusicEmotions[2]++;
				}
			}

			//checking sword enthusiasts
			if (audienceDemographics[i][j] == 2) {
				if (audienceFaces[i][j] == 0) {
					totalSwordEmotions[0]++;
				}
				else if (audienceFaces[i][j] == 1) {
					totalSwordEmotions[1]++;
				}
				else {
					totalSwordEmotions[2]++;
				}
			}

			//checking tree enthusiasts
			if (audienceDemographics[i][j] == 3) {
				if (audienceFaces[i][j] == 0) {
					totalTreeEmotions[0]++;
				}
				else if (audienceFaces[i][j] == 1) {
					totalTreeEmotions[1]++;
				}
				else {
					totalTreeEmotions[2]++;
				}
			}
			
		}
	}


}

void ImageManager::speechOption1() {
	//emotion index 0 = happy, 1 = angry, 2 = neutral

	//going through every person, rolling to see if roll is high enough to change value
	// 1 to 8 means turn emotion angry, 9 to 10 means turn neutral
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int diceRoll = rand() % 10 + 1; //range 1 to 10
			if (diceRoll < 9) {
				audienceFaces[i][j] = 1;
			}
			else {
				audienceFaces[i][j] = 2;
			}
		}
	}
	




}

void ImageManager::speechOption2() {
	//emotion index 0 = happy, 1 = angry, 2 = neutral

	//going through every person, rolling to see if roll is high enough to change value
	// 1 to 8 means turn emotion happy, 9 to 10 means turn neutral
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int diceRoll = rand() % 10 + 1; //range 1 to 10
			if (diceRoll < 9) {
				audienceFaces[i][j] = 0;
			}
			else {
				audienceFaces[i][j] = 2;
			}
		}
	}

}

void ImageManager::speechOption3() {
	//emotion index 0 = happy, 1 = angry, 2 = neutral
	//demographic index 0 = car, 1 = music, 2 = sword, 3 = tree

	//going through every person, rolling to see if roll is high enough to change value
	// 1 to 3 means turn emotion happy, 3 to 10 means turn neutral; all car enthusiasts guaranteed happy regardless of roll
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int diceRoll = rand() % 10 + 1; //range 1 to 10
			if (diceRoll < 4 || audienceDemographics[i][j] == 0) {
				audienceFaces[i][j] = 0;
			}
			else {
				audienceFaces[i][j] = 2;
			}
		}
	}

}

void ImageManager::speechOption4() {
	//emotion index 0 = happy, 1 = angry, 2 = neutral
	//demographic index 0 = car, 1 = music, 2 = sword, 3 = tree

	//going through every person, rolling to see if roll is high enough to change value
	// 1 to 4 means turn emotion happy, 5 to 7 means turn angry, 8 to 10 means turn neutral; all car enthusiasts guaranteed angry regardless of roll, all tree enthusiasts guaranteed happy regardless of roll
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int diceRoll = rand() % 10 + 1; //range 1 to 10
			if (diceRoll < 5 || audienceDemographics[i][j] == 3) {
				audienceFaces[i][j] = 0;
			}
			else if ( (diceRoll >= 5 && (diceRoll < 8)) ) {
				audienceFaces[i][j] = 1;
			} else {
				audienceFaces[i][j] = 2;
			}
			if (audienceDemographics[i][j] == 0) {
				//this is checked again incase the first condition diceRoll < 5 lets some car enthusiasts through
				audienceFaces[i][j] = 1;
			}
		}
	}
}


void ImageManager::shuffleFaces() {
	
	int faceValue = -1; // 0 = happy, 1 = angry, 2 = neutral

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			faceValue = rand() % 3; //random int in range of 0 to 2
			audienceFaces[i][j] = faceValue;
		}
		
	}

}

void ImageManager::shuffleDemographics() {

	int demographicsValue = -1; // 0 = car enthusiasts, 1 = music enthusiasts, 2 = sword enthusiasts, 3 = tree enthusiasts

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			demographicsValue = rand() % 4; //random int in range of 0 to 3
			audienceDemographics[i][j] = demographicsValue;
		}

	}
}

void ImageManager::newAudience() {

	shuffleFaces();
	shuffleDemographics();

}