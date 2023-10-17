#pragma once
#include "Scene.h"

class DeadScene:public Scene
{
public:
	DeadScene();
	~DeadScene();

	virtual void Initiailize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Destroy() override;

private:
};

