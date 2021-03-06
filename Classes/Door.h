#pragma once
#include "MyEvent.h"
#include "Key.h"

class Door :
	public MyEvent
{
public:
	Door(int imageIdx, const std::string& decription, enum KeyType doorType);
	bool triggerEvent();
	virtual ~Door();

private:
	enum KeyType doorType;

};

