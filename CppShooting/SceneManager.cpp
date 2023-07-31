#include"DxLib.h"
#include<time.h>
#include "SceneManager.h"

SceneBase* SceneManager::Update()
{
	SceneBase* NextScene;
	try
	{
		NextScene = mScene->Update();
	}
	catch (const char* err)
	{
		FILE* fp = NULL;

		DATEDATA data;

		GetDateTime(&data);

		return nullptr;
	}

	if (NextScene != mScene)
	{
		delete mScene;
		mScene = NextScene;
	}
	return mScene;
}
void SceneManager::Draw() const
{
	mScene->Draw();
}

