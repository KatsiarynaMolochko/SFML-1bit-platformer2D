#include <string>
#include "SFML/Graphics.hpp"
#include "Character.h"

auto addAnimations(Character& character) -> void {
    // ADDING ANIMATIONS
    // RUNNNING ANIMATION
    Animation runningAnimation;
    for (int i = 0; i < 8; ++i) {
        runningAnimation.addFrame(sf::IntRect(48 * i, 48, 48, 48));
    }
    runningAnimation.setFrameDuration(0.1f);
    character.animations[AnimationType::RUNNING] = runningAnimation;

// IDLE ANIMATION
    Animation idleAnimation;
    for (int i = 0; i < 3; ++i) {
        idleAnimation.addFrame(sf::IntRect (48 * i, 96, 48, 48));
    }
    runningAnimation.setFrameDuration(0.1f);
    character.animations[AnimationType::IDLE] = idleAnimation;

// RUN ATTACK ANIMATION
    Animation runAttackAnimation;
    for (int i = 0; i < 8; ++i) {
        runAttackAnimation.addFrame(sf::IntRect (48 * i, 0, 48, 48));
    }
    runAttackAnimation.setFrameDuration(0.1f);
    character.animations[AnimationType::RUN_ATTACK] = runAttackAnimation;

// HURT ANIMATION
    Animation hurtAnimation;
    for (int i = 4; i < 8; ++i) {
        hurtAnimation.addFrame(sf::IntRect (48 * i, 96, 48, 48));
    }
    hurtAnimation.setFrameDuration(0.1f);
    character.animations[AnimationType::HURT] = hurtAnimation;

// JUMPING ANIMATION
    Animation jumpingAnimation;
    for (int i = 0; i < 6; ++i) {
        jumpingAnimation.addFrame(sf::IntRect (48 * i, 144, 48, 48));
    }
    jumpingAnimation.setFrameDuration(0.1f);
    character.animations[AnimationType::JUMPING];

// ATTACK ANIMATION
    Animation attackAnimation;
    for (int i = 0; i < 6; ++i) {
        attackAnimation.addFrame(sf::IntRect (48 * i, 192, 48, 48));
    }
    attackAnimation.setFrameDuration(0.1f);
    character.animations[AnimationType::ATTACK];

// DEATH ANIMATION
    Animation deathAnimation;
    for(int i = 0; i < 6; ++i) {
        deathAnimation.addFrame(sf::IntRect (48 * i, 240, 48, 48));
    }
    deathAnimation.setFrameDuration(0.1f);
    character.animations[AnimationType::DEATH];

}

auto Boy::loadTexture() -> void {
    texture.loadFromFile("images/Main_characters/Char_boy.png");
    sprite.setTexture(texture);
/*    sprite.setTextureRect(sf::IntRect (0, 0, 48, 48));
    sprite.setPosition(500,500);*/
    sprite.setScale(5,5);
    addAnimations(*this);

}

auto Girl::loadTexture() -> void {
    texture.loadFromFile("images/Main_characters/Char_Girl.png");
    sprite.setTexture(texture);
   /* sprite.setTextureRect(sf::IntRect (0, 0, 48, 48));
    sprite.setPosition(500,500);*/
    sprite.setScale(5,5);
    addAnimations(*this);
}

auto Robot::loadTexture() -> void {
    texture.loadFromFile("images/Main_characters/Char_Robot.png");
    sprite.setTexture(texture);
/*    sprite.setTextureRect(sf::IntRect (0, 0, 48, 48));
    sprite.setPosition(500,500);*/
    sprite.setScale(5,5);
    addAnimations(*this);
}

/*struct Character {
    std::string name;
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Image image;

    virtual ~Character() {}

    virtual auto loadTexture() -> void = 0;


};*/

/*struct Boy : Character {
    auto loadTexture() -> void override {
        image.loadFromFile("images/Main_characters/Char_boy.png");
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect (0, 0, 48, 48));
        sprite.setPosition(500,500);
        sprite.setScale(5,5);
    }
};*/

/*struct Girl : Character {
    auto loadTexture() -> void override {
        image.loadFromFile("images/Main_characters/Char_Girl.png");

        texture = sf::Texture();
        texture.loadFromImage(image);

        sprite = sf::Sprite();
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect (0, 0, 48, 48));
        sprite.setPosition(500,500);
        sprite.setScale(5,5);
    }
};*/

/*
struct Robot : Character {
    auto loadTexture() -> void override {
        image.loadFromFile("images/Main_characters/Char_Robot.png");

        texture = sf::Texture();
        texture.loadFromImage(image);

        sprite = sf::Sprite();
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect (0, 0, 48, 48));
        sprite.setPosition(500,500);
        sprite.setScale(5,5);
    }
};*/
