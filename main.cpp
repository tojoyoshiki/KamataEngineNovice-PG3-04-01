#include <Novice.h>
#include "GameManager.h"

const char kWindowTitle[] = "LE2C_17_トウジョウ_ヨシキ";

// Windowsアプリでのmain関数
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	//GameManegerクラスのインスタンスを作成する
	GameManager* gameManager = new GameManager();

	//GameManegerクラスからメンバ関数Runを呼び出す
	gameManager->Run();

	// ライブラリの終了
	Novice::Finalize();

	//GameManegerを解放
	delete gameManager;

	return 0;
}
