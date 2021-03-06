#include "HeroItem.h"
#include "GlobalDefs.h"
#include "GameData.h"
#include "TransformCoordinate.h"

USING_NS_CC;

HeroItem::HeroItem(int id, std::string s, int imageID, std::function<void()> f, int uses) :id(id), uses(uses), desc(s), imageID(imageID), f(f)
{
}

void HeroItem::attachTo(cocos2d::Node *parent)
{
	if (obtained)
		return;
	obtained = true;
	std::string imagePath = "images/tile (" + std::to_string(imageID) + ").png";
	itemButton = ui::Button::create(imagePath, imagePath);
	itemButton->setAnchorPoint(Vec2(0, 1));
	//itemButton->setTitleText(desc);
	itemButton->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		if (GameData::getInstance().isBlocked())
			return;
		switch (type)
		{
		case ui::Widget::TouchEventType::ENDED:
			if (f)
				f();
			//TODO if f plays an animation... then triggerGlobalEvents might happen before it
			GameData::getInstance().triggerGlobalEvents();
			break;
		default:
			break;
		}
	});

	itemButton->setPosition(TransformCoordinate::itemIDVec2(id));
	parent->addChild(itemButton, 100);
}

bool HeroItem::isObtained()
{
	return obtained;
}

std::function<void()> HeroItem::getEffectFunction(const std::string& e)
{
	if (e == "showFloorEnemyStats") {
		return []() {
			GameData::getInstance().showFloorEnemyStats();
		};
	}
	if (e == "fastStairs") {
		return []() {
			GameData::getInstance().fastStairs();
		};
	}
	if (e == "replayDialog") {
		return []() {
			GameData::getInstance().replayDialog();
		};
	}
	return nullptr;
}



/*
void HeroItem::showFloorEnemyStats()
{
	GameData::getInstance()->showFloorEnemyStats();
}*/
