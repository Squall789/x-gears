#ifndef PARTICLE_EMITTER_TRANSLATOR_H
#define PARTICLE_EMITTER_TRANSLATOR_H

#include <OgreScriptTranslator.h>
#include <OgreSingleton.h>



class ParticleEmitterTranslator : public Ogre::ScriptTranslator
{
public:
    void translate(Ogre::ScriptCompiler *compiler, const Ogre::AbstractNodePtr &node);
};



#endif // PARTICLE_EMITTER_TRANSLATOR_H
