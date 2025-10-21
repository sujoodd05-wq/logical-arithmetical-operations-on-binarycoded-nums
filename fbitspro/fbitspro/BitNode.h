#pragma once
class BitNode
{
public:
	bool bit;
	BitNode* next;
	BitNode(bool b = 0)
	{
		next = nullptr;
		bit = b;
	}

};

