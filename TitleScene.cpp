#define _CRT_SECURE_NO_WARNINGS
#include "TitleScene.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

TitleScene::TitleScene(GameObject* parent)
	:GameObject(parent, "TitleScene")
{
}

void TitleScene::Initialize()
{
}

void TitleScene::Update()
{
    if (Input::IsKey(DIK_SPACE))
    {
        SceneManager* pSceneManager =
            dynamic_cast<SceneManager*>(GetParent());

        if (pSceneManager != nullptr)
        {
            pSceneManager->ChangeScene(SCENE_ID_TEST);
        }
    }

}

void TitleScene::Draw()
{
}

void TitleScene::Release()
{
}
