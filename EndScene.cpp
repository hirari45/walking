#define _CRT_SECURE_NO_WARNINGS
#include "EndScene.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

EndScene::EndScene(GameObject* parent)
	:GameObject(parent, "EndScene")
{
}

void EndScene::Initialize()
{
}

void EndScene::Update()
{
    if (Input::IsKey(DIK_SPACE))
    {
        SceneManager* pSceneManager =
            dynamic_cast<SceneManager*>(GetParent());

        if (pSceneManager != nullptr)
        {
            pSceneManager->ChangeScene(SCENE_ID_TITLE);
        }
    }
}

void EndScene::Draw()
{
}

void EndScene::Release()
{
}
