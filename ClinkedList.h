#pragma once
#include "CNode.h"

class ClinkedList
{

	CNode* firstNode;
	CNode* lastNode;
public:
	ClinkedList();
	~ClinkedList();

	void addToListFront(int _newData);
	void addToListBack(int _newData);

	void addToPosition(int _newData, int _pos);

	void deleteToListFront();
	void deleteToListBack();

	void printAllNodeData();

};

