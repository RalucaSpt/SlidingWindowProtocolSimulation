#pragma once
#include <vector>
#include "Packet.h"
class Reciver
{
	std::vector<Packet*> packets;

public:
	Reciver();
	std::vector<Packet*> getPackets();
	void setPackets(std::vector<Packet*> packets);
	void addPacket(Packet* packet);
	void sortPackets();
	void receivePackets(std::vector<Packet*> packets);
};

