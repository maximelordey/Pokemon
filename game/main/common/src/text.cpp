#include "text.h"

Text::Text()
	: _content()
{}

Text::Text(const wchar_t* _content)
	: _content(_content)
{}
Text::Text(std::wstring& _content)
	: _content(_content)
{}
