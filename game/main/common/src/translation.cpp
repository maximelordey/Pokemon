#include "translation.h"

Translation::Translation()
	: _content()
{}
Translation::Translation(const wchar_t* _content)
	: _content(_content)
{}
Translation::Translation(std::wstring& _content)
	: _content(_content)
{}
