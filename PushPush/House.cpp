#include "House.h"
#include "Map.h"

House::House()
{
	mPos = Pos(-1, -1);
	mCh = L'��';
}

House::House(Pos pos)
{
	mPos = pos;
	mCh = L'��';
}

House::~House()
{

}

void House::Update(Map* map)
{
	Pos prevPos = mPos;
	map->SetGameObjectInMap(mCh, mPos, prevPos);
}

void House::Render()
{

}
