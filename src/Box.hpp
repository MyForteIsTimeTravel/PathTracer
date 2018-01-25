/* * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 * Box
 * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef Box_hpp
#define Box_hpp

#include "Linear/vec3.hpp"
#include "Material.hpp"

struct Box
	{
    Linear::vec3 position;  // center of the box
    Linear::vec3 size;		// (width, height, depth)
    Material material;      // surface information
	};

#endif /* Box_hpp */

