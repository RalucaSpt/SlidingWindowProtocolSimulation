#pragma once
#include <vector>
#include "Packet.h"
#include "Reciver.h"
#include "Window.h"

class Sender
{
	std::vector<Packet*> packets;

public:
	Sender(int);
	std::vector<Packet*> getPackets();
};

