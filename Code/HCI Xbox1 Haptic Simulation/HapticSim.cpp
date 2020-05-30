/*

Andrew Littleton and Jack O'Hare
Accesibility Enhanced Sound and Haptics
Xbox One Controller Vibration Research Simulation
COMP 341 - Human Computer Interaction
04/20/2020

*/
#include "HapticSim.h"
#include <chrono>
#include <thread>

XINPUT_VIBRATION vibration;
DWORD controllerState;
Xbox1HapticSimulation simulationObject;
int vibrationDuration;

//The following only works for the first player controller and is not designed to be robust

void Xbox1HapticSimulation::vibrate(int duration) {
	//conditional to get keystroke and call coordinating function
	//set duration = return value of coordinating function
	controllerState = XInputSetState(0, &vibration); //indicate controller vibration
	std::this_thread::sleep_for(std::chrono::milliseconds(duration)); //wait for designated duration period in ms (set by coordinating cursor function)
	simulationObject.stopVibrate(); //stop controller vibration
};

//function to stop controller vibration
void Xbox1HapticSimulation::stopVibrate() {
	vibration.wLeftMotorSpeed = 0;
	vibration.wRightMotorSpeed = 0;
	controllerState = XInputSetState(0, &vibration);
};

//sets left motor speed to 50% and duration to 0.5 seconds
int Xbox1HapticSimulation::leftCursorMove() {
	vibrationDuration = 500;
	vibration.wLeftMotorSpeed = 32768;	
	return vibrationDuration;
};

//sets right motor speed to 75% and duration to 0.5 seconds
int Xbox1HapticSimulation::rightCursorMove() {
	vibrationDuration = 500;
	vibration.wRightMotorSpeed = 49151; 
	return vibrationDuration;
};

//sets left motor speed to 25% and right motor speed to 50% and  duration to 1 second
int Xbox1HapticSimulation::upCursorMove() {
	vibrationDuration = 1000;
	vibration.wLeftMotorSpeed = 16384;
	vibration.wRightMotorSpeed = 49151;
	return vibrationDuration;
};

//sets left motor speed to 25% and right motor speed to 50% and  duration to 0.5 seconds 
int Xbox1HapticSimulation::downCursorMove() {
	vibrationDuration = 500;
	vibration.wLeftMotorSpeed = 16384;
	vibration.wRightMotorSpeed = 49151;
	return vibrationDuration;
};

//sets left motor speed to 10% and right motor speed to 20% and  duration to 0.25 seconds
int Xbox1HapticSimulation::selectCursorAction() {
	vibrationDuration = 250;
	vibration.wLeftMotorSpeed = 6554;
	vibration.wRightMotorSpeed = 13107;
	return vibrationDuration;
};