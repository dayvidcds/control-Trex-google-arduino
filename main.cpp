#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "SerialPort.hpp"

using namespace std;

char *port_name = "\\\\.\\COM9";

char incomingData[MAX_DATA_LENGTH];

void pular() {
	INPUT pulo = { 0 };
	pulo.type = INPUT_KEYBOARD;
	pulo.ki.wVk = VK_UP;
	SendInput(1, &pulo, sizeof(INPUT));
	pulo.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &pulo, sizeof(INPUT));
}

int main() {
	SerialPort arduino(port_name);
	if (arduino.isConnected()) cout << "Connection Established" << endl;
	else cout << "ERROR, check port name";
	
	while (arduino.isConnected()){
	  int read_result = arduino.readSerialPort(incomingData, MAX_DATA_LENGTH);
	  puts(incomingData);
	  Sleep(10);
	}
	return 0;
}