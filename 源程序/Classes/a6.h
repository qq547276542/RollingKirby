#ifndef __A6_H__
#define __A6_H__


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
class a6 : public cocos2d::CCLayer,public b2ContactListener
{

public:
	virtual bool init();
	static cocos2d::CCScene* scene();
	void menuCloseCallback(CCObject* pSender);  //start按钮触发的事件
	void remenu(CCObject* psender);
	b2World *world;      // 世界
	void update( float dt );//随时触发事件这里的dt就是你运行程序左下角三行数中的第二行数字
		void addNewSpriteWithCoords( cocos2d::CCPoint point, cocos2d::CCSprite *sprite );//添加精灵
		void addNewmk( cocos2d::CCPoint point, cocos2d::CCSprite *sprite );//添加木块
		void addNewzt( cocos2d::CCPoint point, cocos2d::CCSprite *sprite );//添加砖头
		void addNewth( cocos2d::CCPoint point, cocos2d::CCSprite *sprite );//添加弹簧
		void addNewtx( cocos2d::CCPoint point, cocos2d::CCSprite *sprite );//添加铁箱
		void addNewjs( cocos2d::CCPoint point, cocos2d::CCSprite *sprite );//添加加速器 
		void addNewls( cocos2d::CCPoint point, cocos2d::CCSprite *sprite );//添加落石

		virtual void ccTouchesBegan(CCSet *pTouch,CCEvent *pEvent);
		void ccTouchesMoved(CCSet *pTouch, CCEvent *pEvent);
		virtual void ccTouchesEnded( CCSet *pTouches, CCEvent *pEvent);  //鼠标放开事件

		void setthings_num();//设置物体的数量
		int mk_num,zt_num,th_num,tx_num,js_num,ls_num,tps_num,tpx_num;    //物体数量

		int enemy1_num;                                                    //敌人数量
		int fire_num;                                               //火焰数量


		float32 gy;        //控制更新时间步
		int clickcase;     //判断点击屏幕出现的物品
		void setcase1(CCObject* pSender);   //改变clickcase值为1
		void setcase2(CCObject* pSender);   //改变clickcase值为2
		void setcase3(CCObject* pSender);   //.....
		void setcase4(CCObject* pSender);  //.....
		void setcase5(CCObject* pSender);
		void setcase6(CCObject* pSender);
		void setcase7(CCObject* pSender);
	    void setcase8(CCObject* pSender);
		char score1[2],score2[2],score3[2],score4[2],score5[2],score6[2],score7[2],score8[2];   //用字符串存物体数和字体图片关联
		CCLabelAtlas* la_mk,* la_zt,*la_th,*la_tx,*la_js,*la_ls,*la_tps,*la_tpx;     //分数
		int updateok;   
		/*void BeginContact(b2Contact*); 
		void PreSolve(b2Contact* contact, const b2Manifold* oldManifold);
		void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse);*/
		//typedef pair<b2Fixture*,b2Fixture*> MyContact;
		//set<MyContact>  m_contacts;
		void restart(CCObject* pSender);   
		void zanting(CCObject* pSender);
		void continuescene(CCObject* pSender);
	    CREATE_FUNC(HelloWorld);
		bool isbong(CCPoint p1,float r1,CCPoint p2,float r2);
		//int jsbegin;
	    int time;
	void youshang( cocos2d::CCPoint point, cocos2d::CCSprite *sprite );
		void youxia( cocos2d::CCPoint point, cocos2d::CCSprite *sprite );
		void youshangpo( cocos2d::CCPoint point, cocos2d::CCSprite *sprite );
		void youxiapo( cocos2d::CCPoint point, cocos2d::CCSprite *sprite );
		void you( cocos2d::CCPoint point, cocos2d::CCSprite *sprite );
		void zuo( cocos2d::CCPoint point, cocos2d::CCSprite *sprite );
		void zhong( cocos2d::CCPoint point, cocos2d::CCSprite *sprite );
		void shu( cocos2d::CCPoint point, cocos2d::CCSprite *sprite );
		int creatls;
		float ls_x[10];
		CCSize size1 ;
		//////////////////添加初始化物体////////////////
		void addNewCaoping( cocos2d::CCPoint point, cocos2d::CCSprite *sprite );//添加草坪
		void addNewyoushang(cocos2d::CCPoint point);  
		void addNewyouxia(cocos2d::CCPoint point);
		///////////////////////////////x_size ,y_size均为同类障碍间的相邻距离
		//////////////////////zhong衔接zuo或you,y下降13
		void addNewyou(cocos2d::CCPoint point);  //////   x_size：50  y_size：26
		void addNewzuo(cocos2d::CCPoint point);  /////    x_size：50  y_size：26
		void addNewzhong(cocos2d::CCPoint point);   ////     x_size: 100
		void addNewshu(cocos2d::CCPoint point);
		void addNewenemy(cocos2d::CCPoint point);///添加怪物
		void addNewfire(cocos2d::CCPoint point); ///添加火焰

		int star_num,gain_num;
		void addNewstar(cocos2d::CCPoint point);      //添加星星


		void addNewfinish(cocos2d::CCPoint point);      //添加终点

		///////////////////////////////////
		void keyBackClicked();
		void keyMenuClicked();
		
		void zanting1();
		int fd;
		int begin_back;
		int had_js;
		int had_th;
		int attack_ok;
		int attack_time;


		set<int>  removedtag;


		int scene_num;
		void gameover();
		virtual void onEnter();
		virtual void onEnterTransitionDidFinish();

		void init_num();

		void victory();

		void addNewtukuai(cocos2d::CCPoint point, cocos2d::CCSprite *sprite );

};
/////tag:主角 7 加速器 6  弹球 31 弹簧 41    主角平时动作53 攻击动作54    enemy 61~70   enemyaction 71~80    fire 211~220
/////            star  221~230     fihish 888    物体拖动动画  310~320    物体按钮 321~330   物体数量字体 331~340


///////每个场景切记要有一个终点，否则会出错！！！！！
/////////////////////////////////////////////////////////////////////






#endif // __HELLOWORLD_SCENE_H__
