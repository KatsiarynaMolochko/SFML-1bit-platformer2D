//
// Created by Kate on 30.05.2024.
//
#include <SFML/Graphics.hpp>
#include "Animation.h"


Animation::Animation() : current_frame(0), frame_duration(0.1f), elapsed_time(0.0f) { }

auto Animation::addFrame(const sf::IntRect &rect) -> void {
    frames.push_back(rect);
}

auto Animation::update(float delta_time) -> void {
    elapsed_time += delta_time;
    if (elapsed_time >= frame_duration) {
        elapsed_time = 0.0f;
        current_frame = (current_frame + 1) % frames.size();
    }
}

auto Animation::getCurrentFrame() const -> sf::IntRect {
    return frames[current_frame];
}

auto Animation::setFrameDuration(float duration) -> void {
    frame_duration = duration;
}