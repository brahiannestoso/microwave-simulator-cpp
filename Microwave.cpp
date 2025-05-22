#include <iostream>
#include <thread>
#include <chrono>

using namespace std;


/* MICROWAVE SIMULATOR
	- SET TIME = User enters cook time.
	- POWER LEVEL = User selects power level (ex. 1 to 10)
	- START/STOP = User can start, pause, or cancel the cooking.
	- COUNTDOWN TIMER =  Cooking time counts down in real time.
	- DOOR OPEN DECTION (SIMULATED) = Prevents start if door is "open".
	- SOUND ALERT = Print "Beep!" when cooking is done. 
	- OPTIONAL FEATURES = Presets (popcorn, reheat, etc.), LED Display simulation, child lock. 
*/


void countdown(int seconds, int powerLevel) {
	for (int i = seconds; i > 0; i--) {
		cout << "Time remaining: " << i << "s | Power: " << powerLevel << endl;
		this_thread::sleep_for(chrono::seconds(1));
	}
	cout << "Cooking complete! BEEP BEEP BEEP!" << endl;
}

int main() {

	int choice;
	int cookTime = 0;
	int powerLevel = 5;
	bool isDoorOpen = false;
	bool isCooking = false;

	while (true) {
		cout << "\n======== MICROWAVE SIMULATOR ========\n";
		cout << "1. Set Time\n";
		cout << "2. Set Power Level\n";
		cout << "3. Open/Close Door\n";
		cout << "4. Start Cooking\n";
		cout << "5. Stop Cooking\n";
		cout << "6. Exit\n";
		cout << "=======================================\n";
		cout << "Enter a choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Enter cooking time in seconds: ";
			cin >> cookTime;
			break;
		case 2:
			cout << "Enter power level (1-10): ";
			cin >> powerLevel;
			break;
		case 3:
			isDoorOpen = !isDoorOpen;
			cout << (isDoorOpen ? "Door opened.\n" : "Door closed.\n");
			break;
		case 4:
			if (isDoorOpen) {
				cout << "Cannot start cooking. Door is open!\n";
			}
			else if (cookTime <= 0) {
				cout << "Set a vlid cooking time first!\n";
			}
			else {
				isCooking = true;
				countdown(cookTime, powerLevel);
				isCooking = false;
			}
			break;
		case 5:
			if (isCooking) {
				isCooking = false;
				cout << "Cooking stopped.\n";
			}
			else {
				cout << "Microwave is not currently cooking.\n";
			}
			break;
		case 6:
			cout << "Exiting... Goodbye!\n";
			return 0;
		default:
			cout << "Invalid option.\n";
		}

	}


}




