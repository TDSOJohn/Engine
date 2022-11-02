// #include "buildtime/ResourceIdentifiersGenerator.cpp"

/*

OPTIONS:
GET ALL RESOURCE IDENTIFIERS FROM FOLDER FILES -->
	EVERY NAMESPACE IS RETHRIEVED FROM THE FOLDER'S NAME
	EVERY ENUM ID ITEM IS RETHRIEVED FROM THE FILES INSIDE THE FODERS
	problems: .DS_Store and other files
	either:
	1) have to know getResourcePath() before (ResourcePath.cpp has to be compiled before ResourceIdentifiersGenerator.cpp
	2) use relative paths (not good)
	3) ( use CMAKE to export the path to something like a .h and use it instead of getResourcePath()? )

*/


#include <string>
#include <fstream>
// #include "single_include/nlohmann/json.hpp"
#include "config.h"

// Create a ResourceIdentifiers.hpp file inside the CMAKE_CURRENT_BINARY_DIR
void buildDefault()
{
	std::ofstream resourceidentifiers;
	resourceidentifiers.open("ResourceIdentifiers.hpp");
	resourceidentifiers << "#ifndef resourceidentifiers_hpp\n#define resourceidentifiers_hpp\n\n";
	resourceidentifiers << "namespace eng\n{\n";
	resourceidentifiers << "namespace Textures\n{\n";
	resourceidentifiers << "\tenum ID\n\t{\n";
	resourceidentifiers << "\t\tButtons,\n\t\tParticle,\n\t\tTileset,\n\t\tInputField\n";
	resourceidentifiers << "\t};\n";
	resourceidentifiers << "}\n";
	resourceidentifiers << "namespace Fonts\n{\n";
	resourceidentifiers << "\tenum ID\n\t{\n";
	resourceidentifiers << "\t\tMono\n";
	resourceidentifiers << "\t};\n";
	resourceidentifiers << "}\n";
	resourceidentifiers << "namespace Music\n{\n";
	resourceidentifiers << "\tenum ID\n\t{\n";
	resourceidentifiers << "\t\tTheme\n";
	resourceidentifiers << "\t};\n";
	resourceidentifiers << "}\n";
	resourceidentifiers << "namespace Shaders\n{\n";
	resourceidentifiers << "\tenum ID\n\t{\n";
	resourceidentifiers << "\t\tBrightnessPass\n";
	resourceidentifiers << "\t};\n";
	resourceidentifiers << "}\n";
	resourceidentifiers << "namespace SoundEffect\n{\n";
	resourceidentifiers << "\tenum ID\n\t{\n\t\tAlliedGunfire,\n\t\tEnemyGunfire,\n\t\tExplosion1,\n\t\tExplosion2,\n\t\tLaunchMissile,\n\t\tCollectPickup,\n\t\tButton\n\t};\n";
	resourceidentifiers << "}\n";
	resourceidentifiers << "}\n";
	resourceidentifiers << "#endif /* resourceidentifiers_hpp */";
	resourceidentifiers.close();
}

void buildFromFolder(std::string resourcePath)
{

}


int main()
{
	if(BUILD_DEFAULT_IDENTIFIERS)
		buildDefault();
	else
		buildFromFolder(RESOURCES_PATH);

	return 0;
}