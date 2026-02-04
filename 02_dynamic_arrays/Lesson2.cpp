#include <iostream>

// RAII
template <typename T>
class DynamicArray 
{
	T* m_array;
	size_t m_size;

public:

	DynamicArray(size_t size)
		: m_array(new T[size]())
		, m_size(size)
	{
		std::cout << "IntArray constructed." << std::endl;
	}

	// Deconstructor - c++ does not have its own garbage collector
	~DynamicArray() {
		delete [] m_array;
		std::cout << "IntArray excommunicado." << std::endl;
	}

	T get(size_t index) const
	{
		return m_array[index];
	}

	void set(size_t index, T value)
	{
		m_array[index] = value;
	}

	void print() 
	{
		for (size_t i = 0; i < m_size; i++)
		{
			std::cout << i << " " << m_array[i] << std::endl;
		}
	}

	/*
	Problem appears if we need to work with const lists so the first function
	below is a no-go, since we are rturning reference, and they are by themself changeable
	usage: 
	first func for setting
	second func for getting
	*/
	T & operator [](size_t index)
	{
		return m_array[index];
	}

	const T & operator [](size_t index) const
	{
		return m_array[index];
	}
};

int main(int argc, char * argv[]) {

	DynamicArray<float> dynamicArray(10);

	dynamicArray[2] = 6.13;
	dynamicArray.set(6, 137);

	std::cout << dynamicArray[2] << std::endl;

	//dynamicArray.print();

	return 0;
}