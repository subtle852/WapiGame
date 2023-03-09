#pragma once
#include "yaGameObject.h"
#include "yaImage.h"

namespace ya
{
	class Obstacle01 : public GameObject
	{
	public:
		Obstacle01();
		Obstacle01(Vector2 pos);
		~Obstacle01();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

	private:
		Image* mImage;
	};
}