#ifndef DIMENSION_HPP
#define DIMENSION_HPP

#include <cstdint>
#include <optional>
#include <memory>

struct Dimension;
typedef std::optional<Dimension> OptDimension;
typedef std::shared_ptr<Dimension> SharedDimension;
typedef std::unique_ptr<Dimension> UniqueDimension;
typedef std::weak_ptr<Dimension> WeakDimension;


struct Dimension {
	int32_t width;
	int32_t height;
};

#endif
