#include "IBuilder.hpp"
#include "Exception.hpp"

using std::vector;

template<class T>
T IBuilder<T>::GetBuildResult() {
    if (current_state != BuildState::Finished)
        throw Exception("The current builder has not build the final object.");

    return build_result;
}

template MeshData IBuilder<MeshData>::GetBuildResult();