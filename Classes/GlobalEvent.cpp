#include "GlobalEvent.h"
#include <vector>


bool GlobalEvent::tryTrigger(){
    for (auto cond:conditions){
        if (!cond->check())
            return false;
    }
    for (int i=0;i<actions.size();i++)
		actions[i]->perform(nullptr);
    return true;
}

void GlobalEvent::attachAction(MyAction* action){
    actions.push_back(action);
}

void GlobalEvent::addCondition(Condition* cond){
    conditions.push_back(cond);
}

GlobalEvent::~GlobalEvent(){
    for (int i=0;i<conditions.size();i++)
		delete conditions[i];
    for (int i=0;i<actions.size();i++)
		delete actions[i];
}