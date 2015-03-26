#include "XmlTextFile.h"

#include "Logger.h"
#include "TextManager.h"
#include "Utilites.h"



XmlTextFile::XmlTextFile( const Ogre::String& file ):
    XmlFile( file )
{
}



XmlTextFile::~XmlTextFile()
{
}



void
XmlTextFile::LoadTexts()
{
    TiXmlNode* node = m_File.RootElement();

    if( node == NULL || node->ValueStr() != "texts" )
    {
        LOG_ERROR( "Text Manager: " + m_File.ValueStr() + " is not a valid text file! No <texts> in root." );
        return;
    }

    node = node->FirstChild();
    while( node != NULL )
    {
        if( node->Type() == TiXmlNode::TINYXML_ELEMENT && node->ValueStr() == "text" )
        {
            Ogre::String name = GetString( node, "name" );
            TextManager::getSingleton().AddText( name, node->Clone() );
        }
        else if( node->Type() == TiXmlNode::TINYXML_ELEMENT && node->ValueStr() == "dialog" )
        {
            Ogre::String name = GetString( node, "name" );
            float width = GetFloat( node, "width" );
            float height = GetFloat( node, "height" );
            TextManager::getSingleton().AddDialog( name, node->Clone(), width, height );
        }
        node = node->NextSibling();
    }
}