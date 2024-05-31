#include <iostream>
#include "fmt/core.h"
#include "fmt/ranges.h"
#include <SFML/Graphics.hpp>

#include "AnimationType.h"
#include "Character.h"
#include "view.h"

/*

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Animation Test");
    window.setFramerateLimit(60);

    Boy char_boy; // Создаем объект класса Boy

    // Загружаем текстуру и добавляем анимации
    char_boy.loadTexture();
    char_boy.setAnimation(AnimationType::IDLE); // Устанавливаем анимацию ожидания по умолчанию

    float deltaTime = 0.0f;
    sf::Clock clock;
    sf::Clock idleTimer; // Таймер для анимации ожидания
    const float idleTime = 5.0f; // Время до проигрывания анимации ожидания (в секундах)

    while (window.isOpen()) {
        deltaTime = clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // Обновляем таймер каждый раз, когда нажата какая-либо клавиша
            if (event.type == sf::Event::KeyPressed) {
                idleTimer.restart(); // Сбрасываем таймер
            }
        }

        // Если прошло достаточно времени бездействия, переключаемся на анимацию ожидания
        if (idleTimer.getElapsedTime().asSeconds() > idleTime) {
            char_boy.setAnimation(AnimationType::IDLE);
        }

        window.clear(sf::Color::White);
        // Обновляем анимацию персонажа
        char_boy.update(deltaTime);
        // Отрисовываем персонажа
        window.draw(char_boy.sprite);
        window.display();
    }

    return 0;
}
*/



auto main() -> int {

    auto window = sf::RenderWindow(
            sf::VideoMode(1024, 1024), "Fighter2D",
            sf::Style::Default | sf::Style::Resize | sf::Style::Close, sf::ContextSettings(0, 0, 8));
    window.setFramerateLimit(60);

    view.reset(sf::FloatRect (0, 0, 1024, 1024));


    auto char_boy = Boy();
    char_boy.loadTexture();
    char_boy.setAnimation(AnimationType::IDLE);



    float deltaTime = 0.0f;
    auto clock = sf::Clock();
    auto idleTimer= sf::Clock();
    const auto idleTime = float(5.0f);



    while(window.isOpen()) {
        deltaTime = clock.restart().asSeconds();

        auto event = sf::Event();
        while (window.pollEvent(event)){
            switch (event.type) {
                case sf::Event::KeyPressed:
                    idleTimer.restart();
                    if(event.key.code == sf::Keyboard::Escape){
                        window.close();
                    }
                    break;
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }
        if(idleTimer.getElapsedTime().asSeconds() > idleTime) {
            char_boy.setAnimation(AnimationType::IDLE);
        }

/*//// CHAR BOY REALISATION
//        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
//            current_frame += 0.008 * deltaTime; // change frame by counter (counter co 10 msek np.)
//            if(current_frame > 8) {
//                current_frame -= 8;
//            }
//            char_boy.sprite.setTextureRect(sf::IntRect(48 * int(current_frame), 48, 48, 48));
//            char_boy.sprite.move(0.3 * deltaTime, 0);
//        }
//
//        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
//
//            current_frame += 0.008 * deltaTime; // change frame by counter (counter co 10 msek np.)
//            if(current_frame > 8) {
//                current_frame -= 8;
//            }
//            char_boy.sprite.setTextureRect(sf::IntRect(48 * int(current_frame) + 48, 48, -48, 48));
//            char_boy.sprite.move(-0.3 * deltaTime, 0);
//        }
// // сделать гравитацию
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
//            current_frame += 0.008 * deltaTime;
//            if (current_frame > 6) {
//                current_frame -= 6;
//            }
//            char_boy.sprite.setTextureRect(sf::IntRect(48 * int(current_frame), 48 * 3, 48, 48));
//            if (current_frame > 4) {
//                char_boy.sprite.move(0, -0.1 * deltaTime);
//            } else {
//                char_boy.sprite.move(0, 0.1 * deltaTime);
//            }
//
//        }

//*/
        window.setView(view);
        window.clear();
        char_boy.update(deltaTime);
        window.draw(char_boy.sprite);
        window.display();
    }


    return 0;
}
