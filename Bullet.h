#pragma once

class Bullet {
public:
    void Initialize(int startX, int startY);
    void Update();
    void Draw() const; // 修飾子を追加

    int GetX() const { return x_; }
    int GetY() const { return y_; }
    bool IsActive() const { return active_; }

private:
    int x_;         // 弾丸のX座標
    int y_;         // 弾丸のY座標
    int speed_;     // 移動速度
    bool active_;   // 弾丸の有効フラグ
};
