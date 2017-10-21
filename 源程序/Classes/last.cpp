#include "begin.h"
#include "menu.h"
#include "last.h"
#include "cocos-ext.h"
#include "SimpleAudioEngine.h"
#include "GLES-Render.h"
#include<string>
#include <list>
#include<algorithm>
#include"gameover.h"
#include"guoguan.h"
USING_NS_CC;
USING_NS_CC_EXT;
using namespace cocos2d;
using namespace CocosDenshion;
#define PTM_RATIO 32
CCScene* last::scene()
{
	CCScene *scene = CCScene::create();
	last *layer = last::create();
	scene->addChild(layer);
	return scene;
}


bool last::init()
{
	if ( !CCLayer::init() )
	{
		return false;
	}

	////////////////
	CCSize size = CCDirector::sharedDirector()->getWinSize();


	//////////////////////////////////////////////////////////////////////

	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("last.wav");
	CCSprite *sp=CCSprite::create("last.jpg");
	sp->setPosition(ccp(size.width/2,size.height/2));
	sp->setScaleY(0.7);
	sp->setScaleX(0.8);
	addChild(sp,0);

	CCMenuItemImage *pCloseItem10 = CCMenuItemImage::create(
		"renyi.png",
		"renyi.png",
		this,
		menu_selector(last::anniu1));
	pCloseItem10->setPosition(ccp(size.width/2,size.height/2));
	CCMenu* pMenu10 = CCMenu::create(pCloseItem10, NULL);
	pMenu10->setPosition(CCPointZero);
	this->addChild(pMenu10, 5,3);


	return true;
}

void last::anniu1(CCObject* pSender)
{
	SimpleAudioEngine::sharedEngine()->playEffect("button.WAV");
	CCScene * scene2=menu::scene();
	CCTransitionScene * s3=CCTransitionSplitRows::create(1,scene2);
	CCDirector::sharedDirector()->replaceScene(s3);
}
