#pragma once
#include <SFML/Graphics.hpp>

sf::View view;

auto getPlayerCoordinateForView(float x, float y) -> sf::View {
    view.setCenter(x + 100, y);
    return view;
}