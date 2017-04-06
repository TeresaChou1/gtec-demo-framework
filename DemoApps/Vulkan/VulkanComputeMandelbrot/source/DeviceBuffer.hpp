#ifndef VULKAN_VULKANCOMPUTEMANDELBROT_DEVICEBUFFER_HPP
#define VULKAN_VULKANCOMPUTEMANDELBROT_DEVICEBUFFER_HPP
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

#include <FslBase/BasicTypes.hpp>
#include <FslBase/Noncopyable.hpp>
#include <FslGraphicsVulkan1_0/Extend/BufferEx.hpp>
#include <FslGraphicsVulkan1_0/Extend/DeviceMemoryEx.hpp>
#include <vulkan/vulkan.h>

namespace Fsl
{
  class DeviceBuffer : Noncopyable
  {
    Vulkan::BufferEx m_buffer;
    Vulkan::DeviceMemoryEx m_memory;
    //VkFormat m_imageFormat;
  public:
    // move assignment operator
    DeviceBuffer& operator=(DeviceBuffer&& other);
    // move constructor
    DeviceBuffer(DeviceBuffer&& other);

    DeviceBuffer();
    DeviceBuffer(Vulkan::BufferEx&& buffer, Vulkan::DeviceMemoryEx&& deviceMemory);

    void Reset();
    void Reset(Vulkan::BufferEx&& buffer, Vulkan::DeviceMemoryEx&& deviceMemory);

    const Vulkan::BufferEx& GetBuffer() const
    {
      return m_buffer;
    }

    Vulkan::BufferEx& GetBuffer2()
    {
      return m_buffer;
    }

    const Vulkan::DeviceMemoryEx& GetDeviceMemory() const
    {
      return m_memory;
    }

    void MapMemory(const VkDeviceSize offset, const VkDeviceSize size, const VkMemoryMapFlags flags)
    {
      m_memory.MapMemory(offset, size, flags);
    }

    void* GetMappedMemoryPointer() const
    {
      return m_memory.GetMappedMemoryPointer();
    }

    void InvalidateMappedMemoryRanges(const VkDeviceSize offset, const VkDeviceSize size)
    {
      return m_memory.InvalidateMappedMemoryRanges(offset, size);
    }

    void UnmapMemory()
    {
      m_memory.UnmapMemory();
    }

  };

}

#endif