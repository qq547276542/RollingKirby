#ifndef __A2_H__
#define __A2_H__

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
class a2 : public cocos2d::CCLayer,public b2ContactListener
{

public:
	virtual bool init();
	static cocos2d::CCScene* scene();
	void menuCloseCallback(CCObject* pSender);  //start��ť�������¼�
	void remenu(CCObject* psender);
	b2World *world;      // ����
	void update( float dt );//��ʱ�����¼������dt���������г������½��������еĵڶ�������
		void addNewSpriteWithCoords( cocos2d::CCPoint point, cocos2d::CCSprite *sprite );//��Ӿ���
		void addNewmk( cocos2d::CCPoint point, cocos2d::CCSprite *sprite );//���ľ��
		void addNewzt( cocos2d::CCPoint point, cocos2d::CCSprite *sprite );//���שͷ
		void addNewth( cocos2d::CCPoint point, cocos2d::CCSprite *sprite );//��ӵ���
		void addNewtx( cocos2d::CCPoint point, cocos2d::CCSprite *sprite );//�������
		void addNewjs( cocos2d::CCPoint point, cocos2d::CCSprite *sprite );//��Ӽ����� 
		void addNewls( cocos2d::CCPoint point, cocos2d::CCSprite *sprite );//�����ʯ

		virtual void ccTouchesBegan(CCSet *pTouch,CCEvent *pEvent);
		void ccTouchesMoved(CCSet *pTouch, CCEvent *pEvent);
		virtual void ccTouchesEnded( CCSet *pTouches, CCEvent *pEvent);  //���ſ��¼�

		void setthings_num();//�������������
		int mk_num,zt_num,th_num,tx_num,js_num,ls_num,tps_num,tpx_num;    //��������

		int enemy1_num;                                                    //��������
		int fire_num;                                               //��������


		float32 gy;        //���Ƹ���ʱ�䲽
		int clickcase;     //�жϵ����Ļ���ֵ���Ʒ
		void setcase1(CCObject* pSender);   //�ı�clickcaseֵΪ1
		void setcase2(CCObject* pSender);   //�ı�clickcaseֵΪ2
		void setcase3(CCObject* pSender);   //.....
		void setcase4(CCObject* pSender);  //.....
		void setcase5(CCObject* pSender);
		void setcase6(CCObject* pSender);
		void setcase7(CCObject* pSender);
	    void setcase8(CCObject* pSender);
		char score1[2],score2[2],score3[2],score4[2],score5[2],score6[2],score7[2],score8[2];   //���ַ�����������������ͼƬ����
		CCLabelAtlas* la_mk,* la_zt,*la_th,*la_tx,*la_js,*la_ls,*la_tps,*la_tpx;     //����
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
		//////////////////��ӳ�ʼ������////////////////
		void addNewCaoping( cocos2d::CCPoint point, cocos2d::CCSprite *sprite );//��Ӳ�ƺ
		void addNewyoushang(cocos2d::CCPoint point);  
		void addNewyouxia(cocos2d::CCPoint point);
		///////////////////////////////x_size ,y_size��Ϊͬ���ϰ�������ھ���
		//////////////////////zhong�ν�zuo��you,y�½�13
		void addNewyou(cocos2d::CCPoint point);  //////   x_size��50  y_size��26
		void addNewzuo(cocos2d::CCPoint point);  /////    x_size��50  y_size��26
		void addNewzhong(cocos2d::CCPoint point);   ////     x_size: 100
		void addNewshu(cocos2d::CCPoint point);
		void addNewenemy(cocos2d::CCPoint point);///��ӹ���
		void addNewfire(cocos2d::CCPoint point); ///��ӻ���

		int star_num,gain_num;
		void addNewstar(cocos2d::CCPoint point);      //�������


		void addNewfinish(cocos2d::CCPoint point);      //����յ�

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
/////tag:���� 7 ������ 6  ���� 31 ���� 41    ����ƽʱ����53 ��������54    enemy 61~70   enemyaction 71~80    fire 211~220
/////            star  221~230     fihish 888    �����϶�����  310~320    ���尴ť 321~330   ������������ 331~340


///////ÿ�������м�Ҫ��һ���յ㣬����������������
/////////////////////////////////////////////////////////////////////






#endif // __HELLOWORLD_SCENE_H__
