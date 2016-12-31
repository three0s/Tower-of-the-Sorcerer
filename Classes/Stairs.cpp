#include "Stairs.h"
#include "GameData.h"

Stairs::Stairs(int imageIdx,const std::string& desc,int targetFloor,int x,int y,enum DIR dir):
	MyEvent(imageIdx,desc),targetFloor(targetFloor),tx(x),ty(y),heroDir(dir)
{
}

bool Stairs::triggerEvent()
{
	//auto retainSprite=getSprite();
	//retainSprite->retain(); //do not delete yet...
	//CCLOG("walk the stairs");
	GameData::getInstance()->hero->getSprite()->stopAllActions(); //actually need to stop...
	int x=tx;int y=ty;enum DIR dir=heroDir; //setFloor will destruct this object and these fields will be unaccessible
	//CCLOG("setting floor");
	GameData::getInstance()->setFloor(targetFloor);
	//CCLOG("floor set");
	//use the var saved on stack
	GameData::getInstance()->hero->setAbsPos(x,y,dir);
	//CCLOG("done changing floor");
	return false;
}

int Stairs::getTargetFloor(){
	return targetFloor;
}

Stairs::~Stairs()
{
}

Stairs * Stairs::clone()
{
	return new Stairs(*this);
}
