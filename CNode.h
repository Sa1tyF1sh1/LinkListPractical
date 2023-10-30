#pragma once

class CNode					
{

	int dataNo;
	CNode* nextPtr;

public:
	CNode(int _data);

	int getData();
	void setData(int _number);

	CNode* getNextPtr();
	void setNextPtr(CNode* _nextPtr);

	void printNodeData();
};

