#include "concurrency/side_coro.hpp"

#include "errors.hpp"
#include <boost/bind.hpp>

#include "arch/runtime/runtime.hpp"

side_coro_handler_t::side_coro_handler_t(const boost::function<void (signal_t *)>& f)
    : fun(f) {
    coro_t::spawn(boost::bind(&side_coro_handler_t::run, this));
}


void side_coro_handler_t::run() {
    fun(&stop_cond);
    done_cond.pulse();
}

