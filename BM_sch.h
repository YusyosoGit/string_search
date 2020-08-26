#ifndef _BM_SEARCH_H_
#define _BM_SEARCH_H_
#include "searchbase.h"
#include <map>
// Boyer-Moore 法
class BMSearch: public SearchBase
{
public:
	BMSearch(const char *keyword_);
	size_t exec(const char *text, size_t pos = 0U);
private:
	std::map<char, int> SkipTbl;	// スキップテーブル
	size_t Length;					// パターン文字に含まれないときのスキップ数
};

#endif  //_BM_SEARCH_H_
