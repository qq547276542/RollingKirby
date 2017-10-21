#include "guoguan.h"
#include "SimpleAudioEngine.h"
#include "cocos-ext.h"
#include "cocos2d.h"
#include "HelloWorldScene.h"
#include "menu.h"
#include "a1.h"
#include "a2.h"
#include "a3.h"
#include "a4.h"
#include "a5.h"
#include "a6.h"
#include "b1.h"
#include "b2.h"
#include "b3.h"
#include "b4.h"
#include "b5.h"
#include "b6.h"
#include "c1.h"
#include "c2.h"
#include "c3.h"
#include "c4.h"
#include "c5.h"
#include "c6.h"
#include "last.h"
using namespace cocos2d;
using namespace cocos2d::extension;
using namespace CocosDenshion;
CCScene* guoguan::scene()
{
	CCScene * scene = NULL;
	do 
	{
		scene = CCScene::create();
		CC_BREAK_IF(! scene);
		guoguan *layer = guoguan::create();
		CC_BREAK_IF(! layer);
		scene->addChild(layer);
	} while (0);
	return scene;
}

bool guoguan::init()
{
	bool bRet = false;
	do 
	{
		CC_BREAK_IF(! CCLayer::init());
		///////////////////////////////////////////////////////
		//-new-//
		int now=CCUserDefault::sharedUserDefault()->getIntegerForKey("scene_num");//当前玩的关卡
		if(now==1)
		{
			CCUserDefault::sharedUserDefault()->setIntegerForKey("yes1",1);
			CCUserDefault::sharedUserDefault()->flush();
		}
		if(now==2)
		{
			CCUserDefault::sharedUserDefault()->setIntegerForKey("yes2",1);
			CCUserDefault::sharedUserDefault()->flush();
		}
		if(now==3)
		{
			CCUserDefault::sharedUserDefault()->setIntegerForKey("yes3",1);
			CCUserDefault::sharedUserDefault()->flush();
		}
		if(now==4)
		{
			CCUserDefault::sharedUserDefault()->setIntegerForKey("yes4",1);
			CCUserDefault::sharedUserDefault()->flush();
		}
		if(now==5)
		{
			CCUserDefault::sharedUserDefault()->setIntegerForKey("yes5",1);
			CCUserDefault::sharedUserDefault()->flush();
		}
		if(now==6)
		{
			CCUserDefault::sharedUserDefault()->setIntegerForKey("yes6",1);
			CCUserDefault::sharedUserDefault()->flush();
		}
		if(now==11)
		{
			CCUserDefault::sharedUserDefault()->setIntegerForKey("yes11",1);
			CCUserDefault::sharedUserDefault()->flush();
		}
		if(now==12)
		{
			CCUserDefault::sharedUserDefault()->setIntegerForKey("yes12",1);
			CCUserDefault::sharedUserDefault()->flush();
		}
		if(now==13)
		{
			CCUserDefault::sharedUserDefault()->setIntegerForKey("yes13",1);
			CCUserDefault::sharedUserDefault()->flush();
		}
		if(now==14)
		{
			CCUserDefault::sharedUserDefault()->setIntegerForKey("yes14",1);
			CCUserDefault::sharedUserDefault()->flush();
		}
		if(now==15)
		{
			CCUserDefault::sharedUserDefault()->setIntegerForKey("yes15",1);
			CCUserDefault::sharedUserDefault()->flush();
		}
		if(now==16)
		{
			CCUserDefault::sharedUserDefault()->setIntegerForKey("yes16",1);
			CCUserDefault::sharedUserDefault()->flush();
		}
		if(now==21)
		{
			CCUserDefault::sharedUserDefault()->setIntegerForKey("yes21",1);
			CCUserDefault::sharedUserDefault()->flush();
		}
		if(now==22)
		{
			CCUserDefault::sharedUserDefault()->setIntegerForKey("yes22",1);
			CCUserDefault::sharedUserDefault()->flush();
		}
		if(now==23)
		{
			CCUserDefault::sharedUserDefault()->setIntegerForKey("yes23",1);
			CCUserDefault::sharedUserDefault()->flush();
		}
		if(now==24)
		{
			CCUserDefault::sharedUserDefault()->setIntegerForKey("yes24",1);
			CCUserDefault::sharedUserDefault()->flush();
		}
		if(now==25)
		{
			CCUserDefault::sharedUserDefault()->setIntegerForKey("yes25",1);
			CCUserDefault::sharedUserDefault()->flush();
		}
		if(now==26)
		{
			CCUserDefault::sharedUserDefault()->setIntegerForKey("yes26",1);
			CCUserDefault::sharedUserDefault()->flush();
		}





		SimpleAudioEngine::sharedEngine()->playEffect("happy.wav");
		CCSize mysize1=CCDirector::sharedDirector()->getWinSize();
		CCSprite* sp = CCSprite::create("guoguan.jpg");
		sp->setScaleY(0.9);
		sp->setScaleX(1.2);
		sp->setScale(0.8);
		sp->setPosition(ccp(mysize1.width/2, mysize1.height/2));
		this->addChild(sp, 1);
		CCSprite* sp2 = CCSprite::create("guoguan_z.png");
		sp2->setPosition(ccp(mysize1.width+300,mysize1.height/2+105));
		sp2->setScale(0.75);
		sp2->setRotation(14);
		this->addChild(sp2, 2);

CCActionInterval *ac=CCMoveTo::create(0.5f,ccp(mysize1.width/2+190, mysize1.height/2+105));
sp2->runAction(ac);

		CCSize size = CCDirector::sharedDirector()->getWinSize();
		CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
			"xyg1.png",
			"xyg2.png",
			this,
			menu_selector(guoguan::changescene));
		pCloseItem->setPosition(ccp(size.width+90, size.height/2-20));
		CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
		pMenu->setPosition(CCPointZero);
		this->addChild(pMenu, 1000,12);

		CCActionInterval *ac1=CCMoveTo::create(0.5f,ccp(mysize1.width/2+180, mysize1.height/2-20));
		pCloseItem->runAction(ac1);

		

		
		CCMenuItemImage *pCloseItem2 = CCMenuItemImage::create(
			"zcd1.png",
			"zcd2.png",
			this,
			menu_selector(guoguan::remenu));
		pCloseItem2->setPosition(ccp(size.width+90, size.height/2-120));
		CCMenu* pMenu2 = CCMenu::create(pCloseItem2, NULL);
		pMenu2->setPosition(CCPointZero);
		this->addChild(pMenu2, 1000,12);

		CCActionInterval *ac2=CCMoveTo::create(0.5f,ccp(mysize1.width/2+180, mysize1.height/2-120));
		pCloseItem2->runAction(ac2);

		bRet = true;
	} while (0);

	return bRet;
}

void guoguan::remenu(CCObject* pSender)
{
	CCDirector::sharedDirector()->resume();
	CCScene * scene2=menu::scene();
	CCDirector::sharedDirector()->replaceScene(scene2);
}

void guoguan::changescene(CCObject* pSender){

	int now=CCUserDefault::sharedUserDefault()->getIntegerForKey("scene_num");//当前玩的关卡
	now++;
	SimpleAudioEngine::sharedEngine()->playEffect("zanting.wav");
	
	if(now==2)
	{
		CCDirector::sharedDirector()->resume();
		CCScene * scene2=a2::scene();
		CCDirector::sharedDirector()->replaceScene(scene2);
	}
	if(now==3)
	{
		CCDirector::sharedDirector()->resume();
		CCScene * scene2=a3::scene();
		CCDirector::sharedDirector()->replaceScene(scene2);
	}
	if(now==4)
	{
		CCDirector::sharedDirector()->resume();
		CCScene * scene2=a4::scene();
		CCDirector::sharedDirector()->replaceScene(scene2);
	}
	if(now==5)
	{
		CCDirector::sharedDirector()->resume();
		CCScene * scene2=a5::scene();
		CCDirector::sharedDirector()->replaceScene(scene2);
	}
	if(now==6)
	{
		CCDirector::sharedDirector()->resume();
		CCScene * scene2=a6::scene();
		CCDirector::sharedDirector()->replaceScene(scene2);
	}
	if(now==7)
	{
		CCDirector::sharedDirector()->resume();
		CCScene * scene2=b1::scene();
		CCDirector::sharedDirector()->replaceScene(scene2);
	}
	if(now==12)
	{
		CCDirector::sharedDirector()->resume();
		CCScene * scene2=b2::scene();
		CCDirector::sharedDirector()->replaceScene(scene2);
	}
	if(now==13)
	{
		CCDirector::sharedDirector()->resume();
		CCScene * scene2=b3::scene();
		CCDirector::sharedDirector()->replaceScene(scene2);
	}
	if(now==14)
	{
		CCDirector::sharedDirector()->resume();
		CCScene * scene2=b4::scene();
		CCDirector::sharedDirector()->replaceScene(scene2);
	}
	if(now==15)
	{
		CCDirector::sharedDirector()->resume();
		CCScene * scene2=b5::scene();
		CCDirector::sharedDirector()->replaceScene(scene2);
	}
	if(now==16)
	{
		CCDirector::sharedDirector()->resume();
		CCScene * scene2=b6::scene();
		CCDirector::sharedDirector()->replaceScene(scene2);
	}
	if(now==17)
	{
		CCDirector::sharedDirector()->resume();
		CCScene * scene2=c1::scene();
		CCDirector::sharedDirector()->replaceScene(scene2);
	}
	if(now==22)
	{
		CCDirector::sharedDirector()->resume();
		CCScene * scene2=c2::scene();
		CCDirector::sharedDirector()->replaceScene(scene2);
	}
	if(now==23)
	{
		CCDirector::sharedDirector()->resume();
		CCScene * scene2=c3::scene();
		CCDirector::sharedDirector()->replaceScene(scene2);
	}
	if(now==24)
	{
		CCDirector::sharedDirector()->resume();
		CCScene * scene2=c4::scene();
		CCDirector::sharedDirector()->replaceScene(scene2);
	}
	if(now==25)
	{
		CCDirector::sharedDirector()->resume();
		CCScene * scene2=c5::scene();
		CCDirector::sharedDirector()->replaceScene(scene2);
	}
	if(now==26)
	{
		CCDirector::sharedDirector()->resume();
		CCScene * scene2=c6::scene();
		CCDirector::sharedDirector()->replaceScene(scene2);
	}
	if(now==27)
	{
		CCDirector::sharedDirector()->resume();
		CCScene * scene2=last::scene();
		CCDirector::sharedDirector()->replaceScene(scene2);
	}
}

/*
void guoguan::changescene(CCObject* pSender){

	int now=CCUserDefault::sharedUserDefault()->getIntegerForKey("scene_num");//当前玩的关卡
	now++;
	SimpleAudioEngine::sharedEngine()->playEffect("zanting.wav");
	
	if(now==1)
	{

	}
}*/


void guoguan::onEnter(){
	CCLayer::onEnter();
}

void guoguan::onEnterTransitionDidFinish(){
	CCLayer::onEnterTransitionDidFinish();
}

void guoguan::onExit(){
	CCLayer::onExit();
}

void guoguan::menuCloseCallback(CCObject* pSender)
{
	CCDirector::sharedDirector()->end();
}

