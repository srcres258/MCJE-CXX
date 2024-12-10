#include "Thread.h"

#include <utility>

namespace compat {

Thread::Thread() : Thread("Thread") {}

Thread::Thread(std::string name) :
        name(std::move(name)),
        target(nullptr),
        priority(0) {}

Thread::Thread(Runnable* target) :
        name("Thread"),
        target(target),
        priority(0) {}

Thread::Thread(Runnable* target,
        std::string name) :
        name(std::move(name)),
        target(nullptr),
        priority(0) {}

Thread::~Thread() noexcept {
    if (innerThread) {
        delete innerThread;
    }
}

[[nodiscard]]
std::string Thread::getName() const {
    return name;
}

void Thread::setName(std::string name) {
    this->name = std::move(name);
}

[[nodiscard]]
int Thread::getId() const {
    return 0;
}

[[nodiscard]]
int Thread::getPriority() const {
    return priority;
}

void Thread::setPriority(int priority) {
    this->priority = priority;
}

void Thread::start() {
    auto threadStarter = [this]{
        if (target) {
            target->run();
        }
    };
    innerThread = new std::jthread(threadStarter);
}

void Thread::join() const {
    if (innerThread) {
        innerThread->join();
    }
}

}
