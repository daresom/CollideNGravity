#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Object.h"

float dt;

using namespace sf;

void collision(Player* player, Object object[], int size, float dt) {
    FloatRect playerHitbox = player->getSprite().getGlobalBounds();
    FloatRect nextPos = player->getNextPos();
    
    for (int i = 0; i < size; i++) {
        FloatRect objectBox = object[i].getSprite().getGlobalBounds();

        if (nextPos.intersects(objectBox)) {
            if (playerHitbox.top < objectBox.top && playerHitbox.top - playerHitbox.height < objectBox.top) { //Top collision platform
                std::cout << "h";
                player->velocityY = 0;
                player->isOnFloor = true;
                player->setSpritePos(player->x, objectBox.top - playerHitbox.height);
            }
            if (playerHitbox.top > objectBox.top - objectBox.height && playerHitbox.top - playerHitbox.top < objectBox.top) { //Bottom collision platform
                player->velocityY = 0;
                player->isOnFloor = false;
                player->apply(dt);
            }
        }
    }
}

int main()
{
    RenderWindow window(VideoMode(800, 500), "SFML works!");
    Player player;
    Object floor[2];
    player.setSprite(sf::Vector2f(50, 50));
    floor[0].setSpriteSize(sf::Vector2f(1000,25));
    floor[0].setCords(0, 400);

    floor[1].setSpriteSize(sf::Vector2f(100, 25));
    floor[1].setCords(200, 300);

    Clock deltaTime;

    while (window.isOpen())
    {
        dt = deltaTime.restart().asSeconds();
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        player.playerMovement(dt, 2000);
        collision(&player, floor, 2, dt);

        player.apply(dt);

        std::cout << player.isOnFloor << std::endl;

        window.clear();

        for (int i = 0; i < 2; i++) {
            window.draw(floor[i].getSprite());
        }

        window.draw(player.getSprite());
        window.display();
    }

    return 0;
}
