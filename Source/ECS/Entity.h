#pragma once
#include <Vector.h>
#include <Component.h>
#include <string>
#include <typeinfo>
#include <iostream>
#include <unordered_set>

class Component;

class Entity
{
public:
	Entity(std::string Name);
	virtual ~Entity();

	bool MarkedForDeletion;
	std::string Name;

	Vector<Component*> Components;
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
			Component* c = Components[i]; 
			if (typeid(T).name() == typeid(*c).name()) {
				return static_cast<T*>(c);
			}
		}
		return nullptr;
	}

	template <typename T, class... Args>
	T* AddComponent(Args&&... args) {
		T* component(new T(std::forward<Args>(args)...));
		Components.Add(component);
		return component;
	}

private:

	Entity(const Entity& that);
	Entity& operator=(const Entity& that);


};



