#define HelloWorld a4
#include "HelloWorldScene.h"
#include "cocos-ext.h"
#include "SimpleAudioEngine.h"
#include "GLES-Render.h"
#include<string>
#include <list>
#include<algorithm>
#include"gameover.h"
#include"guoguan.h"
#include"menu.h"
USING_NS_CC;
USING_NS_CC_EXT;
using namespace cocos2d;
using namespace CocosDenshion;
#define PTM_RATIO 32
CCScene* HelloWorld::scene()
{
    CCScene *scene = CCScene::create();
    HelloWorld *layer = HelloWorld::create();
    scene->addChild(layer);
    return scene;
}

void HelloWorld::setthings_num()
{
	mk_num=4;
	zt_num=0;
	th_num=2;
	tx_num=0;
	js_num=0;
	ls_num=0;
	tps_num=0;
	tpx_num=0;
}

bool HelloWorld::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }

	///////////////////////////////////////////////
	
	CCUserDefault::sharedUserDefault()->setIntegerForKey("scene_num",4);
	CCUserDefault::sharedUserDefault()->flush();

	//////////////////////////////////////////////
	updateok=2;//jsbegin=0;
	time=1;
	creatls=0;fd=0;begin_back=1;had_js=0;had_th=0;attack_time=0;attack_ok=0;
	enemy1_num=0;
	removedtag.clear();
	fire_num=0;
	star_num=0,gain_num=0;
#define MUSIC_FILE "backmusic.mp3"
	    SimpleAudioEngine::sharedEngine()->preloadEffect("zhangshen.wav");
	    SimpleAudioEngine::sharedEngine()->preloadEffect("dead.wav");
		SimpleAudioEngine::sharedEngine()->preloadEffect("gain.wav");
		SimpleAudioEngine::sharedEngine()->preloadEffect("pengzhuang.wav");
		SimpleAudioEngine::sharedEngine()->preloadEffect("bomb.wav");
		SimpleAudioEngine::sharedEngine()->preloadEffect("jian.wav");
		SimpleAudioEngine::sharedEngine()->preloadEffect("jian1.wav");
		SimpleAudioEngine::sharedEngine()->preloadEffect("jump.wav");
		SimpleAudioEngine::sharedEngine()->preloadEffect("zanting.wav");
		SimpleAudioEngine::sharedEngine()->preloadEffect("button.WAV");
		SimpleAudioEngine::sharedEngine()->preloadEffect("luoxia.wav");
		SimpleAudioEngine::sharedEngine()->preloadEffect("dianji.wav");
		SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic(MUSIC_FILE);
		SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(0.6);
		SimpleAudioEngine::sharedEngine()->playBackgroundMusic(MUSIC_FILE,true);
	////////////////
	CCSize size = CCDirector::sharedDirector()->getWinSize();


	//////////////////////////////////////////////////////////////////////
	
	/*CCMenuItemImage *pCloseItemz = CCMenuItemImage::create(
		"zanting.png",
		"zanting.png",
		this,
		menu_selector(HelloWorld::zanting));
	pCloseItemz->setPosition(ccp(size.width/2 -40, size.height/2-40));
	CCMenu* pMenuz = CCMenu::create(pCloseItemz, NULL);
	pMenuz->setPosition(CCPointZero);
	this->addChild(pMenuz, 1,11);*/

	CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
		"start.png",
		"start.png",
		this,
		menu_selector(HelloWorld::menuCloseCallback));
	pCloseItem->setPosition(ccp(62 ,440));
	pCloseItem->setScaleX(1.4);
	pCloseItem->setScaleY(1.1);
	CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
	pMenu->setPosition(CCPointZero);
	this->addChild(pMenu, 1500,10);


	CCMenuItemImage *pCloseItem1 = CCMenuItemImage::create(
		"mubanganniu.png",
		"mt2.png",
		this,
		menu_selector(HelloWorld::setcase1));
	pCloseItem1->setPosition(ccp(160 ,450));
	CCMenu* pMenu1 = CCMenu::create(pCloseItem1, NULL);
	pMenu1->setPosition(CCPointZero);
	this->addChild(pMenu1, 2,321);
	
	CCMenuItemImage *pCloseItem2 = CCMenuItemImage::create(
		"zhuangtouanniu.png",
		"zk2.png",
		this,
		menu_selector(HelloWorld::setcase2));
	pCloseItem2->setPosition(ccp(220 , 450));
	CCMenu* pMenu2 = CCMenu::create(pCloseItem2, NULL);
	pMenu2->setPosition(CCPointZero);
	this->addChild(pMenu2, 3,322);

	CCMenuItemImage *pCloseItem3 = CCMenuItemImage::create(
		"tanhuanganniu.png",
		"th2.png",
		this,
		menu_selector(HelloWorld::setcase3));
	pCloseItem3->setPosition(ccp(280 , 450));
	CCMenu* pMenu3 = CCMenu::create(pCloseItem3, NULL);
	pMenu3->setPosition(CCPointZero);
	this->addChild(pMenu3, 3,323);
	
	CCMenuItemImage *pCloseItem4 = CCMenuItemImage::create(
		"tiexianganniu.png",
		"mx2.png",
		this,
		menu_selector(HelloWorld::setcase4));
	pCloseItem4->setPosition(ccp(340 , 450));
	CCMenu* pMenu4 = CCMenu::create(pCloseItem4, NULL);
	pMenu4->setPosition(CCPointZero);
	this->addChild(pMenu4, 3,324);

	CCMenuItemImage *pCloseItem5 = CCMenuItemImage::create(
		"speedanniu.png",
		"tq2.png",
		this,
		menu_selector(HelloWorld::setcase5));
	pCloseItem5->setPosition(ccp(400 , 450));
	CCMenu* pMenu5 = CCMenu::create(pCloseItem5, NULL);
	pMenu5->setPosition(CCPointZero);
	this->addChild(pMenu5, 3,325);

	CCMenuItemImage *pCloseItem6 = CCMenuItemImage::create(
		"lsanniu.png",
		"ls2.png",
		this,
		menu_selector(HelloWorld::setcase6));
	pCloseItem6->setPosition(ccp(460 , 450));
	CCMenu* pMenu6 = CCMenu::create(pCloseItem6, NULL);
	pMenu6->setPosition(CCPointZero);
	this->addChild(pMenu6, 3,326);

	CCMenuItemImage *pCloseItem7 = CCMenuItemImage::create(
		"youshangpoanniu.png",
		"xsp2.png",
		this,
		menu_selector(HelloWorld::setcase7));
	pCloseItem7->setPosition(ccp(520 , 450));
	CCMenu* pMenu7 = CCMenu::create(pCloseItem7, NULL);
	pMenu7->setPosition(CCPointZero);
	this->addChild(pMenu7, 3,327);

	CCMenuItemImage *pCloseItem8 = CCMenuItemImage::create(
		"youxiapoanniu.png",
		"xxp2.png",
		this,
		menu_selector(HelloWorld::setcase8));
	pCloseItem8->setPosition(ccp(580 , 450));
	CCMenu* pMenu8 = CCMenu::create(pCloseItem8, NULL);
	pMenu8->setPosition(CCPointZero);
	this->addChild(pMenu8, 3,328);


	CCSprite* pSpritey1 = CCSprite::create("y.png");
	pSpritey1->setPosition(ccp(-21, size.height/2 ));

	this->addChild(pSpritey1, 1);

	CCSprite* pSpritey11 = CCSprite::create("y.png");
	pSpritey11->setPosition(ccp(-12, size.height/2 ));

	this->addChild(pSpritey11, 1);

	CCSprite* pSpritey2 = CCSprite::create("y.png");
	pSpritey2->setPosition(ccp(size.width+21 , size.height/2 ));

	this->addChild(pSpritey2, 1);

	CCSprite* pSpritey22 = CCSprite::create("y.png");
	pSpritey22->setPosition(ccp(size.width+12 , size.height/2 ));

	this->addChild(pSpritey22, 1);

	CCSprite* pSpritex = CCSprite::create("x.png");
	pSpritex->setPosition(ccp(size.width/2 , size.height+38 ));
	pSpritex->setScale(1.03);
	pSpritex->setScaleY(2.8);
	this->addChild(pSpritex, 1);


	

    CCSprite* pSprite = CCSprite::create("background2.jpg");
    pSprite->setPosition(ccp(size.width/2 , size.height/2 ));

    this->addChild(pSprite, 0);

	CCSprite* pSprite1 = CCSprite::create("qiang.png");
	pSprite1->setPosition(ccp(size.width/2 , size.height/2+100 ));
	pSprite1->setScaleX(2.5);
	pSprite1->setScaleY(2.0);
	this->addChild(pSprite1, -1);
	CCSprite* pSprite2 = CCSprite::create("yun.png");
	pSprite2->setPosition(ccp(size.width/2 , size.height/2+100 ));
	pSprite2->setScale(2.6);
	this->addChild(pSprite2, -2);
	setthings_num();
	/////////////////////////////////////////////////////////////////////////////////////////////////
	b2Vec2 gravity;
	gy=0;
	clickcase=0;
	gravity.Set(0.0f,-14.0f);
	world = new b2World( gravity );//创建世界，gravity可以理解为万有引力，物理中的g

	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0, 0); // bottom-l  eft corner
	// 创建身体
	b2Body* groundBody = world->CreateBody(&groundBodyDef);
	// Define the ground box shape.
	//创建地面形状：在屏幕四周创建了刚体防止物理世界中的刚体超屏
	b2EdgeShape groundBox;
	// top
	groundBox.Set(b2Vec2(0,winSize.height/PTM_RATIO), b2Vec2(winSize.width/PTM_RATIO,winSize.height/PTM_RATIO));
	groundBody->CreateFixture(&groundBox,0);
	
	// bottom
	groundBox.Set(b2Vec2(0,0), b2Vec2(winSize.width/PTM_RATIO,0));
	groundBody->CreateFixture(&groundBox,0);
	
	// left
	groundBox.Set(b2Vec2(0,winSize.height/PTM_RATIO), b2Vec2(0,0));
	groundBody->CreateFixture(&groundBox,0);
	// right
	groundBox.Set(b2Vec2(winSize.width/PTM_RATIO,winSize.height/PTM_RATIO), b2Vec2(winSize.width/PTM_RATIO,0));
	groundBody->CreateFixture(&groundBox,0);

	//////////////////草坪//////////////
	

	CCSprite* caoping = CCSprite::create("caoping.png");
	this->addChild(caoping, 0);
	cocos2d::CCPoint locationcao =ccp(size.width/2,-30);
	this->addNewCaoping( locationcao, caoping );
	///////////////////////////////////////////////////////////////////////


	//////////////////////////////////////////////////////////////////////
	////小球下落部分///////
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("zj.plist");
	//创建1个sprite精灵，使用第一张图
	CCSprite* sprite=CCSprite::createWithSpriteFrameName("kabi1");
	char str[50];
	CCArray * animatearray=CCArray::createWithCapacity(5);
	for(int i=1;i<=5;i++){
		sprintf(str,"kabi%i",i);
		CCSpriteFrame * frame=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(str);
		animatearray->addObject(frame);
	}
	//创建CCAnimation对象
	CCAnimation * ma=CCAnimation::createWithSpriteFrames(animatearray,0.18f);
	ma->setLoops(-1);
	//创建CCAnimate对象
	CCFiniteTimeAction * an=CCAnimate::create(ma);
	an->setTag(53);
	//CCFiniteTimeAction * spw=CCSpawn::create(an,run,NULL);
	sprite->runAction(an);
	sprite->setScale(1.3);

	this->addChild(sprite,10,7);
	cocos2d::CCPoint location =ccp(60,size.height-10);
	this->addNewSpriteWithCoords( location, sprite );
	

	init_num();
	///////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	//初始化布局--------------------------------------------------begin
	/////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////
	
	//addNewenemy(ccp(480,330));
	addNewfire(ccp(60,310));
	addNewfire(ccp(170,160));
	addNewstar(ccp(100,100));
	addNewstar(ccp(580,60));
	addNewfinish(ccp(720,110));
	
	cocos2d::CCTMXTiledMap *_tileMap; 
	_tileMap=CCTMXTiledMap::create("a4.tmx");  
	_tileMap->setPosition(ccp(0,0));
	addChild(_tileMap,1000);
	
	CCTMXLayer* barrierlayer = _tileMap->layerNamed("a");

	
	CCSize s = barrierlayer->getLayerSize();
	for( int x=0; x<s.width;x++)
	{
		for( int y=0; y< s.height; y++ ) 
		{
			CCSprite * q=barrierlayer->tileAt(ccp(x,y));
			if(q!=NULL)
			{
				CCPoint location=q->getPosition();
				addNewtukuai(location,q);
			}
		}
	}
	
	
	//初始化布局--------------------------------------------------end//////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////
	
	this->setTouchEnabled(true);
	this->setAccelerometerEnabled(true);
	this->setKeypadEnabled(true);
	this->scheduleUpdate();//执行update函数
    return true;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void HelloWorld::addNewSpriteWithCoords( CCPoint point, CCSprite *sprite )
{
	sprite->setPosition(point);
	b2BodyDef bodyDef;//定义刚体
	bodyDef.type = b2_dynamicBody;//使刚体能够在力的作用下运行，刚体有三种：静态的、运动的、动态的
	bodyDef.position.Set( point.x/PTM_RATIO, point.y/PTM_RATIO);//设置刚体的初始位置
	bodyDef.userData = sprite;
	bodyDef.angularDamping=0.0f;
	bodyDef.linearDamping=0.0f;
	bodyDef.bullet=true;
	b2Body *body = world->CreateBody( &bodyDef );
	
	//b2PolygonShape dynamicBox;
	//dynamicBox.SetAsBox(.9f,.9f);
	b2CircleShape dynamicBox;
	dynamicBox.m_radius = 15.5f/PTM_RATIO;//设置半径
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;//绑定形状
	fixtureDef.density = 0.2f;//设置密度
	fixtureDef.friction = 0.1f;//设置摩擦，当然还可以设置恢复，即反弹，这里我就不一一赘述
	fixtureDef.restitution=0.3f;
	body->CreateFixture( &fixtureDef );

	//给body施加一个力
	b2Vec2 force = body->GetWorldVector(b2Vec2(00.0f,0.0f));
	b2Vec2 point_force = body->GetWorldPoint( b2Vec2(0.4f,0.4f) );
	body->ApplyForce(force,point_force);
}
void HelloWorld::addNewmk( cocos2d::CCPoint point, cocos2d::CCSprite *sprite )
{
	sprite->setPosition(point);
	b2BodyDef bodyDef;//定义刚体
	bodyDef.type = b2_dynamicBody;//使刚体能够在力的作用下运行，刚体有三种：静态的、运动的、动态的
	bodyDef.position.Set( point.x/PTM_RATIO, point.y/PTM_RATIO);//设置刚体的初始位置
	bodyDef.userData = sprite;
	b2Body *body = world->CreateBody( &bodyDef );
	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(2.6f,0.1f);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;//绑定形状
	fixtureDef.density = 2.0f;//设置密度
	fixtureDef.friction = 0.8f;//设置摩擦，当然还可以设置恢复，即反弹，这里我就不一一赘述
	body->CreateFixture( &fixtureDef );

	//给body施加一个力
	b2Vec2 force = body->GetWorldVector(b2Vec2(00.0f,0.0f));
	b2Vec2 point_force = body->GetWorldPoint( b2Vec2(0.4f,0.4f) );
	body->ApplyForce(force,point_force);
}
void HelloWorld::addNewzt( cocos2d::CCPoint point, cocos2d::CCSprite *sprite )
{
	sprite->setPosition(point);
	b2BodyDef bodyDef;//定义刚体
	bodyDef.type = b2_dynamicBody;//使刚体能够在力的作用下运行，刚体有三种：静态的、运动的、动态的
	bodyDef.position.Set( point.x/PTM_RATIO, point.y/PTM_RATIO);//设置刚体的初始位置
	bodyDef.userData = sprite;
	b2Body *body = world->CreateBody( &bodyDef );
	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(0.49f,0.38f);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;//绑定形状
	fixtureDef.density = 2.5f;//设置密度
	fixtureDef.friction = 0.2f;//设置摩擦，当然还可以设置恢复，即反弹，这里我就不一一赘述
	body->CreateFixture( &fixtureDef );

	//给body施加一个力
	b2Vec2 force = body->GetWorldVector(b2Vec2(00.0f,0.0f));
	b2Vec2 point_force = body->GetWorldPoint( b2Vec2(0.4f,0.4f) );
	body->ApplyForce(force,point_force);
}
void HelloWorld::addNewth( cocos2d::CCPoint point, cocos2d::CCSprite *sprite )
{
	had_th++;
	sprite->setPosition(point);
	b2BodyDef bodyDef;//定义刚体
	bodyDef.type = b2_staticBody;//使刚体能够在力的作用下运行，刚体有三种：静态的、运动的、动态的
	bodyDef.position.Set( point.x/PTM_RATIO, point.y/PTM_RATIO);//设置刚体的初始位置
	bodyDef.userData = sprite;
	b2Body *body = world->CreateBody( &bodyDef );
	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(0.8f,0.01f);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;//绑定形状
	fixtureDef.density = 8.0f;//设置密度
	fixtureDef.friction = 0.2f;//设置摩擦，当然还可以设置恢复，即反弹，这里我就不一一赘述
	fixtureDef.restitution=1.5f;
	body->CreateFixture( &fixtureDef );

	//给body施加一个力
	b2Vec2 force = body->GetWorldVector(b2Vec2(00.0f,0.0f));
	b2Vec2 point_force = body->GetWorldPoint( b2Vec2(0.4f,0.4f) );
	body->ApplyForce(force,point_force);
}
void HelloWorld::addNewtx( cocos2d::CCPoint point, cocos2d::CCSprite *sprite )
{
	sprite->setPosition(point);
	b2BodyDef bodyDef;//定义刚体
	bodyDef.type = b2_dynamicBody;//使刚体能够在力的作用下运行，刚体有三种：静态的、运动的、动态的
	bodyDef.position.Set( point.x/PTM_RATIO, point.y/PTM_RATIO);//设置刚体的初始位置
	bodyDef.userData = sprite;
	b2Body *body = world->CreateBody( &bodyDef );
	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(2.0f,1.95f);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;//绑定形状
	fixtureDef.density = 28.0f;//设置密度
	fixtureDef.friction = 0.8f;//设置摩擦，当然还可以设置恢复，即反弹，这里我就不一一赘述
	body->CreateFixture( &fixtureDef );
	//给body施加一个力
	b2Vec2 force = body->GetWorldVector(b2Vec2(00.0f,0.0f));
	b2Vec2 point_force = body->GetWorldPoint( b2Vec2(0.4f,0.4f) );
	body->ApplyForce(force,point_force);
}

void HelloWorld::addNewjs( cocos2d::CCPoint point, cocos2d::CCSprite *sprite )
{
	had_js++;
	sprite->setPosition(point);
	b2BodyDef bodyDef;//定义刚体
	bodyDef.type = b2_staticBody;//使刚体能够在力的作用下运行，刚体有三种：静态的、运动的、动态的
	bodyDef.position.Set( point.x/PTM_RATIO, point.y/PTM_RATIO);//设置刚体的初始位置
	bodyDef.userData = sprite;
	b2Body *body = world->CreateBody( &bodyDef );

	//b2PolygonShape dynamicBox;
	//dynamicBox.SetAsBox(.9f,.9f);
	b2CircleShape dynamicBox;
	dynamicBox.m_radius = 25.5f/PTM_RATIO;//设置半径
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;//绑定形状
	fixtureDef.density = 0.1f;//设置密度
	fixtureDef.friction = 0.1f;//设置摩擦，当然还可以设置恢复，即反弹，这里我就不一一赘述
	fixtureDef.restitution=3.0f;
	body->CreateFixture( &fixtureDef );

	//给body施加一个力
	b2Vec2 force = body->GetWorldVector(b2Vec2(00.0f,0.0f));
	b2Vec2 point_force = body->GetWorldPoint( b2Vec2(0.4f,0.4f) );
	body->ApplyForce(force,point_force);
}

void HelloWorld::addNewls( cocos2d::CCPoint point, cocos2d::CCSprite *sprite )
{
	sprite->setPosition(point);
	b2BodyDef bodyDef;//定义刚体
	bodyDef.type = b2_dynamicBody;//使刚体能够在力的作用下运行，刚体有三种：静态的、运动的、动态的
	bodyDef.position.Set( point.x/PTM_RATIO, point.y/PTM_RATIO);//设置刚体的初始位置
	bodyDef.userData = sprite;
	b2Body *body = world->CreateBody( &bodyDef );
	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(0.6f,0.6f);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;//绑定形状
	fixtureDef.density = 18.0f;//设置密度
	fixtureDef.friction = 0.8f;//设置摩擦，当然还可以设置恢复，即反弹，这里我就不一一赘述
	body->CreateFixture( &fixtureDef );
	//给body施加一个力
	
	b2Vec2 force = body->GetWorldVector(b2Vec2(00.0f,0.0f));
	b2Vec2 point_force = body->GetWorldPoint( b2Vec2(0.4f,0.4f) );
	body->ApplyForce(force,point_force);
}





void HelloWorld::addNewtukuai( cocos2d::CCPoint point, cocos2d::CCSprite *sprite )
{
	sprite->setPosition(point);
	b2BodyDef bodyDef;//定义刚体
	bodyDef.type = b2_staticBody;//使刚体能够在力的作用下运行，刚体有三种：静态的、运动的、动态的
	bodyDef.position.Set( point.x/PTM_RATIO, point.y/PTM_RATIO);//设置刚体的初始位置
	bodyDef.userData = sprite;
	b2Body *body = world->CreateBody( &bodyDef );
	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(0.1f,0.1f);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;//绑定形状
	fixtureDef.density = 18.0f;//设置密度
	fixtureDef.friction = 0.5f;//设置摩擦，当然还可以设置恢复，即反弹，这里我就不一一赘述
	body->CreateFixture( &fixtureDef );
	//给body施加一个力

	b2Vec2 force = body->GetWorldVector(b2Vec2(00.0f,0.0f));
	b2Vec2 point_force = body->GetWorldPoint( b2Vec2(0.4f,0.4f) );
	body->ApplyForce(force,point_force);
}







///////////////////////////////
bool HelloWorld::isbong(CCPoint p1,float r1,CCPoint p2,float r2){
	//用三角型定理来计算圆心距,然后与半径和对比
	if(sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2))>r1+r2){
		return false;
	}else{
		return true;
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void HelloWorld::update( float dt )//注意，之前2dx的版本是用ccTime的，在2.0.3版本中，用float类型
{
	CCSize size1 = CCDirector::sharedDirector()->getVisibleSize();
	if(star_num)
	{
CCSprite * sp1=(CCSprite *)this->getChildByTag(888);
	CCSprite * sp2=(CCSprite *)this->getChildByTag(7);
	//圆形碰撞
	if(this->isbong(sp1->getPosition(),15,sp2->getPosition(),15))
	{
		if(gain_num!=star_num)
		{
			CCUserDefault::sharedUserDefault()->setIntegerForKey("over_case",2);
			CCUserDefault::sharedUserDefault()->flush();
             gameover();
		}
		
		else
		{
			victory();
		}
	}
	}
	


	if(fire_num)
	{
		for(int i=0;i<fire_num;i++)
		{
			CCSprite * sp1=(CCSprite *)this->getChildByTag(211+i);
			CCSprite * sp2=(CCSprite *)this->getChildByTag(7);
			//圆形碰撞
			if(this->isbong(sp1->getPosition(),15,sp2->getPosition(),20))
			{
				CCUserDefault::sharedUserDefault()->setIntegerForKey("over_case",1);
				CCUserDefault::sharedUserDefault()->flush();
				gameover();
			}
		}

	}

	for(int i=0;i<star_num;i++)
	{
		if(removedtag.count(221+i))continue;
		CCSprite * sp1=(CCSprite *)this->getChildByTag(221+i);
		CCSprite * sp2=(CCSprite *)this->getChildByTag(7);
		//圆形碰撞
		if(this->isbong(sp1->getPosition(),25,sp2->getPosition(),20))
		{
			SimpleAudioEngine::sharedEngine()->playEffect("gain.wav");
			gain_num++;
			removeChildByTag(221+i);
			removedtag.insert(221+i);
		}
	}

	if(attack_ok)
	{
		attack_time++;
		for(int i=0;i<enemy1_num;i++)
		{
			if(removedtag.count(61+i))continue;
          CCSprite * sp1=(CCSprite *)this->getChildByTag(61+i);
		  CCSprite * sp2=(CCSprite *)this->getChildByTag(7);
		  //圆形碰撞
		  if(this->isbong(sp1->getPosition(),20,sp2->getPosition(),40))
		   {
			   SimpleAudioEngine::sharedEngine()->playEffect("bomb.wav");
			   removeChildByTag(61+i);
			   removedtag.insert(61+i);
		   }
		}
		
	}
	else
	{

		for(int i=0;i<enemy1_num;i++)
		{
			if(removedtag.count(61+i))continue;
			CCSprite * sp1=(CCSprite *)this->getChildByTag(61+i);
			CCSprite * sp2=(CCSprite *)this->getChildByTag(7);
			//圆形碰撞
			if(this->isbong(sp1->getPosition(),12,sp2->getPosition(),17))
			{
				CCUserDefault::sharedUserDefault()->setIntegerForKey("over_case",1);
				CCUserDefault::sharedUserDefault()->flush();
				gameover();
			}
		}

	}
	if(attack_time==55)
	{
		attack_ok=0;attack_time=0;
		CCSprite* sprite=(CCSprite*)getChildByTag(7);
		sprite->stopActionByTag(54);
		CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("zj.plist");

		char str[50];
		CCArray * animatearray=CCArray::createWithCapacity(8);
		for(int i=1;i<=5;i++){
			sprintf(str,"kabi%i",i);
			CCSpriteFrame * frame=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(str);
			animatearray->addObject(frame);
		}
		//创建CCAnimation对象
		CCAnimation * ma=CCAnimation::createWithSpriteFrames(animatearray,0.18f);
		ma->setLoops(-1);
		//创建CCAnimate对象
		CCFiniteTimeAction * an=CCAnimate::create(ma);
		//CCFiniteTimeAction * spw=CCSpawn::create(an,run,NULL);
		an->setTag(53);
		sprite->runAction(an);
		sprite->setScale(1.3);
	}
	if(had_js)
	{
		for(int i=0;i<had_js;i++)
		{
			CCSprite * sp1=(CCSprite *)this->getChildByTag(31+i);
			CCSprite * sp2=(CCSprite *)this->getChildByTag(7);
			//圆形碰撞
			if(this->isbong(sp1->getPosition(),20,sp2->getPosition(),30))
			{
				SimpleAudioEngine::sharedEngine()->playEffect("pengzhuang.wav");
			}
		}

	}
	if(had_th)
	{
		for(int i=0;i<had_th;i++)
		{
			CCSprite * sp1=(CCSprite *)this->getChildByTag(41+i);
			CCSprite * sp2=(CCSprite *)this->getChildByTag(7);
			//圆形碰撞
			if(this->isbong(sp1->getPosition(),20,sp2->getPosition(),30))
			{
				SimpleAudioEngine::sharedEngine()->playEffect("pengzhuang.wav");
			}
		}

	}

	
	
	
	/*
	CCSprite *sp =(CCSprite *)getChildByTag(7);
	CCPoint p=sp->getPosition();
	CCMenuItemImage *z=(CCMenuItemImage *)getChildByTag(11);
	
	z->setPosition(size1.width-40,size1.height-40);*/

	
	
	//////////////////
	if(gy!=0&&time<106)
	{
    time+=1;
	if(time==105)
	for(int i=0;i<creatls;i++)
	{
		CCSprite *sprite = CCSprite::create("ls.png");
		cocos2d::CCPoint q;
		q.x=ls_x[i];
		q.y=size1.height;
		this->addChild(sprite);

		this->addNewls(q, sprite );
	}
	
	}
	
	if(updateok&&gy==0)
	{
		
		this->removeChild(la_mk);
		this->removeChild(la_zt);
		this->removeChild(la_th);
		this->removeChild(la_tx);
		this->removeChild(la_js);
		this->removeChild(la_ls);
		this->removeChild(la_tps);
		this->removeChild(la_tpx);
		score1[0]=mk_num+'0';score1[1]=0;
		la_mk = CCLabelAtlas::create(score1, "num.png", 12, 32, 46);
		la_mk->setPosition(ccp(150, 415));  
		addChild(la_mk);  
		score2[0]=zt_num+'0';score2[1]=0;
		la_zt = CCLabelAtlas::create(score2, "num.png", 12, 32, 46);
		la_zt->setPosition(ccp(210, 415));  
		addChild(la_zt);  
		score3[0]=th_num+'0';score3[1]=0;
		la_th = CCLabelAtlas::create(score3, "num.png", 12, 32, 46);
		la_th->setPosition(ccp(270, 415));  
		addChild(la_th);  
		score4[0]=tx_num+'0';score4[1]=0;
		la_tx = CCLabelAtlas::create(score4, "num.png", 12, 32, 46);
		la_tx->setPosition(ccp(330, 415));  
		addChild(la_tx);  
		score5[0]=js_num+'0';score5[1]=0;
		la_js = CCLabelAtlas::create(score5, "num.png", 12, 32, 46);
		la_js->setPosition(ccp(390, 415));  
		addChild(la_js);  
		score6[0]=ls_num+'0';score6[1]=0;
		la_ls = CCLabelAtlas::create(score6, "num.png", 12, 32, 46);
		la_ls->setPosition(ccp(450, 415));  
		addChild(la_ls);  
		score7[0]=tps_num+'0';score7[1]=0;
		la_tps = CCLabelAtlas::create(score7, "num.png", 12, 32, 46);
		la_tps->setPosition(ccp(510, 415));  
		addChild(la_tps);  
		score8[0]=tpx_num+'0';score8[1]=0;
		la_tpx= CCLabelAtlas::create(score8, "num.png", 12, 32, 46);
		la_tpx->setPosition(ccp(570, 415));  
		addChild(la_tpx); 
		updateok=0;
		//labelatlas->setScale(2.0f); //放大倍数
	}
	int32 velocityIterations = 8;
	int32 positionIteratoins = 1;
	world->Step( gy, velocityIterations, positionIteratoins);
	for( b2Body *b = world->GetBodyList();b;b = b->GetNext() )
	{
		if(b->GetUserData() != NULL)
		{

		
			CCSprite *myActor = (CCSprite*)b->GetUserData();
				
			myActor->setPosition(ccp((b->GetPosition().x )* PTM_RATIO,b->GetPosition().y * PTM_RATIO));//设置精灵位置
			myActor->setRotation( -1 * CC_RADIANS_TO_DEGREES(b->GetAngle()) );//设置精灵旋转方向
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void HelloWorld::ccTouchesBegan(CCSet *pTouches,CCEvent *pEvent)
{
	if(gy!=0&&attack_time==0)
	{
		SimpleAudioEngine::sharedEngine()->playEffect("jian1.wav");
		SimpleAudioEngine::sharedEngine()->playEffect("jian.wav");
		attack_ok=1;
		CCSprite* sprite=(CCSprite*)getChildByTag(7);
		sprite->stopActionByTag(53);
		CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("attack.plist");

		char str[50];
		CCArray * animatearray=CCArray::createWithCapacity(8);
		for(int i=0;i<8;i++){
			sprintf(str,"a%i",i);
			CCSpriteFrame * frame=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(str);
			animatearray->addObject(frame);
		}
		//创建CCAnimation对象
		CCAnimation * ma=CCAnimation::createWithSpriteFrames(animatearray,0.03f);
		ma->setLoops(-1);
		//创建CCAnimate对象
		CCFiniteTimeAction * an=CCAnimate::create(ma);
		an->setTag(54);
		//CCFiniteTimeAction * spw=CCSpawn::create(an,run,NULL);
		sprite->runAction(an);
		sprite->setScale(1.8);
		//addChild(sprite,10,7);
	}

	CCSize size = CCDirector::sharedDirector()->getWinSize();
	int count = pTouches->count();
	for( CCSetIterator iterTouch = pTouches->begin();iterTouch != pTouches->end();iterTouch++)
	{
		CCTouch *touch = (CCTouch *)*iterTouch;
		cocos2d::CCPoint location = touch->getLocation();


		if(clickcase==1&&mk_num>0&&gy==0)
		{
			CCSprite *sprite =CCSprite::create("mubang.png");
			sprite->setPosition(location);
			this->addChild(sprite,5,310);
		}
		else if(clickcase==2&&zt_num>0&&gy==0)
		{

			CCSprite *sprite = CCSprite::create("zhuangtou.png");
			sprite->setPosition(location);
			this->addChild(sprite,5,311);

		}
		else if(clickcase==3&&th_num>0&&gy==0)
		{

			CCSprite *sprite = CCSprite::create("tanhuang.png");
			sprite->setPosition(location);
			this->addChild(sprite,5,312);

		}
		else if(clickcase==4&&tx_num>0&&gy==0)
		{

			CCSprite *sprite = CCSprite::create("tiexiang.png");
			sprite->setPosition(location);
			this->addChild(sprite,5,313);

		}
		else if(clickcase==5&&js_num>0&&gy==0)
		{

			CCSprite *sprite = CCSprite::create("speed.png");
			sprite->setPosition(location);
			this->addChild(sprite,5,314);
		}
		else if(clickcase==6&&ls_num>0&&gy==0)
		{

			CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("jiantou.plist");
			//创建1个sprite精灵，使用第一张图
			CCSprite* sprite=CCSprite::createWithSpriteFrameName("j0");
			char str[50];
			CCArray * animatearray=CCArray::createWithCapacity(6);
			for(int i=0;i<6;i++){
				sprintf(str,"j%i",i);
				CCSpriteFrame * frame=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(str);
				animatearray->addObject(frame);
			}
			//创建CCAnimation对象
			CCAnimation * ma=CCAnimation::createWithSpriteFrames(animatearray,0.2f);
			ma->setLoops(-1);
			//创建CCAnimate对象
			CCFiniteTimeAction * an=CCAnimate::create(ma);
			//CCFiniteTimeAction * spw=CCSpawn::create(an,run,NULL);
			sprite->runAction(an);
			sprite->setScaleX(0.4);
			sprite->setScaleY(3);
			sprite->setRotation(180);
			sprite->setPosition(location);
			this->addChild(sprite,5,315);
		}
		else if(clickcase==7&&tps_num>0&&gy==0)
		{
			//////////////////////////////////////////////////////////////////////
			////添加右上斜坡///////

			CCSprite *sprite=CCSprite::create("youshangpo.png");
			sprite->setPosition(location);
			this->addChild(sprite,5,316);
			///////////////////////////////////////////////////////////////////////
		}
		else if(clickcase==8&&tpx_num>0&&gy==0)
		{
			//////////////////////////////////////////////////////////////////////
			////添加右上斜坡///////

			CCSprite *sprite=CCSprite::create("youxiapo.png");
			sprite->setPosition(location);
			this->addChild(sprite,5,317);
			///////////////////////////////////////////////////////////////////////
		}
	}
	
}

void HelloWorld::ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent)
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	int count = pTouches->count();
	for( CCSetIterator iterTouch = pTouches->begin();iterTouch != pTouches->end();iterTouch++)
	{
		CCTouch *touch = (CCTouch *)*iterTouch;
		cocos2d::CCPoint location = touch->getLocation();



		if(clickcase==1&&mk_num>0&&gy==0)
		{

			CCSprite *sprite =(CCSprite *)getChildByTag(310);
			sprite->setPosition(location);

		}
		else if(clickcase==2&&zt_num>0&&gy==0)
		{

			CCSprite *sprite =(CCSprite *)getChildByTag(311);
			sprite->setPosition(location);

		}
		else if(clickcase==3&&th_num>0&&gy==0)
		{

			CCSprite *sprite =(CCSprite *)getChildByTag(312);
			sprite->setPosition(location);

		}
		else if(clickcase==4&&tx_num>0&&gy==0)
		{

			CCSprite *sprite =(CCSprite *)getChildByTag(313);
			sprite->setPosition(location);
		}
		else if(clickcase==5&&js_num>0&&gy==0)
		{
			CCSprite *sprite =(CCSprite *)getChildByTag(314);
			sprite->setPosition(location);
		}
		else if(clickcase==6&&ls_num>0&&gy==0)
		{

			CCSprite *sprite =(CCSprite *)getChildByTag(315);
			sprite->setPosition(ccp(location.x,200));
		}
		else if(clickcase==7&&tps_num>0&&gy==0)
		{
			CCSprite *sprite =(CCSprite *)getChildByTag(316);
			sprite->setPosition(location);
		}
		else if(clickcase==8&&tpx_num>0&&gy==0)
		{
			CCSprite *sprite =(CCSprite *)getChildByTag(317);
			sprite->setPosition(location);
		}
		
	}
}

void HelloWorld::ccTouchesEnded( CCSet *pTouches, CCEvent *pEvent)
{
	//world->DestroyBody(front_body);

	/////////////attack//////
	
	if(gy==0)
	SimpleAudioEngine::sharedEngine()->playEffect("dianji.wav");

	updateok=1; 
		CCSize size = CCDirector::sharedDirector()->getWinSize();
	int count = pTouches->count();
	for( CCSetIterator iterTouch = pTouches->begin();iterTouch != pTouches->end();iterTouch++)
	{
		CCTouch *touch = (CCTouch *)*iterTouch;
		cocos2d::CCPoint location = touch->getLocation();
		


		if(clickcase==1&&mk_num>0&&gy==0)
		{
			removeChildByTag(310);
			CCSprite *sprite =CCSprite::create("mubang.png");
			this->addChild(sprite);
			this->addNewmk( location, sprite );
			mk_num--;
		}
		else if(clickcase==2&&zt_num>0&&gy==0)
		{
		    removeChildByTag(311);
			CCSprite *sprite = CCSprite::create("zhuangtou.png");
			this->addChild(sprite);
			this->addNewzt( location, sprite );
			zt_num--;
		}
		else if(clickcase==3&&th_num>0&&gy==0)
		{
	        removeChildByTag(312);
			CCSprite *sprite = CCSprite::create("tanhuang.png");
			this->addChild(sprite,10,41+had_th);
			this->addNewth( location, sprite );
			th_num--;
		}
		else if(clickcase==4&&tx_num>0&&gy==0)
		{
	        removeChildByTag(313);
			CCSprite *sprite = CCSprite::create("tiexiang.png");
			this->addChild(sprite);
			this->addNewtx( location, sprite );
			tx_num--;
		}
		else if(clickcase==5&&js_num>0&&gy==0)
		{
			removeChildByTag(314);
			CCSprite *sprite = CCSprite::create("speed.png");
			this->addChild(sprite,10,31+had_js);
			this->addNewjs( location, sprite );
			js_num--;
		}
		else if(clickcase==6&&ls_num>0&&gy==0)
		{
			removeChildByTag(315);
			CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("jiantou.plist");
			//创建1个sprite精灵，使用第一张图
			CCSprite* sprite=CCSprite::createWithSpriteFrameName("j0");
			char str[50];
			CCArray * animatearray=CCArray::createWithCapacity(6);
			for(int i=0;i<6;i++){
				sprintf(str,"j%i",i);
				CCSpriteFrame * frame=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(str);
				animatearray->addObject(frame);
			}
			//创建CCAnimation对象
			CCAnimation * ma=CCAnimation::createWithSpriteFrames(animatearray,0.2f);
			ma->setLoops(-1);
			//创建CCAnimate对象
			CCFiniteTimeAction * an=CCAnimate::create(ma);
			//CCFiniteTimeAction * spw=CCSpawn::create(an,run,NULL);
			sprite->runAction(an);
			sprite->setScaleX(0.4);
			sprite->setScaleY(3);
			sprite->setRotation(180);
			this->addChild(sprite,100,77);
            sprite->setPosition(ccp(location.x,200));
			ls_x[creatls]=location.x;
			creatls++;
			ls_num--;
		}
		else if(clickcase==7&&tps_num>0&&gy==0)
		{
			//////////////////////////////////////////////////////////////////////
			////添加右上斜坡///////
			removeChildByTag(316);
			CCSprite *sprite=CCSprite::create("youshangpo.png");
			this->addChild(sprite);
			this->youshangpo( location, sprite );
			tps_num--;
			///////////////////////////////////////////////////////////////////////
		}
		else if(clickcase==8&&tpx_num>0&&gy==0)
		{
			//////////////////////////////////////////////////////////////////////
			////添加右上斜坡///////
			removeChildByTag(317);
			CCSprite *sprite=CCSprite::create("youxiapo.png");
			this->addChild(sprite);
			this->youxiapo( location, sprite );
			tpx_num--;
			///////////////////////////////////////////////////////////////////////
		}

	}
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void HelloWorld::menuCloseCallback(CCObject* pSender)
{
	// "close" menu item clicked
	
	fd=1;

	for(int i=321;i<329;i++)
		removeChildByTag(i);


	this->removeChild(la_mk);
	this->removeChild(la_zt);
	this->removeChild(la_th);
	this->removeChild(la_tx);
	this->removeChild(la_js);
	this->removeChild(la_ls);
	this->removeChild(la_tps);
	this->removeChild(la_tpx);


	CCSprite * sprite=(CCSprite *)getChildByTag(7);
	CCFollow * follow = CCFollow::create(sprite,CCRectMake(-200, 0, 1200, 1500));  
	
	CCPoint p=sprite->getPosition();
	this-> runAction(follow); 
   

	gy=1.0f/60.f;
	for(int i=0;i<9;i++)
	removeChildByTag(77);
	
	
	
	SimpleAudioEngine::sharedEngine()->playEffect("luoxia.wav");
	////////////////////////
	this->removeChildByTag(10);
}

void HelloWorld::restart(CCObject* pSender)
{
	SimpleAudioEngine::sharedEngine()->playEffect("zanting.wav");
	CCDirector::sharedDirector()->resume();
	begin_back=1;
	CCScene * scene2=HelloWorld::scene();
	CCDirector::sharedDirector()->replaceScene(scene2);
}

void HelloWorld::continuescene(CCObject* pSender)
{
	SimpleAudioEngine::sharedEngine()->playEffect("zanting.wav");
	CCDirector::sharedDirector()->resume();
	begin_back=1;
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	/*CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
		"zanting.png",
		"zanting.png",
		this,
		menu_selector(HelloWorld::zanting));
	pCloseItem->setPosition(ccp(size.width -40, size.height-40));
	CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
	pMenu->setPosition(CCPointZero);
	this->addChild(pMenu, 1,11);*/
	this->removeChildByTag(12);
	this->removeChildByTag(13);
	this->removeChildByTag(14);
}

void HelloWorld::zanting(CCObject* pSender)
{
	/*SimpleAudioEngine::sharedEngine()->playEffect("zanting.wav");
	CCDirector::sharedDirector()->pause();
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	CCSprite * sp=(CCSprite *)getChildByTag(7);
	CCPoint p=sp->getPosition();
	float32 x,y;
	x=p.x;
	y=p.y;
	y=size.height/2;

	
	
	CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
		"restart.png",
		"restart.png",
		this,
		menu_selector(HelloWorld::restart));
	pCloseItem->setPosition(ccp(x-90,y));
	CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
	pMenu->setPosition(CCPointZero);
	this->addChild(pMenu, 1000,12);
	this->removeChildByTag(11);
	//////
	CCMenuItemImage *pCloseItem1 = CCMenuItemImage::create(
		"continue.png",
		"continue.png",
		this,
		menu_selector(HelloWorld::continuescene));
	pCloseItem1->setPosition(ccp(x+90, y));
	CCMenu* pMenu1 = CCMenu::create(pCloseItem1, NULL);
	pMenu1->setPosition(CCPointZero);
	this->addChild(pMenu1, 1000,13);
	this->removeChildByTag(11);*/
	SimpleAudioEngine::sharedEngine()->playEffect("zanting.wav");
	CCDirector::sharedDirector()->pause();
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
		"restart.png",
		"restart.png",
		this,
		menu_selector(HelloWorld::restart));
	pCloseItem->setPosition(ccp(size.width/2 -130, size.height/2));
	CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
	pMenu->setPosition(CCPointZero);
	this->addChild(pMenu, 1000,12);
	this->removeChildByTag(11);
	//////
	CCMenuItemImage *pCloseItem1 = CCMenuItemImage::create(
		"continue.png",
		"continue.png",
		this,
		menu_selector(HelloWorld::continuescene));
	pCloseItem1->setPosition(ccp(size.width/2 , size.height/2));
	CCMenu* pMenu1 = CCMenu::create(pCloseItem1, NULL);
	pMenu1->setPosition(CCPointZero);
	this->addChild(pMenu1, 1000,13);
	this->removeChildByTag(11);


	CCMenuItemImage *pCloseItem2 = CCMenuItemImage::create(
		"zhuye.png",
		"zhuye.png",
		this,
		menu_selector(HelloWorld::remenu));
	pCloseItem2->setPosition(ccp(size.width/2 +130, size.height/2));
	CCMenu* pMenu2 = CCMenu::create(pCloseItem2, NULL);
	pMenu2->setPosition(CCPointZero);
	this->addChild(pMenu2, 2000,14);
	this->removeChildByTag(11);
}


void HelloWorld::init_num()
{
	score1[0]=mk_num+'0';score1[1]=0;
	la_mk = CCLabelAtlas::create(score1, "num.png", 12, 32, 46);
	la_mk->setPosition(ccp(150, 415));  
	addChild(la_mk);  
	score2[0]=zt_num+'0';score2[1]=0;
	la_zt = CCLabelAtlas::create(score2, "num.png", 12, 32, 46);
	la_zt->setPosition(ccp(210, 415));  
	addChild(la_zt);  
	score3[0]=th_num+'0';score3[1]=0;
	la_th = CCLabelAtlas::create(score3, "num.png", 12, 32, 46);
	la_th->setPosition(ccp(270, 415));  
	addChild(la_th);  
	score4[0]=tx_num+'0';score4[1]=0;
	la_tx = CCLabelAtlas::create(score4, "num.png", 12, 32, 46);
	la_tx->setPosition(ccp(330, 415));  
	addChild(la_tx);  
	score5[0]=js_num+'0';score5[1]=0;
	la_js = CCLabelAtlas::create(score5, "num.png", 12, 32, 46);
	la_js->setPosition(ccp(390, 415));  
	addChild(la_js);  
	score6[0]=ls_num+'0';score6[1]=0;
	la_ls = CCLabelAtlas::create(score6, "num.png", 12, 32, 46);
	la_ls->setPosition(ccp(450, 415));  
	addChild(la_ls);  
	score7[0]=tps_num+'0';score7[1]=0;
	la_tps = CCLabelAtlas::create(score7, "num.png", 12, 32, 46);
	la_tps->setPosition(ccp(510, 415));  
	addChild(la_tps);  
	score8[0]=tpx_num+'0';score8[1]=0;
	la_tpx= CCLabelAtlas::create(score8, "num.png", 12, 32, 46);
	la_tpx->setPosition(ccp(570, 415));  
	addChild(la_tpx); 
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void HelloWorld::setcase1(CCObject* pSender)
{
	clickcase=1;
	SimpleAudioEngine::sharedEngine()->playEffect("button.WAV");
}
void HelloWorld::setcase2(CCObject* pSender)
{
	clickcase=2;
	SimpleAudioEngine::sharedEngine()->playEffect("button.WAV");
}
void HelloWorld::setcase3(CCObject* pSender)
{
	clickcase=3;
	SimpleAudioEngine::sharedEngine()->playEffect("button.WAV");
}
void HelloWorld::setcase4(CCObject* pSender)
{
	clickcase=4;
	SimpleAudioEngine::sharedEngine()->playEffect("button.WAV");
}
void HelloWorld::setcase5(CCObject* pSender)
{
	clickcase=5;
	SimpleAudioEngine::sharedEngine()->playEffect("button.WAV");
}
void HelloWorld::setcase6(CCObject* pSender)
{
	clickcase=6;
	SimpleAudioEngine::sharedEngine()->playEffect("button.WAV");
}
void HelloWorld::setcase7(CCObject* pSender)
{
	clickcase=7;
	SimpleAudioEngine::sharedEngine()->playEffect("button.WAV");
}
void HelloWorld::setcase8(CCObject* pSender)
{
	clickcase=8;
	SimpleAudioEngine::sharedEngine()->playEffect("button.WAV");
}
///////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////
/*void HelloWorld::BeginContact(b2Contact* contact)
{
     	SimpleAudioEngine::sharedEngine()->playEffect("pengzhuang.wav");
}


void HelloWorld::PreSolve(b2Contact* contact, const b2Manifold* oldManifold)
{
	b2WorldManifold worldmaniflod;
	contact->GetWorldManifold(&worldmaniflod);
	contact->SetEnabled(true);
}

void HelloWorld::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse)
{
	SimpleAudioEngine::sharedEngine()->playEffect("pengzhuang.wav");
}*/
///////////////////////////////////////////////////////////////////////
void HelloWorld::addNewyoushang(cocos2d::CCPoint point)
{
	////添加右上斜杆///////

	CCSprite* youshang=CCSprite::create("ys.png");
	this->addChild(youshang);
	this->youshang( point, youshang );

	///////////////////////////////////////////////////////////////////////

	

}
void HelloWorld::addNewyouxia(cocos2d::CCPoint point)
{
	//////////////////////////////////////////////////////////////////////
	////添加右下斜杆///////

	CCSprite* youxia=CCSprite::create("yx.png");
	this->addChild(youxia);
	this->youxia( point, youxia );
}
void HelloWorld::addNewyou(cocos2d::CCPoint point)
{
	////添加右斜杆///////

	CCSprite* you=CCSprite::create("you.png");
	this->addChild(you);
	this->you( point, you );

	///////////////////////////////////////////////////////////////////////

}
void HelloWorld::addNewzuo(cocos2d::CCPoint point)
{
	//////////////////////////////////////////////////////////////////////
	////添加左斜杆///////

	CCSprite* zuo=CCSprite::create("zuo.png");
	this->addChild(zuo);
	this->zuo( point, zuo );
}
void HelloWorld::addNewzhong(cocos2d::CCPoint point)
{
	//////////////////////////////////////////////////////////////////////
	////添加中杆///////

	CCSprite* zhong=CCSprite::create("zhong.png");
	this->addChild(zhong);
	this->zhong( point, zhong );
}
void HelloWorld::addNewshu(cocos2d::CCPoint point)
{
	//////////////////////////////////////////////////////////////////////
	////添加竖杆///////

	CCSprite* shu=CCSprite::create("shu.png");
	this->addChild(shu);
	this->shu( point, shu );
}


void HelloWorld::addNewCaoping( CCPoint point, CCSprite *sprite )
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	sprite->setPosition(point);
	b2BodyDef bodyDef;//定义刚体
	bodyDef.type = b2_staticBody;//使刚体能够在力的作用下运行，刚体有三种：静态的、运动的、动态的
	bodyDef.position.Set( point.x/PTM_RATIO, point.y/PTM_RATIO);//设置刚体的初始位置
	bodyDef.userData = sprite;
	b2Body *body = world->CreateBody( &bodyDef );
	//定义草坪//
	b2Vec2 vertices[4];
	vertices[0].Set(-30.0f,-3.0f);
	vertices[1].Set(30.0f,-3.0f);
	vertices[2].Set(30.0f,1.2f);
	vertices[3].Set(-30.0f,1.2f);
	int32 count=4;
	b2PolygonShape polygon;
	polygon.Set(vertices,count);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &polygon;//绑定形状
	//////////////////////////////
	fixtureDef.density = 15.0f;//设置密度
	fixtureDef.friction = 0.8f;//设置摩擦，当然还可以设置恢复，即反弹，这里我就不一一赘述
	body->CreateFixture( &fixtureDef );

	//给body施加一个力
	b2Vec2 force = body->GetWorldVector(b2Vec2(00.0f,0.0f));
	b2Vec2 point_force = body->GetWorldPoint( b2Vec2(0.4f,0.4f) );
	body->ApplyForce(force,point_force);
}

void HelloWorld::youshang( CCPoint point, CCSprite *sprite )
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	sprite->setPosition(point);
	b2BodyDef bodyDef;//定义刚体
	bodyDef.type = b2_staticBody;//使刚体能够在力的作用下运行，刚体有三种：静态的、运动的、动态的
	bodyDef.position.Set( point.x/PTM_RATIO, point.y/PTM_RATIO);//设置刚体的初始位置
	bodyDef.userData = sprite;
	b2Body *body = world->CreateBody( &bodyDef );
	//定义右上斜体//
	b2Vec2 vertices[4];
	vertices[0].Set(-2.0f,-1.39f);
	vertices[1].Set(-1.99f,-1.4f);
	vertices[2].Set(2.0f,1.39f);
	vertices[3].Set(1.99f,1.4f);
	int32 count=4;
	b2PolygonShape polygon;
	polygon.Set(vertices,count);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &polygon;//绑定形状
	//////////////////////////////
	fixtureDef.density = 0.1f;//设置密度
	fixtureDef.friction = 0.1f;//设置摩擦，当然还可以设置恢复，即反弹，这里我就不一一赘述
	body->CreateFixture( &fixtureDef );

	//给body施加一个力
	b2Vec2 force = body->GetWorldVector(b2Vec2(00.0f,0.0f));
	b2Vec2 point_force = body->GetWorldPoint( b2Vec2(0.4f,0.4f) );
	body->ApplyForce(force,point_force);
}
void HelloWorld::youxia( CCPoint point, CCSprite *sprite )
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	sprite->setPosition(point);
	b2BodyDef bodyDef;//定义刚体
	bodyDef.type = b2_staticBody;//使刚体能够在力的作用下运行，刚体有三种：静态的、运动的、动态的
	bodyDef.position.Set( point.x/PTM_RATIO, point.y/PTM_RATIO);//设置刚体的初始位置
	bodyDef.userData = sprite;
	b2Body *body = world->CreateBody( &bodyDef );
	//定义右下斜体//
	b2Vec2 vertices[4];
	vertices[0].Set(-2.0f,1.39f);
	vertices[1].Set(1.99f,-1.4f);
	vertices[2].Set(2.0f,-1.39f);
	vertices[3].Set(-1.99f,1.4f);
	int32 count=4;
	b2PolygonShape polygon;
	polygon.Set(vertices,count);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &polygon;//绑定形状
	//////////////////////////////
	fixtureDef.density = 0.1f;//设置密度
	fixtureDef.friction = 0.1f;//设置摩擦，当然还可以设置恢复，即反弹，这里我就不一一赘述
	body->CreateFixture( &fixtureDef );

	//给body施加一个力
	b2Vec2 force = body->GetWorldVector(b2Vec2(00.0f,0.0f));
	b2Vec2 point_force = body->GetWorldPoint( b2Vec2(0.4f,0.4f) );
	body->ApplyForce(force,point_force);
}
void HelloWorld::youshangpo( CCPoint point, CCSprite *sprite )
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	sprite->setPosition(point);
	b2BodyDef bodyDef;//定义刚体
	bodyDef.type = b2_dynamicBody;//使刚体能够在力的作用下运行，刚体有三种：静态的、运动的、动态的
	bodyDef.position.Set( point.x/PTM_RATIO, point.y/PTM_RATIO);//设置刚体的初始位置
	bodyDef.userData = sprite;
	b2Body *body = world->CreateBody( &bodyDef );
	//定义右上斜体//
	b2Vec2 vertices[3];
	vertices[0].Set(-3.0f,-1.53f);
	vertices[1].Set(3.0f,-1.53f);
	vertices[2].Set(3.0f,1.2f);
	int32 count=3;
	b2PolygonShape polygon;
	polygon.Set(vertices,count);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &polygon;//绑定形状
	//////////////////////////////
	fixtureDef.density = 15.0f;//设置密度
	fixtureDef.friction = 0.8f;//设置摩擦，当然还可以设置恢复，即反弹，这里我就不一一赘述
	body->CreateFixture( &fixtureDef );

	//给body施加一个力
	b2Vec2 force = body->GetWorldVector(b2Vec2(00.0f,0.0f));
	b2Vec2 point_force = body->GetWorldPoint( b2Vec2(0.4f,0.4f) );
	body->ApplyForce(force,point_force);
}
void HelloWorld::youxiapo( CCPoint point, CCSprite *sprite )
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	sprite->setPosition(point);
	b2BodyDef bodyDef;//定义刚体
	bodyDef.type =b2_dynamicBody;//使刚体能够在力的作用下运行，刚体有三种：静态的、运动的、动态的
	bodyDef.position.Set( point.x/PTM_RATIO, point.y/PTM_RATIO);//设置刚体的初始位置
	bodyDef.userData = sprite;
	b2Body *body = world->CreateBody( &bodyDef );
	//定义右下斜体//
	b2Vec2 vertices[3];
	vertices[0].Set(-3.1f,-1.45f);
	vertices[1].Set(3.0f,-1.45f);
	vertices[2].Set(-3.1f,1.22f);
	int32 count=3;
	b2PolygonShape polygon;
	polygon.Set(vertices,count);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &polygon;//绑定形状
	//////////////////////////////
	fixtureDef.density = 15.0f;//设置密度
	fixtureDef.friction = 0.8f;//设置摩擦，当然还可以设置恢复，即反弹，这里我就不一一赘述
	body->CreateFixture( &fixtureDef );

	//给body施加一个力
	b2Vec2 force = body->GetWorldVector(b2Vec2(00.0f,0.0f));
	b2Vec2 point_force = body->GetWorldPoint( b2Vec2(0.4f,0.4f) );
	body->ApplyForce(force,point_force);
}
void HelloWorld::you( CCPoint point, CCSprite *sprite )
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	sprite->setPosition(point);
	b2BodyDef bodyDef;//定义刚体
	bodyDef.type = b2_staticBody;//使刚体能够在力的作用下运行，刚体有三种：静态的、运动的、动态的
	bodyDef.position.Set( point.x/PTM_RATIO, point.y/PTM_RATIO);//设置刚体的初始位置
	bodyDef.userData = sprite;
	b2Body *body = world->CreateBody( &bodyDef );
	//定义右体//
	b2Vec2 vertices[4];
	vertices[0].Set(-0.99f,0.19f);
	vertices[1].Set(0.99f,-1.01f);
	vertices[2].Set(0.99f,-0.30f);
	vertices[3].Set(-0.99f,0.9f);
	int32 count=4;
	b2PolygonShape polygon;
	polygon.Set(vertices,count);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &polygon;//绑定形状
	//////////////////////////////
	fixtureDef.density = 0.1f;//设置密度
	fixtureDef.friction = 0.1f;//设置摩擦，当然还可以设置恢复，即反弹，这里我就不一一赘述
	body->CreateFixture( &fixtureDef );

	//给body施加一个力
	b2Vec2 force = body->GetWorldVector(b2Vec2(00.0f,0.0f));
	b2Vec2 point_force = body->GetWorldPoint( b2Vec2(0.4f,0.4f) );
	body->ApplyForce(force,point_force);
}
void HelloWorld::zuo( CCPoint point, CCSprite *sprite )
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	sprite->setPosition(point);
	b2BodyDef bodyDef;//定义刚体
	bodyDef.type = b2_staticBody;//使刚体能够在力的作用下运行，刚体有三种：静态的、运动的、动态的
	bodyDef.position.Set( point.x/PTM_RATIO, point.y/PTM_RATIO);//设置刚体的初始位置
	bodyDef.userData = sprite;
	b2Body *body = world->CreateBody( &bodyDef );
	//定义左体//
	b2Vec2 vertices[4];
	vertices[0].Set(-0.99f,-0.30f);
	vertices[1].Set(-0.99f,-1.01f);
	vertices[2].Set(0.99f,0.09f);
	vertices[3].Set(0.99f,0.8f);
	int32 count=4;
	b2PolygonShape polygon;
	polygon.Set(vertices,count);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &polygon;//绑定形状
	//////////////////////////////
	fixtureDef.density = 0.1f;//设置密度
	fixtureDef.friction = 0.1f;//设置摩擦，当然还可以设置恢复，即反弹，这里我就不一一赘述
	body->CreateFixture( &fixtureDef );

	//给body施加一个力
	b2Vec2 force = body->GetWorldVector(b2Vec2(00.0f,0.0f));
	b2Vec2 point_force = body->GetWorldPoint( b2Vec2(0.4f,0.4f) );
	body->ApplyForce(force,point_force);
}
void HelloWorld::zhong( CCPoint point, CCSprite *sprite )
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	sprite->setPosition(point);
	b2BodyDef bodyDef;//定义刚体
	bodyDef.type = b2_staticBody;//使刚体能够在力的作用下运行，刚体有三种：静态的、运动的、动态的
	bodyDef.position.Set( point.x/PTM_RATIO, point.y/PTM_RATIO);//设置刚体的初始位置
	bodyDef.userData = sprite;
	b2Body *body = world->CreateBody( &bodyDef );
	//定义中体//
	b2Vec2 vertices[4];
	vertices[0].Set(-1.5f,-0.3f);
	vertices[1].Set(1.5f,-0.3f);
	vertices[2].Set(1.5f,0.3f);
	vertices[3].Set(-1.5f,0.3f);
	int32 count=4;
	b2PolygonShape polygon;
	polygon.Set(vertices,count);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &polygon;//绑定形状
	//////////////////////////////
	fixtureDef.density = 0.1f;//设置密度
	fixtureDef.friction = 0.1f;//设置摩擦，当然还可以设置恢复，即反弹，这里我就不一一赘述
	body->CreateFixture( &fixtureDef );

	//给body施加一个力
	b2Vec2 force = body->GetWorldVector(b2Vec2(00.0f,0.0f));
	b2Vec2 point_force = body->GetWorldPoint( b2Vec2(0.4f,0.4f) );
	body->ApplyForce(force,point_force);
}
void HelloWorld::shu( CCPoint point, CCSprite *sprite )
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	sprite->setPosition(point);
	b2BodyDef bodyDef;//定义刚体
	bodyDef.type = b2_staticBody;//使刚体能够在力的作用下运行，刚体有三种：静态的、运动的、动态的
	bodyDef.position.Set( point.x/PTM_RATIO, point.y/PTM_RATIO);//设置刚体的初始位置
	bodyDef.userData = sprite;
	b2Body *body = world->CreateBody( &bodyDef );
	//定义中体//
	b2Vec2 vertices[4];
	vertices[0].Set(-0.3f,-1.1f);
	vertices[1].Set(0.3f,-1.1f);
	vertices[2].Set(0.3f,1.1f);
	vertices[3].Set(-0.3f,1.1f);
	int32 count=4;
	b2PolygonShape polygon;
	polygon.Set(vertices,count);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &polygon;//绑定形状
	//////////////////////////////
	fixtureDef.density = 0.1f;//设置密度
	fixtureDef.friction = 0.1f;//设置摩擦，当然还可以设置恢复，即反弹，这里我就不一一赘述
	body->CreateFixture( &fixtureDef );

	//给body施加一个力
	b2Vec2 force = body->GetWorldVector(b2Vec2(00.0f,0.0f));
	b2Vec2 point_force = body->GetWorldPoint( b2Vec2(0.4f,0.4f) );
	body->ApplyForce(force,point_force);
}

void HelloWorld::zanting1()
{
	SimpleAudioEngine::sharedEngine()->playEffect("zanting.wav");
	CCDirector::sharedDirector()->pause();
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
		"restart.png",
		"restart.png",
		this,
		menu_selector(HelloWorld::restart));
	pCloseItem->setPosition(ccp(size.width/2 -130, size.height/2));
	CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
	pMenu->setPosition(CCPointZero);
	this->addChild(pMenu, 1000,12);
	this->removeChildByTag(11);
	//////
	CCMenuItemImage *pCloseItem1 = CCMenuItemImage::create(
		"continue.png",
		"continue.png",
		this,
		menu_selector(HelloWorld::continuescene));
	pCloseItem1->setPosition(ccp(size.width/2 , size.height/2));
	CCMenu* pMenu1 = CCMenu::create(pCloseItem1, NULL);
	pMenu1->setPosition(CCPointZero);
	this->addChild(pMenu1, 1000,13);
	this->removeChildByTag(11);


	CCMenuItemImage *pCloseItem2 = CCMenuItemImage::create(
		"zhuye.png",
		"zhuye.png",
		this,
		menu_selector(HelloWorld::remenu));
	pCloseItem2->setPosition(ccp(size.width/2 +130, size.height/2));
	CCMenu* pMenu2 = CCMenu::create(pCloseItem2, NULL);
	pMenu2->setPosition(CCPointZero);
	this->addChild(pMenu2, 2000,14);
	this->removeChildByTag(11);
}
void HelloWorld::keyBackClicked()
{
	if(begin_back)
	{
		zanting1();
		begin_back=0;
	}
	
}
void HelloWorld::keyMenuClicked()
{
	if(begin_back)
	{
		zanting1();
		begin_back=0;
	}
}
void HelloWorld::addNewenemy(cocos2d::CCPoint point)
{
	enemy1_num++;
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("youling.plist");
	//创建1个sprite精灵，使用第一张图
	CCSprite* sprite=CCSprite::createWithSpriteFrameName("y0");
	char str[50];
	CCArray * animatearray=CCArray::createWithCapacity(4);
	for(int i=0;i<4;i++){
		sprintf(str,"y%i",i);
		CCSpriteFrame * frame=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(str);
		animatearray->addObject(frame);
	}
	//创建CCAnimation对象
	CCAnimation * ma=CCAnimation::createWithSpriteFrames(animatearray,0.23f);
	ma->setLoops(-1);
	//创建CCAnimate对象
	CCFiniteTimeAction * an=CCAnimate::create(ma);
	//CCFiniteTimeAction * spw=CCSpawn::create(an,run,NULL);
	an->setTag(71);
	sprite->runAction(an);
	sprite->setScale(1.5);
	sprite->setPosition(point);
	this->addChild(sprite,10,60+enemy1_num);

}

void HelloWorld::addNewfire(cocos2d::CCPoint point)
{
	fire_num++;
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("huoyan.plist");
	//创建1个sprite精灵，使用第一张图
	CCSprite* sprite=CCSprite::createWithSpriteFrameName("f0");
	char str[50];
	CCArray * animatearray=CCArray::createWithCapacity(5);
	for(int i=0;i<5;i++){
		sprintf(str,"f%i",i);
		CCSpriteFrame * frame=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(str);
		animatearray->addObject(frame);
	}
	//创建CCAnimation对象
	CCAnimation * ma=CCAnimation::createWithSpriteFrames(animatearray,0.15f);
	ma->setLoops(-1);
	//创建CCAnimate对象
	CCFiniteTimeAction * an=CCAnimate::create(ma);
	//CCFiniteTimeAction * spw=CCSpawn::create(an,run,NULL);
	sprite->runAction(an);
	sprite->setScale(1);
	sprite->setPosition(point);
	this->addChild(sprite,10,210+fire_num);

}


void HelloWorld::addNewstar(cocos2d::CCPoint point)
{
	star_num++;
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("star.plist");
	//创建1个sprite精灵，使用第一张图
	CCSprite* sprite=CCSprite::createWithSpriteFrameName("s0");
	char str[50];
	CCArray * animatearray=CCArray::createWithCapacity(8);
	for(int i=0;i<8;i++){
		sprintf(str,"s%i",i);
		CCSpriteFrame * frame=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(str);
		animatearray->addObject(frame);
	}
	//创建CCAnimation对象
	CCAnimation * ma=CCAnimation::createWithSpriteFrames(animatearray,0.18f);
	ma->setLoops(-1);
	//创建CCAnimate对象
	CCFiniteTimeAction * an=CCAnimate::create(ma);
	//CCFiniteTimeAction * spw=CCSpawn::create(an,run,NULL);
	sprite->runAction(an);
	sprite->setScale(1.4);
	sprite->setPosition(point);
	this->addChild(sprite,10,220+star_num);

}


void HelloWorld::addNewfinish(cocos2d::CCPoint point)
{

	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("finish.plist");
	//创建1个sprite精灵，使用第一张图
	CCSprite* sprite=CCSprite::createWithSpriteFrameName("z0");
	char str[50];
	CCArray * animatearray=CCArray::createWithCapacity(4);
	for(int i=0;i<4;i++){
		sprintf(str,"z%i",i);
		CCSpriteFrame * frame=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(str);
		animatearray->addObject(frame);
	}
	//创建CCAnimation对象
	CCAnimation * ma=CCAnimation::createWithSpriteFrames(animatearray,0.15f);
	ma->setLoops(-1);
	//创建CCAnimate对象
	CCFiniteTimeAction * an=CCAnimate::create(ma);
	//CCFiniteTimeAction * spw=CCSpawn::create(an,run,NULL);
	sprite->runAction(an);
	sprite->setScale(0.6);
	sprite->setPosition(point);
	this->addChild(sprite,10,888);

}


void HelloWorld::victory()
{
	SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
	 SimpleAudioEngine::sharedEngine()->playEffect("zhangshen.wav");
	 CCScene * scene2=guoguan::scene();

	 CCDirector::sharedDirector()->replaceScene(scene2);
}



//进入此类中的调用函数
void HelloWorld::onEnter(){
	CCLayer::onEnter();
}

//切换动画完成后调用的函数
void HelloWorld::onEnterTransitionDidFinish(){
	CCLayer::onEnterTransitionDidFinish();
}



void HelloWorld::gameover()
{
	SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
	SimpleAudioEngine::sharedEngine()->playEffect("dead.wav");
	CCScene * scene2=gameover::scene();
	CCDirector::sharedDirector()->replaceScene(scene2);
}

void HelloWorld::remenu(CCObject* psender)
{
	CCDirector::sharedDirector()->resume();
	CCScene * scene2=menu::scene();
	CCDirector::sharedDirector()->replaceScene(scene2);
}
