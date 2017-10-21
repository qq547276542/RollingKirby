#include "AppDelegate.h"
#include "menu.h"
#include "last.h"
#include "HelloWorldScene.h"
#include "HelloWorldScene2.h"
#include "HelloWorldScene3.h"
#include "SimpleAudioEngine.h"
#include "gameover.h"
#include "begin.h"
#include "a2.h"
#include "a1.h"
#include "b1.h"
#include "c1.h"
USING_NS_CC;
using namespace CocosDenshion;
AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
	SimpleAudioEngine::end();
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    CCDirector* pDirector = CCDirector::sharedDirector();
    CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();

    pDirector->setOpenGLView(pEGLView);
	

	//kResolutionExactFit        
	//kResolutionNoBorder    
	//kResolutionShowAll        

CCEGLView::sharedOpenGLView()->setDesignResolutionSize(800, 480, kResolutionNoBorder);



    // turn on display FPS
pDirector->setDisplayStats(false);
    

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
    CCScene *pScene = menu::scene();

    // run
    pDirector->runWithScene(pScene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    CCDirector::sharedDirector()->stopAnimation();
	SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    CCDirector::sharedDirector()->startAnimation();
	SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
