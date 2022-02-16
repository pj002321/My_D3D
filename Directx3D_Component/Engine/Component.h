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
	Component(COMPONENT_TYPE type); //������Ʈ Ÿ��
	virtual ~Component(); // �޸� �� ����

public:
	virtual void Awake() { } //�ʱ�ȭ
	virtual void Start() { }
	virtual void Update() { }
	virtual void LateUpdate() { } //������Ʈ �� �ѹ� �� ȣ�� : ������Ʈ ���� �и�

public:
	COMPONENT_TYPE GetType() { return _type; }
	bool IsValid() { return _gameObject.expired() == false; } //gameobject�� �Ҹ�ƴ��� üũ

	shared_ptr<GameObject> GetGameObject();
	shared_ptr<Transform> GetTransform();

private:
	friend class GameObject;
	void SetGameObject(shared_ptr<GameObject> gameObject) { _gameObject = gameObject; }

protected:
	COMPONENT_TYPE _type;
	weak_ptr<GameObject> _gameObject;
	// weak_ptr : Component�� GameObject���� ���θ� �˰� �ϱ� ���ؼ�

};

