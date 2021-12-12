#include "poliRalSimFluid.h"

int main(int argc, char** argv) {
	ShowWindow(GetConsoleWindow(), SW_HIDE); //hides the console window because this is a console program; alternate is to switch this over to a gui like win32 api or ... winmain(), those may cause compatibility with mac and linux
	UserInterface* mainGUI = new UserInterface();
	mainGUI->createWindow()->show(); //createWindow() returns a FL_window type so that can show() but mainGUI-> wont work cuz mainGUI didnt inherit anything

	return Fl::run();
}