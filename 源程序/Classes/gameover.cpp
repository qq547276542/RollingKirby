#include "gameover.h"
#include "menu.h"
#include "SimpleAudioEngine.h"
#include "cocos-ext.h"
#include "cocos2d.h"
#include "HelloWorldScene.h"
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
using namespace cocos2d;
using namespace cocos2d::extension;
using namespace CocosDenshion;
CCScene* gameover::scene()
{
    CCScene * scene = NULL;
    do 
    {
        scene = CCScene::create();
        CC_BREAK_IF(! scene);
        gameover *layer = gameover::create();
        CC_BREAK_IF(! layer);
        scene->addChild(layer);
    } while (0);
    return scene;
}

bool gameover::init()
{
    bool bRet = false;
    do 
    {
		
        CC_BREAK_IF(! CCLayer::init());
		///////////////////////////////////////////////////////
		//-new-//
		

		CCSize mysize1=CCDirector::sharedDirector()->getWinSize();
        CCSprite* sp = CCSprite::create("gameover.jpg");
		sp->setScale(1.4);
        sp->setPosition(ccp(mysize1.width/2, mysize1.height/2));
        this->addChild(sp, -1);
		CCSprite* sp2 = CCSprite::create("gameover_z.png");
		sp2->setPosition(ccp(-300,mysize1.height/2+105));
		sp2->setScale(0.75);
		sp2->setRotation(-14);
		this->addChild(sp2,2);
		CCActionInterval *ac=CCMoveTo::create(0.5f,ccp(mysize1.width/2-190, mysize1.height/2+105));
		sp2->runAction(ac);


		CCSize size = CCDirector::sharedDirector()->getWinSize();
		CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
			"zlyc1.png",
			"zlyc2.png",
			this,
			menu_selector(gameover::changescene));
		pCloseItem->setPosition(ccp(size.width+150, size.height/2-20));
		CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
		pMenu->setPosition(CCPointZero);
		this->addChild(pMenu, 1000,12);
		CCActionInterval *q=CCMoveTo::create(0.4f,ccp(size.width/2+240, size.height/2-20));
		pCloseItem->runAction(q);


		CCSize size2 = CCDirector::sharedDirector()->getWinSize();
		CCMenuItemImage *pCloseItem2 = CCMenuItemImage::create(
			"zcd1.png",
			"zcd2.png",
			this,
			menu_selector(gameover::remenu));
		pCloseItem2->setPosition(ccp(size.width+150, size.height/2-120));
		CCMenu* pMenu2 = CCMenu::create(pCloseItem2, NULL);
		pMenu2->setPosition(CCPointZero);
		this->addChild(pMenu2, 1000,12);
		CCActionInterval *qq=CCMoveTo::create(0.4f,ccp(size.width/2+240, size.height/2-120));
		pCloseItem2->runAction(qq);


		int overcase=CCUserDefault::sharedUserDefault()->getIntegerForKey("over_case");
		if(overcase==1)
		{
			CCSprite *p=CCSprite::create("over1.png");
			p->setPosition(ccp(570,380));
			p->setRotation(15);
			p->setScale(1.1);
			addChild(p);
		}
		else if(overcase==2)
		{
			CCSprite *p=CCSprite::create("over2.png");
			p->setPosition(ccp(570,380));
			p->setRotation(15);
			p->setScale(1.1);
			addChild(p);
		}
        bRet = true;
    } while (0);

    return bRet;
}
void gameover::changescene(CCObject* pSender){
	
	int now=CCUserDefault::sharedUserDefault()->getIntegerForKey("scene_num");//当前玩的关卡
	
	SimpleAudioEngine::sharedEngine()->playEffect("zanting.wav");
	if(now==1)
	{
CCDirector::sharedDirector()->resume();
		CCScene * scene2=a1::scene();
		CCDirector::sharedDirector()->replaceScene(scene2);
	}
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
		if(now==11)
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
		if(now==21)
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
}

void gameover::remenu(CCObject* psender)
{
	CCDirector::sharedDirector()->resume();
	CCScene * scene2=menu::scene();
	CCDirector::sharedDirector()->replaceScene(scene2);
}


void gameover::onEnter(){
    CCLayer::onEnter();
}

void gameover::onEnterTransitionDidFinish(){
    CCLayer::onEnterTransitionDidFinish();
}

void gameover::onExit(){
    CCLayer::onExit();
}

void gameover::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();
}

