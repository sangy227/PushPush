#include "TitleScene.h"
#include "Application.h"


TitleScene::TitleScene()
{
}

TitleScene::~TitleScene()
{
}

void TitleScene::Initiailize()
{

}

void TitleScene::Update()
{
    if (_kbhit())
    {        //Ű���� �Է� Ȯ�� (true / false)
		char input = _getch();
		if (input == '\r')
		{
			system("cls");
			SET_COLOR(COLOR::BLACK);
			Application::GetInstance()->SetPlaySceneNumber(SCENETYPE::PLAY);
		}
    }
}

void TitleScene::Render()
{
	short x = SIZE_MAP_X * 2;
	short y = 10;

	SET_COLOR(COLOR::SKY_BLUE);
	GOTO_XY((x + 2), (y + 1));   std::wcout << (L"P U S H  P U S H");
	SET_COLOR(COLOR::DARK_YELLOW);
	GOTO_XY(x, (y + 2));   std::wcout << (L"������������������������������������");
	GOTO_XY(x, (y + 3));   std::wcout << (L"��P U S H  P U S H��");
	GOTO_XY(x, (y + 4));   std::wcout << (L"�� made by AR 44th��");
	GOTO_XY(x, (y + 5));   std::wcout << (L"������������������������������������");

	GOTO_XY(x, (y + 8));   std::wcout << (L"   PRESS ENTER");
	SET_COLOR(COLOR::YELLOW);
	

	// ��¦�Ÿ��� ȿ��
	int to_add = 0;
	int cur_color = 0;
	while (true)
	{
		GOTO_XY((x - 7), (y + 9));
		for (to_add = 0; to_add < 37; to_add++)
		{
			SET_COLOR((cur_color + to_add) % 16 * 16);
			std::wcout << L" ";
		}
		if (cur_color > 0)
			cur_color--;
		else
			cur_color = 15;
		Sleep(100);

		if (_kbhit())
		{
			break;
		}
	}

}

void TitleScene::Destroy()
{
}
