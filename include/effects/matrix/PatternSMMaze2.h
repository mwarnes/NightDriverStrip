#pragma once

#include "effects/strip/musiceffect.h"
#include "effectmanager.h"

#if ENABLE_AUDIO
class PatternSMMaze2 : public BeatEffectBase, public LEDStripEffect
#else
class PatternSMMaze2 : public LEDStripEffect
#endif
{
private:
public:
  PatternSMMaze2() :
#if ENABLE_AUDIO
    BeatEffectBase(1.50, 0.05),
#endif
    LEDStripEffect(EFFECT_MATRIX_SMMAZE2, "Maze 2")
    {
    }

  PatternSMMaze2(const JsonObjectConst& jsonObject) :
#if ENABLE_AUDIO
    BeatEffectBase(1.50, 0.05),
#endif
    LEDStripEffect(jsonObject)
  {
  }

  virtual void Start() override
  {
    g()->Clear();
  }

  virtual void Draw() override
  {
#if ENABLE_AUDIO
    ProcessAudio();
#endif
  }

#if ENABLE_AUDIO
  virtual void HandleBeat(bool bMajor, float elapsed, float span) override
  {

  }
#endif
};
