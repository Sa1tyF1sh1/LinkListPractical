#include <iostream>	
#include "ClinkedList.h"

int main()
{
	ClinkedList gd23;
	
	gd23.addToListBack(11);
	gd23.addToListBack(22);
	gd23.addToListBack(33);
	gd23.addToListBack(44);
	gd23.addToListBack(55);

	gd23.printAllNodeData();

	gd23.DelValue(44);

	gd23.printAllNodeData();

	return 0;
}