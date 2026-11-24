// main.cpp — entry point. Wires config and subsystems together.

#include "deadlockoptimizer/settings.h"
#include "deadlockoptimizer/tuner.h"
#include "deadlockoptimizer/configs.h"
#include "deadlockoptimizer/monitor.h"
#include <csignal>
#include <memory>

namespace { std::atomic<bool> g_running{true}; void on_signal(int) { g_running.store(false); } }

int main(int argc, char** argv) {
    std::signal(SIGINT, on_signal);
    std::signal(SIGTERM, on_signal);

    deadlockoptimizer::Settings settings = deadlockoptimizer::Settings::load_default();
    deadlockoptimizer::Tuner tuner(settings.store_path);
    deadlockoptimizer::Configs configs(settings.store_path);
    deadlockoptimizer::Monitor monitor(settings.store_path);
    std::fprintf(stderr, "[deadlock-optimizer] ready\n");

    while (g_running.load()) {
        // main loop: pump subsystems
        break;
    }
    return 0;
}
