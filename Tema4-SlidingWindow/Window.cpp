#include "Window.h"
#include <iostream>
#include <thread>
#include <chrono>

Window::Window(int s, std::vector<Packet*> sw)
	:size(s), slidingWindow(sw)
{
}

Window::Window(int s)
	:size(s)
{
	for (int i = 0; i < s; i++)
	{
		Packet* p = new Packet(i);
		slidingWindow.push_back(p);
	}
}

int Window::getSize()
{
	return size;
}

std::vector<Packet*> Window::getSlidingWindow()
{
	return slidingWindow;
}

void Window::setSlidingWindow(std::vector<Packet*>sd)
{
	slidingWindow = sd;
}

void Window::setSize(int s)
{
	size = s;
}

void Window::slideWindow(std::vector<Packet*> packets)
{
	if (slidingWindow[0]->IsAck())
	{
		std::cout << "\nSliding window:\n";
		std::this_thread::sleep_for(std::chrono::seconds(1));

		std::cout << "[";
		for (auto packet : slidingWindow)
		{
			std::cout << packet->getId() << " ";
		}
		std::cout << "]\n";
		std::this_thread::sleep_for(std::chrono::seconds(1));

	}

	while (slidingWindow[0]->IsAck())
	{
		if (getLastPacketId() == packets.size() - 1)
		{
			slidingWindow.erase(slidingWindow.begin());
			break;
		}
		slidingWindow.erase(slidingWindow.begin());
		packets[getLastPacketId() + 1]->setSent(true);
		slidingWindow.push_back(packets[getLastPacketId() + 1]);
		std::cout << "[";
		for (auto packet : slidingWindow)
		{
			std::cout << packet->getId() << " ";
		}
		std::cout << "]\n";
		std::this_thread::sleep_for(std::chrono::seconds(1));

		std::cout << getLastPacketId() << " sent\n";
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}


int Window::getLastPacketId()
{
	return slidingWindow.back()->getId();
}

