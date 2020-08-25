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

SearchBase::SearchBase()
{
	Keyword = new char[1];
	*Keyword = '\0';
}

SearchBase::SearchBase(const char *keyword_)
{
	Keyword = NULL;
	setKeyword(keyword_);
}

void SearchBase::setKeyword(const char *keyword_)
{
	if (Keyword) {
		delete [] Keyword;
	}
	
	size_t sz = strlen(keyword_);
	Keyword = new char[++sz];
	strcpy(Keyword, keyword_);
}

SearchBase::~SearchBase()
{
	delete [] Keyword;
}

#endif		// _SEARCH_BASE_H_
