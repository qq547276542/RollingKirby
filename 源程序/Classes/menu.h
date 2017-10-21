#ifndef __MENU_H__
#define __MENU_H__

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include <list>
#include <set>
#include "SimpleAudioEngine.h"
#include "cocos-ext.h"
#include "GLES-Render.h"
#include <vector>
#include <algorithm>
USING_NS_CC;
USING_NS_CC_EXT;
using std::list;
#define PTM_RATIO 32
class menu : public cocos2d::CCLayer,public b2ContactListener
{

public:
	virtual bool init();
	static cocos2d::CCScene* scene();
	CREATE_FUNC(menu);
	void anniu1(CCObject* pSender);
	void anniu2(CCObject* pSender);
	void anniu3(CCObject* pSender);
};





#endif // __HELLOWORLD_SCENE_H__
