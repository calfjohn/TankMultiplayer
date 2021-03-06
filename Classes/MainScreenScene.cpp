//
//  MainScreenScene.cpp
//  TankMultiplayer
//
//  Created by Jacky on 14-5-16.
//
//

#include "MainScreenScene.h"
#include "GameScene.h"
#include "GPGSManager.h"
//#include <random>
#include "TestTBMP.h"
#include "VisibleRect.h"
#include "Configuration.h"
#include "GameScene.h"
#include "Configuration.h"
#include "WagonSelect.h"
#include "NoTouchLayer.h"

USING_NS_CC;

#define ACH_ACHIEVEMENT_01 "CgkIs7qm9rYbEAIQAQ"
#define ACH_ACHIEVEMENT_02 "CgkIs7qm9rYbEAIQAg"
#define LEAD_LEADERBOARD "CgkIs7qm9rYbEAIQAw"

Scene* MainScreenScene::createScene()
{
    auto scene = Scene::create();
    
    auto layer = MainScreenScene::create();
    
    scene->addChild(layer);
    
    return scene;
}

bool MainScreenScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
//    Size visibleSize = Director::getInstance()->getVisibleSize();
//    
//    //SignIn and Sign Out.
//    std::string strSign = "Sign In";
//    if (GPGSManager::IsSignedIn()) {
//        strSign = "Sign Out";
//    }
//    auto signin_label = Label::createWithSystemFont(strSign, "Arial", 20);
//    auto signin_menuitem = MenuItemLabel::create(signin_label,
//                                                 [signin_label](Ref* ref){
//                                                     if (GPGSManager::IsSignedIn()) {
//                                                         log("The Status of now is SignedIn");
//                                                         signin_label->setString("Sign Out");
//                                                         GPGSManager::SignOut();
//                                                     } else {
//                                                         log("The Status of now is not SignedIn");
//                                                         GPGSManager::BeginUserInitiatedSignIn();
//                                                     }
//                                                     
//                                                 });
//    signin_menuitem->setPosition(Point(visibleSize.width/2-100, visibleSize.height/2+50));
//    
//    //Show LeaderBoards
//    auto leaderboard_label = Label::createWithSystemFont("LeaderBoard", "Arial", 20);
//    auto leaderboard_menuitem = MenuItemLabel::create(leaderboard_label,
//                                                      [](Ref* ref){
//                                                          if (GPGSManager::IsSignedIn()) {
//                                                              log("Show LeaderBoard");
//                                                              GPGSManager::ShowLeaderboard(LEAD_LEADERBOARD);
//                                                          }
//                                                          else{
//                                                              log("Failed to show LeaderBoard, Not Signed in");
//                                                          }
//                                                      });
//    leaderboard_menuitem->setPosition(Point(visibleSize.width/2+100, visibleSize.height/2+50));
//    
//    //Show Achievements
//    auto achievement_label = Label::createWithSystemFont("Achievement", "Arial", 20);
//    auto achievement_menuitem = MenuItemLabel::create(achievement_label,
//                                                      [](Ref* ref){
//                                                          if (GPGSManager::IsSignedIn()) {
//                                                              log("Show Achievements");
//                                                              GPGSManager::ShowAchievements();
//                                                          }
//                                                          else{
//                                                              log("Failed to show Achievements, Not Signed in");
//                                                          }
//                                                      });
//    achievement_menuitem->setPosition(Point(visibleSize.width/2-100, visibleSize.height/2));
//    
//    //Submit Score
//    std::uniform_int_distribution<unsigned> u(0,10000);
//    std::default_random_engine e;
//    e.seed((unsigned)time(NULL));
//    auto rand_score =  u(e);
//    auto submitscore_label = Label::createWithSystemFont("SubmitScore", "Arial", 20);
//    auto submitscore_menuitem = MenuItemLabel::create(submitscore_label,
//                                                      [rand_score](Ref* ref){
//                                                          if (GPGSManager::IsSignedIn()) {
//                                                              log("Submit Score %d", rand_score);
//                                                              GPGSManager::SubmitHighScore(LEAD_LEADERBOARD, rand_score);
//                                                          }
//                                                          else{
//                                                              log("Failed to submit score, Not Signed in");
//                                                          }
//                                                      });
//    submitscore_menuitem->setPosition(Point(visibleSize.width/2+100, visibleSize.height/2));
//    
//    //Unlock Achievement
//    auto unlockachievement_label = Label::createWithSystemFont("UnlockAchievement", "Arial", 20);
//    auto unlockachievement_menuitem = MenuItemLabel::create(unlockachievement_label,
//                                                            [](Ref* ref){
//                                                                if (GPGSManager::IsSignedIn()) {
//                                                                    log("Unlock Achievement %s", ACH_ACHIEVEMENT_01);
//                                                                    GPGSManager::UnlockAchievement(ACH_ACHIEVEMENT_01);
//                                                                }
//                                                                else{
//                                                                    log("Failed to unlock Achievements, Not Signed in");
//                                                                }
//                                                            });
//    unlockachievement_menuitem->setPosition(Point(visibleSize.width/2-100, visibleSize.height/2-50));
//    
//    //Increase Achievement
//    auto increaseachievement_label = Label::createWithSystemFont("IncreaseAchievement", "Arial", 20);
//    auto increaseachievement_menuitem = MenuItemLabel::create(increaseachievement_label,
//                                                              [](Ref* ref){
//                                                                  if (GPGSManager::IsSignedIn()) {
//                                                                      log("Increase Achievement %s", ACH_ACHIEVEMENT_02);
//                                                                   GPGSManager::IncrementAchievement(ACH_ACHIEVEMENT_02);
//                                                                  }
//                                                              });
//    increaseachievement_menuitem->setPosition(Point(visibleSize.width/2+100, visibleSize.height/2-50));
//    
//    auto quickmatch_label = Label::createWithSystemFont("QuickMatch", "Arial", 20);
//    auto quickmatch_menuitem = MenuItemLabel::create(quickmatch_label,
//                                                              [](Ref* ref){
//                                                                  if (GPGSManager::IsSignedIn()) {
//                                                                      log("Quick Match");
//                                                                      GPGSManager::QuickMatch();
//                                                                  }
//                                                              });
//    quickmatch_menuitem->setPosition(Point(visibleSize.width/2-100, visibleSize.height/2-100));
//
//    
//    auto invitefriend_label = Label::createWithSystemFont("InviteFriend", "Arial", 20);
//    auto invitefriend_menuitem = MenuItemLabel::create(invitefriend_label,
//                                                     [](Ref* ref){
//                                                         if (GPGSManager::IsSignedIn()) {
//                                                             log("InviteFriend");
//                                                             GPGSManager::InviteFriend();
//                                                         }
//                                                     });
//    invitefriend_menuitem->setPosition(Point(visibleSize.width/2+100, visibleSize.height/2-100));
//    
//    auto showmatchinbox_label = Label::createWithSystemFont("ShowMatchInBox", "Arial", 20);
//    auto showmatchinbox_menuitem = MenuItemLabel::create(showmatchinbox_label,
//                                                       [](Ref* ref){
//                                                           if (GPGSManager::IsSignedIn()) {
//                                                               log("ShowMatchInBox");
//                                                               GPGSManager::ShowMatchInbox();
//                                                           }
//                                                       });
//    showmatchinbox_menuitem->setPosition(Point(visibleSize.width/2-100, visibleSize.height/2-150));
//    
//    auto menu = Menu::create(signin_menuitem, leaderboard_menuitem, achievement_menuitem,
//                             submitscore_menuitem, unlockachievement_menuitem, increaseachievement_menuitem,
//                             quickmatch_menuitem, invitefriend_menuitem, showmatchinbox_menuitem, nullptr);
//    menu->setPosition(Point::ZERO);
//    this->addChild(menu);
    
    auto mainscreen_bk = Sprite::create("mainscreen_bk.jpg");
    if(g_visibleRect.visibleWidth>960)
    {
        mainscreen_bk->setScaleX(g_visibleRect.visibleWidth/960);
    }
    mainscreen_bk->setAnchorPoint(Point::ANCHOR_MIDDLE);
    mainscreen_bk->setPosition(g_visibleRect.center);
    this->addChild(mainscreen_bk);
    
    auto mainscreen_logo = Sprite::create("mainscreen_logo.png");
    mainscreen_logo->setAnchorPoint(Point::ANCHOR_MIDDLE);
    mainscreen_logo->setPosition(Point(g_visibleRect.center.x-150,g_visibleRect.center.y+130));
    mainscreen_logo->setRotation(-10);
    this->addChild(mainscreen_logo,2);
    
    mainscreen_logo->runAction(RepeatForever::create(Sequence::create(MoveBy::create(1.0f, Point(0,-20)),MoveBy::create(1.0f, Point(0,20)),nullptr)));
    
    quickmatch_menuitem = MenuItemImage::create("btn_quickmatch_0.png",
                                                     "btn_quickmatch_1.png",
                                                     CC_CALLBACK_1(MainScreenScene::quickmatch_callback, this));
    quickmatch_menuitem->setAnchorPoint(Point::ANCHOR_MIDDLE);
    quickmatch_menuitem->setPosition(Point(g_visibleRect.visibleWidth-350,g_visibleRect.visibleHeight-100));
    
    invitefriend_menuitem = MenuItemImage::create("btn_invitefriend_0.png",
                                                     "btn_invitefriend_1.png",
                                                     CC_CALLBACK_1(MainScreenScene::invitefriend_callback, this));
    invitefriend_menuitem->setAnchorPoint(Point::ANCHOR_MIDDLE);
    invitefriend_menuitem->setPosition(Point(g_visibleRect.visibleWidth-350,g_visibleRect.visibleHeight-250));
    
    mygames_menuitem = MenuItemImage::create("btn_mygames_0.png",
                                                     "btn_mygames_1.png",
                                                     CC_CALLBACK_1(MainScreenScene::mygames_callback, this));
    mygames_menuitem->setAnchorPoint(Point::ANCHOR_MIDDLE);
    mygames_menuitem->setPosition(Point(g_visibleRect.visibleWidth-350,g_visibleRect.visibleHeight-400));
    
    achievements_menuitem = MenuItemImage::create("btn_achievements_0.png",
                                                     "btn_achievements_1.png",
                                                     CC_CALLBACK_1(MainScreenScene::achievements_callback, this));
    achievements_menuitem->setAnchorPoint(Point::ANCHOR_MIDDLE);
    achievements_menuitem->setPosition(Point(g_visibleRect.visibleWidth-420,g_visibleRect.visibleHeight-520));
    
    leaderboard_menuitem = MenuItemImage::create("btn_leaderboard_0.png",
                                                     "btn_leaderboard_1.png",
                                                     CC_CALLBACK_1(MainScreenScene::leaderboard_callback, this));
    leaderboard_menuitem->setAnchorPoint(Point::ANCHOR_MIDDLE);
    leaderboard_menuitem->setPosition(Point(g_visibleRect.visibleWidth-280,g_visibleRect.visibleHeight-520));
    
    auto menu = Menu::create(quickmatch_menuitem, invitefriend_menuitem, mygames_menuitem, achievements_menuitem, leaderboard_menuitem, nullptr);
    menu->setPosition(Point(150,-50));
    this->addChild(menu,1);
    
    sign_status = Label::create("status:unknown.", GameConfig::defaultFontName, 20);
    sign_status->setAnchorPoint(Point::ANCHOR_MIDDLE);
    sign_status->setPosition(Point(750,50));
    this->addChild(sign_status,1);
    this->schedule(schedule_selector(MainScreenScene::updateStatus), 0.1f, kRepeatForever, 2.0f);
    
    auto listener1 = EventListenerCustom::create("enterWagonSelect_1", CC_CALLBACK_0(MainScreenScene::enterWagonSelect_1, this));
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, this);

    auto listener2 = EventListenerCustom::create("enterWagonSelect_2", CC_CALLBACK_0(MainScreenScene::enterWagonSelect_2, this));
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener2, this);
    
    auto listener3 = EventListenerCustom::create("enterGame", CC_CALLBACK_0(MainScreenScene::enterGame, this));
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener3, this);
    
    
    auto cnm = Sprite::createWithSpriteFrameName("cnm_idle01.png");
    auto cnmhit = g_gameConfig.getAnimate(g_gameAnimation.cnm_hit);
    cnm->runAction(RepeatForever::create(cnmhit));
    this->addChild(cnm,100);
    cnm->setPosition(300,300);
    
    return true;
}

void MainScreenScene::quickmatch_callback(cocos2d::Ref* pSender)
{
    log("QuickMatch");
    if (GPGSManager::IsSignedIn()) {
        
        auto notouchlayer = NoTouchLayer::create();
        notouchlayer->setTag(NOTOUCHTAG);
        Director::getInstance()->getRunningScene()->addChild(notouchlayer,100);
        
        GPGSManager::QuickMatch();
    }
    else{
        GPGSManager::BeginUserInitiatedSignIn();
    }
}
void MainScreenScene::invitefriend_callback(cocos2d::Ref* pSender)
{
    log("InviteFriend");
    if (GPGSManager::IsSignedIn()) {
        GPGSManager::InviteFriend();
    }
    else{
        GPGSManager::BeginUserInitiatedSignIn();
    }
}
void MainScreenScene::mygames_callback(cocos2d::Ref* pSender)
{
    log("MyGames");
    if (GPGSManager::IsSignedIn()) {
        GPGSManager::ShowMatchInbox();
    }
    else{
        GPGSManager::BeginUserInitiatedSignIn();
    }
}
void MainScreenScene::achievements_callback(cocos2d::Ref* pSender)
{
    log("Achievements");
    if (GPGSManager::IsSignedIn()) {
        GPGSManager::ShowAchievements();
    }
    else{
        GPGSManager::BeginUserInitiatedSignIn();
    }
}
void MainScreenScene::leaderboard_callback(cocos2d::Ref* pSender)
{
    log("LeaderBoard");
    if (GPGSManager::IsSignedIn()) {
        GPGSManager::ShowLeaderboard(LEAD_LEADERBOARD);
    }
    else{
        GPGSManager::BeginUserInitiatedSignIn();
    }
}

void MainScreenScene::enableUI(bool isEnable)
{
    quickmatch_menuitem->setEnabled(isEnable);
    invitefriend_menuitem->setEnabled(isEnable);
    mygames_menuitem->setEnabled(isEnable);
    achievements_menuitem->setEnabled(isEnable);
    leaderboard_menuitem->setEnabled(isEnable);
}

void MainScreenScene::updateStatus(float dt)
{
//    if (GPGSManager::IsSignedIn()) {
//        sign_status->setString("status:sign in.");
//    }
//    else
//    {
//        sign_status->setString("status:sign out.");
//    }
}

void MainScreenScene::enterWagonSelect_1()
{
    
    scheduleOnce(schedule_selector(MainScreenScene::enterWagonSelectWithDelay_1), transSceneDelayTime);
}

void MainScreenScene::enterWagonSelectWithDelay_1(float dt)
{
    log("recv data is ===>%s", g_gameConfig.match_string.c_str());
    Director::getInstance()->getRunningScene()->removeChildByTag(NOTOUCHTAG);
    auto scene = WagonSelect::createScene(FIRST_TURN);
    cocos2d::Director::getInstance()->replaceScene(scene);
}

void MainScreenScene::enterWagonSelect_2()
{
    scheduleOnce(schedule_selector(MainScreenScene::enterWagonSelectWithDelay_2), transSceneDelayTime);
}

void MainScreenScene::enterWagonSelectWithDelay_2(float dt)
{
    log("recv data is ===>%s", g_gameConfig.match_string.c_str());
    Director::getInstance()->getRunningScene()->removeChildByTag(NOTOUCHTAG);
    auto scene = WagonSelect::createScene(SECOND_TURN);
    cocos2d::Director::getInstance()->replaceScene(scene);
}

void MainScreenScene::enterGame()
{
    scheduleOnce(schedule_selector(MainScreenScene::enterGameWithDelay), transSceneDelayTime);
}
void MainScreenScene::enterGameWithDelay(float dt)
{
    log("recv data is ===>%s", g_gameConfig.match_string.c_str());
    this->removeChildByTag(NOTOUCHTAG);
    auto scene = GameScene::createScene();
    cocos2d::Director::getInstance()->replaceScene(scene);
}
