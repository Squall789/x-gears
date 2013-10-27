#include "map/QGearsWalkmeshFileXMLSerializer.h"

#include <OgreLogManager.h>
#include <OgreException.h>

namespace QGears
{
    //--------------------------------------------------------------------------
    WalkmeshFileXMLSerializer::WalkmeshFileXMLSerializer() :
        XMLSerializer()
    {
    }
    
    //--------------------------------------------------------------------------
    WalkmeshFileXMLSerializer::~WalkmeshFileXMLSerializer()
    {
    }
    
    //--------------------------------------------------------------------------
    void WalkmeshFileXMLSerializer::readHeader( TiXmlNode *node )
    {
        if( node == NULL || node->ValueStr() != "walkmesh" )
        {
            OGRE_EXCEPT(Ogre::Exception::ERR_INVALIDPARAMS
                ,"not a valid walkmesh file, no <walkmesh> in root"
                ,"WalkmeshFileXMLSerializer::readHeader" );
        }
    }

    //--------------------------------------------------------------------------
    void
    WalkmeshFileXMLSerializer::importWalkmeshFile( Ogre::DataStreamPtr &stream
                                                  ,WalkmeshFile *pDest )
    {
        TiXmlDocument document;
        parse( stream, document );

        TiXmlNode *root_node( document.RootElement() );
        readHeader( root_node );
        TiXmlNode &node( *root_node );

        readVector( node, pDest->getTriangles(), "triangle" );
    }

    //--------------------------------------------------------------------------
    void
    WalkmeshFileXMLSerializer::readObject( TiXmlNode &node
                                          ,WalkmeshFileXMLSerializer::Triangle &pDest )
    {
        readAttribute( node, pDest.a, "a" );
        readAttribute( node, pDest.b, "b" );
        readAttribute( node, pDest.c, "c" );
        readAttribute( node, pDest.access_side[0], "a_b" );
        readAttribute( node, pDest.access_side[1], "b_c" );
        readAttribute( node, pDest.access_side[2], "c_a" );
    }

    //--------------------------------------------------------------------------
}

