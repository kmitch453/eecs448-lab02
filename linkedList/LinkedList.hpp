/**
*	@author (kinda) KayLee Mitchell
*	@date due 2/14/2021
*	@file LinkedList.hpp
*	@brief Implementation file for templated LinkedList class
*/

template <typename T>
LinkedList<T>::LinkedList() : m_front(nullptr), m_size(0)
{

}

template <typename T>
LinkedList<T>::~LinkedList() 
{
	while(!isEmpty())
	{
		removeFront();
	}
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
	return(m_size == 0);
}

template <typename T>
int LinkedList<T>::size() const
{
	return(m_size);
}

template <typename T>
bool LinkedList<T>::search(T value) const
{
	Node<T>* temp = m_front;
	T actual;
	bool isFound = false;
	
	for(int i=1; i<m_size; i++)
	{
		actual = temp->getValue();
		if(actual == value)
		{
			isFound = true;
			break;
		}
		else
		{
			temp = temp->getNext();
			if(temp == nullptr)
			{
				break;
			}
		}
	}

	return(isFound);
}

template <typename T>
std::vector<T> LinkedList<T>::toVector() const
{
	std::vector<T> vec;
	Node<T>* temp = m_front;

	while( temp != nullptr )
	{
		vec.push_back(temp->getValue());
		temp = temp->getNext();
	}

	return(vec);	
	
}

template <typename T>
void LinkedList<T>::addBack(T value)
{
	Node<T>* temp = nullptr;

	if(isEmpty())
	{
		m_front = new Node<T>(value);	
	}
	else
	{
		temp = m_front;
		while(temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}

		temp->setNext( new Node<T>(value) );		
	}

	m_size++;
}

template <typename T>
void LinkedList<T>::addFront(T value)
{
	Node<T>* temp = m_front;
	m_front = new Node<T>(value);
	m_front->setNext( temp );
	m_size++;
}

template <typename T>
bool LinkedList<T>::removeBack()
{
	Node<T>* lastNode = nullptr;
	Node<T>* secondintoLast = nullptr;
	Node<T>* temp = nullptr;
	bool isRemoved = false;
	
	if(!isEmpty())
	{
		if(m_size == 1)
		{
			isRemoved = removeFront();
		}
		
		else if(m_size == 2)
		{
			temp = m_front->getNext();
			delete temp;
			m_size--;
			isRemoved = true;
		}
		
		else
		{
			lastNode = m_front->getNext();
			secondintoLast = m_front;
			temp = lastNode->getNext();
			
			for(int i=1; i<(m_size-2); i++)
			{
				lastNode = lastNode->getNext();
				secondintoLast = secondintoLast->getNext();
				temp = temp->getNext();
			}
			
			delete temp;
			m_size--;
			isRemoved = true;
		}
		
	return(isRemoved);
}	

template <typename T>
bool LinkedList<T>::removeFront()
{
	Node<T>* temp = nullptr;
	bool isRemoved = false;

	if(!isEmpty())
	{
		temp = m_front;
		m_front = temp->getNext();
		delete temp;
		m_size--;
		isRemoved = true;
	}

	return(isRemoved);
}
