#include "Ground.h"
#include "Engine/Model.h"
#include "Engine/Debug.h"
#include "TestScene.h"

Ground::Ground(GameObject* parent)
{
}

void Ground::Initialize()
{
	hSilly = Model::Load("ground.fbx");
	Model::SetAnimFrame(hSilly, 0, 59, 1.0);
	bu = Model::Load("bevel-hq-brick-2x2.fbx");
	Model::SetAnimFrame(bu, 0, 59, 1.0);

}

void Ground::Update()
{
}

void Ground::Draw()
{
	transform_.position_ = { 0, -1.0f, 0 };
	transform_.scale_ = { 1.0f, 1.0f, 1.0f };
	Model::SetTransform(hSilly, transform_);
	Model::Draw(hSilly);

	// ブロック
	transform_.position_ = { 0, -1.0f, 0 };
	transform_.scale_ = { 0.3f, 0.3f, 0.3f };
	Model::SetTransform(bu, transform_);
	Model::Draw(bu);
}

void Ground::Release()
{
}
