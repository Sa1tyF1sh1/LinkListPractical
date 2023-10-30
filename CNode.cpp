#include "CNode.h"
#include <iostream>

CNode::CNode(int _data)
{
	dataNo = _data;
	nextPtr = nullptr;
}

int CNode::getData()
{
	return dataNo;
}

void CNode::setData(int _number)
{
	dataNo = _number;
}

CNode* CNode::getNextPtr()
{
	return nextPtr;
}

void CNode::setNextPtr(CNode* _nextPtr)
{
	nextPtr = _nextPtr;
}

void CNode::printNodeData()
{
	std::cout << "Data Number: " << dataNo << '\n';
}
