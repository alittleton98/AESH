#pragma once
#include <Windows.h>
#include <XInput.h>;

class Xbox1HapticSimulation {
public:
	int leftCursorMove();
	int rightCursorMove();
	int upCursorMove();
	int downCursorMove();
	int selectCursorAction();
	void vibrate(int duration);
	void stopVibrate();
};
	

