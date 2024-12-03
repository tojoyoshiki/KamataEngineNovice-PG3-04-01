#pragma once

class Enemy {
public:
    void Initialize(int startX, int startY);
    void Update();
    void Draw();
    bool CheckCollision(int bulletX, int bulletY);
    void Destroy();

    bool IsAlive() const { return alive_; }

private:
    int x_;        // 敵のX座標
    int y_;        // 敵のY座標
    int speed_;    // 移動速度
    bool alive_;   // 生存フラグ
    int direction_; // 移動方向（1:右, -1:左）
};
