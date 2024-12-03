#include "Bullet.h"
#include "Novice.h"

void Bullet::Initialize(int startX, int startY) {
    x_ = startX;
    y_ = startY;
    speed_ = 10;
    active_ = true;
}

void Bullet::Update() {
    if (!active_) return;

    y_ -= speed_; // 弾丸は上方向に進む

    // 画面外に出たら非アクティブ化
    if (y_ < 0) {
        active_ = false;
    }
}

void Bullet::Draw() const{
    if (active_) {
        Novice::DrawBox(x_ - 5, y_ - 10, 10, 20, 0.0f, 0xFFFF00, kFillModeSolid);
    }
}
