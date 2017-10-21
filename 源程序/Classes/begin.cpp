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
#include "begin.h"
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
CCScene* begin1::scene()
{
    CCScene *scene = CCScene::create();
    begin1 *layer = begin1::create();
    scene->addChild(layer);
    return scene;
}


bool begin1::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }

	////////////////
	CCSize size = CCDirector::sharedDirector()->getVisibleSize();


	//////////////////////////////////////////////////////////////////////
	CCSprite *bj=CCSprite::create("choose_scene.jpg");
	bj->setPosition(ccp(size.width/2,size.height/2));
	bj->setScaleX(1.02);
	bj->setScaleY(0.9);
	addChild(bj,0);

	CCMenuItemImage *pCloseItem2 = CCMenuItemImage::create(
		"conglin.png",
		"conglin2.png",
		this,
		menu_selector(begin1::casea1));
	pCloseItem2->setPosition(ccp(-120 , size.height-150));
	CCMenu* pMenu2 = CCMenu::create(pCloseItem2, NULL);
	pMenu2->setPosition(CCPointZero);
	this->addChild(pMenu2, 3,1);
	CCActionInterval *p1=CCMoveTo::create(0.6f,ccp(180,size.height-150));
	pCloseItem2->runAction(p1);



	CCMenuItemImage *pCloseItem3 = CCMenuItemImage::create(
		"xuedi.png",
		"xuedi2.png",
		this,
		menu_selector(begin1::casea2));
	pCloseItem3->setPosition(ccp(size.width+120 , size.height-240));
	CCMenu* pMenu3 = CCMenu::create(pCloseItem3, NULL);
	pMenu3->setPosition(CCPointZero);
	this->addChild(pMenu3, 3,2);
	CCActionInterval *p3=CCMoveTo::create(0.6f,ccp(size.width-180,size.height-240));
	pCloseItem3->runAction(p3);


	CCMenuItemImage *pCloseItem4 = CCMenuItemImage::create(
		"zhongli.png",
		"zhongli2.png",
		this,
		menu_selector(begin1::casea3));
	pCloseItem4->setPosition(ccp(-120 , size.height-360));
	CCMenu* pMenu4 = CCMenu::create(pCloseItem4, NULL);
	pMenu4->setPosition(CCPointZero);
	this->addChild(pMenu4, 3,3);
	CCActionInterval *p4=CCMoveTo::create(0.6f,ccp(180,size.height-360));
	pCloseItem4->runAction(p4);
	return true;
}
void begin1::xuanguan(CCObject* pSender)
{
	SimpleAudioEngine::sharedEngine()->playEffect("button.WAV");
	removeAllChildren();


	CCSize size = CCDirector::sharedDirector()->getVisibleSize();


	CCSprite *bj=CCSprite::create("choose_scene.jpg");
	bj->setPosition(ccp(size.width/2,size.height/2));
	bj->setScaleX(1.02);
	bj->setScaleY(0.9);
	addChild(bj,0);

	if(scene_case==1)
	{
		int ok=CCUserDefault::sharedUserDefault()->getIntegerForKey("yes1");
		if(ok==1)
		{
			CCSprite *q=CCSprite::create("yes.png");
			q->setPosition(ccp(size.width/4 , size.height-150));
			q->setScale(0.25);
			addChild(q,20);
		}
		 ok=CCUserDefault::sharedUserDefault()->getIntegerForKey("yes2");
		if(ok==1)
		{
			CCSprite *q=CCSprite::create("yes.png");
			q->setPosition(ccp(size.width*2/4 , size.height-150));
			q->setScale(0.25);
			addChild(q,20);
		}
		ok=CCUserDefault::sharedUserDefault()->getIntegerForKey("yes3");
		if(ok==1)
		{
			CCSprite *q=CCSprite::create("yes.png");
			q->setPosition(ccp(size.width*3/4 , size.height-150));
			q->setScale(0.25);
			addChild(q,20);
		}
		 ok=CCUserDefault::sharedUserDefault()->getIntegerForKey("yes4");
		if(ok==1)
		{
			CCSprite *q=CCSprite::create("yes.png");
			q->setPosition(ccp(size.width/4 , size.height-300));
			q->setScale(0.25);
			addChild(q,20);
		}
		ok=CCUserDefault::sharedUserDefault()->getIntegerForKey("yes5");
		if(ok==1)
		{
			CCSprite *q=CCSprite::create("yes.png");
			q->setPosition(ccp(size.width*2/4 , size.height-300));
			q->setScale(0.25);
			addChild(q,20);
		}
		 ok=CCUserDefault::sharedUserDefault()->getIntegerForKey("yes6");
		if(ok==1)
		{
			CCSprite *q=CCSprite::create("yes.png");
			q->setPosition(ccp(size.width*3/4 , size.height-300));
			q->setScale(0.25);
			addChild(q,20);
		}
	}

	if(scene_case==2)
	{
	     int ok=CCUserDefault::sharedUserDefault()->getIntegerForKey("yes11");
		if(ok==1)
		{
			CCSprite *q=CCSprite::create("yes.png");
			q->setPosition(ccp(size.width/4 , size.height-150));
			q->setScale(0.25);
			addChild(q,20);
		}
		 ok=CCUserDefault::sharedUserDefault()->getIntegerForKey("yes12");
		if(ok==1)
		{
			CCSprite *q=CCSprite::create("yes.png");
			q->setPosition(ccp(size.width*2/4 , size.height-150));
			q->setScale(0.25);
			addChild(q,20);
		}
		 ok=CCUserDefault::sharedUserDefault()->getIntegerForKey("yes13");
		if(ok==1)
		{
			CCSprite *q=CCSprite::create("yes.png");
			q->setPosition(ccp(size.width*3/4 , size.height-150));
			q->setScale(0.25);
			addChild(q,20);
		}
		 ok=CCUserDefault::sharedUserDefault()->getIntegerForKey("yes14");
		if(ok==1)
		{
			CCSprite *q=CCSprite::create("yes.png");
			q->setPosition(ccp(size.width/4 , size.height-300));
			q->setScale(0.25);
			addChild(q,20);
		}
		 ok=CCUserDefault::sharedUserDefault()->getIntegerForKey("yes15");
		if(ok==1)
		{
			CCSprite *q=CCSprite::create("yes.png");
			q->setPosition(ccp(size.width*2/4 , size.height-300));
			q->setScale(0.25);
			addChild(q,20);
		}
		 ok=CCUserDefault::sharedUserDefault()->getIntegerForKey("yes16");
		if(ok==1)
		{
			CCSprite *q=CCSprite::create("yes.png");
			q->setPosition(ccp(size.width*3/4 , size.height-300));
			q->setScale(0.25);
			addChild(q,20);
		}
	}

	if(scene_case==3)
	{
		int ok=CCUserDefault::sharedUserDefault()->getIntegerForKey("yes21");
		if(ok==1)
		{
			CCSprite *q=CCSprite::create("yes.png");
			q->setPosition(ccp(size.width/4 , size.height-150));
			q->setScale(0.25);
			addChild(q,20);
		}
		ok=CCUserDefault::sharedUserDefault()->getIntegerForKey("yes22");
		if(ok==1)
		{
			CCSprite *q=CCSprite::create("yes.png");
			q->setPosition(ccp(size.width*2/4 , size.height-150));
			q->setScale(0.25);
			addChild(q,20);
		}
		ok=CCUserDefault::sharedUserDefault()->getIntegerForKey("yes23");
		if(ok==1)
		{
			CCSprite *q=CCSprite::create("yes.png");
			q->setPosition(ccp(size.width*3/4 , size.height-150));
			q->setScale(0.25);
			addChild(q,20);
		}
		ok=CCUserDefault::sharedUserDefault()->getIntegerForKey("yes24");
		if(ok==1)
		{
			CCSprite *q=CCSprite::create("yes.png");
			q->setPosition(ccp(size.width/4 , size.height-300));
			q->setScale(0.25);
			addChild(q,20);
		}
		ok=CCUserDefault::sharedUserDefault()->getIntegerForKey("yes25");
		if(ok==1)
		{
			CCSprite *q=CCSprite::create("yes.png");
			q->setPosition(ccp(size.width*2/4 , size.height-300));
			q->setScale(0.25);
			addChild(q,20);
		}
		ok=CCUserDefault::sharedUserDefault()->getIntegerForKey("yes26");
		if(ok==1)
		{
			CCSprite *q=CCSprite::create("yes.png");
			q->setPosition(ccp(size.width*3/4 , size.height-300));
			q->setScale(0.25);
			addChild(q,20);
		}
	}




	CCMenuItemImage *pCloseItem1 = CCMenuItemImage::create(
		"xiao1.png",
		"da1.png",
		this,
		menu_selector(begin1::guan1));
	pCloseItem1->setPosition(ccp(size.width/4 , size.height-200));
	CCMenu* pMenu1 = CCMenu::create(pCloseItem1, NULL);
	pMenu1->setPosition(CCPointZero);
	this->addChild(pMenu1, 3,3);

	CCMenuItemImage *pCloseItem2 = CCMenuItemImage::create(
		"xiao2.png",
		"da2.png",
		this,
		menu_selector(begin1::guan2));
	pCloseItem2->setPosition(ccp(size.width*2/4 , size.height-200));
	CCMenu* pMenu2 = CCMenu::create(pCloseItem2, NULL);
	pMenu2->setPosition(CCPointZero);
	this->addChild(pMenu2, 3,3);

	CCMenuItemImage *pCloseItem3 = CCMenuItemImage::create(
		"xiao3.png",
		"da3.png",
		this,
		menu_selector(begin1::guan3));
	pCloseItem3->setPosition(ccp(size.width*3/4 , size.height-200));
	CCMenu* pMenu3 = CCMenu::create(pCloseItem3, NULL);
	pMenu3->setPosition(CCPointZero);
	this->addChild(pMenu3, 3,3);

	CCMenuItemImage *pCloseItem4 = CCMenuItemImage::create(
		"xiao4.png",
		"da4.png",
		this,
		menu_selector(begin1::guan4));
	pCloseItem4->setPosition(ccp(size.width*1/4 , size.height-350));
	CCMenu* pMenu4 = CCMenu::create(pCloseItem4, NULL);
	pMenu4->setPosition(CCPointZero);
	this->addChild(pMenu4, 3,3);

	CCMenuItemImage *pCloseItem5 = CCMenuItemImage::create(
		"xiao5.png",
		"da5.png",
		this,
		menu_selector(begin1::guan5));
	pCloseItem5->setPosition(ccp(size.width*2/4 , size.height-350));
	CCMenu* pMenu5 = CCMenu::create(pCloseItem5, NULL);
	pMenu5->setPosition(CCPointZero);
	this->addChild(pMenu5, 3,3);

	CCMenuItemImage *pCloseItem6 = CCMenuItemImage::create(
		"xiao6.png",
		"da6.png",
		this,
		menu_selector(begin1::guan6));
	pCloseItem6->setPosition(ccp(size.width*3/4 , size.height-350));
	CCMenu* pMenu6 = CCMenu::create(pCloseItem6, NULL);
	pMenu6->setPosition(CCPointZero);
	this->addChild(pMenu6, 3,3);


}



void begin1::casea1(CCObject* pSender)
{
	SimpleAudioEngine::sharedEngine()->playEffect("button.WAV");
	scene_case=1;
	removeAllChildren();
	CCSize size = CCDirector::sharedDirector()->getVisibleSize();
	CCSprite *q=CCSprite::create("jiaoxue1.jpg");
	q->setPosition(ccp(size.width/2,size.height/2-10));
	q->setScaleY(0.9);
	addChild(q,2,13);
	
	
	CCMenuItemImage *pCloseItem10 = CCMenuItemImage::create(
		"renyi.png",
		"renyi.png",
		this,
		menu_selector(begin1::xuanguan));
	pCloseItem10->setPosition(ccp(size.width/2 , size.height/2));
	CCMenu* pMenu10 = CCMenu::create(pCloseItem10, NULL);
	pMenu10->setPosition(CCPointZero);
	this->addChild(pMenu10, 5,3);

}
void begin1::casea2(CCObject* pSender)
{
	SimpleAudioEngine::sharedEngine()->playEffect("button.WAV");
	scene_case=2;
	removeAllChildren();
	CCSize size = CCDirector::sharedDirector()->getVisibleSize();
	
	CCSprite *q=CCSprite::create("jiaoxue2.jpg");
	q->setPosition(ccp(size.width/2,size.height/2-10));
	q->setScaleY(0.9);
	addChild(q,2,13);


	CCMenuItemImage *pCloseItem10 = CCMenuItemImage::create(
		"renyi.png",
		"renyi.png",
		this,
		menu_selector(begin1::xuanguan));
	pCloseItem10->setPosition(ccp(size.width/2 , size.height/2));
	CCMenu* pMenu10 = CCMenu::create(pCloseItem10, NULL);
	pMenu10->setPosition(CCPointZero);
	this->addChild(pMenu10, 5,3);
}

void begin1::casea3(CCObject* pSender)
{
	SimpleAudioEngine::sharedEngine()->playEffect("button.WAV");
	scene_case=3;
	removeAllChildren();
	CCSize size = CCDirector::sharedDirector()->getVisibleSize();
	CCSprite *q=CCSprite::create("jiaoxue3.jpg");
	q->setPosition(ccp(size.width/2,size.height/2-10));
	q->setScaleY(0.9);
	addChild(q,2,13);


	CCMenuItemImage *pCloseItem10 = CCMenuItemImage::create(
		"renyi.png",
		"renyi.png",
		this,
		menu_selector(begin1::xuanguan));
	pCloseItem10->setPosition(ccp(size.width/2 , size.height/2));
	CCMenu* pMenu10 = CCMenu::create(pCloseItem10, NULL);
	pMenu10->setPosition(CCPointZero);
	this->addChild(pMenu10, 5,3);
}

void begin1::guan1(CCObject* pSender)
{
	SimpleAudioEngine::sharedEngine()->playEffect("button.WAV");
	if(scene_case==1)
	{
		CCScene * scene2=a1::scene();

		CCDirector::sharedDirector()->replaceScene(scene2);
	}
	else if(scene_case==2)
	{
		CCScene * scene2=b1::scene();

		CCDirector::sharedDirector()->replaceScene(scene2);
	}
	else if(scene_case==3)
	{
		CCScene * scene2=c1::scene();

		CCDirector::sharedDirector()->replaceScene(scene2);
	}
}


void begin1::guan2(CCObject* pSender)
{
	SimpleAudioEngine::sharedEngine()->playEffect("button.WAV");
	if(scene_case==1)
	{
		CCScene * scene2=a2::scene();

		CCDirector::sharedDirector()->replaceScene(scene2);
	}
	else if(scene_case==2)
	{
		CCScene * scene2=b2::scene();

		CCDirector::sharedDirector()->replaceScene(scene2);
	}
	else if(scene_case==3)
	{
		CCScene * scene2=c2::scene();

		CCDirector::sharedDirector()->replaceScene(scene2);
	}
}


void begin1::guan3(CCObject* pSender)
{
	SimpleAudioEngine::sharedEngine()->playEffect("button.WAV");
	if(scene_case==1)
	{
		CCScene * scene2=a3::scene();

		CCDirector::sharedDirector()->replaceScene(scene2);
	}
	else if(scene_case==2)
	{
		CCScene * scene2=b3::scene();

		CCDirector::sharedDirector()->replaceScene(scene2);
	}
	else if(scene_case==3)
	{
		CCScene * scene2=c3::scene();

		CCDirector::sharedDirector()->replaceScene(scene2);
	}
}


void begin1::guan4(CCObject* pSender)
{
	SimpleAudioEngine::sharedEngine()->playEffect("button.WAV");
	if(scene_case==1)
	{
		CCScene * scene2=a4::scene();

		CCDirector::sharedDirector()->replaceScene(scene2);
	}
	else if(scene_case==2)
	{
		CCScene * scene2=b4::scene();

		CCDirector::sharedDirector()->replaceScene(scene2);
	}
	else if(scene_case==3)
	{
		CCScene * scene2=c4::scene();

		CCDirector::sharedDirector()->replaceScene(scene2);
	}
}


void begin1::guan5(CCObject* pSender)
{
	SimpleAudioEngine::sharedEngine()->playEffect("button.WAV");
	if(scene_case==1)
	{
		CCScene * scene2=a5::scene();

		CCDirector::sharedDirector()->replaceScene(scene2);
	}
	else if(scene_case==2)
	{
		CCScene * scene2=b5::scene();

		CCDirector::sharedDirector()->replaceScene(scene2);
	}
	else if(scene_case==3)
	{
		CCScene * scene2=c5::scene();

		CCDirector::sharedDirector()->replaceScene(scene2);
	}
}


void begin1::guan6(CCObject* pSender)
{
	SimpleAudioEngine::sharedEngine()->playEffect("button.WAV");
	if(scene_case==1)
	{
		CCScene * scene2=a6::scene();

		CCDirector::sharedDirector()->replaceScene(scene2);
	}
	else if(scene_case==2)
	{
		CCScene * scene2=b6::scene();

		CCDirector::sharedDirector()->replaceScene(scene2);
	}
	else if(scene_case==3)
	{
		CCScene * scene2=c6::scene();

		CCDirector::sharedDirector()->replaceScene(scene2);
	}
}





