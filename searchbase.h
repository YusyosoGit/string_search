#ifndef _SEARCH_BASE_H_
#define _SEARCH_BASE_H_
#include <stdlib.h>
#include <string.h>

class SearchBase
{
public:
	SearchBase();
	SearchBase(const char *keyword_);
	void setKeyword(const char *keyword_);
	virtual ~SearchBase();

	virtual size_t exec(const char *text, size_t pos=0U) = 0;
protected:
	char *Keyword;
};

#endif		// _SEARCH_BASE_H_
