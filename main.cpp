#include <iostream>
#include <stdlib.h>
#define _WIN32_WINNT 0x0500
#include "Windows.h"
#define _WIN32_WINNT 0x0500
#include <string.h>
#include "SerialPort.hpp"

using namespace std;

void pular() {
	INPUT pulo = { 0 };
	pulo.type = INPUT_KEYBOARD;
	pulo.ki.wVk = VK_UP;
	SendInput(1, &pulo, sizeof(INPUT));
	pulo.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &pulo, sizeof(INPUT));
}

int main(int argc, char **argv) {
	char *port_name = argv[1];
	char incomingData[MAX_DATA_LENGTH];
	SerialPort arduino(port_name);
	if (arduino.isConnected()) cout << "Connection Established" << endl;
	else cout << "ERROR, check port name";
	
	while (arduino.isConnected()){
	  int read_result = arduino.readSerialPort(incomingData, MAX_DATA_LENGTH);
	  if (read_result) {
		pular();
		cout << "pulando!!!";
	  }
	  else {
		cout << "Aguardando..." << endl;
	  }
	  Sleep(10);
	}
	return 0;
}
