#pragma once

#include <string>
#include <optional>
#include <memory>
#include <thread>

#include "Runnable.h"

namespace compat {

class Thread : public Runnable {
public:
    Thread();

    explicit Thread(std::string name);

    explicit Thread(Runnable* target);

    Thread(Runnable* target, std::string name);

    virtual ~Thread() noexcept;

    [[nodiscard]]
    std::string getName() const;

    void setName(std::string name);

    [[nodiscard]]
    int getId() const;

    [[nodiscard]]
    int getPriority() const;

    void setPriority(int priority);

    void start();

    void join() const;


private:
    std::string name;
    Runnable* target;
    int priority;
    std::jthread* innerThread;
    bool started;
};

} // namespace compat
