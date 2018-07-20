#include <SFML/Graphics.hpp>
#include <iostream>
#include <ball.h>
#include <cstdlib>
#include <ctime>
#include <sstream>
using namespace sf;
using namespace std;
int main()
{
    srand(time(NULL));
    RenderWindow window(VideoMode(800, 600), "Balls");
    window.setFramerateLimit(60);
    RectangleShape rect;
    rect.setSize(Vector2f(100, 20));
    rect.setFillColor(Color::Blue);
    rect.setPosition(350, 500);
    rect.setOrigin(50, 0);
    float speed = 20;
    vector<ball> ballArray;
    int timer = 0;
    int gameTime = 0;
    bool gameStart = false;
    Text text, scoreText, scoreText2;
    Font font;
    font.loadFromFile("123.ttf");
    text.setFont(font);
    text.setString("Press Space bar to start");
    text.setPosition(150, 400);
    text.setCharacterSize(40);
    text.setFillColor(Color::White);
    scoreText.setFont(font);
    scoreText.setString(" ");
    scoreText.setPosition(50, 200);
    scoreText.setCharacterSize(40);
    scoreText.setFillColor(Color::White);
    scoreText2.setFont(font);
    scoreText2.setString(" ");
    scoreText2.setPosition(180, 200);
    scoreText2.setCharacterSize(40);
    scoreText2.setFillColor(Color::White);
    int score = 0;
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        timer ++;
        if(timer > 100 && gameStart)
        {
            timer = 0;
            ball b;
            ballArray.push_back(b);
        }
        if(gameStart)
        {
            score += ballArray.size();
            gameTime ++;
        }
        if(gameTime > 5000 && gameStart)
        {
            gameStart = false;
            ballArray.clear();
            text.setString("Game Over \n Press Space bar to restart");
            scoreText.setString("Score:");
            std::stringstream ss;
            ss << score;
            scoreText2.setString( ss.str().c_str() );
        }
        for(int i = 0; i < ballArray.size(); i ++)
        {
            ballArray[i].update();
            if(rect.getGlobalBounds().intersects(ballArray[i].getCircle().getGlobalBounds()))
            {
                float distFromMid = ballArray[i].getCircle().getPosition().x - rect.getPosition().x;
                ballArray[i].bounce(distFromMid);
            }
        }
        if(Keyboard::isKeyPressed(Keyboard::Space) && !gameStart)
        {
            gameStart = true;
            text.setString(" ");
            scoreText.setString(" ");
            scoreText2.setString(" ");
            gameTime = 0;
            score = 0;
        }
        if(Keyboard::isKeyPressed(Keyboard::Left) && rect.getPosition().x > 0 + 50)
        {
            rect.move(-speed, 0);
        }
        else if(Keyboard::isKeyPressed(Keyboard::Right) && rect.getPosition().x < 800 - 50)
        {
            rect.move(speed, 0);
        }
        for(int i = 0; i < ballArray.size(); i ++)
        {
            if(ballArray[i].isDead())
            {
                ballArray.erase(ballArray.begin() + i);
            }
        }
        window.clear();
        for(int i = 0; i < ballArray.size(); i ++)
        window.draw(ballArray[i]);
        window.draw(rect);
        window.draw(text);
        window.draw(scoreText);
        window.draw(scoreText2);
        window.display();
    }

    return 0;
}
