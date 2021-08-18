#pragma once
#include <vector>
#include <Component.h>
#include <string>
#include <typeinfo>
#include <iostream>

class Component;

class Entity
{
public:
	Entity(std::string Name);
	virtual ~Entity();

	bool MarkedForDeletion;
	std::string Name;

	Component** Components = new Component * [32];

	virtual void Update();
	virtual void LateUpdate();
	virtual void OnRender();
	virtual void Delete();
	virtual void OnCollide(Entity* B);

	template<typename T>
	T* GetComponent()
	{
		for (unsigned int i = 0; i < ComponentCount; i++) {
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
		Components[ComponentCount] = component;
		ComponentCount++;
		return component;
	}

protected:
	unsigned int MaxComponents = 32;
	unsigned int ComponentCount = 0;

private:

	Entity(const Entity& that);
	Entity& operator=(const Entity& that);


};



