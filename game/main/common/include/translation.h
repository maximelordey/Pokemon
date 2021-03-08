#ifndef TRANSLATION_H
#define TRANSLATION_H

#include <string>

class Translation {
	public:
		Translation();
		Translation(const wchar_t* _content);
		Translation(std::wstring& _content);

	public:
		std::wstring _content;
};

#endif
