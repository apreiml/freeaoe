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


#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "Resource.h"

#include <memory>
#include "Graphic.h"

//------------------------------------------------------------------------------
/// The resource manager is the primary interface for getting recourses. At
/// initialization the manager loads header information from drs and other
/// files and loads needed resources on the fly.
//
class ResourceManager
{
public:
  //----------------------------------------------------------------------------
  /// Initializes the resource manager, must be called before using it.
  //
  static void init();
  
  //----------------------------------------------------------------------------
  /// Destroys the resource manager. Has to be called on exit.
  //
  static void destroy();
  
  //----------------------------------------------------------------------------
  /// Returns 
  //
  static std::auto_ptr<Graphic> getGraphic(unsigned int id);
  
private:
  ResourceManager();
  virtual ~ResourceManager();
};

#endif // RESOURCEMANAGER_H
