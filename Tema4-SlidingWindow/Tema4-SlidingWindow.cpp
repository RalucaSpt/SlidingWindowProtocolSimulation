#include <iostream>
#include <algorithm>
#include "Reciver.h"
#include "Sender.h"
#include "Window.h"
#include<thread>
#include <chrono>
#include <random>

int random()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, 7);
	return dis(gen);
}

int main()
{
	int n, windowSize;
	std::cout << "Introduceti nr de pachete: ";
	std::cin >> n;
	std::cout << "Introduceti dimensiunea ferestrei: ";
	std::cin >> windowSize;
	Window window(windowSize);
	Sender sender(n);
	std::vector<Packet*> recivedPackets;
	while (recivedPackets.size() < n)
	{
		for (auto packet : window.getSlidingWindow())
		{
			if (!packet->IsSent() && !packet->IsAck())
				if (random() == 1)
				{
					std::cout << packet->getId() << " lost sending\n";
					//stai 2 secunde pe loc
					std::this_thread::sleep_for(std::chrono::seconds(1));
					packet->setSent(false);
				}
				else
				{
					std::cout << packet->getId() << " sent\n";
					std::this_thread::sleep_for(std::chrono::seconds(1));

					packet->setSent(true);
				}

		}
		for (auto packet : window.getSlidingWindow())
		{
			if (packet->IsSent() && !packet->IsAck())
				if (random() == 1)
				{
					std::cout << packet->getId() << " lost ack\n";
					std::this_thread::sleep_for(std::chrono::seconds(1));

					packet->setSent(false);
					packet->setAck(false);
				}
				else
				{
					std::cout << packet->getId() << " ack\n";
					std::this_thread::sleep_for(std::chrono::seconds(1));

					packet->setAck(true);
					recivedPackets.push_back(packet);
					window.slideWindow(sender.getPackets());
				}
		}
	}
	std::cout << "All packets received.\n";
	std::cout << "Packets received: ";
	for (auto packet : recivedPackets)
		std::cout << packet->getId() << " ";
	std::cout << "\n";
	std::cout << "Sorted packets: ";
	std::sort(recivedPackets.begin(), recivedPackets.end(), [](Packet* a, Packet* b) {return a->getId() < b->getId(); });
	for (auto packet : recivedPackets)
		std::cout << packet->getId() << " ";

}
