#include "ball.h"

ball::ball()
{
    circle.setRadius(10.f);
    circle.setFillColor(Color::White);
    circle.setOrigin(5,5);
    circle.setPosition(randNum(0, 800), 0);
}

ball::~ball()
{
    //dtor
}
void ball::update()
{
    circle.move(dx, dy);
    if(circle.getPosition().x > 800 - 5) dx = -5;
    if(circle.getPosition().x < 0 + 5) dx = 5;
    if(circle.getPosition().y > 600 - 5) life = 0;
    if(circle.getPosition().y < 0 + 5) dy = 5;
}
CircleShape ball::getCircle()
{
    return circle;
}
void ball::bounce(int distFromMid)
{
    dy = -5;
    dx = distFromMid * 0.2;
}
bool ball::isDead()
{
    return life > 0 ? 0 : 1;
}
int ball::randNum(int min, int max)
{
   return rand() % max + min;
}
