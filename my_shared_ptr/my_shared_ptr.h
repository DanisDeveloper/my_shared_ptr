#ifndef _MY_SHARED_PTR_
#define _MY_SHARED_PTR_

 // not for array
template<class T>
class my_shared_ptr
{
private:

	T* m_ptr;
	int count = 0;

public:

	my_shared_ptr(T* ptr = nullptr);
	my_shared_ptr(const my_shared_ptr<T>& ptr);
	my_shared_ptr& operator=(const my_shared_ptr<T>& ptr)
	{
		if (m_ptr == ptr.m_ptr)
			return *this;

		delete m_ptr;
		m_ptr = ptr.m_ptr;
		count = ptr.count;
		++count;
		return *this;
	}


	T& operator*() const { return *m_ptr; }
	T* operator->()const { return m_ptr; }

	bool isNull() const { return (m_ptr == nullptr); }

	~my_shared_ptr();

};

template<class T>
my_shared_ptr<T>::my_shared_ptr(T* ptr ) 
{
	if (m_ptr)
	{
		++count;
	}
}
                   
template<class T>
my_shared_ptr<T>::my_shared_ptr(const my_shared_ptr<T>& ptr)
{
	m_ptr = ptr.m_ptr;
	count = ptr.count;
	++count;
}

template<class T>
my_shared_ptr<T>::~my_shared_ptr() {
	if (count == 1)
		delete m_ptr;
	else
	{
		--count;
	}
}





  // for array
template<class T>
class my_shared_ptr<T[]>
{
private:

	T* m_ptr;
	int count = 0;

public:

	my_shared_ptr(T* ptr = nullptr);
	my_shared_ptr(const my_shared_ptr<T[]>& ptr);
	my_shared_ptr& operator=(const my_shared_ptr<T[]>& ptr)
	{
		if (m_ptr == ptr.m_ptr)
			return *this;

		delete m_ptr;
		m_ptr = ptr.m_ptr;
		count = ptr.count;
		++count;
		return *this;
	}


	T& operator*() const { return *m_ptr; }
	T* operator->()const { return m_ptr; }
	T& operator[](const int& number) { return m_ptr[number]; }

	bool isNull() const { return (m_ptr == nullptr); }

	~my_shared_ptr();

};

template<class T>
my_shared_ptr<T[]>::my_shared_ptr(T* ptr) :m_ptr(ptr)
{
	if (m_ptr)
	{
		++count;
	}
}

template<class T>
my_shared_ptr<T[]>::my_shared_ptr(const my_shared_ptr<T[]>& ptr)
{
	m_ptr = ptr.m_ptr;
	count = ptr.count;
	++count;
}

template<class T>
my_shared_ptr<T[]>::~my_shared_ptr()
{
	if (count == 1)
		delete[] m_ptr;
	else
	{
		--count;
	}
}

#endif