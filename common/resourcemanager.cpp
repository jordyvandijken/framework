#include "resourcemanager.h"

ResourceManager* ResourceManager::instance = NULL;
ResourceManager::ResourceManager() {

}

ResourceManager::~ResourceManager() {
	// clean up Textures
	this->cleanUp();
}

ResourceManager* ResourceManager::getInstance() {
	if (!instance) {
		ResourceManager::instance = new ResourceManager();
	}
	return ResourceManager::instance;
}

// Sprite
Sprite* ResourceManager::_getSprite(const std::string& filename, int filter)  {
  auto search = _sprites.find(filename);
  if(search != _sprites.end()) {
		return search->second;
  } else {
	  	std::cout << "Load: " << filename << '\n';
		Sprite* t = new Sprite(filename, filter);
		_sprites[filename] = t;
		return t;
	}
	return NULL;
}

void ResourceManager::cleanUp() {
	// clean up the sprites
	std::map<std::string, Sprite*>::iterator sprite_it;
	for (sprite_it=_sprites.begin(); sprite_it!=_sprites.end(); ++sprite_it) {
		if (sprite_it->second != NULL) {
			deleteSprite(sprite_it->first);
		}
	}
	_sprites.clear();
}

void ResourceManager::deleteSprite(const std::string& filename) {
	delete _sprites[filename];
	_sprites[filename] = NULL;
}
