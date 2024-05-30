#pragma once
#include <vector>
#include "Packet.h"
class Window
{
	int size;
	std::vector<Packet*> slidingWindow;

public:
	Window(int);
	Window(int, std::vector<Packet*>);
	int getSize();
	std::vector<Packet*> getSlidingWindow();
	void setSlidingWindow(std::vector<Packet*>);
	void setSize(int);
	void slideWindow(std::vector<Packet*> packets);
	int getLastPacketId();
};


