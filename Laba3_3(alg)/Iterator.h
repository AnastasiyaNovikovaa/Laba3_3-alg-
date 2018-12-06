#pragma once
//Итератор - структура данных, которая предоставляет доступ к элементам коллекции и навигацию по ним.

class Iterator
{
public:
	virtual ~Iterator() = default;
	virtual int next() = 0;
	virtual bool has_next() = 0;
	
};