#include "BM_sch.h"
#include <iostream>

/* ボイヤー・ムーア法と呼ばれるアルゴリズム
 * 応用情報技術者試験対策 午後問題６章の３番目の問題を元に制作
 */
BMSearch::BMSearch(const char *keyword_):
SearchBase(keyword_)
{
	size_t len = strlen(keyword_);

	for (size_t pos=0; pos < len-1; pos++) {
		SkipTbl[*(keyword_+pos)] = len - 1 - pos;
	}
	Length = len;
	
#if 0
	// デバッグ用：内部処理表示
	std::map<char, int>::iterator it;
	for (it = SkipTbl.begin(); it!= SkipTbl.end(); it++) {
		std::cout << (*it).first << ":" << (*it).second << std::endl;
	}
	std::cout << "word_length: " << Length << std::endl;

	it = SkipTbl.find('x');
	if (it == SkipTbl.end()) {
		std::cout << "'x' is not included." << std::endl;
	}
#endif

}

size_t BMSearch::exec(const char *text, size_t pos)
{
	const char *q = text + strlen(text) - Length;
	const char *p;
	const char *r, *pp;
	std::map<char, int>::iterator it;

	for (p = text+ pos; p <= q; ) {
		for (r = Keyword, pp=p; *r; r++, pp++) {
			if (*r != *pp) break;        
		}
		if (!*r) {
			return p- text;
		}
		it = SkipTbl.find(*(p + Length - 1));
		if (it == SkipTbl.end()) {
			p += Length;
		}
		else {
			p += (*it).second;
		}
	}                                    

	return (size_t)-1;
}

