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
	GOTO_XY(x, (y + 2));   std::wcout << (L"������������������������������������");
	GOTO_XY(x, (y + 3));   std::wcout << (L"��    YOU  DEAD   ��");
	GOTO_XY(x, (y + 4));   std::wcout << (L"������������������������������������");
}

void DeadScene::Destroy()
{
}
