#pragma once
#include"scene.h"

class SCENE_MANAGER
{
private:
	SCENE *scene = NULL;

public:
	void SceneChange(SCENE* s)
	{
		if (scene != NULL)	delete scene;
		scene = s;
		scene->Initialize();
	}
	void Initialize()
	{
		scene->Initialize();
	}
	void Update()
	{
		scene->Update();
	}
	void Draw()
	{
		scene->Draw();
	}
	SCENE* GetScene()
	{
		return scene;
	}
};