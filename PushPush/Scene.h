#pragma once
#include "Map.h"


// �߻�Ŭ���� ( ���������Լ��� �ϳ��� ��� ������ )
class Scene
{
public:
	Scene();
	~Scene();

	// ���������Լ�
	virtual void Initiailize() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Destroy() = 0;

protected:
	Map* mMap;
};

