#pragma once
#include <memory>
#include "IScene.h"
#include "TitleScene.h"
#include "StageScene.h"
#include "ClearScene.h"

/// GameManegerクラス
class GameManager
{
private:
	//シーン保持メンバ関数
	std::unique_ptr<IScene> sceneArr_[3];

	//現在のシーン
	int currentSceneNo_;

	//1つ前のシーン
	int prevSceneNo_;

public:
	GameManager(); //コンストラクタ
	~GameManager(); //デストラクタ

	//ゲームループで呼び出す関数
	int Run();
};

