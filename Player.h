#pragma once

class Player {
public:
    void Initialize();
    void Update(char* keys);
    void Draw();

    int GetX() const { return x_; }
    int GetY() const { return y_; }

private:
    int x_;     // プレイヤーのX座標
    int y_;     // プレイヤーのY座標
    int speed_; // 移動速度
};
