#include "DeadScene.h"
#include "Application.h"

DeadScene::DeadScene()
{
}

DeadScene::~DeadScene()
{
}

void DeadScene::Initiailize()
{
	
}

void DeadScene::Update()
{
}

void DeadScene::Render()
{
	short x = SIZE_MAP_X * 2;
	short y = 10;

	SET_COLOR(COLOR::DARK_YELLOW);
	GOTO_XY(x, (y + 2));   std::wcout << (L"旨收收收收收收收收收收收收收收收收旬");
	GOTO_XY(x, (y + 3));   std::wcout << (L"早    YOU  DEAD   早");
	GOTO_XY(x, (y + 4));   std::wcout << (L"曲收收收收收收收收收收收收收收收收旭");
}

void DeadScene::Destroy()
{
}
