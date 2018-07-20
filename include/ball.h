#ifndef BALL_H
#define BALL_H
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
using namespace sf;
class ball : public Drawable
{
    public:
        ball();
        virtual ~ball();
        virtual void draw(RenderTarget& target, RenderStates states)const
        {
            target.draw(circle, states);
        }
        void update();
        CircleShape getCircle();
        void bounce(int distFromMid);
        bool isDead();
    protected:

    private:
        int randNum(int min, int max);
        CircleShape circle;
        float dx = 0;
        float dy = 5;
        bool life = true;
};

#endif // BALL_H
