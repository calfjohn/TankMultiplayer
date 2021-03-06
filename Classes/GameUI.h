//
//  GameUI.h
//  TankMultiplayer
//
//  Created by WuHao on 14-5-20.
//
//

#ifndef __TankMultiplayer__GameUI__
#define __TankMultiplayer__GameUI__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class PowerIndicator;
class PlayBackIndictaor;

class GameUI : public cocos2d::Layer
{
public:
    CREATE_FUNC(GameUI);
    virtual bool init();
    
    bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
    void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event);
    
protected:
    PowerIndicator* _power;
    PlayBackIndictaor* _playback;
    GameUI(){};
    cocos2d::EventListenerTouchOneByOne *_mytouchListener;
    void _toggleTouchEnable(bool onoff);
};

class WindIndicator : public cocos2d::Node
{
public:
    CREATE_FUNC(WindIndicator);
    virtual bool init();
    
    void setWind(cocos2d::Point pos);
protected:
    cocos2d::LabelAtlas *_label;
    cocos2d::Sprite *_arrow;
    
};

class PowerIndicator : public cocos2d::Node
{
public:
    CREATE_FUNC(PowerIndicator);
    virtual bool init();
    
    PowerIndicator():_leftFlag(false), _rightFlag(false),_startShootFlag(false){};
    
protected:
    cocos2d::Sprite* _left;
    cocos2d::Sprite* _right;
    cocos2d::Sprite* _fire;
    cocos2d::Sprite* _powerbar;
    cocos2d::Sprite* _innerpower;
    
    bool _leftFlag;
    bool _rightFlag;
    bool _startShootFlag;
    
    bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
    void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event);
    
    bool _powerFlag = false;
    int _tick = 0;
    int _tickPre;
    //timeval _now;
    
    void update(float delta);
    
    void increasePower();
    void dismissPower();
};

class PlayBackIndictaor : public cocos2d::Node{
public:
    CREATE_FUNC(PlayBackIndictaor);
    
    virtual bool init();
    
protected:
    cocos2d::ui::LoadingBar* _playBackInnerBar;
    cocos2d::Label* _turnInfoLabel;
    cocos2d::Label* _timeLabel;
};

#endif /* defined(__TankMultiplayer__GameUI__) */
