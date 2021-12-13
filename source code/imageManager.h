#pragma once
#include <iostream>
#include <cstdlib>
#include <string>

class ImageManager {
public:
	
	int getAudienceFace(int row, int col); //gets the emotion of the person at that location
	int getAudienceDemographics(int row, int col); //gets the demographics of the person at that location

	int getTotalHappyFaces();
	int getTotalAngryFaces();
	int getTotalNeutralFaces();

	int getCarEmotions(int index);
	int getMusicEmotions(int index);
	int getSwordEmotions(int index);
	int getTreeEmotions(int index);
	std::string getCityName(); //returns a random city name

	void calcTotalFaces(); //counts all the total happy/angry/neutral faces and replaces the private variables for each one	
	void calcTotalEmotionsPerDemo(); //counts all the individual happy/angry/neutral faces of each demographic and replaces the private variable for each one
	void newAudience(); //shuffles around the faces and the demographics, the demographics will always be a 4/4/4/4 split

	void speechOption1();//"Taxes go up" rerolls for 80% will be angry, 20% neutral
	void speechOption2();//"Taxes go down" rerolls for 80% will be happy, 20% neutral
	void speechOption3();//"Fix the roads" rerolls for 30% will be happy (all car enthusiasts will be guaranteed happy), 70% neutral
	void speechOption4();//"More bicycle lanes" rerolls for 40% will be happy(all environmentalists will be happy), 30% angry (all car enthusiasts wil be angry), 30% neutral
 
	

private:

	std::string cityName[5] = { "Dallas", "San Diego", "New York", "Seattle", "Miami" };

	int cityRollCounter = 0;
	int totalAudience = 16;
	int audienceFaces[4][4];
	int audienceDemographics[4][4];
	int totalHappyFaces;
	int totalAngryFaces;
	int totalNeutralFaces;
	int totalCarEmotions[3]; //index 0 = happy, 1 = angry, 2 = neutral; the value is the quantity
	int totalMusicEmotions[3];//index 0 = happy, 1 = angry, 2 = neutral; the value is the quantity
	int totalSwordEmotions[3];//index 0 = happy, 1 = angry, 2 = neutral; the value is the quantity
	int totalTreeEmotions[3];//index 0 = happy, 1 = angry, 2 = neutral; the value is the quantity


	void shuffleFaces(); //shuffles the faces only and changes the values in the audienceFaces variable
	void shuffleDemographics(); //shuffles the demographics only and changes the values in the audienceDemographics variable


	



};