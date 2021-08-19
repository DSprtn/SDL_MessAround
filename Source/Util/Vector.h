#pragma once
#include <exception>
#include <iostream>

template<class T>
class Vector
{
public:

	~Vector() { delete[] m_elements; }

	Vector(unsigned int size)
	{
		m_elements = new T[size];
		m_size = size;
		Count = 0;
	}

	Vector() : Vector(5) {};

	Vector(const Vector& that) {
		m_size = that.m_size;
		m_elements = new T[m_size];

		for (int i = 0; i < that.Count; i++) {
			m_elements[i] = that[i];
		}
		Count = that.Count;
	}

	Vector& operator=(Vector that) {
		this->swap(that);
		return *this;
	}

	Vector& operator=(Vector&& that)
	{
		this->swap(that);
		return *this;
	}

	Vector(Vector&& that)
		: m_size(0)
		, Count(0)
		, m_elements(nullptr)
	{
		this->swap(that);
	}

	T operator [] (int i) const { 
		if (i <= Count) {
			return m_elements[i];
		}
		throw std::exception("Tried to access out of bounds element!");
	}

	T& operator [] (int i) {
		if (i <= Count) {
			return m_elements[i];
		}
		throw std::exception("Tried to access out of bounds element!");
	}

	void Add(T const& elem)
	{
		if (m_size == Count) {
			Reserve(m_size * 2);
		}
		m_elements[Count] = elem;
		Count++;
	}

	void Clear() {
		for (int i = 0; i < Count; i++) {
			m_elements[i].~T();
		}
		Count = 0;
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
			m_elements[index-1] = m_elements[index];
		}
		Count--;
	}

	void Reserve(unsigned int size)
	{
		if (size < m_size) {
			return;
		}
		T* newElem = new T[size];
		for (int i = 0; i < Count; i++) {
			newElem[i] = m_elements[i];
		}

		m_size = size;
		delete[] m_elements;
		m_elements = newElem;
	}

	int Count;

protected:
	int m_size;
	T* m_elements;

};