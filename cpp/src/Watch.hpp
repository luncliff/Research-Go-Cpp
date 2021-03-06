// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ====
//
//  Author  : Park  Dong Ha ( luncliff@gmail.com )
//
//  Note
//      Simple stop watch
//
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----
#ifndef _STOP_WATCH_HPP_
#define _STOP_WATCH_HPP_

#include <chrono>

// - Note
//      Stop watch class.
//      - `pick()`  : Acquire elapsed time from start
//      - `reset()` : Reset the starting time_point
template <typename Clock>
class stop_watch
{
  public:
    using clock_type = Clock;
    using time_point = typename clock_type::time_point;
    using duration = typename clock_type::duration;

  private:
    time_point start = clock_type::now();

  public:
    template <typename UnitType = std::chrono::milliseconds>
    decltype(auto) pick() const noexcept
    {
        duration span = clock_type::now() - start;
        return std::chrono::duration_cast<UnitType>(span);
    };

    template <typename UnitType = std::chrono::milliseconds>
    decltype(auto) reset() noexcept
    {
        auto span = this->pick<UnitType>();

        // reset start time point
        start = clock_type::now();

        return std::chrono::duration_cast<UnitType>(span);
    }
};

// Alias for stop watch class
using StopWatch = stop_watch<std::chrono::high_resolution_clock>;

#endif
