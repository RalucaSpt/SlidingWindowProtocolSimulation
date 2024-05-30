#include "Reciver.h"
#include <algorithm>
#include <iostream>

Reciver::Reciver()
{
	packets = std::vector<Packet*>();
}

std::vector<Packet*> Reciver::getPackets()
{
	return packets;
}

void Reciver::setPackets(std::vector<Packet*> packets)
{
	this->packets = packets;
}

void Reciver::addPacket(Packet* packet)
{
	packets.push_back(packet);
}

void Reciver::sortPackets()
{
	std::sort(packets.begin(), packets.end(), [](Packet* a, Packet* b) { return a->getId() < b->getId(); });
}

bool randomLoss()
{
	return rand() % 10 + 1 == 1;
}

void Reciver::receivePackets(std::vector<Packet*> sendPackets)
{
	for (auto packet : sendPackets)
	{
		if (randomLoss())
		{
			system("color 0C");
			std::cout << "Packet " << packet->getId() << " was lost" << std::endl;
			packet->setSent(false);
			continue;
		}
		addPacket(packet);
		system("color 0A");
		std::cout << "Packet " << packet->getId() << " received" << std::endl;

		if (randomLoss()&& packet->IsSent())
		{
			system("color 0C");
			std::cout << "Acknowledge for packet " << packet->getId() << " was lost" << std::endl;
			continue;
		}
	}
}
