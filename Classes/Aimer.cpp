//
//  Aimer.cpp
//  TankMultiplayer
//
//  Created by WuHao on 14-5-30.
//
//

#include "Aimer.h"
USING_NS_CC;

Aimer* Aimer::create(bool isRight, float upper, float lower)
{
    Aimer *pRet = new Aimer();
    if (pRet && pRet->init(isRight, upper, lower))
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = NULL;
        return NULL;
    }
}

bool Aimer::init(bool isRight, float upper, float lower)
{
    _back = Sprite::create("aimerback.png");
    addChild(_back);
    
    //const Point mid(getContentSize()/2);
    _pointer = Sprite::create("pointer.png");
    _pointer->setAnchorPoint(Point::ANCHOR_MIDDLE_LEFT);
    //_pointer->setPosition(mid);
    _pointer->setScaleY(0.5);
    _pointer->setOpacity(200);
    
    _green = ProgressTimer::create(Sprite::create("aimergreen.png"));
    
    //_green->setPosition(mid);
    _green->setType(ProgressTimer::Type::RADIAL);
    _green->setOpacity(150);
    
    _crosshair=Sprite::create("crosshair.png");
    
    addChild(_crosshair);
    
    addChild(_green);
    addChild(_pointer);
    
    
    upperLimit = upper;
    lowerLimit = lower;
    reversed = !isRight;
    //find out the percentage
    if(!isRight)
        setAngle((upperLimit+lowerLimit)/2);
    else{
        setAngle(-180-((upperLimit+lowerLimit)/2));
    }
    _green->setPercentage((lowerLimit-upperLimit)/3.6);
    //_green->setRotation(-upperLimit);
    
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = CC_CALLBACK_2(Aimer::onTouchBegan, this);
    listener->onTouchEnded = CC_CALLBACK_2(Aimer::onTouchEnded, this);
    listener->onTouchMoved = CC_CALLBACK_2(Aimer::onTouchMoved, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    listener->setSwallowTouches(true);
    
        _back->setRotation((upperLimit+lowerLimit)/2);
    
    return true;

}
bool Aimer::onTouchBegan(Touch* touch, Event* event)
{
    if(convertToWorldSpace(_crosshair->getPosition()).getDistance(touch->getLocation()) < 50)
    {
        _pointer->runAction(ScaleTo::create(0.1, 2, _pointer->getScaleY()));
        _pointer->runAction(FadeTo::create(0.1, 255));
        return true;
    }
    else
    {
        return false;
    }

}
void Aimer::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event)
{
    _pointer->stopAllActions();
    _pointer->runAction(ScaleTo::create(0.1, 1.0, _pointer->getScaleY()));
    _pointer->runAction(FadeTo::create(0.1, 200));
    log("aaaa %f", getWorldAngle());
}

void Aimer::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event)
{
    float a = CC_RADIANS_TO_DEGREES((touch->getLocation()-convertToWorldSpace(getPosition())).getAngle());
    setAngle(-a-getParent()->getParent()->getRotation());
    
    
}
float Aimer::getWorldAngle()
{
    return _angle + getParent()->getParent()->getRotation();
}
void Aimer::setAngle(float a)
{
    if(!reversed)
    {
        a = a>0? a-360: a;
        _angle = clampf(a, -180-upperLimit ,-180-lowerLimit);
        log("%f,, %f,, %f",a, -180-upperLimit, -180-lowerLimit);
        _crosshair->setPosition(Point(-200,0).rotateByAngle(Point(0,0), CC_DEGREES_TO_RADIANS(_angle)));
        _pointer->setRotation(-180-_angle);
        _crosshair->setRotation(-_angle);
    }
    else
    {
        _angle = clampf(a, upperLimit, lowerLimit);
        _pointer->setRotation(_angle);
        _crosshair->setRotation(_angle);
        _crosshair->setPosition(Point(200,0).rotateByAngle(Point(0,0), CC_DEGREES_TO_RADIANS(-_angle)));
    }
}