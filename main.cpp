#include"DxLib.h"
#include"main.h"
#include"scene_manager.h"
#include"scenemain.h"

//-----------------------------------------------------------------------------
//プロトタイプ宣言
//-----------------------------------------------------------------------------

void Initialzie();
void Finalize();

//-----------------------------------------------------------------------------
//グローバル変数
//-----------------------------------------------------------------------------

SCENE_MANAGER *scene_mgr = NULL;



//-----------------------------------------------------------------------------
//メイン処理
//-----------------------------------------------------------------------------

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	//初期化
	ChangeWindowMode(TRUE);
	SetGraphMode(256, 256, 16);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);

	Initialzie();

	//メインループ
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		
		
		scene_mgr->Update();

		scene_mgr->Draw();


	}
	//終了処理
	Finalize();

	DxLib_End();
}

void Initialzie()
{
	scene_mgr = new SCENE_MANAGER;
	scene_mgr->SceneChange(new SCENEMAIN);		//初期シーン登録
	//srand((unsigned int)time(NULL));
}

void Finalize()
{
	if (scene_mgr != NULL)	delete scene_mgr;
}