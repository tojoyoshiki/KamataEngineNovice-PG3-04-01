#include "Player.h"
#include "Novice.h"

void Player::Initialize() {
    x_ = 400;   // 初期位置X
    y_ = 500;   // 初期位置Y
    speed_ = 5; // 移動速度
}

void Player::Update(char* keys) {
    if (keys[DIK_W]) y_ -= speed_;
    if (keys[DIK_S]) y_ += speed_;
    if (keys[DIK_A]) x_ -= speed_;
    if (keys[DIK_D]) x_ += speed_;

    // 画面外に出ないようにする
    if (x_ < 0) x_ = 0;
    if (x_ > 800) x_ = 800;
    if (y_ < 0) y_ = 0;
    if (y_ > 600) y_ = 600;
}

void Player::Draw() {
    Novice::DrawBox(x_ - 10, y_ - 10, 20, 20, 0.0f, 0xFFFFFF, kFillModeSolid);
}
