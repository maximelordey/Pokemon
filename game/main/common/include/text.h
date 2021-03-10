#ifndef TEXT_T
#define TEXT_T

#include <string>

class Text {
	public:
		Text();
		Text(const wchar_t* _content);
		Text(std::wstring& _content);

	public:
		std::wstring _content;
};

#endif
