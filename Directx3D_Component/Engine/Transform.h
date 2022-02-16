#pragma once
#include "Component.h"

struct TransformMatrix
{
	Vec4 offset;
};


class Transform : public Component
{
public:
	Transform();
	virtual ~Transform();

	//todo : 온갖 부모/자식 관계

private:
	//todo : World위치 관련
};

