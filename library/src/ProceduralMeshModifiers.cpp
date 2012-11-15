/*
-----------------------------------------------------------------------------
This source file is part of ogre-procedural

For the latest info, see http://code.google.com/p/ogre-procedural/

Copyright (c) 2010-2012 Michael Broutin

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
#include "ProceduralStableHeaders.h"
#include "ProceduralMeshModifiers.h"

namespace Procedural
{
void SpherifyModifier::modify()
{
	if(mInputTriangleBuffer == NULL)
		OGRE_EXCEPT(Ogre::Exception::ERR_INVALID_STATE, "Input triangle buffer must be set", "Procedural::SpherifyModifier::modify()");
	
	for (std::vector<TriangleBuffer::Vertex>::iterator it = mInputTriangleBuffer->getVertices().begin(); it!=mInputTriangleBuffer->getVertices().end(); ++it)
	{
		Ogre::Real l = it->mPosition.length();
		if (l>1e-6)
			it->mNormal = it->mPosition = it->mPosition / l;
	}
}
}