#ifndef __GUOGUAN_H__
#define __GUOGUAN_H__

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "SimpleAudioEngine.h"
#include "cocos-ext.h"
using namespace cocos2d;
using namespace cocos2d::extension;
USING_NS_CC;
USING_NS_CC_EXT;
class guoguan : public cocos2d::CCLayer
{
public:
	virtual bool init();  
	static cocos2d::CCScene* scene();
	void menuCloseCallback(CCObject* pSender);
	CREATE_FUNC(guoguan);
	void changescene(CCObject* pSender);
	void nextscene(CCObject* pSender);
	void remenu(CCObject* pSender);
	//生命周期函数
	virtual void onEnter();
	virtual void onEnterTransitionDidFinish();
	virtual void onExit();
};

#endif  