#ifndef __BEGIN_H__
#define __BEGIN_H__

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
class begin1 : public cocos2d::CCLayer,public b2ContactListener
{

public:
	virtual bool init();
	static cocos2d::CCScene* scene();
	CREATE_FUNC(begin1);
	
	void xuanguan(CCObject* pSender);

	void casea1(CCObject* pSender);
	void casea2(CCObject* pSender);
	void casea3(CCObject* pSender);
	int scene_case;
	void guan1(CCObject* pSender);
	void guan2(CCObject* pSender);
	void guan3(CCObject* pSender);
	void guan4(CCObject* pSender);
	void guan5(CCObject* pSender);
	void guan6(CCObject* pSender);
	
};





#endif // __HELLOWORLD_SCENE_H__
