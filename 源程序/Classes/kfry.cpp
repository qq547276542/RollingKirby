#include "begin.h"
#include "menu.h"
#include "kfry.h"
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
CCScene* kfry::scene()
{
	CCScene *scene = CCScene::create();
	kfry *layer = kfry::create();
	scene->addChild(layer);
	return scene;
}


bool kfry::init()
{
	if ( !CCLayer::init() )
	{
		return false;
	}

	////////////////
	CCSize size = CCDirector::sharedDirector()->getWinSize();


	//////////////////////////////////////////////////////////////////////

	SimpleAudioEngine::sharedEngine()->preloadEffect("button.WAV");
	SimpleAudioEngine::sharedEngine()->preloadEffect("play5.wav");
	SimpleAudioEngine::sharedEngine()->preloadEffect("play1.wav");
	SimpleAudioEngine::sharedEngine()->preloadEffect("play3.wav");
	SimpleAudioEngine::sharedEngine()->preloadEffect("play2.wav");
	SimpleAudioEngine::sharedEngine()->preloadEffect("play4.wav");
	CCSprite *sp=CCSprite::create("kfry.jpg");
	sp->setPosition(ccp(size.width/2,size.height/2-50));
	sp->setScale(0.78);
	addChild(sp,0);

	CCMenuItemImage *pCloseItem10 = CCMenuItemImage::create(
		"cyz.png",
		"cyz.png",
		this,
		menu_selector(kfry::play1));
	pCloseItem10->setPosition(ccp(160,370));
	CCMenu* pMenu10 = CCMenu::create(pCloseItem10, NULL);
	pMenu10->setPosition(CCPointZero);
	this->addChild(pMenu10, 5,3);

	pCloseItem10  = CCMenuItemImage::create(
		"lh.png",
		"lh.png",
		this,
		menu_selector(kfry::play2));
	pCloseItem10->setPosition(ccp(320,370));
	pMenu10 = CCMenu::create(pCloseItem10, NULL);
	pMenu10->setPosition(CCPointZero);
	this->addChild(pMenu10, 5,3);

	

	pCloseItem10  = CCMenuItemImage::create(
		"zjf.jpg",
		"zjf.jpg",
		this,
		menu_selector(kfry::play3));
	pCloseItem10->setPosition(ccp(160,240));
	pMenu10 = CCMenu::create(pCloseItem10, NULL);
	pMenu10->setPosition(CCPointZero);
	this->addChild(pMenu10, 5,3);
	

	pCloseItem10  = CCMenuItemImage::create(
		"cz.jpg",
		"cz.jpg",
		this,
		menu_selector(kfry::play4));
	pCloseItem10->setPosition(ccp(320,240));
	pMenu10 = CCMenu::create(pCloseItem10, NULL);
	pMenu10->setPosition(CCPointZero);
	this->addChild(pMenu10, 5,3);
	

	pCloseItem10  = CCMenuItemImage::create(
		"ypb.jpg",
		"ypb.jpg",
		this,
		menu_selector(kfry::play5));
	pCloseItem10->setPosition(ccp(160,100));
	pMenu10 = CCMenu::create(pCloseItem10, NULL);
	pMenu10->setPosition(CCPointZero);
	this->addChild(pMenu10, 5,3);



	pCloseItem10 = CCMenuItemImage::create(
		"zhuye.png",
		"zhuye.png",
		this,
		menu_selector(kfry::anniu1));
	pCloseItem10->setPosition(ccp(620 ,420));
	 pMenu10 = CCMenu::create(pCloseItem10, NULL);
	pMenu10->setPosition(CCPointZero);
	this->addChild(pMenu10, 1,3);


	return true;
}

void kfry::anniu1(CCObject* pSender)
{
	SimpleAudioEngine::sharedEngine()->playEffect("button.WAV");
	CCScene * scene2=menu::scene();
	CCTransitionScene * s3=CCTransitionFadeBL::create(1,scene2);
	CCDirector::sharedDirector()->replaceScene(s3);
}

void kfry::play1(CCObject* pSender)
{
	SimpleAudioEngine::sharedEngine()->playEffect("play1.wav");
}
void kfry::play2(CCObject* pSender)
{
	SimpleAudioEngine::sharedEngine()->playEffect("play2.wav");
}
void kfry::play3(CCObject* pSender)
{
	SimpleAudioEngine::sharedEngine()->playEffect("play3.wav");
}
void kfry::play4(CCObject* pSender)
{
	SimpleAudioEngine::sharedEngine()->playEffect("play4.wav");
}
void kfry::play5(CCObject* pSender)
{
	SimpleAudioEngine::sharedEngine()->playEffect("play5.wav");
	
}