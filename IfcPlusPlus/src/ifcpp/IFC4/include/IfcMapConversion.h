/* -*-c++-*- IfcPlusPlus - www.ifcplusplus.com - Copyright (C) 2011 Fabian Gerold
*
* This library is open source and may be redistributed and/or modified under  
* the terms of the OpenSceneGraph Public License (OSGPL) version 0.0 or 
* (at your option) any later version.  The full license is in LICENSE file
* included with this distribution, and on the openscenegraph.org website.
* 
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
* OpenSceneGraph Public License for more details.
*/
#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "ifcpp/model/shared_ptr.h"
#include "ifcpp/model/IfcPPObject.h"
#include "IfcCoordinateOperation.h"
class IfcLengthMeasure;
class IfcReal;
//ENTITY
class IfcMapConversion : public IfcCoordinateOperation
{
public:
	IfcMapConversion();
	IfcMapConversion( int id );
	~IfcMapConversion();
	virtual shared_ptr<IfcPPObject> getDeepCopy( IfcPPCopyOptions& options );
	virtual void getStepLine( std::stringstream& stream ) const;
	virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
	virtual void readStepArguments( const std::vector<std::wstring>& args, const std::map<int,shared_ptr<IfcPPEntity> >& map );
	virtual void setInverseCounterparts( shared_ptr<IfcPPEntity> ptr_self );
	virtual void getAttributes( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes );
	virtual void getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes );
	virtual void unlinkSelf();
	virtual const char* classname() const { return "IfcMapConversion"; }


	// IfcCoordinateOperation -----------------------------------------------------------
	// attributes:
	//  shared_ptr<IfcCoordinateReferenceSystemSelect>	m_SourceCRS;
	//  shared_ptr<IfcCoordinateReferenceSystem>		m_TargetCRS;

	// IfcMapConversion -----------------------------------------------------------
	// attributes:
	shared_ptr<IfcLengthMeasure>					m_Eastings;
	shared_ptr<IfcLengthMeasure>					m_Northings;
	shared_ptr<IfcLengthMeasure>					m_OrthogonalHeight;
	shared_ptr<IfcReal>							m_XAxisAbscissa;			//optional
	shared_ptr<IfcReal>							m_XAxisOrdinate;			//optional
	shared_ptr<IfcReal>							m_Scale;					//optional
};

