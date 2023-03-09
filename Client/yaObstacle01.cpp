#include "yaObstacle01.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"
#include "yaAnimator.h"
#include "yaCollider.h"
//#include "yaBaseBullet.h"
#include "yaScene.h"


namespace ya
{
	Obstacle01::Obstacle01()
	{
	}
	Obstacle01::Obstacle01(Vector2 pos)
	{
		Transform* tr = GetComponent<Transform>();
		tr->SetPos(Vector2(pos.x, pos.y));
	}
	Obstacle01::~Obstacle01()
	{
	}
	void Obstacle01::Initialize()
	{
		mImage = Resources::Load<Image>(L"Land1Slide01", L"..\\Resources\\land1\\land1_sl_0001.bmp");

		Collider* collider = AddComponent<Collider>();
		collider->SetSize(Vector2(120.0f, 200.0f));
		collider->SetCenter(Vector2(20.0f, 300.0f));

		GameObject::Initialize();
	}
	void Obstacle01::Update()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();
		pos.x -= 10.0f;

		tr->SetPos(pos);

		GameObject::Update();
	}
	void Obstacle01::Render(HDC hdc)
	{
		GameObject::Render(hdc);

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		TransparentBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight()
			, mImage->GetHdc(), 0, 0, mImage->GetWidth(), mImage->GetHeight(), RGB(170, 0, 0));
	}
	void Obstacle01::Release()
	{
		GameObject::Release();
	}
}