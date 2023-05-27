#pragma once

#include <vector>

enum class BuildState {
    None = 0,
    InProgress = 1,
    Finished = 2
};


struct MeshData;

template<class T>
class IBuilder {
protected:
    BuildState current_state = BuildState::None; 
    T build_result {};

public:
    IBuilder() { current_state = BuildState::InProgress; }
    ~IBuilder() = default;

    virtual void Build() = 0;

    T GetBuildResult();
};

#include "MeshData.hpp"