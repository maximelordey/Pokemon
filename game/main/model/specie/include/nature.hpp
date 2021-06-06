#ifndef NATURE_H
#define NATURE_H

#include <memory>

#include "coefficient.h"
#include "identifier.h"

class Nature;
typedef std::shared_ptr<Nature> SharedNature;

class Nature {
	public:
		Nature();
		Nature(const Identifier& identifier);

		bool isEqualTo(const Nature& nature) const;
		bool isLesserThan(const Nature& nature) const;
		bool isGreaterThan(const Nature& nature) const;

		bool operator==(const Nature& nature) const;
		bool operator!=(const Nature& nature) const;
		bool operator<(const Nature& nature) const;
		bool operator>(const Nature& nature) const;

	public:
		Coefficient attack_bonus;
		Coefficient defence_bonus;
		Coefficient attackSpe_bonus;
		Coefficient defenceSpe_bonus;
		Coefficient speed_bonus;

	private:
		Identifier identifier;
};

#endif
