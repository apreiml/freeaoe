/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) 2011  <copyright holder> <email>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include "ResourceManager.h"

#include <fstream>
#include <iostream>
#include <memory>

#include <file/DrsGraphics.h>
#include <global/Config.h>

ResourceManager *ResourceManager::instance_ = 0;

//------------------------------------------------------------------------------
ResourceManager* ResourceManager::Inst()
{
  if (instance_ == 0)
    instance_ = new ResourceManager();
  
  return instance_;
}

//------------------------------------------------------------------------------
void ResourceManager::Destroy()
{
  delete instance_;
}

//------------------------------------------------------------------------------
std::auto_ptr< Graphic > ResourceManager::getGraphic(unsigned int id)
{
  std::map<long int, SlpFile *>::iterator pos = slp_files_.find(id);
  
  if (pos == slp_files_.end())
  {
    std::cerr << "Graphic " << id << " not found!" << std::endl;
    return std::auto_ptr< Graphic > (0);
  }
  else
  {
    pos->second->load();
    return std::auto_ptr< Graphic >( new Graphic(pos->second) );
  }
}


//------------------------------------------------------------------------------
ResourceManager::ResourceManager()
{
  initialize();
}

//------------------------------------------------------------------------------
ResourceManager::~ResourceManager()
{

}

//------------------------------------------------------------------------------
void ResourceManager::initialize()
{
  std::string terrain_path(Config::Inst()->getDataPath() + "terrain.drs");
  DrsGraphics *g_terrain = new DrsGraphics(terrain_path.c_str(), &slp_files_);
  g_terrain->load();
  
  drs_files_.push_back(g_terrain);
  
  std::string graphics_path(Config::Inst()->getDataPath() + "graphics.drs");
  g_terrain = new DrsGraphics(graphics_path.c_str(), &slp_files_);
  g_terrain->load();
  
  drs_files_.push_back(g_terrain);
}
