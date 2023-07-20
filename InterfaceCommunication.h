#pragma once
 class InterfaceCommunication
{
public:
	virtual void SendEmail() = 0;
	virtual void SendSMS() = 0;
	virtual void SendFax() = 0;

};

