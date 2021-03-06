#pragma once

#include "cocos2d.h"
#include <queue>
#include "GlobalDefs.h"

class FloorScene : public cocos2d::Layer
{

	float startX;
	float startY;


public:
	bool movementActive = false;
	bool canChangeDIR = true;

	static cocos2d::Scene* createScene();
	virtual bool init();

	//called when changing floor
	void loadFloor();

	CREATE_FUNC(FloorScene);

	void onTouchesEnded(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *event);

	//draw a dialog of given type
	//options are optional, will call GameData dialogComplete on dismiss
	void drawDialog(const std::string & text, twsutil::DIALOGTYPE dType, std::vector<std::string>options = {});

	void drawEnemyPortrait(cocos2d::Sprite* s);

	void showFloorEnemyStats(std::vector<std::tuple<cocos2d::Sprite*, std::string, int, int, int, int>>& stats);

	//attach the sprite to floorContent
	void attachFloorSprite(cocos2d::Sprite* s);

	void continousMovement();

private:
	cocos2d::Node* floorContent = nullptr; //the 11x11 grid
	cocos2d::DrawNode* dialogNode;
	bool dialogOpen = false;
	int absorbClick = 0;
	twsutil::DIALOGTYPE dialogType; //current dialog type

	//bottom right enemy info
	int eSpriteX = -1;
	int eSpriteY = -1;
	cocos2d::Sprite* enemyInfoSprite = nullptr;

	twsutil::DIR currentMovement;

	void closeDialog(int);

	void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

};