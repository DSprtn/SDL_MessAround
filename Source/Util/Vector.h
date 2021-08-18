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

	Vector()
	{
		m_elements = new T[5];
		m_size = 5;
		Count = 0;
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

	void Add(const T &elem)
	{
		if (m_size == Count) {
			Reserve(m_size * 2);
		}

		//std::cout << "Added elem, capacity: " << m_size << " new element count:" << Count + 1 << std::endl;

		m_elements[Count] = elem;
		Count++;
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

	unsigned int Count;

protected:

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

	T* m_elements;
	unsigned int m_size;


private:
	Vector(const Vector& that);
	Vector& operator=(const Vector& that);
};