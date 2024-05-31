//
// Created by Kate on 29.05.2024.
//
#pragma once
#ifndef SONIC2D_CHARACTER_H
#define SONIC2D_CHARACTER_H
#include <string>
#include "SFML/Graphics.hpp"
#include "Animation.h"


struct Character {
    std::string name;
    sf::Sprite sprite;
    sf::Texture texture;
    std::map<AnimationType, Animation> animations;
    AnimationType current_animation;


    virtual ~Character() {}

    virtual auto loadTexture() -> void = 0;

    auto update(float delta_time) -> void {
        animations[current_animation].update(delta_time);
        sprite.setTextureRect(animations[current_animation].getCurrentFrame());
    }

    auto setAnimation(AnimationType type) -> void {
        current_animation = type;
    }

};

auto addAnimations(Character& character) -> void;

struct Boy : Character {
    auto loadTexture() -> void override;
};

struct Girl : Character {
    auto loadTexture() -> void override;
};

struct Robot : Character {
    auto loadTexture() -> void override;
};

#endif //SONIC2D_CHARACTER_H
