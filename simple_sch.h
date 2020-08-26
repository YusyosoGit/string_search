#ifndef _SIMPLE_SEARCH_H_
#define _SIMPLE_SEARCH_H_
#include "searchbase.h"

class SimpleSearch: public SearchBase
{
public:
	SimpleSearch(const char *keyword_): SearchBase(keyword_) {}
	size_t exec(const char *text, size_t pos = 0U);
};

#endif  //_SIMPLE_SEARCH_H_
