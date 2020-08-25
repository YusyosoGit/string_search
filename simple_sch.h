#ifndef _SIMPLE_SEARCH_CPP_
#define _SIMPLE_SEARCH_CPP_
#include "searchbase.h"

class SimpleSearch: public SearchBase
{
public:
	SimpleSearch(const char *keyword_): SearchBase(keyword_) {}
	size_t exec(const char *text, size_t pos = 0U);
};


// 与えられた地点からテキストの照合を開始する
// 戻り値は発見場所
// 見つからない場合変数の最大値
size_t SimpleSearch::exec(const char *text, size_t pos)// = 0U)
{
	const char *q = text + strlen(text) - strlen(Keyword);
	const char *p;
	const char *r, *pp;
	
	for (p = text+ pos; p <= q; p++) {
		for (r = Keyword, pp=p; *r; r++, pp++) {
			if (*r != *pp) break;
		}
		if (!*r) {
			return p- text;
		}
	}
	return (size_t)-1;// SIZE_MAX
}

#endif  //_SIMPLE_SEARCH_CPP_
