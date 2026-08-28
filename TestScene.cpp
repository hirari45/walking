#define _CRT_SECURE_NO_WARNINGS
#include "TestScene.h"
#include "Player.h"
#include "Ground.h"
#include "Enemy.h"
#include "Engine/Camera.h"
#include "Engine/Text.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

namespace
{
	int myScore = 10;
}
//コンストラクタ
TestScene::TestScene(GameObject * parent)
	: GameObject(parent, "TestScene")
{
}

//初期化
void TestScene::Initialize()
{	
	//pWp = Instantiate<Weapon>(this);
	Player* pPlayer = Instantiate <Player>(this);
	//Enemy* pEnemy = Instantiate<Enemy>(this);
	Ground* pGround = Instantiate <Ground>(this);
	pPlayer->SetGround(pGround);
	//pEnemy->SetGround(pGround);

	Camera::SetPosition({ 0, 10, -20 });
	Camera::SetTarget({ 0, 0, 0 });

	pText_ = new Text;
	pText_->Initialize();
}

//更新
void TestScene::Update()
{
	if (Input::IsKey(DIK_SPACE))
	{
		SceneManager* pSceneManager =
			dynamic_cast<SceneManager*>(GetParent());

		if (pSceneManager != nullptr)
		{
			pSceneManager->ChangeScene(SCENE_ID_END);
		}
	}
}

//餌をかぞえて、残り餌数を表示
//スコアを表示
//やり方は任せる
//sprintfでcの文字列を時価で作ってもいいよ

//描画
void TestScene::Draw()
{
	std::string scrText;
	char buffer[256];
	sprintf(buffer, "SCORE:%010d", myScore);
	scrText = "SCORE" + std::string(buffer);
	pText_->Draw(500, 50, scrText.c_str());
}

//開放
void TestScene::Release()
{
	pText_->Release();
}
