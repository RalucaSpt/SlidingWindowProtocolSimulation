#include "Packet.h"

Packet::Packet(int id, bool ack, bool sent)
	:id(id), isAcked(ack), isSent(sent)
{
}


int Packet::getId()
{
	return id;
}

bool Packet::IsAck()
{
	return isAcked;
}

bool Packet::IsSent()
{
	return isSent;
}

void Packet::setAck(bool ack)
{
	this->isAcked = ack;
}

void Packet::setId(int id)
{
	this->id = id;
}

void Packet::setSent(bool sent)
{
	isSent = sent;
}

