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
#include <iostream>
#include <filesystem>
#include <vector>

// #include "single_include/nlohmann/json.hpp"
#include "config.h"

namespace fs = std::filesystem;


void writeInitial(std::ofstream& resourceidentifiers)
{
	resourceidentifiers << "#ifndef resourceidentifiers_hpp\n#define resourceidentifiers_hpp\n\n";
	resourceidentifiers << "namespace eng\n{\n";	
}

void writeClosing(std::ofstream& resourceidentifiers)
{
	resourceidentifiers << "}\n";
	resourceidentifiers << "#endif /* resourceidentifiers_hpp */";
}

// Create a ResourceIdentifiers.hpp file inside the CMAKE_CURRENT_BINARY_DIR
void buildDefault(std::ofstream& resourceidentifiers)
{
	writeInitial(resourceidentifiers);
	resourceidentifiers << "namespace Textures\n{\n";
	resourceidentifiers << "\tenum ID\n\t{\n";
	resourceidentifiers << "a";
//	resourceidentifiers << "\t\tButtons,\n\t\tParticle,\n\t\tTileSet,\n\t\tInputField\n";
	resourceidentifiers << "\t};\n";
	resourceidentifiers << "}\n";
	resourceidentifiers << "namespace Fonts\n{\n";
	resourceidentifiers << "\tenum ID\n\t{\n";
	resourceidentifiers << "a";
//	resourceidentifiers << "\t\tMono\n";
	resourceidentifiers << "\t};\n";
	resourceidentifiers << "}\n";
	resourceidentifiers << "namespace Music\n{\n";
	resourceidentifiers << "\tenum ID\n\t{\n";
	resourceidentifiers << "a";
//	resourceidentifiers << "\t\tTheme\n";
	resourceidentifiers << "\t};\n";
	resourceidentifiers << "}\n";
	resourceidentifiers << "namespace Shaders\n{\n";
	resourceidentifiers << "\tenum ID\n\t{\n";
	resourceidentifiers << "a";
//	resourceidentifiers << "\t\tBrightnessPass\n";
	resourceidentifiers << "\t};\n";
	resourceidentifiers << "}\n";
	resourceidentifiers << "namespace SoundEffects\n{\n";
	resourceidentifiers << "\tenum ID\n\t{\n";
	resourceidentifiers << "a";
//	resourceidentifiers << "\t\tAlliedGunfire,\n\t\tEnemyGunfire,\n\t\tExplosion1,\n\t\tExplosion2,\n\t\tLaunchMissile,\n\t\tCollectPickup,\n\t\tButton\n"
	resourceidentifiers << "\t};\n";
	resourceidentifiers << "}\n";
	writeClosing(resourceidentifiers);
}

void buildFromFolder(std::ofstream& resourceidentifiers)
{
	writeInitial(resourceidentifiers);
	// Store all namespaces (es.: Textures, Music, ...)
	std::vector<std::string> namespaces;
	std::vector<std::vector<std::string> > paths;

	int counter = 0;
    for (const auto & entry : fs::directory_iterator(RESOURCES_PATH))
    {
        if(entry.is_directory())
        {
	    	//	create empty vector rappresenting the curent namespace (Textures, Music, ...)
    		paths.push_back({});
		    // See https://www.appsloveworld.com/cplus/100/156/how-to-subtract-one-path-from-another
		    fs::path folder = entry.path().lexically_relative(entry.path().parent_path());
        	namespaces.push_back(folder);
        	resourceidentifiers << "namespace " << folder.string() << "\n{\n";
			resourceidentifiers << "\tenum ID\n\t{\n";
			for( const auto & resource : fs::directory_iterator(entry.path()))
			{
				if(resource.is_regular_file())
				{
					fs::path file = resource.path().lexically_relative(resource.path().parent_path());
					//	Add different files used by the OS that the software should not use
					if(file != ".DS_Store")
					{
				        std::cout << file << std::endl;
				        paths[counter].push_back(file.string());
				        resourceidentifiers << "\t\t" << file.stem().string() << ",\n";						
					}
				}
			}
			resourceidentifiers << "\t};\n";
	        resourceidentifiers << "}\n";
        }
        counter++;
    }

    for(int i = 0; i < paths.size(); i++)
    {
    	std::cout << namespaces[i] << " :\n";
    	for(int j = 0; j < paths[i].size(); j++)
    		std::cout << "\n" << paths[i][j] << "\n";
    }
    std::cout << std::endl;
    writeClosing(resourceidentifiers);
}


int main()
{
	std::ofstream resourceidentifiers;
	resourceidentifiers.open("ResourceIdentifiers.hpp", std::ofstream::trunc);

	if(BUILD_DEFAULT_IDENTIFIERS)
	{
		buildDefault(resourceidentifiers);
	}
	else
	{
		buildFromFolder(resourceidentifiers);
	}
	resourceidentifiers.close();

	return 0;
}