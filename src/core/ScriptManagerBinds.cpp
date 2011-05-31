#include "Logger.h"
#include "Entity.h"
#include "EntityManager.h"



void
ScriptPrint( const char* text )
{
    LOG_TRIVIAL( text );
}



void
ScriptManager::InitBinds()
{
    // globals
    luabind::module( m_LuaState )
    [
        luabind::def( "print", &ScriptPrint )
    ];

    // entity access
    luabind::module( m_LuaState )
    [
        luabind::class_< Entity >( "Entity" )
            .def( "set_position", ( void( Entity::* )( const float, const float, const float ) ) &Entity::ScriptSetPosition )
            .def( "set_direction", ( void( Entity::* )( const float ) ) &Entity::ScriptSetDirection )
            .def( "set_solid_radius", ( void( Entity::* )( const float ) ) &Entity::SetSolidRadius )
            .def( "get_solid_radius", ( float( Entity::* )() ) &Entity::GetSolidRadius )
            .def( "set_solid", ( void( Entity::* )( const bool ) ) &Entity::SetSolid )
            .def( "is_solid", ( bool( Entity::* )() ) &Entity::IsSolid )
            .def( "set_talk_radius", ( void( Entity::* )( const float ) ) &Entity::SetTalkRadius )
            .def( "get_talk_radius", ( float( Entity::* )() ) &Entity::GetTalkRadius )
            .def( "set_talkable", ( void( Entity::* )( const bool ) ) &Entity::SetTalkable )
            .def( "is_talkable", ( bool( Entity::* )() ) &Entity::IsTalkable )
            .def( "set_visible", ( void( Entity::* )( const bool ) ) &Entity::SetVisible )
            .def( "is_visible", ( bool( Entity::* )() ) &Entity::IsVisible )
            .def( "set_move_speed", ( void( Entity::* )( const float ) ) &Entity::SetMoveSpeed )
            .def( "get_move_speed", ( float( Entity::* )() ) &Entity::GetMoveSpeed )
            .def( "move_auto_rotation", ( void( Entity::* )( const bool ) ) &Entity::SetMoveAutoRotation )
            .def( "move_walkmesh", ( int( Entity::* )( const float, const float ) ) &Entity::ScriptMoveWalkmesh )
            .def( "play_animation", ( void( Entity::* )( const char* ) ) &Entity::ScriptPlayAnimation )
            .def( "play_animation_stop", ( void( Entity::* )( const char* ) ) &Entity::ScriptPlayAnimationStop )
            .def( "play_animation", ( void( Entity::* )( const char*, const float, const float ) ) &Entity::ScriptPlayAnimation )
            .def( "play_animation_stop", ( void( Entity::* )( const char*, const float, const float ) ) &Entity::ScriptPlayAnimationStop )
            .def( "set_default_animation", ( void( Entity::* )( const char* ) ) &Entity::ScriptSetDefaultAnimation )
            .def( "animation_sync", ( int( Entity::* )()) &Entity::ScriptAnimationSync, luabind::yield )
    ];

    // game access
    luabind::module( m_LuaState )
    [
        luabind::class_< EntityManager >( "EntityManager" )
            .def( "get_entity", ( Entity* ( EntityManager::* )( const char* ) ) &EntityManager::ScriptGetEntity )
    ];

    // script access
    luabind::module( m_LuaState )
    [
        luabind::class_< ScriptManager >( "Script" )
            .def( "wait", ( int( ScriptManager::* )( const float ) ) &ScriptManager::ScriptWait, luabind::yield )
            .def( "request", ( void( ScriptManager::* )( const char*, const char*, const int ) ) &ScriptManager::ScriptRequest )
            .def( "request_start_sync", ( int( ScriptManager::* )( const char*, const char*, const int ) ) &ScriptManager::ScriptRequestStartSync, luabind::yield )
            .def( "request_end_sync", ( int( ScriptManager::* )( const char*, const char*, const int ) ) &ScriptManager::ScriptRequestEndSync, luabind::yield )
    ];

    luabind::globals( m_LuaState )[ "script" ] = boost::ref( *this );
    luabind::globals( m_LuaState )[ "game" ] = boost::ref( *( EntityManager::getSingletonPtr() ) );
}
