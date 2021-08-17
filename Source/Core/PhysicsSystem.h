#pragma once
#include <vector>
#include <Collider.h>
class PhysicsSystem
{
	public:
		static PhysicsSystem* Instance;	
		std::vector<Collider*> Colliders;

		void RegisterCollider(Collider* col);
		void UnregisterCollider(Collider* col);

		void Update();

		PhysicsSystem();
		~PhysicsSystem();
};

