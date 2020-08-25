#include "searchbase.h"

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

