#ifndef GLES3_VERLETINTEGRATION101_VERLETINTEGRATION101_HPP
#define GLES3_VERLETINTEGRATION101_VERLETINTEGRATION101_HPP
/****************************************************************************************************************************************************
* Copyright (c) 2016 Freescale Semiconductor, Inc.
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
*    * Redistributions of source code must retain the above copyright notice,
*      this list of conditions and the following disclaimer.
*
*    * Redistributions in binary form must reproduce the above copyright notice,
*      this list of conditions and the following disclaimer in the documentation
*      and/or other materials provided with the distribution.
*
*    * Neither the name of the Freescale Semiconductor, Inc. nor the names of
*      its contributors may be used to endorse or promote products derived from
*      this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
* LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
* OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
* ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
****************************************************************************************************************************************************/

#include <FslDemoApp/OpenGLES3/DemoAppGLES3.hpp>
#include <FslUtil/OpenGLES3/GLProgram.hpp>
#include <FslUtil/OpenGLES3/GLTexture.hpp>
#include <FslUtil/OpenGLES3/NativeBatch2D.hpp>
#include <FslSimpleUI/App/UIDemoAppExtension.hpp>
#include <deque>

namespace Fsl
{
  class VerletIntegration101
    : public DemoAppGLES3
    , public UI::EventListener
  {
    UI::CallbackEventListenerScope m_uiEventListener;
    std::shared_ptr<UIDemoAppExtension> m_uiExtension;
    std::shared_ptr<GLES3::NativeBatch2D> m_batch;
    AtlasTexture2D m_texFill;
    AtlasTexture2D m_texBall;
    AtlasTexture2D m_texTest;

    struct Particle
    {
      Vector2 Position;
      Vector2 OldPosition;

      Particle()
        : Position()
        , OldPosition()
      {
      }

      Particle(const float x, const float y, const float oldX, const float oldY)
        : Position(x, y)
        , OldPosition(oldX, oldY)
      {
      }
    };

    struct Stick
    {
      int32_t PointIndex0;
      int32_t PointIndex1;
      float Length;

      Stick()
        : PointIndex0(0)
        , PointIndex1(0)
        , Length(0)
      {
      }

      Stick(const int32_t pointIndex0, const int32_t pointIndex1, const float length)
        : PointIndex0(pointIndex0)
        , PointIndex1(pointIndex1)
        , Length(length)
      {
      }
    };

    Rectangle m_boundaryRect;
    std::deque<Particle> m_particles;
    std::deque<Stick> m_sticks;
    float m_rotation;

  public:
    VerletIntegration101(const DemoAppConfig& config);
    ~VerletIntegration101();
  protected:
    virtual void FixedUpdate(const DemoTime& demoTime) override;
    virtual void Update(const DemoTime& demoTime) override;
    virtual void Draw(const DemoTime& demoTime) override;
  private:
    void UpdateParticles(std::deque<Particle>& particles, const float friction);
    void UpdateSticks(std::deque<Particle>& particles, std::deque<Stick>& sticks);
    void ConstrainPoints(std::deque<Particle>& particles, const Rectangle& boundaryRect, const float friction);
    void DrawSticks(const std::deque<Particle>& particles, const std::deque<Stick>& sticks);
    void DrawParticles(const std::deque<Particle>& particles);
  };
}

#endif
