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
}

void Ground::Update()
{
}

void Ground::Draw()
{
	transform_.position_ = { 0, -1.0, 0 };
	Model::SetTransform(hSilly, transform_);
	Model::Draw(hSilly);
}

void Ground::Release()
{
}
