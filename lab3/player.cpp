#include "player.h"
#include "object.h"
#include <string>
#include <iostream>

using namespace lab3;

Player::Player() : Object() {
}

Player::Player(int x, int y) : Object(x, y) {
}

std::string Player::symbol() {
  return "X";
}

void Player::move_up() { x--; }
void Player::move_down() { x++; }
void Player::move_right() { y++; }
void Player::move_left() { y--; }
