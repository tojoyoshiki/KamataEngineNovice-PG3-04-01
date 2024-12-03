#include "Enemy.h"
#include "Novice.h"

void Enemy::Initialize(int startX, int startY) {
    x_ = startX;
    y_ = startY;
    speed_ = 3;
    direction_ = 1; // 初期方向は右
    alive_ = true;
}

void Enemy::Update() {
    if (!alive_) return;

    // 左右に移動
    x_ += speed_ * direction_;

    // 画面端で反転
    if (x_ < 0 || x_ > 800) {
        direction_ *= -1;
    }
}

void Enemy::Draw() {
    if (alive_) {
        Novice::DrawBox(x_ - 15, y_ - 15, 30, 30, 0.0f, 0xFF0000, kFillModeSolid);
    }
}

bool Enemy::CheckCollision(int bulletX, int bulletY) {
    if (!alive_) return false;

    // 簡易的な当たり判定
    int dx = bulletX - x_;
    int dy = bulletY - y_;
    int distanceSquared = dx * dx + dy * dy;
    int radiusSquared = 15 * 15; // 敵の半径

    return distanceSquared <= radiusSquared;
}

void Enemy::Destroy() {
    alive_ = false;
}
