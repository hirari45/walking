#include "Enemy.h"
#include "Engine/Model.h"
#include "Engine/Debug.h"
#include "TestScene.h"
#include "Engine/Input.h"
#include "Ground.h"

namespace
{
	std::vector<std::vector<int>> gmap;

}

Enemy::Enemy(GameObject* parent)
	:GameObject(parent), hWalkModel_(-1), hIdleModel_(-1)
{
}

void Enemy::Initialize()
{
	hWalkModel_ = Model::Load("enemy1.fbx");
	Model::SetAnimFrame(hWalkModel_, 0, 59, 1.0);

	if (ground_ != nullptr)
	{
		gmap = ground_->GetMapData();
	}
}

void Enemy::Update()
{
}

void Enemy::Draw()
{
	//transform_.scale_ = { 0.01,0.01,0.01 };

	transform_.position_ = { 0, 0, 0 };
	Model::SetTransform(hWalkModel_, transform_);
	Model::Draw(hWalkModel_);
}

void Enemy::Release()
{
}
