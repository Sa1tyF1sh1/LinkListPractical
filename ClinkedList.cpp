#include "ClinkedList.h"
#include <iostream>

ClinkedList::ClinkedList()
{
	firstNode = nullptr;
	lastNode = nullptr;
}

ClinkedList::~ClinkedList()
{
	if (firstNode == nullptr)
	{
		// Link List is empty
		std::cout << "List Is Empth.";

	}
	else
	{
		// Link List is not empty
		CNode* currentNode = firstNode;

		while (currentNode != nullptr)
		{
			currentNode = currentNode->getNextPtr();
			delete firstNode;
			firstNode = currentNode;
		}
	}
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
	if (firstNode == nullptr)
	{
		//Link List is empty
		std::cout << "Nothing to delete";
	}
	else if (firstNode == lastNode)
	{
		//Link List only left with 1 node
		/*CNode* temp = firstNode;
		firstNode = firstNode->getNextPtr();*/
		delete firstNode;
		firstNode = nullptr;
		lastNode = nullptr;
	}
	else
	{
		CNode* temp = firstNode;
		firstNode = firstNode->getNextPtr();
		delete temp;
	}

}

void ClinkedList::deleteToListBack()
{
	if (firstNode == nullptr)
	{
		//Link List is empty
		std::cout << "Nothing to delete";
	}
	else if (firstNode = lastNode)
	{
		//Link List only left with 1 node
				/*CNode* temp = firstNode;
				firstNode = firstNode->getNextPtr();*/
		delete firstNode;
		firstNode = nullptr;
		lastNode = nullptr;
	}
	else
	{
		CNode* currentNode = firstNode;
		while (currentNode->getNextPtr() != lastNode)
		{
			currentNode = currentNode->getNextPtr();
		}
		delete lastNode;
		lastNode = currentNode;
		currentNode->setNextPtr(nullptr);
	}
}

void ClinkedList::DelValue(int _value)
{
	if (firstNode == nullptr)
	{
		std::cout << "Link List Is Empty" << '\n';
	}
	else
	{
		CNode* currentNode = firstNode;
		CNode* b4CurrentNode = nullptr;

		bool found = false;

		while (currentNode != nullptr)
		{
			if (currentNode->getData() == _value) 
			{
				found = true;
				
				break;
			}
			else
			{
				b4CurrentNode = currentNode;
				currentNode = currentNode->getNextPtr();
			}
		}
		//Try to match the no. that user want to delete
		if (!found)
		{
			std::cout << "Not Found!";
		}
		else
		{
			//If the value found at the first Line
			if (currentNode == firstNode)
			{
				deleteToListFront();
			}
			//If the value found at the last line
			else if(currentNode == lastNode)
			{
				deleteToListBack();
			}
			//If the value found at the middle of the list
			else
			{
				b4CurrentNode->setNextPtr(currentNode->getNextPtr());
				delete currentNode;
			}
		}
	}
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
				std::cout << '-';
			}
			tempPtr = tempPtr->getNextPtr();
		}
		std::cout << '\n';
	}
}