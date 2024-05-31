//
// Created by Kate on 30.05.2024.
//
#pragma once
#ifndef SONIC2D_ANIMATION_H
#define SONIC2D_ANIMATION_H
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "AnimationType.h"


struct Animation {
    std::vector<sf::IntRect> frames;
    int current_frame;
    float frame_duration;
    float elapsed_time;

    Animation();

    auto addFrame(const sf::IntRect& rect) -> void;
    auto update(float deltaTime) -> void;
    auto getCurrentFrame() const -> sf::IntRect;
    auto setFrameDuration(float duration) -> void;


};

#endif //SONIC2D_ANIMATION_H
