#ifndef IDENTIFIER_H
#define IDENTIFIER_H

#include <string>

class Identifier {
	public:
		Identifier();
		Identifier(const char* identifier);
		Identifier(const std::string& identifier);

		bool isEqualTo(const Identifier& identifier) const;
		bool isGreaterThan(const Identifier& identifier) const;
		bool isLesserThan(const Identifier& identifier) const;

		bool operator==(const Identifier& identifier) const;
		bool operator!=(const Identifier& identifier) const;
		bool operator<(const Identifier& identifier) const;
		bool operator>(const Identifier& identifier) const;

	public:
		std::string _identifier;
};

#endif
