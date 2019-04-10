#include"DxLib.h"
#include"main.h"
#include"scene_manager.h"
#include"scenemain.h"

//-----------------------------------------------------------------------------
//�v���g�^�C�v�錾
//-----------------------------------------------------------------------------

void Initialzie();
void Finalize();

//-----------------------------------------------------------------------------
//�O���[�o���ϐ�
//-----------------------------------------------------------------------------

SCENE_MANAGER *scene_mgr = NULL;



//-----------------------------------------------------------------------------
//���C������
//-----------------------------------------------------------------------------

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	//������
	ChangeWindowMode(TRUE);
	SetGraphMode(256, 256, 16);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);

	Initialzie();

	//���C�����[�v
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		
		
		scene_mgr->Update();

		scene_mgr->Draw();


	}
	//�I������
	Finalize();

	DxLib_End();
}

void Initialzie()
{
	scene_mgr = new SCENE_MANAGER;
	scene_mgr->SceneChange(new SCENEMAIN);		//�����V�[���o�^
	//srand((unsigned int)time(NULL));
}

void Finalize()
{
	if (scene_mgr != NULL)	delete scene_mgr;
}