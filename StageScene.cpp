#include "StageScene.h"

void StageScene::Initialize() {
	// プレイヤー初期化
	player_.Initialize();

	// 敵初期化
	enemy_.Initialize(400, 200);  // 初期位置を設定}
}

void StageScene::Update(char* keys, char* preKeys) {

	if (sceneNo == STAGE) {
		// プレイヤー移動処理
		player_.Update(keys);

		// 弾丸発射処理
		if (keys[DIK_E] && !preKeys[DIK_E]) {
			Bullet newBullet;
			newBullet.Initialize(player_.GetX(), player_.GetY());
			bullets_.push_back(newBullet);
		}

		// 弾丸更新
		for (auto& bullet : bullets_) {
			bullet.Update();
		}

		// 敵移動処理
		enemy_.Update();

		// 当たり判定（弾丸と敵）
		for (auto it = bullets_.begin(); it != bullets_.end();) {
			if (enemy_.CheckCollision(it->GetX(), it->GetY())) {
				it = bullets_.erase(it);  // 弾丸を削除
				enemy_.Destroy();        // 敵を削除（フラグ設定）
			}
			else {
				++it;
			}
		}
		//この条件を敵が死んだときに変更
		if (!enemy_.IsAlive()) {
			//シーンをCLEARに変える
			sceneNo = CLEAR;
		}
	}
}

void StageScene::Draw() {
	if (sceneNo == STAGE) {
		Novice::ScreenPrintf(0, 0, "Stage Scene");
		Novice::ScreenPrintf(0, 30, "Push E");
		enemy_.Draw();
		player_.Draw();

		for (const auto& bullet : bullets_) {
			bullet.Draw();
		}
	}
}
