/*
Copyright 2013 eric schkufza

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#ifndef X64ASM_ENV_BITS_H
#define X64ASM_ENV_BITS_H

#include <iostream>

namespace x64asm {

/** An environment register bit. */
class EnvBits {
  public:
    /** Returns this bit's upper register index. */
    constexpr size_t index();
    /** Returns the number of bits this register bit spans. */
    constexpr size_t width();

  protected:
    /** Direct access to this constructor is disallowed. */
    constexpr EnvBits(size_t i, size_t w);

  private:
    /** This bit's upper register index. */
    const size_t index_;
    /** The number of bits this register bit spans. */
    const size_t width_;
};

/** An EFLAGS register bit. */
class Eflags : public EnvBits {
    // Needs access to constructor.
    friend class Constants;

  private:
    /** Direct access to this constructor is disallowed. */
    constexpr Eflags(size_t i, size_t w);
};

/** An FPU control register bit. */
class FpuControl : public EnvBits {
    // Needs access to constructor.
    friend class Constants;

  private:
    /** Direct access to this constructor is disallowed. */
    constexpr FpuControl(size_t i, size_t w);
};

/** An FPU status register bit. */
class FpuStatus : public EnvBits {
    // Needs access to constructor.
    friend class Constants;

  private:
    /** Direct access to this constructor is disallowed. */
    constexpr FpuStatus(size_t i, size_t w);
};

/** An FPU tag register. */
class FpuTag : public EnvBits {
    // Needs access to constructor.
    friend class Constants;

  private:
    /** Direct access to this constructor is disallowed. */
    constexpr FpuTag(size_t i, size_t w);
};

/** An MXCSR register bit. */
class Mxcsr : public EnvBits {
    // Needs access to constructor.
    friend class Constants;

  private:
    /** Direct access to this constructor is disallowed. */
    constexpr Mxcsr(size_t i, size_t w);
};

inline constexpr size_t EnvBits::index() {
  return index_;
}

inline constexpr size_t EnvBits::width() {
  return width_;
}

inline constexpr EnvBits::EnvBits(size_t i, size_t w) :
    index_{i}, width_{w} {
}

inline constexpr Eflags::Eflags(size_t i, size_t w) : 
    EnvBits {i, w} { 
}

inline constexpr FpuControl::FpuControl(size_t i, size_t w) : 
    EnvBits {i, w} { 
}

inline constexpr FpuStatus::FpuStatus(size_t i, size_t w) : 
    EnvBits {i, w} { 
}

inline constexpr FpuTag::FpuTag(size_t i, size_t w) : 
    EnvBits {i, w} { 
}

inline constexpr Mxcsr::Mxcsr(size_t i, size_t w) : 
    EnvBits {i, w} { 
}

} // namespace std

#endif

