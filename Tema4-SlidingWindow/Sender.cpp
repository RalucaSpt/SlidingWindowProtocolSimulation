#include "Sender.h"

Sender::Sender(int n)
{
	for (int i = 0; i < n; i++)
	{
		Packet* p = new Packet(i);
		packets.push_back(p);
	}
}

std::vector<Packet*> Sender::getPackets()
{
		return packets;
}


