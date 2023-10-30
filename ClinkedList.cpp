#include "ClinkedList.h"
#include <iostream>

ClinkedList::ClinkedList()
{
	firstNode = nullptr;
	lastNode = nullptr;
}

ClinkedList::~ClinkedList()
{

}

void ClinkedList::addToListFront(int _newData)
{
	if (firstNode == nullptr)
	{
		firstNode = new CNode(_newData);
		lastNode = firstNode;
	}
	else
	{
		CNode* temp = new CNode(_newData);
		temp->setNextPtr(firstNode);
		firstNode = temp;
	}
}

void ClinkedList::addToListBack(int _newData)
{
	if (firstNode == nullptr)
	{
		firstNode = new CNode(_newData);
		lastNode = firstNode;
	}
	else
	{
		CNode* temp = new CNode(_newData);
		lastNode->setNextPtr(temp);
		lastNode = temp;
	}
}

void ClinkedList::addToPosition(int _newData,int _pos)
{
	if (firstNode == nullptr)
	{
		firstNode = new CNode(_newData);
		lastNode = firstNode;
	}
	else
	{
		int moveCount = _pos - 2;
		if (_pos == 1)
		{
			addToListFront(_newData);
		}
		else
		{
			CNode* currentNode = firstNode;
			
			//Position the current ptr to the node b4 where we wish to insert

			while (moveCount > 0)
			{
				currentNode->getNextPtr();
				moveCount--;
			}

			if (currentNode == lastNode)
			{
				addToListBack(_newData);
			}
			else
			{
				CNode* temp = new CNode(_newData);
				temp->setNextPtr(currentNode->getNextPtr());
				currentNode->setNextPtr(temp);
			}	
		}
	}
}

void ClinkedList::deleteToListFront()
{

}
void ClinkedList::deleteToListBack()
{
	

}

void ClinkedList::printAllNodeData()
{
	CNode* tempPtr = firstNode;
	if (firstNode == nullptr)
	{
		std::cout << "Link List is empty." << '\n';
	}
	else
	{
		while (tempPtr != nullptr)
		{
			std::cout << tempPtr->getData();
			if (tempPtr != lastNode)
			{
				std::cout << '-' << '\n';
			}
			tempPtr = tempPtr->getNextPtr();
		}
		std::cout << '\n';
	}
}