#pragma once

class Packet
{
	int id;
	bool isAcked;
	bool isSent;

public:
	Packet(int id, bool ack=false, bool sent=false);
	~Packet()=default;

	int getId();
	bool IsAck();
	bool IsSent();
	void setAck(bool ack);
	void setId(int id);
	void setSent(bool sent);
};

