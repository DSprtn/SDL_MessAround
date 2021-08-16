#pragma once
#include <vector>
#include <ECS\Component.h>
#include <string>
#include <typeinfo>
#include <iostream>

class Component;

class Entity
{
	public:
		Entity(std::string Name);
		~Entity();

		bool MarkedForDeletion;
		std::string Name;
		std::vector<Component*> Components;

		void Update();
		void OnRender();
		void Delete();

		template<typename T>
		T* GetComponent()
		{
			for (auto const component : Components) {
				if (typeid(T).name() == typeid(*component).name()) {
					return static_cast<T*>(component);
				}
			}
			return nullptr;
		}

		template <typename T, class... Args>
		T* AddComponent(Args&&... args) {
			T* component(new T(std::forward<Args>(args)...));
			Components.push_back(component);
			return component;
		}

	private:

		Entity(const Entity& that);
		Entity& operator=(const Entity& that);


};



