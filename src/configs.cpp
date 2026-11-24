// configs.cpp — part of deadlock-optimizer.

#include "deadlockoptimizer/configs.h"

#include <cstdio>

namespace deadlockoptimizer {

Configs::Configs(const std::string& config_path)
    : config_path_(config_path) {}

void Configs::configure(const std::string& key, const std::string& value) {
    if (key == "verbose") verbose_ = (value == "true");
}

bool Configs::run() {
    if (verbose_) std::fprintf(stderr, "[deadlock-optimizer] configs: run\n");
    // core logic lives here
    return true;
}

}  // namespace deadlockoptimizer
