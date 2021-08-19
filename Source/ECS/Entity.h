#pragma once
#include <Vector.h>
#include <Component.h>
#include <string>
#include <typeinfo>
#include <iostream>
#include <unordered_set>

class Component;
class TransformComponent;

class Entity
{
public:
	Entity(std::string Name, int sizeX, int sizeY);
	Entity(std::string Name);
	virtual ~Entity() = default;

	bool MarkedForDeletion;
	std::string Name;

	Vector<std::shared_ptr<Component>> Components;
	std::unordered_set<std::string> Tags;

	virtual void Update();
	virtual void LateUpdate();
	virtual void OnRender();
	virtual void Delete();
	virtual void OnCollide(Entity* B);

	void AddTag(std::string tag) {
		Tags.insert(tag);
	}

	void RemoveTag(std::string tag) {
		Tags.erase(tag);
	}

	bool HasTag(std::string tag) {
		return Tags.count(tag) > 0;
	}

	template<typename T>
	T* GetComponent()
	{
		for (unsigned int i = 0; i < Components.Count; i++) {
			Component* c = Components[i].get(); 
			if (typeid(T).name() == typeid(*c).name()) {
				return static_cast<T*>(c);
			}
		}
		return nullptr;
	}

	template <typename T, class... Args>
	std::weak_ptr<T> AddComponent(Args&&... args) {
		std::shared_ptr<T> shared = std::make_shared<T>(std::forward<Args>(args)...);
		Components.Add(shared);
		return shared;
	}

	TransformComponent* Transform;

private:

	Entity(const Entity& that);
	Entity& operator=(const Entity& that);


};



