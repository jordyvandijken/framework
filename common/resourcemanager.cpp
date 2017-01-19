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
Sprite* ResourceManager::_getSprite(const std::string& filename, int _sprite_width, int _sprite_height)  {
	auto search = _sprites.find(filename);
  if(search != _sprites.end()) {
		return search->second;
  } else {
		Sprite* t = new Sprite(filename, _sprite_width, _sprite_height);
		_sprites[filename] = t;
		return t;
	}
	return NULL;
}

void ResourceManager::cleanUp() {
	// adawda
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
