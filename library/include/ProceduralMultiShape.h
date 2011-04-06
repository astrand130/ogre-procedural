/*
-----------------------------------------------------------------------------
This source file is part of ogre-procedural

For the latest info, see http://code.google.com/p/ogre-procedural/

Copyright (c) 2010 Michael Broutin

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
-----------------------------------------------------------------------------
*/
#ifndef PROCEDURAL_MULTISHAPE_INCLUDED
#define PROCEDURAL_MULTISHAPE_INCLUDED

#include "ProceduralRoot.h"

namespace Procedural
{
	class Shape;

/**
 * Holds a bunch of shapes.
 * There are a number of assumptions that are made and are not checked
 * against : the shapes must not cross each other
 * 
 */
class _ProceduralExport MultiShape
{
	std::vector<Shape> mShapes;
	
	public:
	MultiShape()
	{}		
	//-----------------------------------------------------------------------
	MultiShape(const Shape& shape)
	{
		mShapes.push_back(shape);
	}		
	//-----------------------------------------------------------------------
	MultiShape& addShape(const Shape& shape)
	{
		mShapes.push_back(shape);
		return *this;
	}	
	//-----------------------------------------------------------------------
	const Shape& getShape(int i) const
	{		
		return mShapes[i];
	}	
	//-----------------------------------------------------------------------
	Shape& getShape(int i)
	{		
		return mShapes[i];
	}
	//-----------------------------------------------------------------------
	std::vector<Ogre::Vector2> getPoints() const;
	//-----------------------------------------------------------------------
	int getShapeCount() const
	{
		return mShapes.size();
	}	
	//-----------------------------------------------------------------------
	void addMultiShape(const MultiShape& other)
	{
		for (std::vector<Shape>::const_iterator it = other.mShapes.begin(); it!=other.mShapes.end(); it++)
		{
			mShapes.push_back(*it);
		}
	}	
	//-----------------------------------------------------------------------
	Ogre::MeshPtr MultiShape::realizeMesh(const std::string& name);
	//-----------------------------------------------------------------------
	bool isPointInside(const Ogre::Vector2& point) const;
	
};
}
#endif
