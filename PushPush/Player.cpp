#include "Player.h"
#include "Map.h"
#include "Ball.h"

Player::Player()
{
	mCh = L'��';
	mPos.y = 4;
	mPos.x = 4;
	mStepCount = 0;
}

Player::Player(Pos pos)
{
	mCh = L'��';
	mPos.y = pos.y;
	mPos.x = pos.x;
	mStepCount = 0;
}

Player::~Player()
{

}

void Player::Update(Map* map)
{
	Pos prevPos = mPos;
	DIRECTION dir = InputProcess();

	// �÷��̾� �� �浹 üũ
	if (map->IsBarrier(mPos)) //���̸� ���̴�
	{
		mPos = prevPos;
	}

	OnCollisionBalls(map, dir, prevPos);


	map->SetGameObjectInMap(mCh, mPos, prevPos);
}

void Player::Render()
{

}

DIRECTION Player::InputProcess()
{
	DIRECTION dir = DIRECTION::NONE;

	if (_kbhit())
	{        //Ű���� �Է� Ȯ�� (true / false)
		char input = _getch();

		dir = Move(input, mPos);
		mStepCount++;

		Beep(800, 100);
	}

	return dir;
}

void Player::OnCollisionBalls(Map* map, DIRECTION dir, Pos& prevPos)
{
	// �� �̶� �÷��̾� �浹üũ
	std::list<Ball*>& balls = Ball::GetBalls();
	for (std::list<Ball*>::iterator iter = balls.begin()
		; iter != balls.end()
		; iter++)
	{
		Pos ballPos = (*iter)->GetPos();
		Pos prevBallPos = ballPos;
		if (mPos == ballPos)
		{
			Move(dir, ballPos);

			// �� ���浹 üũ
			if (map->GetPixel(ballPos) == L'��'
				|| map->GetPixel(ballPos) == L'��')
			{
				ballPos = prevBallPos;

				// �÷��̾ �������� ���ϰ� �����־�� �Ѵ�.
				mPos = prevPos;
			}

			(*iter)->SetPos(ballPos);
			map->SetGameObjectInMap((*iter)->GetWChar_t(), ballPos, prevBallPos);
		}
	}
}
