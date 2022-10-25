// Hubbard_Lab07.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFPhysics.h>

using namespace std;
using namespace sf;
using namespace sfp;


int main()
{
    RenderWindow window(VideoMode(800, 600), "Bounce");
    World world(Vector2f(0, 1.0));

    PhysicsCircle ball;
    ball.setCenter(Vector2f(400, 150));
    ball.setRadius(20);
    ball.applyImpulse(Vector2f(1,0.5));
    world.AddPhysicsBody(ball);

    PhysicsRectangle floor;
    floor.setSize(Vector2f(850, 40));
    floor.setCenter(Vector2f(400, 590));
    floor.setStatic(true);
    world.AddPhysicsBody(floor);

    PhysicsRectangle leftWall;
    leftWall.setSize(Vector2f(20, 800));
    leftWall.setCenter(Vector2f(10,200));
    leftWall.setStatic(true);
    world.AddPhysicsBody(leftWall);

    PhysicsRectangle rightWall;
    rightWall.setSize(Vector2f(40, 800));
    rightWall.setCenter(Vector2f(800, 180));
    rightWall.setStatic(true);
    world.AddPhysicsBody(rightWall);

    PhysicsRectangle ceiling;
    ceiling.setSize(Vector2f(800, 20));
    ceiling.setCenter(Vector2f(400,0));
    ceiling.setStatic(true);
    world.AddPhysicsBody(ceiling);

    PhysicsRectangle middle;
    middle.setSize(Vector2f(100, 100));
    middle.setCenter(Vector2f(400, 300));
    middle.setStatic(true);
    world.AddPhysicsBody(middle);



    int thudCount(0);
    floor.onCollision = [&thudCount](PhysicsBodyCollisionResult result) {
        cout << "thud " << thudCount << endl;
        thudCount++;
    };
    
    leftWall.onCollision = [&thudCount](PhysicsBodyCollisionResult result) {
        cout << "thud " << thudCount << endl;
        thudCount++;
    };
  
    rightWall.onCollision = [&thudCount](PhysicsBodyCollisionResult result) {
        cout << "thud " << thudCount << endl;
        thudCount++;
    };
   
    ceiling.onCollision = [&thudCount](PhysicsBodyCollisionResult result) {
        cout << "thud " << thudCount << endl;
        thudCount++;
    };

    int bangCount(0);
    middle.onCollision = [&bangCount](PhysicsBodyCollisionResult result) {
        cout << "bang " << bangCount+1 << endl;
        bangCount++;
        if (bangCount >= 3) {
            exit(0);
        }
    };


    Clock clock;
    Time lastTime(clock.getElapsedTime());
    while (true) {
        Time currentTime(clock.getElapsedTime());
        Time deltaTime(currentTime - lastTime);
        int deltaTimeMS(deltaTime.asMilliseconds());
        if (deltaTimeMS > 0) {
            world.UpdatePhysics(deltaTimeMS);
            lastTime = currentTime;
        }
        window.clear(Color(0,0,0));
        window.draw(ball);
        window.draw(floor);
        window.draw(middle);
        window.draw(ceiling);
        window.draw(leftWall);
        window.draw(rightWall);
        
        window.display();
    }

}





