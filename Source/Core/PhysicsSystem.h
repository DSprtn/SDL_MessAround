#pragma once
#include <Vector.h>
#include <Collider.h>
class PhysicsSystem
{
public:
	static PhysicsSystem* Instance;	
	Vector<Collider*> Colliders;

	void RegisterCollider(Collider* col);
	void UnregisterCollider(Collider* col);

	void Update();

	PhysicsSystem();
	~PhysicsSystem();
};

