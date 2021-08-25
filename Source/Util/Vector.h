#pragma once
#include <exception>
#include <iostream>

template<class T>
class Vector
{
public:

	~Vector() 
	{
		delete[] m_elements;
	}

	Vector(unsigned int size = 5)
		: Count(0)
		, m_size(size)
		, m_elements(new T[m_size])
	{}

	Vector(Vector const& copy)
		: Count(copy.Count)
		, m_size(copy.m_size)
		, m_elements(new T[m_size])
	{
		for (int i = 0; i < copy.Count; i++) {
			m_elements[i] = std::move(copy.m_elements[i]);
		}
	}

	Vector(Vector&& move)
		: m_size(0)
		, Count(0)
		, m_elements(nullptr)
	{
		swap(move);
	}

	Vector& operator=(Vector const& copy) {
		if (this == &copy) {
			return *this;
		}
		// If we have enough space allocated we can clear all current elements and assign the new ones to the existing memory.
		if (m_size >= copy.Count) {

			for (int i = Count; i-- > 0;) {
				m_elements[i].~T();
			}
			for (int i = 0; i < copy.Count; i++) {
				m_elements[i] = std::move(copy.m_elements[i]);
			}
			Count = copy.Count;
		}
		else 
		{	
			// If we don't have enough space we can use the copy&swap idiom to construct and fill a new suitable vector for us
			// through the copy ctor, which we can then swap data with
			Vector<T> tmp(copy);
			swap(tmp);
		}
		return *this;
	}

	Vector& operator=(Vector&& move)
	{
		swap(move);
		return *this;
	}

	T operator [] (int i) const {
		if (i <= Count && i >= 0) {
			return m_elements[i];
		}
		throw std::exception("Tried to access out of bounds element!");
	}

	T& operator [] (int i) {
		if (i <= Count && i >= 0) {
			return m_elements[i];
		}
		throw std::exception("Tried to access out of bounds element!");
	}

	void Add(const T& elem)
	{
		if (m_size == Count) {
			Reserve(m_size * 2);
		}
		m_elements[Count] = elem;
		Count++;
	}

	void Add(T&& elem)
	{
		if (m_size == Count) {
			Reserve(m_size * 2);
		}
		m_elements[Count] = std::move(elem);
		Count++;
	}

	template<typename... Args>
	T& AddInPlace(Args&&... args) {
		if (m_size == Count) {
			Reserve(m_size * 2);
		}
		new(&m_elements[Count]) T(std::forward<Args>(args)...);
		return m_elements[Count++];
	}

	void Clear() {
		for (int i = Count; i-- > 0;) {
			m_elements[i].~T();
		}
		Count = 0;
	}

	int GetIndex(const T& elem) {
		for (int i = 0; i < Count; i++) {
			if (m_elements[i] == elem) {
				return i;
			}
		}
		throw std::exception("Element not inside of array!");
	}

	void Erase(const T &elem)
	{
		for (int i = 0; i < Count; i++) {
			if (m_elements[i] == elem) {
				EraseAt(i);
				return;
			}
		}
		throw std::exception("Element not inside of array!");
	}

	void EraseAt(int index) {
		if (index < 0 || index > Count) {
			throw std::exception("Trying to erase outside of bounds!");
		}
		m_elements[index].~T();
		for (++index; index < Count; index++) {
			m_elements[index - 1] = std::move(m_elements[index]);
		}
		m_elements[index].~T();
		Count--;
	}

	void Reserve(unsigned int size)
	{
		if (size < m_size) {
			return;
		}
		T* newElem = new T[size];
		for (int i = 0; i < Count; i++) {
			newElem[i] =  std::move(m_elements[i]);
		}

		m_size = size;
		delete[] m_elements;
		m_elements = newElem;
	}

	void swap(Vector& other)
	{
		std::swap(m_size, other.m_size);
		std::swap(Count, other.Count);
		std::swap(m_elements, other.m_elements);
	}

	int Count;

protected:
	int m_size;
	T* m_elements;

};

