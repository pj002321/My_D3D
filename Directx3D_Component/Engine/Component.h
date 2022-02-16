#pragma once

enum class COMPONENT_TYPE : uint8
{
	TRANSFORM,
	MESH_RENDERER,
	// ...
	MONO_BEHAVIOUR,
	END,
};

enum
{
	FIXED_COMPONENT_COUNT = static_cast<uint8>(COMPONENT_TYPE::END) - 1
};

class GameObject;
class Transform;


class Component
{
public:
	Component(COMPONENT_TYPE type); //컴포넌트 타입
	virtual ~Component(); // 메모리 릭 예방

public:
	virtual void Awake() { } //초기화
	virtual void Start() { }
	virtual void Update() { }
	virtual void LateUpdate() { } //업데이트 후 한번 더 호출 : 업데이트 시점 분리

public:
	COMPONENT_TYPE GetType() { return _type; }
	bool IsValid() { return _gameObject.expired() == false; } //gameobject가 소멸됐는지 체크

	shared_ptr<GameObject> GetGameObject();
	shared_ptr<Transform> GetTransform();

private:
	friend class GameObject;
	void SetGameObject(shared_ptr<GameObject> gameObject) { _gameObject = gameObject; }

protected:
	COMPONENT_TYPE _type;
	weak_ptr<GameObject> _gameObject;
	// weak_ptr : Component와 GameObject끼리 서로를 알게 하기 위해서

};

