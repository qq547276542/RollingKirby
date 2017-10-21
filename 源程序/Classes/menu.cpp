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
CCScene* menu::scene()
{
	CCScene *scene = CCScene::create();
	menu *layer = menu::create();
	scene->addChild(layer);
	return scene;
}


bool menu::init()
{
	if ( !CCLayer::init() )
	{
		return false;
	}

	////////////////
	CCSize size = CCDirector::sharedDirector()->getVisibleSize();


	//////////////////////////////////////////////////////////////////////
	  
	SimpleAudioEngine::sharedEngine()->preloadEffect("button.WAV");
	
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("menu.mp3");
		SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(0.5);
	CCSprite *sp=CCSprite::create("menu_scene.jpg");
	sp->setPosition(ccp(size.width/2,size.height/2-50));
	sp->setScale(0.8);
	addChild(sp,0);
    

	CCSprite *sp1=CCSprite::create("title.png");
	sp1->setPosition(ccp(size.width/2+40,size.height+150));
	sp1->setScale(0.9);
	addChild(sp1,0);
	 CCActionInterval *ac=CCMoveTo::create(1.5f,ccp(size.width/2+40,size.height/2+150));
	 sp1->runAction(ac);

	CCSprite *kb=CCSprite::create("kb.png");
	kb->setPosition(ccp(-100,size.height/2-80));
	kb->setScale(0.35);
	addChild(kb,1);
	CCActionInterval * a1=CCMoveTo::create(1.5f,ccp(size.width/3.5,size.height/2-80));
	kb->runAction(a1);



	CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
		"ksyx1.png",
		"ksyx2.png",
		this,
		menu_selector(menu::anniu1));
	pCloseItem->setPosition(ccp(size.width+150 , size.height/1.8));
	CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
	pMenu->setPosition(CCPointZero);
	this->addChild(pMenu, 15,10);
	CCActionInterval * a2=CCMoveTo::create(1.5f,ccp(size.width/1.15,size.height/1.8));
	pCloseItem->runAction(a2);


	CCMenuItemImage *pCloseItem1 = CCMenuItemImage::create(
		"kftd1.png",
		"kftd2.png",
		this,
		menu_selector(menu::anniu2));
	pCloseItem1->setPosition(ccp(size.width+150 , size.height/1.8-80));
	CCMenu* pMenu1 = CCMenu::create(pCloseItem1, NULL);
	pMenu1->setPosition(CCPointZero);
	this->addChild(pMenu1, 15,10);
	CCActionInterval * a3=CCMoveTo::create(1.5f,ccp(size.width/1.15,size.height/1.8-80));
	pCloseItem1->runAction(a3);



	CCMenuItemImage *pCloseItem2 = CCMenuItemImage::create(
		"tcyx1.png",
		"tcyx2.png",
		this,
		menu_selector(menu::anniu3));
	pCloseItem2->setPosition(ccp(size.width+150 , size.height/1.8-160));
	CCMenu* pMenu2 = CCMenu::create(pCloseItem2, NULL);
	pMenu2->setPosition(CCPointZero);
	this->addChild(pMenu2, 15,10);
	CCActionInterval * a4=CCMoveTo::create(1.5f,ccp(size.width/1.15,size.height/1.8-160));
	pCloseItem2->runAction(a4);
	return true;
}

void menu::anniu1(CCObject* pSender)
{
	SimpleAudioEngine::sharedEngine()->playEffect("button.WAV");
	CCScene * scene2=begin1::scene();

	CCDirector::sharedDirector()->replaceScene(scene2);
}

void menu::anniu2(CCObject* pSender)
{
	SimpleAudioEngine::sharedEngine()->playEffect("button.WAV");
	CCScene * scene2=kfry::scene();

	CCTransitionScene * s5=CCTransitionFadeTR::create(1,scene2);

	CCDirector::sharedDirector()->replaceScene(s5);
}

void menu::anniu3(CCObject* pSender)
{
	SimpleAudioEngine::sharedEngine()->playEffect("button.WAV");
	CCDirector::sharedDirector()->end();
}